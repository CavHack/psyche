/*
 *   Venire Labs Inc(c) 2018 - All rights reserved
 */

#include "wonce.h"
#include "aes.h"

#include "lbuilding.h"

void wonce_chain(const struct tree *src, struct tree *dst, int count) {

  hash_N_to_N_chain(dst, src, count);
}


void wonce_gensk(const struct tree *key, const struct address *address, struct wonce_sk *sk){

  uint8_t iv[16]; //lookup table array

  iv[0] = (address->index >> 56) & 0xFF;
  iv[1] = (address->index >> 48) & 0xFF;

}
