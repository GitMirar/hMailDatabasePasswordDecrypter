#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
#include "blowfish.h"

std::vector<char> HexToBytes(const std::string& hex) {
    std::vector<char> bytes;

    for (unsigned int i = 0; i < hex.length(); i += 2) {
        std::string byteString = hex.substr(i, 2);
        char byte = (char) strtol(byteString.c_str(), NULL, 16);
        bytes.push_back(byte);
    }

    return bytes;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Please provide the encrypted database password" << std::endl;
        return -1;
    }
    CBlowFish cb;
    unsigned char key[] = "THIS_KEY_IS_NOT_SECRET";
    int keylen = strlen((const char*)key);
    cb.Initialize(key, keylen);
    std::vector<char> encoded = HexToBytes(argv[1]);
    unsigned char *decoded = (unsigned char*)malloc(encoded.size());
    cb.Decode((unsigned char*)encoded.data(), decoded, encoded.size());
    std::cout << decoded << std::endl;
    free(decoded);

    return 0;
}
