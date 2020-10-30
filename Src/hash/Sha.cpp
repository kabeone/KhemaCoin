#include <string>
#include <cstring>
#include <openssl/sha.h>
#include "Inc/Sha.hpp"

Sha::Sha() {
    SHA512_Init(&sha512);
    SHA256_Init(&sha256);
}

Hash_Sha512 Sha::hash512(const char *str) {
    Hash_Sha512 s {};

    SHA512_Update(&sha512, str, strlen(str));
    SHA512_Final(s.sha_512, &sha512);
    return s;
}

Hash_Sha512 Sha::hash512(std::string str) {
    Hash_Sha512 s {};

    SHA512_Update(&sha512, str.c_str(), str.size());
    SHA512_Final(s.sha_512, &sha512);
    return s;
}

Hash_Sha256 Sha::hash256(const char *str) {
    Hash_Sha256 s {};

    SHA256_Update(&sha256, str, strlen(str));
    SHA256_Final(s.sha_256, &sha256);
    return s;
}

Hash_Sha256 Sha::hash256(std::string str) {
    Hash_Sha256 s {};

    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(s.sha_256, &sha256);
    return s;
}

const uint8_t *Hash_Sha512::get_hash() {
    return this->sha_512;
}

const uint8_t *Hash_Sha256::get_hash() {
    return this->sha_256;
}