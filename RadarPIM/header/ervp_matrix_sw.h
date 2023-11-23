#ifndef __ERVP_MATRIX_SW_H__
#define __ERVP_MATRIX_SW_H__

#include "ervp_matrix.h"

static inline void *get_row_addr(const ErvpMatrixInfo *matrix, int row_index)
{
	void *addr = 0;
	addr = matrix->addr;
	addr += (matrix->stride*row_index);
	return addr; 
}

static inline void *get_element_addr(const ErvpMatrixInfo *matrix, int row_index, int col_index)
{
	void *addr = get_row_addr(matrix, row_index);
	switch(matrix->datatype)
	{
		case MATRIX_DATATYPE_SINT08:
		case MATRIX_DATATYPE_UINT08:
		{
			addr += (col_index);
			break;
		}
		case MATRIX_DATATYPE_SINT16:
		case MATRIX_DATATYPE_UINT16:
		{
			addr += (col_index<<1);
			break;
		}
		case MATRIX_DATATYPE_SINT32:
		case MATRIX_DATATYPE_UINT32:
		case MATRIX_DATATYPE_FLOAT32:
		{
			addr += (col_index<<2);
			break;
		}
	}
	return addr; 
}

void matrix_add_float_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_add_int_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);

void matrix_sub_float_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_sub_int_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);

void matrix_ewmult_float_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_ewmult_int_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);

void matrix_mult_float_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);
void matrix_mult_int_sw(const ErvpMatrixInfo *a, const ErvpMatrixInfo *b, ErvpMatrixInfo *c);

void matrix_transpose_float_sw(const ErvpMatrixInfo *a, ErvpMatrixInfo *c);
void matrix_transpose_int_sw(const ErvpMatrixInfo *a, ErvpMatrixInfo *c);

#include "ervp_matrix_access_int.h"
#include "ervp_matrix_access_float.h"

#endif
