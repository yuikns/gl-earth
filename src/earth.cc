#include <unistd.h>
#include <cmath>
#include <cstdio>

#include <functional>
#include <string>

#include <SDL2/SDL_image.h>

#ifdef __APPLE__
#include <GLFW/glfw3.h>
#else  // for linux : yum install glfw* :)
#include <GL/glfw3.h>
#endif

/**
 * 打印键盘的 MOD,  aka SHIFT, CTRL, ALT, SUPER 的组合键解析
 */
inline std::string KeyCallbackModParse(int mods) {
  std::string m;
  m += mods & GLFW_MOD_SHIFT ? "[SHIFT]" : "_";
  m += mods & GLFW_MOD_CONTROL ? "[CTRL]" : "_";
  m += mods & GLFW_MOD_ALT ? "[ALT]" : "_";
  m += mods & GLFW_MOD_SUPER ? "[SUPER]" : "_";
  return m;
}

/**
 * Window 的上下文
 */
class GLContext {
 public:
  // 初始化参数
  GLContext() : speed_(1), earth_size_(0.3), offset_(0), texture_id_(0) {}

  // 加速
  void SpeedUp() {
    double rsec = glfwGetTime();
    speed_++;
    offset_ -= rsec * 50.f;
    printf("[SpeedUp] current speed: %d offset: %.3f\n", speed_, offset_);
    fflush(NULL);
  }

  // 减速
  void SlowDown() {
    double rsec = glfwGetTime();
    speed_--;
    offset_ += rsec * 50.f;
    printf("[SlowDown] current speed: %d offset: %.3f\n", speed_, offset_);
    fflush(NULL);
  }

  void EarthSizeUp() {
    earth_size_ += 0.01;
    printf("[EarthSizeUp] current size: %.3f\n", earth_size_);
    fflush(NULL);
  }

  void EarthSizeDown() {
    earth_size_ -= 0.01;
    printf("[EarthSizeDown] current size: %.3f\n", earth_size_);
    fflush(NULL);
  }

  int& speed() { return speed_; }
  double& offset() { return offset_; }
  double& earth_size() { return earth_size_; }
  GLuint& texture_id() { return texture_id_; }

 private:
  int speed_;
  double earth_size_;
  double offset_;
  GLuint texture_id_;
};

// 画个太阳
// 太阳其实是一组三角形构成
// 组合类似于橘子
// 当三角形足够多的时候
// 就是一个圆形了
void DrawSun(GLfloat radius, GLContext* ctx) {
  int i;
  int n_slice = 10000;  // $ of triangles used to draw circle
  GLfloat PI_2 = 2.0f * M_PI;
  static GLuint sun_list = 0;

  // 因为太阳是固定的, 因此我们可以构造个 GenList, 然后将
  // 其保存, 之后直接捞出来即可
  if (!sun_list) {
    sun_list = glGenLists(1);
    glNewList(sun_list, GL_COMPILE_AND_EXECUTE);
    glBegin(GL_TRIANGLE_FAN);
    // 内顶点的颜色
    // 颜色是 R, G, B, Alpha 四个值构成, 当然也可以用 RGB 3 值
    // 不同于网上常见的 RGB 的 base 为 255 (aka FF), 此处的最大
    // 值应该是 1.0, 当然超过了也不会报错, 只是没效果
    glColor4f(.85f * 1.4, 0.69f * 1.4, 0.44f * 1.4, 1.f);
    glVertex2f(0, 0);  // center of circle
    for (i = 0; i <= n_slice; i++) {
      glColor4f(.85f, 0.69f, 0.44f, 1.f);
      // 圆边的某个顶点 x 和 y 坐标
      // 内圆和外圆使用略微不同的颜色, opengl 会自动处理渐变效果
      glVertex2f(radius * cos(i * PI_2 / n_slice),
                 radius * sin(i * PI_2 / n_slice));
    }
    glEnd();
    glEndList();
  } else {
    // 捞出那个圆
    glCallList(sun_list);
  }
}

// 画个地球
// 此处做法很粗暴, 画一个正方形
// 贴上事先准备好的图片
// 然后就算完事
void DrawEarth(GLfloat x, GLfloat y, GLfloat radius, GLContext* ctx) {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, ctx->texture_id());
  glBegin(GL_QUADS);
  glColor3f(1.f, 1.f, 1.f);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(x + 0.0 * radius, y + 0.0 * radius, 0.0);
  glTexCoord2f(1, 0.0);
  glVertex3f(x + 1.0 * radius, y + 0.0 * radius, 0.0);
  glTexCoord2f(1.0, 1.0);
  glVertex3f(x + 1.0 * radius, y + 1.0 * radius, 0.0);
  glTexCoord2f(0.0, 1.0);
  glVertex3f(x + 0.0, y + 1.0 * radius, 0.0);
  glEnd();
  glDisable(GL_TEXTURE_2D);
}

