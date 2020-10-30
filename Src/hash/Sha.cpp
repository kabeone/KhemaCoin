#include <iostream>
#include <string>
#include <cstring>
#include <openssl/sha.h>
#include "Inc/Sha.hpp"

Sha::Sha() {
    SHA512_Init(&sha512);
    SHA256_Init(&sha256);
}

void Sha::clear_sha_512() {
    SHA512_Init(&sha512);
}

void Sha::clear_sha_256() {
    SHA256_Init(&sha256);
}

Hash_Sha512 Sha::hash512(const char *str) {
    Hash_Sha512 s {};

    SHA512_Update(&sha512, str, strlen(str));
    SHA512_Final(s.sha_512, &sha512);
    clear_sha_512();
    return s;
}

Hash_Sha512 Sha::hash512(const std::string &str) {
    Hash_Sha512 s {};

    SHA512_Update(&sha512, str.c_str(), str.size());
    SHA512_Final(s.sha_512, &sha512);
    clear_sha_512();
    return s;
}

Hash_Sha256 Sha::hash256(const char *str) {
    Hash_Sha256 s {};

    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(s.sha_256, &sha256);
    clear_sha_256();
    return s;
}

Hash_Sha256 Sha::hash256(const std::string &str) {
    Hash_Sha256 s {};

    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(s.sha_256, &sha256);
    clear_sha_256();
    return s;
}

const uint8_t *Hash_Sha512::get_hash() {
    return this->sha_512;
}

bool Hash_Sha512::operator==(const Hash_Sha512 &hash) {
    if (memcmp(this->sha_512, hash.sha_512, SHA512_DIGEST_LENGTH) == 0)
        return true;
    return false;
}

const uint8_t *Hash_Sha256::get_hash() {
    return this->sha_256;
}

bool Hash_Sha256::operator==(const Hash_Sha256 &hash) {
    std::cout << memcmp(this->sha_256, hash.sha_256, SHA256_DIGEST_LENGTH) << std::endl;
    if (memcmp(this->sha_256, hash.sha_256, SHA256_DIGEST_LENGTH) == 0)
        return true;
    return false;
}