/*
 * Venire Labs Inc 2018
 */

#pragma once

#include "commom.h"
#include "tree.h"

struct wonce_sk {
  struct tree k[WONCE_ell];
};

struct wonce_pk {
  struct tree k[WONCE_ell];
};

struct wonce_sign {
  struct tree s[WONCE_ell];
};

void wonce_gensk (const struct tree *key, const struct address *address, struct wonce_sk *sk);

void wonce_sign (const struct wonce_sk *sk, struct wonce_sign *sign, const struct tree *msg);

/*One time sig with Tits Building and without masks*/

struct lwonce_pk {
  struct tree k;
};

void lwonce_genpk (cont struct wonce_sk *sk, struct lwonce_pk *pk);

void lwonce_extract(struct lwonce_pk *pk, const struct wonce_sign *sign, const struct tree *msg);
