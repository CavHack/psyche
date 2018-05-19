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
  struct lamportBlock_sign lamportBlock[HYPERGRAPH_d];
#if HYPERGRAPH_c > 0
  struct tree auth[HYPERGRAPH_c];
#endif
};

int hypergraph_gensk(struct hypergraph_sk *sk);

int hypergraph_genpk(const struct hypergraph_sk *sk, struct hypergraph_pk *pk);

int hypergraph_sign (const struct hypergraph_sk *sk, struct hypergraph_sign *sign, const struct tree *msg);

int hypergraph_verify(const struct hypergraph_pk *pk,
		      const struct hypergraph_sign *sign,
		      const struct tree *msg);

/*Serialization*/
int hypergraph_loadsign(struct hypergraph_sign *sign, const uint8_t *_sign, size_t _len);

int gravity_signcmp(const struct hypergraph_sign *sign1, const struct hypergraph_sign *sign2);

