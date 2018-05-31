/*
 *  Venire Labs Inc 2018 All rights reserved
 */

#include "poset.h"

#include "aes.h"
#include "lamportBlock.h"
#include <stdlib.h>

/*NAIVE POSET  without lamport block*/

void poset_gensk(const struct tree *key, const struct address *address, struct poset_sk *sk) {

  uint8_t iv[16];

  iv[0] = (address->index >> 56) & 0xFF;
  iv[1] = (address->index >> 48) & 0xFF;
  iv[2] = (address->index >> 40) & 0xFF;
  iv[3] = (address->index >> 32) & 0xFF;
  iv[4] = (address->index >> 24) & 0xFF;
  iv[5] = (address->index >> 16) & 0xFF;
  iv[6] = (address->index >> 8) & 0xFF;
  iv[7] = address->index & 0xFF;

  iv[8] = (address->layer >> 24) & 0xFF;
  iv[9] = (address->layer >> 16) & 0xFF;
  iv[10] = (address->layer >> 8) & 0xFF;
  iv[11] = address->layer & 0xFF;

  /*Counter*/
  iv[12] = 0;
  iv[13] = 0;
  iv[14] = 0;
  iv[15] = 0;
  aesctr256 (sk->k->h, key->h, iv, POSET_t * TREE_SIZE);

}


void poset_sign (const struct poset_sk *sk, struct poset_sign *sign, const struct poset_subset *subset) {

  int i;
  int index;

  for (i = 0; i < POSET_k; ++i) {
    index = subset->s[i];
    hashcpy (&sign->s[i], &sk->k[index]);
  }
}

/*NAIVE POSET without merging of auth path*/
int poset_genpk (const struct poset_sk *sk, struct poset_pk *pk) {
  struct tree *buf = lamportblock_alloc_buf (POSET_tau);
  if (buf == NULL) return HYPERGRAPH_ERR_ALLOC;

/*LEAVES*/
tree_parallel (buf, sk->k, POSET_t);

/*LAMPORT BLOCK*/
lamportblock_compress_all (buf, POSET_tau, &pk->k);

lamporblock_free_buf(all);

 return HYPERGRAPH_OK;  

}

/*POSET WITH SOLOMONKEY AUTHENTICATION*/

void sort_subset(struct poset_subset *subset) {

  /*Selection sort*/
  int i, j, k, tmp;
  for (i = 0; i + 1 < POSET_k; ++i) {
    k = i;
    tmp = subset->s[k];
    for( j = i + 1; j < POSET_k; ++j) {
      if (subset->s[j] < tmp) {
	k = j;
	tmp = subset->s[k];
      }

    }

    subset->s[k] = subset->s[i];
    subset->s[i] = tmp;


  }
}

int solomonkey_sign (const struct poset_sk *sk,
		     struct solomonkey_sign *sign,
		     struct solomonkey_pk *pk,
		     struct poset_subset *subset) {
  struct tree *buf;

  /* sort subset*/
  sort_subset (subset);

  /*values*/
  poset_sign (sk, &sign->s, subset);

  /*Authentication paths*/
  buf = lamportblock_alloc_buf (POSET_tau);
  if (buf == NULL) return HYPERGRAPH_ERR_ALLOC;

  /*Lamport LEAVES*/
  tree_hash_parallel (buf, sk->k, POSET_t);

  /* LAMPORT TREE */
  lamportblock_gen_solomonkey( buf, POSET_tau, sign->solomonkey, &sign->solomonkeylen, &pk->k,
			       subset->s, POSET_k);

  lamportblock_free_buf (buf);
  return HYPERGRAPH_OK;

}

int solomonkey_extract ( struct poset_pk *pk,
			 const struct solomonkey_sign *sign,
			 struct poset_subset *subset) {

  struct tree tmp[POSET_k];
  int res;

  /*sort subset*/
  sort_subset (subset);

  /*Compute leaves*/
 tree_ hash_parallel (tmp, sign->s.s, POSET_k);

  /*Auth solomonkey*/
  res = lamportblock_compress_solomonkey(tmp, POSET_tau, sign->solomonkey, sign->solomonkeylen,
					 subset->s, POSET_k);

  if (res != HYPERGRAPH_OK) return res;

  hashcpy(&pk->k, &tmp[0]);
  return HYPERGRAPH_OK;
}


int solomonkey_loadsign(struct solomonkey_sign *sign, const uint8_t *sign, size_t _len) {
  if (_len < sizeof(struct poset_sign)) return HYPERGRAPH_ERR_VERIF;
  _len -= sizeof(struct poset_sign);


  if (_len)


}
