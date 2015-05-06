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
#ifndef __BUDGETBVHD_H__
#define __BUDGETBVHD_H__

#ifdef __cplusplus
extern "C" { 
#endif

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>


typedef struct
{
  uint8_t uuid[8];
} bvhd_uuid;

typedef struct
{
  uint8_t locator[8];
} bvhd_locator;

typedef struct
{
  uint8_t cookie[8];
  uint64_t data_offset;
  uint64_t table_offset;
  uint32_t header_version;
  uint32_t max_table_entries;
  uint32_t block_size;
  uint32_t checksum;
  bvhd_uuid parent_unique_id;
  uint32_t parent_time_stamp;
  uint32_t reserved1;
  uint16_t parent_name[256];
  bvhd_locator parent_locator[8];
  uint8_t reserved2[256];
} bvhd_header;

typedef struct
{
  uint16_t cylinders;
  uint8_t heads;
  uint8_t sectors;
} bvhd_geometry;


typedef struct
{
  uint8_t cookie[8];
  uint32_t features;
  uint32_t file_format_version;
  uint64_t data_offset;
  uint32_t time_stamp;
  uint8_t creator_application[4];
  uint32_t creator_version;
  uint32_t creator_host_os;
  uint64_t original_size;
  uint64_t current_size;
  bvhd_geometry disk_geometry;
  uint32_t disk_type;
  uint32_t checksum;
  bvhd_uuid unique_id;
  uint8_t saved_state;
  uint8_t reserved[427];
} bvhd_footer;

typedef struct BVHD_struct
{
  FILE *f;


  uint32_t *bat;
  uint32_t bat_ents;
  uint64_t bat_offset;


  uint64_t size;

  uint32_t block_size;
  uint32_t block_shift;
  uint64_t block_mask;

  uint32_t block_sector_size;
  uint32_t block_sector_shift;
  uint64_t block_sector_mask;

  uint8_t *bitmap;
  uint64_t bitmap_size;

  uint64_t current_tail;

  bvhd_footer footer;
  bvhd_header header;

  int ro;
}BVHD;

#define BVHD_COOKIE "conectix"
#define BVHD_COOKIE2 "cxsparse"
#define BVHD_COOKIE_LEN 8

#define BVHD_FEATURES_TEMPORARY 0x1
#define BVHD_FEATURES_RESERVED  0x2

#define BVHD_FILE_FORMAT_VERSION 0x0010000

#define BVHD_CREATOR_HOST_OS_WINDOWS 0x5769326B
#define BVHD_CREATOR_HOST_OS_MACINTOSH 0x4D616320

#define BVHD_DISK_TYPE_NONE	0
#define BVHD_DISK_TYPE_FIXED_HARD_DISK	2
#define BVHD_DISK_TYPE_DYNAMIC_HARD_DISK 3
#define BVHD_DISK_TYPE_DIFFERENCING_HARD_DISK 4

#define BVHD_HEADER_VERSION 0x00010000

void bvhd_close(BVHD *v);
BVHD *bvhd_open(char *name, int ro);
BVHD *bvhd_create(char *name, uint64_t size, uint64_t blocksize);
int bvhd_read_sector(BVHD *v, void *buf, uint64_t sector);
uint32_t bvhd_read(BVHD *v, void *_buf, uint64_t sector, uint32_t nsectors);
int bvhd_write_sector(BVHD *v, const void *buf, uint64_t sector);
uint32_t bvhd_write(BVHD *v, const void *_buf, uint64_t sector, uint32_t nsectors);
uint64_t bvhd_size(BVHD *v);
void bvhd_flush(BVHD *v);
uint64_t bvhd_block_size(BVHD *v);
int bvhd_bat_filled(BVHD *v, uint64_t sector);
#ifdef __cplusplus
}
#endif

#endif /* __BUDGETVHD_H__ */
