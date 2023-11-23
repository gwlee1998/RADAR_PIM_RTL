#ifndef __ERVP_MATRIX_ACCESS_INT_H__
#define __ERVP_MATRIX_ACCESS_INT_H__

static inline int read_matrix_int_element(const ErvpMatrixInfo *matrix, int row_index, int col_index)
{
	void *row_addr = get_row_addr(matrix, row_index);
	int data;
	switch(matrix->datatype)
	{
		case MATRIX_DATATYPE_SINT08:
		{
			char* addr = ((char*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_UINT08:
		{
			unsigned char* addr = ((unsigned char*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_SINT16:
		{
			short* addr = ((short*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_UINT16:
		{
			unsigned short* addr = ((unsigned short*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_SINT32:
		{
			int* addr = ((int*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_UINT32:
		{
			unsigned int* addr = ((unsigned int*)row_addr);
			data = addr[col_index];
			break;
		}
		case MATRIX_DATATYPE_FLOAT32:
		{
			float* addr = ((float*)row_addr);
			data = addr[col_index];
			break;
		}
		default:
			data = 0;
	}
	return data;
}

static inline void write_matrix_int_element(const ErvpMatrixInfo *matrix, int row_index, int col_index, int wdata)
{
	void *row_addr = get_row_addr(matrix, row_index);
	switch(matrix->datatype)
	{
		case MATRIX_DATATYPE_SINT08:
		{
			char* addr = ((char*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_UINT08:
		{
			unsigned char* addr = ((unsigned char*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_SINT16:
		{
			short* addr = ((short*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_UINT16:
		{
			unsigned short* addr = ((unsigned short*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_SINT32:
		{
			int* addr = ((int*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_UINT32:
		{
			unsigned int* addr = ((unsigned int*)row_addr);
			addr[col_index] = wdata;
			break;
		}
		case MATRIX_DATATYPE_FLOAT32:
		{
			float* addr = ((float*)row_addr);
			addr[col_index] = wdata;
			break;
		}
	}
}

#endif
