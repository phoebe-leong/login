# cryptorv2
Extension of [njh0602/cryptor](https://github.com/njh0602/cryptor)

## Changes/Additions

- Added proper functioning key generator
- Made `setKey()` and `getKey()` work properly
- Gave `encrypt()` and `decrypt()` more parameters regarding encryption and decryption keys
- Made `deleteKey()`

## Example

```cpp
#include "cryptorv2.hpp"
#include <iostream>

int main() {

    // Encrypt with random key generated
    std::string encrypted = cryptorv2::encrypt("Hello World", true);
    // Decrypt same message
    cryptorv2::decrypt(encrypted);
    
    // Encrypt without randomly generated key
    cryptorv2::encrypt("Hello World", false);
    // This also does the same thing
    cryptorv2::encrypt("Hello World");

    // delete the current key
    cryptorv2::deleteKey();
    // set a new key
    cryptorv2::setKey("Hello");
    // get the current key
    std::string currentKey = cryptorv2::getKey();

    return 0;
}
```

## Compile

```
g++ example.cpp -std=c++11
```
