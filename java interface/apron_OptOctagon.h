/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class apron_OptOctagon */

#ifndef _Included_apron_OptOctagon
#define _Included_apron_OptOctagon
#ifdef __cplusplus
extern "C" {
#endif
#undef apron_OptOctagon_FUNID_COPY
#define apron_OptOctagon_FUNID_COPY 1L
#undef apron_OptOctagon_FUNID_FREE
#define apron_OptOctagon_FUNID_FREE 2L
#undef apron_OptOctagon_FUNID_SIZE
#define apron_OptOctagon_FUNID_SIZE 3L
#undef apron_OptOctagon_FUNID_MINIMIZE
#define apron_OptOctagon_FUNID_MINIMIZE 4L
#undef apron_OptOctagon_FUNID_CANONICALIZE
#define apron_OptOctagon_FUNID_CANONICALIZE 5L
#undef apron_OptOctagon_FUNID_HASH
#define apron_OptOctagon_FUNID_HASH 6L
#undef apron_OptOctagon_FUNID_APPROXIMATE
#define apron_OptOctagon_FUNID_APPROXIMATE 7L
#undef apron_OptOctagon_FUNID_FPRINT
#define apron_OptOctagon_FUNID_FPRINT 8L
#undef apron_OptOctagon_FUNID_FPRINTDIFF
#define apron_OptOctagon_FUNID_FPRINTDIFF 9L
#undef apron_OptOctagon_FUNID_FDUMP
#define apron_OptOctagon_FUNID_FDUMP 10L
#undef apron_OptOctagon_FUNID_SERIALIZE_RAW
#define apron_OptOctagon_FUNID_SERIALIZE_RAW 11L
#undef apron_OptOctagon_FUNID_DESERIALIZE_RAW
#define apron_OptOctagon_FUNID_DESERIALIZE_RAW 12L
#undef apron_OptOctagon_FUNID_BOTTOM
#define apron_OptOctagon_FUNID_BOTTOM 13L
#undef apron_OptOctagon_FUNID_TOP
#define apron_OptOctagon_FUNID_TOP 14L
#undef apron_OptOctagon_FUNID_OF_BOX
#define apron_OptOctagon_FUNID_OF_BOX 15L
#undef apron_OptOctagon_FUNID_DIMENSION
#define apron_OptOctagon_FUNID_DIMENSION 16L
#undef apron_OptOctagon_FUNID_IS_BOTTOM
#define apron_OptOctagon_FUNID_IS_BOTTOM 17L
#undef apron_OptOctagon_FUNID_IS_TOP
#define apron_OptOctagon_FUNID_IS_TOP 18L
#undef apron_OptOctagon_FUNID_IS_LEQ
#define apron_OptOctagon_FUNID_IS_LEQ 19L
#undef apron_OptOctagon_FUNID_IS_EQ
#define apron_OptOctagon_FUNID_IS_EQ 20L
#undef apron_OptOctagon_FUNID_IS_DIMENSION_UNCONSTRAINED
#define apron_OptOctagon_FUNID_IS_DIMENSION_UNCONSTRAINED 21L
#undef apron_OptOctagon_FUNID_SAT_INTERVAL
#define apron_OptOctagon_FUNID_SAT_INTERVAL 22L
#undef apron_OptOctagon_FUNID_SAT_LINCONS
#define apron_OptOctagon_FUNID_SAT_LINCONS 23L
#undef apron_OptOctagon_FUNID_SAT_TCONS
#define apron_OptOctagon_FUNID_SAT_TCONS 24L
#undef apron_OptOctagon_FUNID_BOUND_DIMENSION
#define apron_OptOctagon_FUNID_BOUND_DIMENSION 25L
#undef apron_OptOctagon_FUNID_BOUND_LINEXPR
#define apron_OptOctagon_FUNID_BOUND_LINEXPR 26L
#undef apron_OptOctagon_FUNID_BOUND_TEXPR
#define apron_OptOctagon_FUNID_BOUND_TEXPR 27L
#undef apron_OptOctagon_FUNID_TO_BOX
#define apron_OptOctagon_FUNID_TO_BOX 28L
#undef apron_OptOctagon_FUNID_TO_LINCONS_ARRAY
#define apron_OptOctagon_FUNID_TO_LINCONS_ARRAY 29L
#undef apron_OptOctagon_FUNID_TO_TCONS_ARRAY
#define apron_OptOctagon_FUNID_TO_TCONS_ARRAY 30L
#undef apron_OptOctagon_FUNID_TO_GENERATOR_ARRAY
#define apron_OptOctagon_FUNID_TO_GENERATOR_ARRAY 31L
#undef apron_OptOctagon_FUNID_MEET
#define apron_OptOctagon_FUNID_MEET 32L
#undef apron_OptOctagon_FUNID_MEET_ARRAY
#define apron_OptOctagon_FUNID_MEET_ARRAY 33L
#undef apron_OptOctagon_FUNID_MEET_LINCONS_ARRAY
#define apron_OptOctagon_FUNID_MEET_LINCONS_ARRAY 34L
#undef apron_OptOctagon_FUNID_MEET_TCONS_ARRAY
#define apron_OptOctagon_FUNID_MEET_TCONS_ARRAY 35L
#undef apron_OptOctagon_FUNID_JOIN
#define apron_OptOctagon_FUNID_JOIN 36L
#undef apron_OptOctagon_FUNID_JOIN_ARRAY
#define apron_OptOctagon_FUNID_JOIN_ARRAY 37L
#undef apron_OptOctagon_FUNID_ADD_RAY_ARRAY
#define apron_OptOctagon_FUNID_ADD_RAY_ARRAY 38L
#undef apron_OptOctagon_FUNID_ASSIGN_LINEXPR_ARRAY
#define apron_OptOctagon_FUNID_ASSIGN_LINEXPR_ARRAY 39L
#undef apron_OptOctagon_FUNID_SUBSTITUTE_LINEXPR_ARRAY
#define apron_OptOctagon_FUNID_SUBSTITUTE_LINEXPR_ARRAY 40L
#undef apron_OptOctagon_FUNID_ASSIGN_TEXPR_ARRAY
#define apron_OptOctagon_FUNID_ASSIGN_TEXPR_ARRAY 41L
#undef apron_OptOctagon_FUNID_SUBSTITUTE_TEXPR_ARRAY
#define apron_OptOctagon_FUNID_SUBSTITUTE_TEXPR_ARRAY 42L
#undef apron_OptOctagon_FUNID_ADD_DIMENSIONS
#define apron_OptOctagon_FUNID_ADD_DIMENSIONS 43L
#undef apron_OptOctagon_FUNID_REMOVE_DIMENSIONS
#define apron_OptOctagon_FUNID_REMOVE_DIMENSIONS 44L
#undef apron_OptOctagon_FUNID_PERMUTE_DIMENSIONS
#define apron_OptOctagon_FUNID_PERMUTE_DIMENSIONS 45L
#undef apron_OptOctagon_FUNID_FORGET_ARRAY
#define apron_OptOctagon_FUNID_FORGET_ARRAY 46L
#undef apron_OptOctagon_FUNID_EXPAND
#define apron_OptOctagon_FUNID_EXPAND 47L
#undef apron_OptOctagon_FUNID_FOLD
#define apron_OptOctagon_FUNID_FOLD 48L
#undef apron_OptOctagon_FUNID_WIDENING
#define apron_OptOctagon_FUNID_WIDENING 49L
#undef apron_OptOctagon_FUNID_CLOSURE
#define apron_OptOctagon_FUNID_CLOSURE 50L
#undef apron_OptOctagon_SCALAR_DOUBLE
#define apron_OptOctagon_SCALAR_DOUBLE 0L
#undef apron_OptOctagon_SCALAR_MPQ
#define apron_OptOctagon_SCALAR_MPQ 1L
#undef apron_OptOctagon_SCALAR_MPFR
#define apron_OptOctagon_SCALAR_MPFR 2L
/*
 * Class:     apron_OptOctagon
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_apron_OptOctagon_init
  (JNIEnv *, jobject);

/*
 * Class:     apron_OptOctagon
 * Method:    class_init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_apron_OptOctagon_class_1init
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif