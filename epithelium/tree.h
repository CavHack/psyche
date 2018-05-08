/*
* Venire Labs Inc (c) All rights reserved.
*/

#pragma once

#ifndef CRYPTO_BYTES

#define CRYPTO_ALGNAME "PRUNE-HORST S"
#define CRYPTO_SECRETKEYBYTES 64
#define CRYPTO_PUBLICKEYBYTES 2048
#define CRYPTO_BYTES 20768

#if 0
#define CRYPTO_ALGNAME "PRUNE-HORST M"
#define CRYPTO_SECRETKEYBYTES 64
#define CRYPTO_PUBLICKEYBYTES 4096
#define CRYPTO_BYTES 23840
#endif

#if 0
#define CRYPTO_ALGNAME "PRUNE-HORST L"
#define CRYPTO_SECRETKEYBYTES 64
#define CRYPTO_PUBLICKEYBYTES 4096
#define CRYPTO_BYTES 26656
#endif

#endif

#include "common.h"

#include <stdint.h>
#include <string.h>

struct tree {
  uint 8_t  h[TREE_SIZE];
} __attribute__((aligned (16)));

struct address {
  uint64_t index;
  uint32_t layer;
};

void tree_N_to_N (struct tree *dst, const struct tree *src);
void tree_N_to_N_chain(struct tree *dst, const struct tree * src, int chainlen);
void tree_2N_to_N (struct tree *dst, const struct tree *src);
void tree_to_N (struct tree *dst, const uint8_t *src, uint64_t srclen);
