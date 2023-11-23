#ifndef __ERVP_FLOAT_H__
#define __ERVP_FLOAT_H__

#include <stdint.h>

typedef union
{
	float value;
	uint32_t hex;
	struct
	{
		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} br;
} Float32Binary;

typedef union
{
	double value;
	uint64_t hex;
	struct
	{
		uint64_t mantissa : 52;
		unsigned int exponent : 11;
		unsigned int sign : 1;
	} br;
  struct
	{
		unsigned int lower : 32;
    unsigned int upper : 32;
	} int32;
} Float64Binary;

void print_float32_detail(float value);

int is_float32_nan(float value);
int get_float32_similarity(float a, float b);
static inline int are_two_float32_similar(float a, float b, int similarity)
{
  return (get_float32_similarity(a,b) >= similarity);
}

unsigned int get_float32_significand(float a);

#define FLOAT32_PINF  0x7f800000
#define FLOAT32_MINF  0xff800000
#define FLOAT32_PZERO 0x0
#define FLOAT32_MZERO 0x80000000
#define FLOAT32_NAN   0x7fc00000

void print_float64_detail(double value);

int is_float64_nan(float value);
int get_float64_similarity(double a, double b);
static inline int are_two_float64_similar(double a, double b, int similarity)
{
  return (get_float64_similarity(a,b) >= similarity);
}

#endif