// 载入贴图
// 虽然引用太多第三方包不太好
// 但是 glfw3 直接把自带的载入图给干掉了
// 说他们要专注
// 真是没办法
// 因此我使用 SDL2 的库
// https://www.libsdl.org/
// Simple DirectMedia Layer is a cross-platform 
// development library designed to provide low level access
// to audio, keyboard, mouse, joystick, and graphics hardware
// via OpenGL and Direct3D. It is used by video playback
// software, emulators, and popular games including Valve's
// award winning catalog and many Humble Bundle games.
// 使用前, 全局至少加载一次
int loadTexture(const std::string& path) {
  GLuint texture_id;
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  SDL_Surface* img = IMG_Load(path.c_str());
  printf("%s:%d -- %d %d %p\n", __FILE__, __LINE__, img->w, img->h,
         img->pixels);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->w, img->h, 0, GL_RGBA,
               GL_UNSIGNED_BYTE, img->pixels);

  // gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, img->w, img->h, GL_RGBA,
  // GL_UNSIGNED_BYTE, img->pixels);
  SDL_FreeSurface(img);
  return texture_id;
}

void PrintHelper() {
  printf("Compiled against GLFW %i.%i.%i\n", GLFW_VERSION_MAJOR,
         GLFW_VERSION_MINOR, GLFW_VERSION_REVISION);
  int major, minor, revision;
  glfwGetVersion(&major, &minor, &revision);
  printf("Running against GLFW %i.%i.%i\n", major, minor, revision);
  printf("Operations: \n");
  printf("+/- : speed up/down\n");
  printf("v : print window size in terminal\n");
  printf("arrow up/down: change the size of earth\n");
  printf("h: hide this window\n");
  printf("s: show this window\n");
  printf("q, ESC: Quit this program\n");
}

