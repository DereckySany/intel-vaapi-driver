#ifndef _I965_FOURCC_H_
#define _I965_FOURCC_H_

#ifndef VA_FOURCC_YV12
#define VA_FOURCC_YV12     VA_FOURCC('Y','V','1','2')
#endif

#ifndef VA_FOURCC_NV12
#define VA_FOURCC_NV12     VA_FOURCC('N','V','1','2')
#endif

#ifndef VA_FOURCC_YV16
#define VA_FOURCC_YV16     VA_FOURCC('Y','V','1','6')
#endif

#ifndef VA_FOURCC_I420
#define VA_FOURCC_I420     VA_FOURCC('I','4','2','0')
#endif

#ifndef VA_FOURCC_I420
#define VA_FOURCC_I420     VA_FOURCC('I','4','2','0')
#endif

/*
 * VA_FOURCC_IA44 is an exception because the va.h already
 * defines the AI44 as VA_FOURCC('I','A','4','4').
 */
#ifndef VA_FOURCC_IA44
#define VA_FOURCC_IA44     VA_FOURCC('A','I','4','4')
#endif

#ifndef VA_FOURCC_IA88
#define VA_FOURCC_IA88     VA_FOURCC('I','A','8','8')
#endif

#ifndef VA_FOURCC_AI88
#define VA_FOURCC_AI88     VA_FOURCC('A','I','8','8')
#endif

#ifndef VA_FOURCC_IMC1
#define VA_FOURCC_IMC1     VA_FOURCC('I','M','C','1')
#endif

#ifndef VA_FOURCC_YVY2
#define VA_FOURCC_YVY2     VA_FOURCC('Y','V','Y','2')
#endif

#ifndef VA_FOURCC_I010
#define VA_FOURCC_I010     VA_FOURCC('I','0','1','0')
#endif

#ifndef VA_FOURCC_YUY2
#define VA_FOURCC_YUY2     VA_FOURCC('Y','U','Y','2')
#endif

#ifndef VA_FOURCC_UYVY
#define VA_FOURCC_UYVY     VA_FOURCC('U','Y','V','Y')
#endif

#ifndef VA_FOURCC_RGB565
#define VA_FOURCC_RGB565     VA_FOURCC('R','G','B','2')
#endif

#ifndef VA_FOURCC_RGB888
#define VA_FOURCC_RGB888     VA_FOURCC('R','G','B',' ')
#endif

#ifndef VA_FOURCC_BGR888
#define VA_FOURCC_BGR888     VA_FOURCC('B','G','R',' ')
#endif

#ifndef VA_FOURCC_ARGB8888
#define VA_FOURCC_ARGB8888     VA_FOURCC('A','R','G','B')
#endif

#ifndef VA_FOURCC_ABGR8888
#define VA_FOURCC_ABGR8888     VA_FOURCC('A','B','G','R')
#endif

#ifndef VA_FOURCC_RGBA8888
#define VA_FOURCC_RGBA8888     VA_FOURCC('R','G','B','A')
#endif

#ifndef VA_FOURCC_BGRA8888
#define VA_FOURCC_BGRA8888     VA_FOURCC('B','G','R','A')
#endif

#ifndef VA_FOURCC_RGBA4444
#define VA_FOURCC_RGBA4444     VA_FOURCC('R','4','4','4')
#endif

#ifndef VA_FOURCC_BGRA4444
#define VA_FOURCC_BGRA4444     VA_FOURCC('B','4','4','4')
#endif

#ifndef VA_FOURCC_RGBA5551
#define VA_FOURCC_RGBA5551     VA_FOURCC('R','5','5','1')
#endif

#ifndef VA_FOURCC_BGRA5551
#define VA_FOURCC_BGRA5551     VA_FOURCC('B','5','5','1')
#endif

#ifndef VA_FOURCC_RGBA1010102
#define VA_FOURCC_RGBA1010102     VA_FOURCC('R','1','0',' ')
#endif

#ifndef VA_FOURCC_BGRA1010102
#define VA_FOURCC_BGRA1010102     VA_FOURCC('B','1','0',' ')
#endif


#define I965_MAX_PLANES         4
#define I965_MAX_COMONENTS      4

#define I965_COLOR_YUV          0
#define I965_COLOR_RGB          1
#define I965_COLOR_INDEX        2

typedef struct {
    uint8_t plane;                      /* o plano ao qual o pixel pertence */
    uint8_t offset;                     /* bits compensados dentro de um macro-pixel para formatos YUV compactados ou pixel para outros formatos no plano */
} i965_component_info;

typedef struct {
    uint32_t fourcc;                    /* fourcc */
    uint32_t format;                    /* 0: YUV, 1: RGB, 2: Formato indexado */
    uint32_t subsampling;               /* Subamostragem */
    uint8_t flag;                       /* 1: suportado apenas por vaCreateSurfaces(), 2: suportado apenas por vaCreateImage(), 3: ambos */
    uint8_t hfactor;                    /* fator de amostragem horizontal */
    uint8_t vfactor;                    /* fator de amostragem vertical */
    uint8_t num_planes;                 /* número de planes */
    uint8_t bpp[I965_MAX_PLANES];       /* bits por pixel dentro de um plano */
    uint8_t num_components;             /* número de componentes */

	/*
	 * Os componentes da matriz são ordenados em Y, U, V, A (até 4 componentes)
	 * para formatos YUV, R, G, B, A (até 4 componentes) para formatos RGB e
	 * I, A (2 componentes) para formatos indexados
	 */
    i965_component_info components[I965_MAX_COMONENTS];
} i965_fourcc_info;

extern const i965_fourcc_info *get_fourcc_info(unsigned int);

#endif /* _VA_FOURCC_H_ */
