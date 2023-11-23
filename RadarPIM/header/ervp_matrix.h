#ifndef __ERVP_MATRIX_H__
#define __ERVP_MATRIX_H__

#include <stdint.h>
#include "platform_info.h"

#define MATRIX_DATATYPE_SINT08 0
#define MATRIX_DATATYPE_UINT08 1
#define MATRIX_DATATYPE_SINT16 2
#define MATRIX_DATATYPE_UINT16 3
#define MATRIX_DATATYPE_SINT32 4
#define MATRIX_DATATYPE_UINT32 5
#define MATRIX_DATATYPE_FLOAT32 6

#define GET_MATRIX_CASE_TYPE(a, b, c) (((a)<<6) + ((b)<<3) + (c))

typedef struct {
	void *addr;
	unsigned int stride;
	int num_row;
	int num_col;
	unsigned int datatype;
} ErvpMatrixInfo;

void matrix_add_hw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_add_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);

static inline void matrix_add(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_add_hw(a,b,c);
#else
	matrix_add_sw(a,b,c);
#endif
}

void matrix_sub_hw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_sub_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
static inline void matrix_sub(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_sub_hw(a,b,c);
#else
	matrix_sub_sw(a,b,c);
#endif
}

void matrix_ewmult_hw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_ewmult_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
static inline void matrix_ewmult(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_ewmult_hw(a,b,c);
#else
	matrix_ewmult_sw(a,b,c);
#endif
}

void matrix_mult_hw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_mult_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
static inline void matrix_mult(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_mult_hw(a,b,c);
#else
	matrix_mult_sw(a,b,c);
#endif
}

void matrix_transpose_hw(const ErvpMatrixInfo *a, ErvpMatrixInfo *c);
void matrix_transpose_sw(const ErvpMatrixInfo *a, ErvpMatrixInfo *c);
static inline void matrix_transpose(const ErvpMatrixInfo *a, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_transpose_hw(a,c);
#else
	matrix_transpose_sw(a,c);
#endif
}

void matrix_scalar_mult_int_hw(const ErvpMatrixInfo *a, int value, ErvpMatrixInfo *c);
void matrix_scalar_mult_int_sw(const ErvpMatrixInfo *a, int value, ErvpMatrixInfo *c);
static inline void matrix_scalar_mult_int(const ErvpMatrixInfo *a, int value, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_scalar_mult_int_hw(a,value,c);
#else
	matrix_scalar_mult_int_sw(a,value,c);
#endif
}

void matrix_scalar_mult_float_hw(const ErvpMatrixInfo *a, float value, ErvpMatrixInfo *c);
void matrix_scalar_mult_float_sw(const ErvpMatrixInfo *a, float value, ErvpMatrixInfo *c);
static inline void matrix_scalar_mult_float(const ErvpMatrixInfo *a, float value, ErvpMatrixInfo *c)
{
#ifdef USE_PACT
	matrix_scalar_mult_float_hw(a,value,c);
#else
	matrix_scalar_mult_float_sw(a,value,c);
#endif
}

int compare_matrix(const ErvpMatrixInfo *result, const ErvpMatrixInfo *ref, int prints);

#endif
