#include <endian.h>

#if __BYTE_ORDER == __BIG_ENDIAN
#define ENDIAN_SUFFIX "eb"
#else
#define ENDIAN_SUFFIX ""
#endif

#if __SOFTFP__
#define FP_SUFFIX ""
#else
#define FP_SUFFIX "hf"
#endif

#define LDSO_ARCH "arm" ENDIAN_SUFFIX FP_SUFFIX

#define NO_LEGACY_INITFINI

#define TPOFF_K 8

#define REL_SYMBOLIC    R_ARM_ABS32
#define REL_GOT         R_ARM_GLOB_DAT
#define REL_PLT         R_ARM_JUMP_SLOT
#define REL_RELATIVE    R_ARM_RELATIVE
#define REL_COPY        R_ARM_COPY
#define REL_DTPMOD      R_ARM_TLS_DTPMOD32
#define REL_DTPOFF      R_ARM_TLS_DTPOFF32
#define REL_TPOFF       R_ARM_TLS_TPOFF32
//#define REL_TLSDESC     R_ARM_TLS_DESC

#define CRTJMP(pc,sp) __asm__ __volatile__( \
	"mov sp,%1 ; tst %0,#1 ; moveq pc,%0 ; bx %0" : : "r"(pc), "r"(sp) : "memory" )
