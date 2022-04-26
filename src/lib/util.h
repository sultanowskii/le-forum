#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lib/status.h"

#define newline() printf("\n")

/**
 * @brief Returns maximum between two given arguments. 
 * 
 */
#define MAX(x, y)            (((x) > (y)) ? (x) : (y))

/**
 * @brief Returns minimum between two given arguments. 
 * 
 */
#define MIN(x, y)            (((x) < (y)) ? (x) : (y))

/**
 * @brief Returns increased by one x. If it becomes more than max, min is returned.  
 * 
 */
#define cyclic_inc(x, min, max) x = ((x + 1) <= (max)) ? (x + 1) : (min)

/**
 * @brief Returns decreased by one x. If it becomes less than min, max is returned.  
 * 
 */
#define cyclic_dec(x, min, max) x = ((x - 1) >= (min)) ? (x - 1) : (max)

/**
 * @brief fgets() wrapper that sets '\0' instead of '\n'. 
 * 
 * @param s Data pointer where input will be stored
 * @param n Max amounts to read 
 * @param fd File descriptor to read from 
 * @return Size of read data on success. LESTATUS_CLIB is retured if fgets() failed  
 */
size_t s_fgets(char *s, size_t n, FILE* fd);