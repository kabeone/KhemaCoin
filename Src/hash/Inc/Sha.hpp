#ifndef BLOCKCHAIN_SHA_HPP
#define BLOCKCHAIN_SHA_HPP

#include <string>
#include <openssl/sha.h>
#include "Hasher.hpp"

class Hash_Sha512: public Hash {
    friend class Sha;

public:
    const uint8_t *get_hash();
    bool operator==(const Hash_Sha512 &);

private:
    uint8_t sha_512[SHA512_DIGEST_LENGTH];
};

class Hash_Sha256: public Hash {
    friend class Sha;

public:
    const uint8_t *get_hash();
    bool operator==(const Hash_Sha256 &);

private:
    uint8_t sha_256[SHA256_DIGEST_LENGTH];
};

class Sha: public Hasher {
public:
    Sha();
    void clear_sha_512();
    void clear_sha_256();
    Hash_Sha512 hash512(const char *);
    Hash_Sha512 hash512(const std::string &);
    Hash_Sha256 hash256(const char *);
    Hash_Sha256 hash256(const std::string &);

private:
    SHA512_CTX sha512;
    SHA256_CTX sha256;
};


#endif
