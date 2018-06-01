/*
 * Venire Labs Inc 2018(c) All rights reserved
 */

#include "hypergraph.h"

#include<stdio.h>
#include<stdlib.h>

int hypergraph_gensk(struct hypergraph_sk *sk) {
  int n = HYPERGRAPH_ccc;
  struct tree *src;
  struct tree *dst = sk->cache;
  struct lamportBlock_pk mpk;
  struct address address;
  int i;
  int res;

  /*Create sub lamport block*/
  address.layer = 0;
  for (i=0; i <n; ++i) {
    address.index = i * LAMPORTBLOCK_hhh;
    res = lamportBlock_genpk(&sk->seed, &address, &mpk);
    if(res != HYPERGRAPH_OK) return res;

    hashcpy(&dst[i], &mpk.k);

  }

  /*Cache layers of blocks*/
  for (i=0; i < HYPERGRAPH_c; ++i) {
    src = dst;
    dst += n;
    n >>= 1;

    hash_compress_pairs(dst, src, n);

  }

  return HYPERGRAPH_OK;


}

int hypergraph_genpk(const struct hypergraph_sk *sk, struct hypergraph_pk *pk) {
  hashcpy (&pk->k, &sk->cache[2 * HYPERGRAPH_ccc - 2]);

  return HYPERGRAPH_OK;

}

int hypergraph_genpk (const struct hypergraph_sk *sk, struct hypergraph_sign *sign, const struct tree *msg) {

  struct tree buf[2];
  struct address address;
  struct poset_subset subset;
  struct poset_sk *psk;
  struct poset_pk ppk;
  struct lamportBlock_pk mpk;
  struct tree h;
  int layer;
  int res;
#if HYPERGRAPH_c > 0
  int offset;
  int n = HYPERGRAPH_ccc;
  int i, sibling;
#endif

  /*Generate a form of randomness from message and secret salf*/


  hashcpy (&buf[0], &sk->salt);
  hashcpy (&buf[1], msg);
  tree_hash_20_to_N (&sign->rand, msg, &address.index, &subset);

  /*poset*/
  psk = malloc(sizeof(struct poset_sk));
  if (psk == NULL) return HYPERGRAPH_ERR_ALLOC;

  address.layer = HYPERGRAPH_d;
  poset_gensk (&sk->seed, &address, psk);

  res = solomonkey_sign(psk, &sign->op_sign, &ppk, &subset);

  /*Wipe key*/
  free(psk);

  if (res != HYPERGRAPH_OK) return res;

  /*Store poset pubkey into h*/
  hashcpy(&h, &ppk.k);

  /*Hypergraph*/
  for (layer = 0; layer < HYPERGRAPH_d; ++layer) {

    /*sign h with lamport block algo and obtain a pub key*/
    --address.layer;
    res = lamportBlock_sign(&sk->seed, &address, &sign->lamportBlock[layer], &h, &mpk);
    if(res != HYPERGRAPH_OK) return res;
    hashcpy (&h, &mpk.h);

    /*Reduce address for next layer*/
    address.index >>=HYPERGRAPH_h;

  }






}
