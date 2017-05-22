/// @ref core
/// @file glm/detail/_swizzle_func.hpp

#pragma once

#define GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                   SWIZZLED_TYPE, CONST, A, B)       \
  SWIZZLED_TYPE<TMPL_TYPE, PRECISION> A##B() CONST {                 \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B);    \
  }

#define GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                   SWIZZLED_TYPE, CONST, A, B, C)          \
  SWIZZLED_TYPE<TMPL_TYPE, PRECISION> A##B##C() CONST {                    \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B, this->C); \
  }

#define GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE,      \
                                   SWIZZLED_TYPE, CONST, A, B, C, D)      \
  SWIZZLED_TYPE<TMPL_TYPE, PRECISION> A##B##C##D() CONST {                \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B, this->C, \
                                               this->D);                  \
  }

#define GLM_SWIZZLE_GEN_VEC2_ENTRY_DEF(TMPL_TYPE, PRECISION, CLASS_TYPE,    \
                                       SWIZZLED_TYPE, CONST, A, B)          \
  template <typename TMPL_TYPE>                                             \
  SWIZZLED_TYPE<TMPL_TYPE> CLASS_TYPE<TMPL_TYPE, PRECISION>::A##B() CONST { \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B);           \
  }

#define GLM_SWIZZLE_GEN_VEC3_ENTRY_DEF(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                       SWIZZLED_TYPE, CONST, A, B, C)          \
  template <typename TMPL_TYPE>                                                \
  SWIZZLED_TYPE<TMPL_TYPE> CLASS_TYPE<TMPL_TYPE, PRECISION>::A##B##C() CONST { \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B, this->C);     \
  }

#define GLM_SWIZZLE_GEN_VEC4_ENTRY_DEF(TMPL_TYPE, PRECISION, CLASS_TYPE,  \
                                       SWIZZLED_TYPE, CONST, A, B, C, D)  \
  template <typename TMPL_TYPE>                                           \
  SWIZZLED_TYPE<TMPL_TYPE> CLASS_TYPE<TMPL_TYPE, PRECISION>::A##B##C##D() \
      CONST {                                                             \
    return SWIZZLED_TYPE<TMPL_TYPE, PRECISION>(this->A, this->B, this->C, \
                                               this->D);                  \
  }

#define GLM_MUTABLE

#define GLM_SWIZZLE_GEN_REF2_FROM_VEC2_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B)                    \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, B)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, A)

#define GLM_SWIZZLE_GEN_REF_FROM_VEC2(TMPL_TYPE, PRECISION, CLASS_TYPE,    \
                                      SWIZZLED_VEC2_TYPE)                  \
  GLM_SWIZZLE_GEN_REF2_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                         SWIZZLED_VEC2_TYPE, x, y)         \
  GLM_SWIZZLE_GEN_REF2_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                         SWIZZLED_VEC2_TYPE, r, g)         \
  GLM_SWIZZLE_GEN_REF2_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                         SWIZZLED_VEC2_TYPE, s, t)

// GLM_SWIZZLE_GEN_REF_FROM_VEC2(valType, detail::vec2, detail::ref2)

#define GLM_SWIZZLE_GEN_REF2_FROM_VEC3_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C)                 \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, B)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, C)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, A)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, C)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, A)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, B)

#define GLM_SWIZZLE_GEN_REF3_FROM_VEC3_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C)                 \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, B, C)                            \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, C, B)                            \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, A, C)                            \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, C, A)                            \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, A, B)                            \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, B, A)

#define GLM_SWIZZLE_GEN_REF_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                           SWIZZLED_VEC2_TYPE,               \
                                           SWIZZLED_VEC3_TYPE, A, B, C)      \
  GLM_SWIZZLE_GEN_REF3_FROM_VEC3_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC3_TYPE, A, B, C)        \
  GLM_SWIZZLE_GEN_REF2_FROM_VEC3_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC2_TYPE, A, B, C)

#define GLM_SWIZZLE_GEN_REF_FROM_VEC3(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                      SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE) \
  GLM_SWIZZLE_GEN_REF_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     x, y, z)                                 \
  GLM_SWIZZLE_GEN_REF_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     r, g, b)                                 \
  GLM_SWIZZLE_GEN_REF_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     s, t, p)

// GLM_SWIZZLE_GEN_REF_FROM_VEC3(valType, detail::vec3, detail::ref2,
// detail::ref3)

#define GLM_SWIZZLE_GEN_REF2_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, B)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, C)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, A, D)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, A)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, C)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, B, D)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, A)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, B)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, C, D)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, D, A)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, D, B)                               \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             GLM_MUTABLE, D, C)

#define GLM_SWIZZLE_GEN_REF3_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, B, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, B, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, C, B)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, C, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, D, B)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, D, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, A, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, A, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, C, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, C, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, D, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, D, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, A, B)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, A, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, B, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, B, D)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, D, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, D, B)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, A, B)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, A, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, B, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, B, C)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, C, A)                                       \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, C, B)

#define GLM_SWIZZLE_GEN_REF4_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, C, B, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, C, D, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, D, B, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, D, C, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, B, D, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , A, B, C, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, C, A, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, C, D, A)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, D, A, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, D, C, A)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, A, D, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , B, A, C, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, B, A, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, B, D, A)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, D, A, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, D, B, A)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, A, D, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , C, A, B, D)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, C, B, A)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, C, A, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, A, B, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, A, C, B)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, B, A, C)                                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             , D, B, C, A)

