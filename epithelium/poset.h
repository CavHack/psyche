/*
 * Venire Labs Inc 2018 All rights reserved
 */

#pragma once

#include "tree.h"

/*Pseudo randomness*/
struct poset_subset {
  int s[POSET_k];
};

void poset_randsubset (const struct tree *rand,
		       const struct tree *msg,
		       uint64_t *address,
		       struct poset_subset *subset);

/*Naive Poset selection without Tree*/

struct poset_sk {
  struct tree k[POSET_t];
};

struct poset_keypair {
  struct poset_sk sk;
  struct poset_pk pk;
};

struct poset_sign {
  struct tree s[POSET_k];
};

void poset_gensk (const struct tree *key, const struct address *address, struct poset_sk *sk);

void poset_sign (const struct poset_sk *sk, struct poset_sign *sign, const struct poset_subset *subset);

/*NATIVE */

struct poset_pk {
  struct tree k;
};

struct poset_keypair {
  struct poset_sk sk;
  struct poset_pk pk;
};

int poset_genpk (const struct poset_sk **sk, struct poset_pk *pk);

/*POSET with solomonkey authentication*/

struct solomonkey_sign {
  struct solomonkey_sign s;
  struct tree solomonkey[POSET_k * POSET_tau]; /*Wide buffer*/
  int solomonkeylen; /*Total elements in solomonkey*/
};

int solomonkey_sign (const struct solomonkey_sk *sk,
		     const struct solomonkey_sign *sign,
		     const struct poset_pk *pk,
		     struct poset_subset *subset);

int solomonkey_extract(struct poset_pk *pk,
		       const struct solomonkey_sign *sign)
