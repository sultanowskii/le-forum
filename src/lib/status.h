#pragma once

#include <stdint.h>

typedef int8_t status_t;

enum LeStatus {
	LESTATUS_OK,   /* Ok */ 
	LESTATUS_CLIB, /* C Library Call Error */
	LESTATUS_NSFD, /* No Such File or Directory */
	LESTATUS_EXST, /* Already Exists */
	LESTATUS_NFND, /* Not found */
	LESTATUS_ISYN, /* Invalid Syntax */
	LESTATUS_IDAT, /* Invalid Data */
	LESTATUS_NPTR, /* Null pointer */
};

const char *SREPR_LESTATUS[LESTATUS_NPTR - LESTATUS_OK + 1];

/**
 * @brief Get the lestatus string representation 
 * 
 * @param status Status code 
 * @return String representation of the status code 
 */
const char *get_lestatus_string_repr(status_t status);
