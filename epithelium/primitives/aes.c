#include "../aes.h"
#include <openssl/conf.h>
#include <openssl/err.h>
#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

int aesctr256(uint8_t *out, const uint8_t *sk, const void *counter, int bytes) {
  static const uint8_t buffer[4096] = { 0 };
  EVP_CIPHER_CTX *ctx;
  int len = 0;
  int ret = 0;

  if (bytes == 0) return 0;

  if (!(ctx = EVP_CIPHER_CTX ())){
    ret =-2;
    goto label_exit_0;
  }

  if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_ctr(), ))

}
