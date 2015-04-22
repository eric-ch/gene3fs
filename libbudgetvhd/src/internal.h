/*
 * project.h:
 *
 *
 */

/*
 * Copyright (c) 2012 Citrix Systems, Inc.
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


/*
 * $Id:$
 */

/*
 * $Log:$
 *
 */

#ifndef __PROJECT_H__
#define __PROJECT_H__

#include "config.h"

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <stdint.h>
#include <fcntl.h>

#include "budgetvhd.h"

#define EXPORT_SYMBOL __attribute__ ((visibility ("default")))

/* These symbols are only used internally */
uint32_t bvhd_checksum(void *_buf, int len);
uint32_t bvhd_now(void);
bvhd_uuid bvhd_new_uid(void);
uint64_t bvhd_round_to_block(BVHD *v, uint64_t ret);
uint64_t bvhd_round_to_sector(BVHD *v, uint64_t ret);
bvhd_geometry bvhd_make_geometry(uint64_t sectors);
int bvhd_check_footer(bvhd_footer *footer);
int bvhd_check_header(bvhd_header *header);
void bvhd_create_footer(BVHD *v, bvhd_footer *footer);
void bvhd_create_header(BVHD *v, bvhd_header *header);
uint32_t bvhd_new_block(BVHD *v);
int bvhd_update_bat(BVHD *v, uint32_t block, uint32_t offset);
/* version.c */
char *libbudgetvhd_get_version(void);
/* swab.c */
int bvhd_swab16(uint16_t *b, size_t n);
int bvhd_swab32(uint32_t *b, size_t n);
int bvhd_swab64(uint64_t *b, size_t n);
int bvhd_swab_header(bvhd_header *h);
int bvhd_swab_geometry(bvhd_geometry *g);
int bvhd_swab_footer(bvhd_footer *f);

#endif /* __PROJECT_H__ */
