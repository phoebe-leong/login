#include "cryptor/cryptor.hpp"
#include <ctime>
#pragma once

namespace cryptorv2 {
    std::string key;

    std::string encrypt(std::string string, bool genkey = false) {
        if (genkey) {
            char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

            while (key.length() != sizeof(letters) / sizeof(letters[0])) {
                int letter = rand() % sizeof(letters) / sizeof(letters[0]);
                key += letters[letter];
            }

            return cryptor::encrypt(string, key);
        } else if (!key.empty()) {
            return cryptor::encrypt(string, key);
        }

        return cryptor::encrypt(string);
    }

    std::string decrypt(std::string string) {
        if (!key.empty()) {
            return cryptor::decrypt(string, key);
        }

        return cryptor::decrypt(string);
    }

    std::string getKey() {
        if (!key.empty()) {
            return key;
        }

        return "NO KEY";
    }

    void setKey(std::string newKey) {
        key = newKey;
    }

    void deleteKey() {
        key = "";
    }

}
