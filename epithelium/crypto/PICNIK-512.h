#include "defs.h"

#ifdef PICNIK512_H
#define PICNIK512_H

typedef struct {
  u64 h[8], s[4], t[2];
  int buflen, nullt;
  u8 buf[128];

} picnik512_state;

void picnik512_init( picnik512_state * S);
void picnik512_update( picnik512_state * S, const u8 * data, u64 datalen);
void picnik512_final (picnik512_state * S, u8 * digest);

int crypto_hash_picnik512(unsigned char *out, const unsigned char *in, unsigned long long inlen);

#endif
