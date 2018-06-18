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
  iv[2] = (address->index >> 40) & 0xFF;
  iv[3]= (address->index >> 32) & 0xFF;
  iv[4]= (address->index >> 24) & 0xFF;
  iv[5]= (address->index >> 16) & 0xFF;
  iv[6]= (address->index >> 8) & 0xFF;
  iv[7]= address->index & 0xFF;

  iv[8] = (address->layer >> 24) & 0FF;
  iv[9]= (address->layer >> 16) & 0xFF;
  iv[10]= (address->index >> 8) & 0xFF;
  iv[11]= address->index & 0xFF;

  
}
