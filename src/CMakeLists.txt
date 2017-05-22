MESSAGE(STATUS "[GLEW] configuration , ref: http://www.glfw.org/docs/latest/build.html#build_link_cmake_source ")
MESSAGE(STATUS "[GLEW] coding , ref: http://www.glfw.org/docs/latest/quick.html")

ADD_EXECUTABLE(earth earth.cc)

TARGET_LINK_LIBRARIES(earth ${OPENGL_LIBRARIES})
TARGET_LINK_LIBRARIES(earth ${GLFW_LIBRARIES})
TARGET_LINK_LIBRARIES(earth ${SDL2IMAGE_LIBRARIES})
# TARGET_LINK_LIBRARIES(earth ${GLEW_LIBRARIES})
# TARGET_LINK_LIBRARIES(earth ${SDL2_LIBRARIES})

SET_TARGET_PROPERTIES(earth PROPERTIES OUTPUT_NAME "earth")


