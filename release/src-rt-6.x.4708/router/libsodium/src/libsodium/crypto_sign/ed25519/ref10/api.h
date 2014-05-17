
#include "crypto_sign_ed25519.h"

#define crypto_sign crypto_sign_ed25519
#define crypto_sign_open crypto_sign_ed25519_open
#define crypto_sign_keypair crypto_sign_ed25519_keypair
#define crypto_sign_seed_keypair crypto_sign_ed25519_seed_keypair
#define crypto_sign_BYTES crypto_sign_ed25519_BYTES
#define crypto_sign_SEEDBYTES crypto_sign_ed25519_SEEDBYTES
#define crypto_sign_PUBLICKEYBYTES crypto_sign_ed25519_PUBLICKEYBYTES
#define crypto_sign_SECRETKEYBYTES crypto_sign_ed25519_SECRETKEYBYTES
#define crypto_sign_IMPLEMENTATION crypto_sign_ed25519_IMPLEMENTATION
#define crypto_sign_VERSION crypto_sign_ed25519_VERSION
