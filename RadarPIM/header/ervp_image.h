#ifndef __ERVP_IMAGE_H__
#define __ERVP_IMAGE_H__

#include <stdint.h>

#pragma pack(push)  // save the original data alignment
#pragma pack(1)     // Set data alignment to 1 byte boundary

typedef struct {
    uint16_t type;              // Magic identifier: 0x4d42
    uint32_t size;              // File size in bytes
    uint16_t reserved1;         // Not used
    uint16_t reserved2;         // Not used
    uint32_t offset;            // Offset to image data in bytes from beginning of file
    uint32_t dib_header_size;   // DIB Header size in bytes
    int32_t  width_px;          // Width of the image
    int32_t  height_px;         // Height of image
    uint16_t num_planes;        // Number of color planes
    uint16_t bits_per_pixel;    // Bits per pixel
    uint32_t compression;       // Compression type
    uint32_t image_size_bytes;  // Image size in bytes
    int32_t  x_resolution_ppm;  // Pixels per meter
    int32_t  y_resolution_ppm;  // Pixels per meter
    uint32_t num_colors;        // Number of colors
    uint32_t important_colors;  // Important colors
    uint32_t red_channel_bitmask;  //Red channel bitmask
    uint32_t green_channel_bitmask;  //Green channel bitmask
    uint32_t blue_channel_bitmask;  //blue channel bitmask
} BMPHeader;

#pragma pack(pop)  // restore the previous pack setting


typedef enum {
	IMAGE_FMT_YUV_420_PLANAR_YV12 = 0,
	IMAGE_FMT_YUV_420_PLANAR_N12 = 1,
	IMAGE_FMT_RGB_888_PLANE = 2,
	IMAGE_FMT_ARGB_8888_PACKED = 3,
	IMAGE_FMT_RGB_565_PACKED = 4,
	IMAGE_FMT_YUV_422_PACKED = 5,
	IMAGE_FMT_JPEG = 6,
	IMAGE_FMT_JPEGLS = 7,
	IMAGE_FMT_BMP = 8,
} ImageFormat;

typedef struct {
	int format;

	unsigned int width;
	unsigned int height;	

	void *addr[3];
	unsigned int stride[3];

  unsigned int size; // bug??

} ErvpImage;

void init_image_structure(ErvpImage* image, int width, int height, int format);
void init_image(ErvpImage* image, int width, int height, int format);
ErvpImage* alloc_image(int width, int height, int format);
ErvpImage* convert_image(const ErvpImage* const before, ErvpImage* after, int format);
//ErvpImage* resize(ErvpImage* before, ErvpImage* after);

void prepare_image_dump(const ErvpImage *image);

#endif
