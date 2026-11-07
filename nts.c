#include "nts.h"

/*------------------TYPES---------------------*/
static const uint16_t nts_div_mask[] = {1, 10, 100, 1000, 10000};
#ifdef NTS_USE_32BIT_FUNC
static const uint32_t nts_div_mask_32bit[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
#endif

/*----------------FUNCTIONS-------------------*/
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
        div_buf = (u_num / nts_div_mask[i]); // extract degree
        u_num -= (div_buf)*nts_div_mask[i];  // remove degree
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
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 2; i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract degree
        num -= (div_buf)*nts_div_mask[i];  // remove degree
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
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract degree
        u_num -= (div_buf)*nts_div_mask[i];  // remove degree
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
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 4; i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract degree
        num -= (div_buf)*nts_div_mask[i];  // remove degree
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
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
    } else {
        u_num = num;
    }

    for (int8_t i = 9; i >= 0; i--) {
        div_buf = (u_num / nts_div_mask_32bit[i]); // extract degree
        u_num -= (div_buf)*nts_div_mask_32bit[i];  // remove degree
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

    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = 9; i >= 0; i--) {
        div_buf = (num / nts_div_mask_32bit[i]); // extract degree
        num -= (div_buf)*nts_div_mask_32bit[i];  // remove degree
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
 * @param fract symbols after comma (1-4)
 * @param[out] str output string pointer (max size 8 symb)
 */
nts_t NTS_ConvFakeFloatI(int16_t num, uint8_t fract, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    if (fract > 4 || fract < 1) {
        return NTS_ERR_INPAR;
    }
    uint8_t div_buf;     ///< buffer to hold digit for division
    uint16_t u_num;      ///< int to uint conversion
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

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
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert fake float (unt16_t) to the string
 * @param num unt16_t to convert
 * @param fract symbols after comma (1-4)
 * @param[out] str output string pointer (max size 8 symb)
 */
nts_t NTS_ConvFakeFloatU(uint16_t num, uint8_t fract, nts_str_t *str) {
    NTS_CHECK_PTR(str);

    if (fract > 4 || fract < 1) {
        return NTS_ERR_INPAR;
    }
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

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
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert int8_t to the string
 * with fixed quantity of digits. Right alignment
 * @param num int8_t to convert
 * @param symb_qty quantity of symbols in the string (2-4)
 * @param[out] str output string pointer (max size 5 symb)
 */
nts_t NTS_ConvFixI8(int8_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 2 || symb_qty > 4) {
        return NTS_ERR_INPAR;
    }

    uint8_t u_num;       ///< int to uint conversion
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
        symb_qty--; // decrease to insert minus
    } else {
        u_num = num;
    }

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        u_num -= (div_buf)*nts_div_mask[i]; // remove degree
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

/**
 * @brief Function to convert uint8_t to the string
 * with fixed quantity of digits. Right alignment
 * @param num uint8_t to convert
 * @param symb_qty quantity of symbols in the string (1-3)
 * @param[out] str output string pointer (max size 4 symb)
 */
nts_t NTS_ConvFixU8(uint8_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 1 || symb_qty > 3) {
        return NTS_ERR_INPAR;
    }

    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        num -= (div_buf)*nts_div_mask[i]; // remove degree
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1;
        } else {
            *str++ = ' ';
            continue;
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
 * with fixed quantity of digits. Right alignment
 * @param num int16_t to convert
 * @param symb_qty quantity of symbols in the string (2-6)
 * @param[out] str output string pointer (max size 7 symb)
 */
nts_t NTS_ConvFixI16(int16_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 2 || symb_qty > 6) {
        return NTS_ERR_INPAR;
    }

    uint16_t u_num;      ///< int to uint conversion
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
        symb_qty--; // decrease to insert minus
    } else {
        u_num = num;
    }

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        u_num -= (div_buf)*nts_div_mask[i]; // remove degree
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

/**
 * @brief Function to convert uint16_t to the string
 * with fixed quantity of digits. Right alignment
 * @param num uint16_t to convert
 * @param symb_qty quantity of symbols in the string (1-5)
 * @param[out] str output string pointer (max size 6 symb)
 */
nts_t NTS_ConvFixU16(uint16_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 1 || symb_qty > 5) {
        return NTS_ERR_INPAR;
    }

    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        num -= (div_buf)*nts_div_mask[i]; // remove degree
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1;
        } else {
            *str++ = ' ';
            continue;
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
 * with fixed quantity of digits. Right alignment
 * @param num int32_t to convert
 * @param symb_qty quantity of symbols in the string (2-11)
 * @param[out] str output string pointer (max size 12 symb)
 */
nts_t NTS_ConvFixI32(int32_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 2 || symb_qty > 11) {
        return NTS_ERR_INPAR;
    }

    uint32_t u_num;      ///< int to uint conversion
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
        symb_qty--; // decrease to insert minus
    } else {
        u_num = num;
    }

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (u_num / nts_div_mask_32bit[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        u_num -= (div_buf)*nts_div_mask_32bit[i]; // remove degree
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
#endif
#ifdef NTS_USE_32BIT_FUNC
/**
 * @brief Function to convert uint32_t to the string
 * with fixed quantity of digits. Right alignment
 * @param num uint32_t to convert
 * @param symb_qty quantity of symbols in the string (1-10)
 * @param[out] str output string pointer (max size 11 symb)
 */
nts_t NTS_ConvFixU32(uint32_t num, uint8_t symb_qty, nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 1 || symb_qty > 10) {
        return NTS_ERR_INPAR;
    }

    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (num / nts_div_mask_32bit[i]); // extract degree
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        num -= (div_buf)*nts_div_mask_32bit[i]; // remove degree
        // digit start point or the last x^0
        if (div_buf > 0 || i == 0) {
            start_flag = 1;
        } else {
            *str++ = ' ';
            continue;
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
 * with fixed quantity of digits. Right alignment
 * @param num int16_t to convert
 * @param symb_qty quantity of symbols in the string (4-7)
 * @param fract symbols after comma (1-4)
 * @param[out] str output string pointer (max size 8 symb)
 */
nts_t NTS_ConvFixFakeFloatI(int16_t num, uint8_t symb_qty, uint8_t fract,
                            nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 4 || symb_qty > 7) {
        return NTS_ERR_INPAR;
    }
    uint8_t div_buf;     ///< buffer to hold digit for division
    uint16_t u_num;      ///< int to uint conversion
    bool start_flag = 0; ///< first digit flag
    bool minus_flag = 0; ///< minus flag

    symb_qty--; // decrease to insert comma
    if (num < 0) {
        u_num = -num;
        minus_flag = 1;
        symb_qty--; // decrease to insert minus
    } else {
        u_num = num;
    }
    if (fract > symb_qty - 1 || fract < 1) {
        return NTS_ERR_INPAR;
    }
    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (u_num / nts_div_mask[i]);
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
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
        } else {
            *str++ = ' ';
            continue;
        }
        if (i == (int8_t)fract) {
            *str++ = '.';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}

/**
 * @brief Function to convert fake float (uint16_t) to the string
 * with fixed quantity of digits. Right alignment
 * @param num uint16_t to convert
 * @param symb_qty quantity of symbols in the string (3-6)
 * @param fract symbols after comma (1-4)
 * @param[out] str output string pointer (max size 7 symb)
 */
nts_t NTS_ConvFixFakeFloatU(uint16_t num, uint8_t symb_qty, uint8_t fract,
                            nts_str_t *str) {
    NTS_CHECK_PTR(str);
    if (symb_qty < 3 || symb_qty > 6) {
        return NTS_ERR_INPAR;
    }
    if (fract > symb_qty - 1 || fract < 1) {
        return NTS_ERR_INPAR;
    }
    uint8_t div_buf;     ///< buffer to hold digit for division
    bool start_flag = 0; ///< first digit flag

    symb_qty--; // decrease to insert comma

    for (int8_t i = (int8_t)(symb_qty - 1); i >= 0; i--) {
        div_buf = (num / nts_div_mask[i]);
        // if symb_qty is smaller than max degree of a number
        // num = 255, symb_qty = 2, 255/10^2 -> 25
        if (div_buf > 9) {
            return NTS_ERR_INPAR;
        }
        num -= div_buf * nts_div_mask[i];
        // if number starts or index before comma
        if (div_buf > 0 || i == (int8_t)fract) {
            start_flag = 1; // start printing
        }
        if (start_flag) {
            *str++ = div_buf + '0';
        } else {
            *str++ = ' ';
            continue;
        }
        if (i == (int8_t)fract) {
            *str++ = '.';
        }
    }
    *str++ = '\0';
    return NTS_OK;
}