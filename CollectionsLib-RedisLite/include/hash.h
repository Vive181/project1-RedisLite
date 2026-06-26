#ifndef HASH_FUNCTION_CPP //if hash function is not defined
#define HASH_FUNCTION_CPP 
//they provide header guard if hashfunction is include  more
//than one time but it compile it only once

#include <string>

class HashFunction {
public:

    int generate(int key) const {
        return key;
    }

    int generate(char key) const {
        return key;
    }

    int generate(bool key) const {
        return key ? 1 : 0;
    }

    int generate(const std::string& key) const {

        size_t hash = 0;

        for(char ch : key) {
            hash = hash * 31 + ch;
        }

        return hash;
    }

    // User-defined class with hashCode()
    template<typename T>
    int generate(const T& key) const
        -> decltype(key.hashCode())
    {
        return key.hashCode();
    }

    template<typename T>
    int generateFallback(const T& key) const {

        const unsigned char* bytes =
            reinterpret_cast<const unsigned char*>(&key); //read the object bits

            //const unsigned char* bytes = used to get raw bytes

        int hash = 0;

        for(size_t i = 0; i < sizeof(T); i++) { //loop through all bytes
            hash = hash * 31 + bytes[i];
        }

        return hash;
    }
};

#endif // HASH_FUNCTION_CPP