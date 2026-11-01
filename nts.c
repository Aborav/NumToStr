#include "nts.h"
#include <stdint.h>

static const uint16_t nts_div_mask[] = {1, 10, 100, 1000, 10000};
#ifdef NTS_USE_32BIT_FUNC
static const uint32_t nts_div_mask_32bit[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
#endif

/**
 * @brief Function to convert int8_t to the string
 * @param num int8_t to convert
 * @param[out] str output string pointer (max size 5 symb)
 */
nts_t NTS_ConvI8(int8_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    uint8_t u_num;       ///< int to uint conversion
    uint16_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 2; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract pow
        u_num -= (div_buf)*nts_div_mask[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            // write minus just before the first digit
            if (minus_flag) {
                *str++ = '-';
                minus_flag = 0;
            }
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert uint8_t to the string
 * @param num uint8_t to convert
 * @param[out] str output string pointer (max size 4 symb)
 */
nts_t NTS_ConvU8(uint8_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    uint16_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 2; i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract pow
        num -= (div_buf)*nts_div_mask[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert int16_t to the string
 * @param num int16_t to convert
 * @param[out] str output string pointer (max size 7 symb)
 */
nts_t NTS_ConvI16(int16_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    uint16_t u_num;      ///< int to uint conversion
    uint16_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract pow
        u_num -= (div_buf)*nts_div_mask[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            // write minus just before the first digit
            if (minus_flag) {
                *str++ = '-';
                minus_flag = 0;
            }
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert uint16_t to the string
 * @param num uint16_t to convert
 * @param[out] str output string pointer (max size 6 symb)
 */
nts_t NTS_ConvU16(uint16_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    uint16_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract pow
        num -= (div_buf)*nts_div_mask[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}

#ifdef NTS_USE_32BIT_FUNC
/**
 * @brief Function to convert int32_t to the string
 * @param num int32_t to convert
 * @param[out] str output string pointer (max size 12 symb)
 */
nts_t NTS_ConvI32(int32_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    uint32_t u_num;      ///< int to uint conversion
    uint32_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 9; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask_32bit[i]); // extract pow
        u_num -= (div_buf)*nts_div_mask_32bit[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            // write minus just before the first digit
            if (minus_flag) {
                *str++ = '-';
                minus_flag = 0;
            }
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}
#endif

#ifdef NTS_USE_32BIT_FUNC
/**
 * @brief Function to convert uint32_t to the string
 * @param num uint32_t to convert
 * @param[out] str output string pointer (max size 11 symb)
 */
nts_t NTS_ConvU32(uint32_t num, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    uint32_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 9; i >= 0; i--) {
        div_buf = (num / nts_div_mask_32bit[i]); // extract pow
        num -= (div_buf)*nts_div_mask_32bit[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}
#endif

/**
 * @brief Function to convert fake float (int16_t) to the string
 * @param num int16_t to convert
 * @param fract symbols after comma
 * @param[out] str output string pointer (max size 8 symb)
 */
nts_t NTS_ConvFakeFloatI(int16_t num, uint8_t fract, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    if (fract > 4 || fract < 1) {
        return NTS_ERR_IP;
    }
    uint16_t div_buf;      ///< buffer to hold digit for division
    uint16_t u_num;        ///< int to uint conversion
    uint8_t dig_index = 0; ///< string index
    bool start_flag = 0;   ///< first digit flag
    bool minus_flag = 0;   ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]);
        u_num -= div_buf * nts_div_mask[i];
        // if number starts or index before comma
        if (div_buf > 0 || i == (int8_t)fract) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            if (minus_flag) {
                *str++ = '-';
                minus_flag = 0;
            }
            *str++ = div_buf + '0';
        }
        if (i == (int8_t)fract) {
            *str++ = '.';
        }
    }
    str[dig_index++] = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert fake float (unt16_t) to the string
 * @param num unt16_t to convert
 * @param fract symbols after comma
 * @param[out] str output string pointer (max size 8 symb)
 */
nts_t NTS_ConvFakeFloatU(uint16_t num, uint8_t fract, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    if (fract > 4 || fract < 1) {
        return NTS_ERR_IP;
    }
    uint16_t div_buf;      ///< buffer to hold digit for division
    uint8_t dig_index = 0; ///< string index
    bool start_flag = 0;   ///< first digit flag

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]);
        num -= div_buf * nts_div_mask[i];
        // if number starts or index before comma
        if (div_buf > 0 || i == (int8_t)fract) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            *str++ = div_buf + '0';
        }
        if (i == (int8_t)fract) {
            *str++ = '.'; // comma at designed place
        }
    }
    str[dig_index++] = '\0'; 
    return NTS_OK;
}

nts_t NTS_ConvFixI8(int8_t num, uint8_t num_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    uint8_t u_num;       ///< int to uint conversion
    uint16_t div_buf;    ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = (int8_t)num_qty; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract pow
        u_num -= (div_buf)*nts_div_mask[i];  // remove pow
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1;
        } else {
            *str++ = ' ';
            continue;
        }
        if (start_flag) {
            // write minus just before the first digit
            if (minus_flag) {
                *str++ = '-';
                minus_flag = 0;
            }
            *str++ = div_buf + '0';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}