int main(int argc, char* argv[]) {
  PrintHelper();
  GLFWwindow* window;
  GLContext context;

  /* Initialize the library */
  if (!glfwInit()) {
    fprintf(stderr, "GLFW3 init failed\n");
    return -1;
  }

  if (!IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF)) {
    fprintf(stderr, "IMG init failed: %s %s:%d\n", IMG_GetError(), __FILE__,
            __LINE__);
    return -1;
  }

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "My Earth", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  // http://www.glfw.org/docs/latest/group__window.html#ga3d2fc6026e690ab31a13f78bc9fd3651
  glfwSetWindowUserPointer(window, &context);

  // Make the window's context current
  // http://www.glfw.org/docs/latest/group__context.html#ga1c04dc242268f827290fe40aa1c91157
  glfwMakeContextCurrent(window);

  // http://www.glfw.org/docs/latest/group__context.html#ga6d4e0cdf151b5e579bd67f13202994ed
  glfwSwapInterval(1);

  // http://www.glfw.org/docs/latest/group__init.html#gaa5d796c3cf7c1a7f02f845486333fb5f
  glfwSetErrorCallback([](int error, const char* description) {
    fprintf(stderr, "[GLFW] error message: %s\n", description);
  });

  // http://www.glfw.org/docs/3.0/group__input.html#gaa92336e173da9c8834558b54ee80563b
  // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  // http://www.glfw.org/docs/latest/group__input.html#ga7e496507126f35ea72f01b2e6ef6d155
  glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode,
                                int action, int mods) {
    // double rsec = glfwGetTime();
    // printf("[KEY]: %c %d %d %s %s --- %.3f\n", key, key, scancode,
    //        action == GLFW_PRESS
    //            ? "GLFW_PRESS"
    //            : (action == GLFW_RELEASE ? "GLFW_RELEASE" : "GLFW_REPEAT"),
    //        KeyCallbackModParse(mods).c_str(), rsec);
    // fflush(NULL);

    GLContext* ctx = static_cast<GLContext*>(glfwGetWindowUserPointer(window));
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
      switch (key) {
        case '+':
        case '=':
          ctx->SpeedUp();
          break;
        case '-':
        case '_':
          ctx->SlowDown();
          break;
        case 'v':
        case 'V':
          int w;
          int h;
          glfwGetFramebufferSize(window, &w, &h);
          printf("glfwGetFramebufferSize: %d %d\n", w, h);
          fflush(NULL);
          break;
        case GLFW_KEY_UP:
          ctx->EarthSizeUp();
          break;
        case GLFW_KEY_DOWN:
          ctx->EarthSizeDown();
          break;
        case 'h':
        case 'H':
          glfwHideWindow(window);
          break;
        case 's':
        case 'S':
          glfwShowWindow(window);
          break;
        case GLFW_KEY_ESCAPE:
        case 'q':
        case 'Q':
          // http://www.glfw.org/docs/latest/group__window.html#ga49c449dde2a6f87d996f4daaa09d6708
          glfwSetWindowShouldClose(window, GL_TRUE);
          break;
        default:
          // nothing
          break;
      }
    }

  });

  // http://www.glfw.org/docs/3.0/group__input.html#gacf02eb10504352f16efda4593c3ce60e
  glfwSetScrollCallback(window, [](GLFWwindow* window, double x_axis,
                                   double y_axis) {
    printf("[SCROLL] %.3f %.3f\n", x_axis, y_axis);
    fflush(NULL);
    GLContext* ctx = static_cast<GLContext*>(glfwGetWindowUserPointer(window));
    if (y_axis > 0) {
      ctx->SpeedUp();
    } else {
      ctx->SlowDown();
    }
  });

  // http://www.glfw.org/docs/3.0/group__input.html#gaef49b72d84d615bca0a6ed65485e035d
  glfwSetMouseButtonCallback(
      window, [](GLFWwindow* window, int button, int action, int mods) {
        // http://www.glfw.org/docs/3.0/group__buttons.html
        printf("[MOUSE] %d %d %d\n", button, action, mods);
        fflush(NULL);
      });

  // http://www.glfw.org/docs/3.0/group__input.html#gaa299c41dd0a3d171d166354e01279e04
  glfwSetCursorEnterCallback(window, [](GLFWwindow* window, int entered) {
    printf("[CURSOR] %s\n", entered == GL_TRUE ? "GL_TRUE" : "GL_FALSE");
    fflush(NULL);
  });

  // http://www.glfw.org/docs/3.0/group__input.html#ga7dad39486f2c7591af7fb25134a2501d
  glfwSetCursorPosCallback(
      window, [](GLFWwindow* window, double x_coordinate, double y_coordinate) {
        // printf("[C_POS] %.3f %.3f\n", x_coordinate, y_coordinate);
        // fflush(NULL);
      });

  context.texture_id() = loadTexture("../resource/earth-modified.png");

  int csec = 0;
  int scnt = 0;
  // Loop until the user closes the window
  // http://www.glfw.org/docs/latest/group__window.html#ga24e02fbfefbb81fc45320989f8140ab5
  while (!glfwWindowShouldClose(window)) {
    int rsec = (int)glfwGetTime();
    scnt++;
    if (rsec - csec > 3) {
      int rc = scnt / (rsec - csec);
      fprintf(stdout, "FPS: %d (%d/%d)\n", rc, scnt, (rsec - csec));
      fflush(stdout);
      csec = rsec;
      scnt = 0;
    }

    // render here
    float ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    ratio = width / (float)height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glMatrixMode ref:
    // https://www.opengl.org/sdk/docs/man2/xhtml/glMatrixMode.xml
    glMatrixMode(GL_PROJECTION);  // Applies subsequent matrix operations to the
                                  // projection matrix stack.
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);  // Applies subsequent matrix operations to the
                                 // modelview matrix stack.
    glLoadIdentity();
    glRotatef((float)glfwGetTime() * 50.f * context.speed() + context.offset(),
              0.f, 0.f, 1.f);

    DrawEarth(0.6f, 0.f, context.earth_size(), &context);

    DrawSun(0.2f, &context);

    // Swap front and back buffers
    // http://www.glfw.org/docs/latest/group__window.html#ga15a5a1ee5b3c2ca6b15ca209a12efd14
    glfwSwapBuffers(window);

    // Poll for and process events
    // http://www.glfw.org/docs/latest/group__window.html#ga37bd57223967b4211d60ca1a0bf3c832
    glfwPollEvents();
  }
  printf("Bye!\n");

  // http://www.glfw.org/docs/latest/group__window.html#gacdf43e51376051d2c091662e9fe3d7b2
  glfwDestroyWindow(window);

  // http://www.glfw.org/docs/latest/group__init.html#gaaae48c0a18607ea4a4ba951d939f0901
  glfwTerminate();
  return 0;
}
