/*
* Copyright (C) 2018 Venire Labs Inc
*/

#pragma once

#include "wots.h"

struct lamportBlock_pk {
  struct tree k;
};

struct lamportBlock_sign {
  struct wots_sign wots;
  struct tree auth[LAMPORTBLOCK_H];
};

int lamportBlock_genpk (const struct tree *key, const struct address *address, struct lamportBlock_pk *pk);

int lamportBlock_sign( const struct tree *key,
  const struct address *address,
  struct lamportBlock_sign *sign,
  const struct tree *msg,
  struct lamportBlock_pk *pk);

  void lamportBlock_extract (struct lamportBlock_pk *pk,
                             const struct address * address,
                             const struct tree *msg;

/*Library Functions*/
/*Buffer Tree*/

struct tree *lamportBlock_alloc_buf(int height);

void lamportBlock_alloc_buf (struct tree *buf);

/*Compress leaves from level height to root*/

void lamportBlock_compress_all(struct tree *buf, int height, struct tree * root);


void lamportBlock_gen_auth(struct tree *node, int height, struct tree *auth, int index, struct tree *root);


int lamportBlock_compress_auth(struct tree *node, int index, const struct tree *auth, int height_diff);

/*sort indices*/

void lamportBlock_gen_solomon (struct tree *buf, int height, const struct tree *solomon, int solomon, int *indices, int count);
