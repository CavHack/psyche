/*
* Copyright (c) 2018 Venire Labs Inc
*/

#pragma once

#include "lamportBlock.h"
#include "pors.h"

struct hypergraph_sk {
  struct hash_seed;
  struct hash salt;
  //struct hash cache[  2 * HYPERGRAPH_ccc - 1];
};
