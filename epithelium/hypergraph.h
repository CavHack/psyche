/*
* Copyright (c) 2018 Venire Labs Inc
*/

#pragma once

#include "lamportBlock.h"
#include "pors.h"

struct hypergraph_sk {
  struct tree seed;
  struct tree salt;
  struct tree cache[  2 * HYPERGRAPH_ccc - 1];
};

struct hypergraph_pk {
  struct tree k;
};

struct hypergraph_sign {
  struct tree rand;
  struct solomonkey_sign op_sign;
  struct 
}

