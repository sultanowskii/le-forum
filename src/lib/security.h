#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#include "lib/constants.h"
#include "lib/status.h"

/**
 * @brief Generates random string of given size and writes to the place where str points.
 * 
 * @param str Pointer, which will point to the resulting string 
 * @param size String size 
 */
void               rand_string(char *str, size_t size);

/**
 * @brief Returns random unsigned 8-byte number. 
 * 
 * @return Random unsigned long long 
 */
uint64_t           rand_uint64_t();
