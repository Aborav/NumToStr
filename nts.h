#ifndef _NTS_H_
#define _NTS_H_

/*
LIBRARY TO CONVERT NUMBER TO STRING

Features:
* exclude '%' operator during conversion
* convert fake float (uint16_t/int16_t)
* functions with fixed quantity of digits
* returned errors can be collected in stack:
    * err |= NTS_Conv...
    * err |= NTS_Conv...
    * if(err) printf("err: %d", err);
*/

#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*-------------------DEFINES-----------------*/
// Use uint32/int32 convert functions
#define NTS_USE_32BIT_FUNC

// MACROS
/*
#define NTS_WRITE(str, ind, symb)                                              \
    do {                                                                       \
        if ((str)[ind] == 0) {                                                 \
            (str)[(ind)++] = symb;                                             \
        } else {                                                               \
            return NTS_ERR_OW;                                                 \
        }                                                                      \
    } while (0)
*/
#define NTS_WRITE(str, ind, symb)                                              \
    do {                                                                       \
        (str)[(ind)++] = symb;                                                 \
    } while (0)

#define NTS_CHECK_PTR(ptr)                                                     \
    do {                                                                       \
        if (!(ptr)) {                                                          \
            return NTS_ERR_PTR;                                                \
        }                                                                      \
    } while (0)

/*------------------TYPES---------------------*/
typedef enum {
    NTS_OK = 0,        // good
    NTS_ERR_PTR = 0b1, // empty pointer
    NTS_ERR_OW = 0b01, // output sting cell is not empty
    NTS_ERR_IP = 0b001 // invalid parameter
} nts_t;

typedef uint8_t nts_str_t;

/*------------------FUNCTIONS------------------*/
nts_t NTS_ConvI8(int8_t num, nts_str_t *str);
nts_t NTS_ConvU8(uint8_t num, nts_str_t *str);

nts_t NTS_ConvI16(int16_t num, nts_str_t *str);
nts_t NTS_ConvU16(uint16_t num, nts_str_t *str);

nts_t NTS_ConvI32(int32_t num, nts_str_t *str);
nts_t NTS_ConvU32(uint32_t num, nts_str_t *str);

nts_t NTS_ConvFakeFloatI(int16_t num, uint8_t fract, nts_str_t *str);
nts_t NTS_ConvFakeFloatU(uint16_t num, uint8_t fract, nts_str_t *str);

// Fixed amount of digits. Right alignment
nts_t NTS_ConvFixI8(int8_t num, uint8_t num_qty, nts_str_t *str);

#ifdef __cplusplus
}
#endif

#endif