#define GLM_SWIZZLE_GEN_REF_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                           SWIZZLED_VEC2_TYPE,               \
                                           SWIZZLED_VEC3_TYPE,               \
                                           SWIZZLED_VEC4_TYPE, A, B, C, D)   \
  GLM_SWIZZLE_GEN_REF2_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC2_TYPE, A, B, C, D)     \
  GLM_SWIZZLE_GEN_REF3_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC3_TYPE, A, B, C, D)     \
  GLM_SWIZZLE_GEN_REF4_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC4_TYPE, A, B, C, D)

#define GLM_SWIZZLE_GEN_REF_FROM_VEC4(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                      SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE, \
                                      SWIZZLED_VEC4_TYPE)                     \
  GLM_SWIZZLE_GEN_REF_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, x, y, z, w)          \
  GLM_SWIZZLE_GEN_REF_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, r, g, b, a)          \
  GLM_SWIZZLE_GEN_REF_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, s, t, p, q)

// GLM_SWIZZLE_GEN_REF_FROM_VEC4(valType, detail::vec4, detail::ref2,
// detail::ref3, detail::ref4)

#define GLM_SWIZZLE_GEN_VEC2_FROM_VEC2_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B)                    \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B)

#define GLM_SWIZZLE_GEN_VEC3_FROM_VEC2_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B)                    \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B)

#define GLM_SWIZZLE_GEN_VEC4_FROM_VEC2_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B)                    \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, B)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC2_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                           SWIZZLED_VEC2_TYPE,               \
                                           SWIZZLED_VEC3_TYPE,               \
                                           SWIZZLED_VEC4_TYPE, A, B)         \
  GLM_SWIZZLE_GEN_VEC2_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC2_TYPE, A, B)           \
  GLM_SWIZZLE_GEN_VEC3_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC3_TYPE, A, B)           \
  GLM_SWIZZLE_GEN_VEC4_FROM_VEC2_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC4_TYPE, A, B)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC2(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                      SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE, \
                                      SWIZZLED_VEC4_TYPE)                     \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC2_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, x, y)                \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC2_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, r, g)                \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC2_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, s, t)

// GLM_SWIZZLE_GEN_VEC_FROM_VEC2(valType, detail::vec2, detail::vec2,
// detail::vec3, detail::vec4)

#define GLM_SWIZZLE_GEN_VEC2_FROM_VEC3_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C)                 \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C)

#define GLM_SWIZZLE_GEN_VEC3_FROM_VEC3_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C)                 \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C)

#define GLM_SWIZZLE_GEN_VEC4_FROM_VEC3_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C)                 \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, C)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                           SWIZZLED_VEC2_TYPE,               \
                                           SWIZZLED_VEC3_TYPE,               \
                                           SWIZZLED_VEC4_TYPE, A, B, C)      \
  GLM_SWIZZLE_GEN_VEC2_FROM_VEC3_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC2_TYPE, A, B, C)        \
  GLM_SWIZZLE_GEN_VEC3_FROM_VEC3_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC3_TYPE, A, B, C)        \
  GLM_SWIZZLE_GEN_VEC4_FROM_VEC3_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC4_TYPE, A, B, C)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC3(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                      SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE, \
                                      SWIZZLED_VEC4_TYPE)                     \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, x, y, z)             \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, r, g, b)             \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC3_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, s, t, p)

// GLM_SWIZZLE_GEN_VEC_FROM_VEC3(valType, detail::vec3, detail::vec2,
// detail::vec3, detail::vec4)

#define GLM_SWIZZLE_GEN_VEC2_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C)                                     \
  GLM_SWIZZLE_GEN_VEC2_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D)

#define GLM_SWIZZLE_GEN_VEC3_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, D)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, A)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, B)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, C)                                  \
  GLM_SWIZZLE_GEN_VEC3_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, D)

#define GLM_SWIZZLE_GEN_VEC4_FROM_VEC4_SWIZZLE(                               \
    TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, A, B, C, D)              \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, A, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, B, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, C, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, A, D, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, A, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, B, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, C, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, B, D, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, A, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, B, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, C, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, C, D, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, A, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, B, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, C, D, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, A, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, A, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, A, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, A, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, B, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, B, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, B, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, B, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, C, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, C, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, C, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, C, D)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, D, A)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, D, B)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, D, C)                               \
  GLM_SWIZZLE_GEN_VEC4_ENTRY(TMPL_TYPE, PRECISION, CLASS_TYPE, SWIZZLED_TYPE, \
                             const, D, D, D, D)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE, \
                                           SWIZZLED_VEC2_TYPE,               \
                                           SWIZZLED_VEC3_TYPE,               \
                                           SWIZZLED_VEC4_TYPE, A, B, C, D)   \
  GLM_SWIZZLE_GEN_VEC2_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC2_TYPE, A, B, C, D)     \
  GLM_SWIZZLE_GEN_VEC3_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC3_TYPE, A, B, C, D)     \
  GLM_SWIZZLE_GEN_VEC4_FROM_VEC4_SWIZZLE(TMPL_TYPE, PRECISION, CLASS_TYPE,   \
                                         SWIZZLED_VEC4_TYPE, A, B, C, D)

#define GLM_SWIZZLE_GEN_VEC_FROM_VEC4(TMPL_TYPE, PRECISION, CLASS_TYPE,       \
                                      SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE, \
                                      SWIZZLED_VEC4_TYPE)                     \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, x, y, z, w)          \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, r, g, b, a)          \
  GLM_SWIZZLE_GEN_VEC_FROM_VEC4_COMP(TMPL_TYPE, PRECISION, CLASS_TYPE,        \
                                     SWIZZLED_VEC2_TYPE, SWIZZLED_VEC3_TYPE,  \
                                     SWIZZLED_VEC4_TYPE, s, t, p, q)

// GLM_SWIZZLE_GEN_VEC_FROM_VEC4(valType, detail::vec4, detail::vec2,
// detail::vec3, detail::vec4)
