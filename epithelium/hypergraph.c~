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



  }


}
