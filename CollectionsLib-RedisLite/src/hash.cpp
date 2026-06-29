#ifndef HASH_FUNCTION_CPP //if hash function is not defined
#define HASH_FUNCTION_CPP 
//they provide header guard if hashfunction is include  more
//than one time but it compile it only once

#include <string>

class HashFunction {
public:


    int generate(char key) const {
        return key;
    }

    int generate(bool key) const {
        return key ? 1 : 0;
    }

    int generate(const std::string& key) const {

        size_t hash = 0;
        //Using size_t gives a much larger range.
        //it gives only positive values

        for(char ch : key) {
            hash = hash * 31 + ch;
        }
        //different strings produce the same hash if we dont multiply by 31

        //This is called a collision if 2 string produce same hash value.
        //if we use large number then multiplication become expensive and if we use small
        // then there is a chance of collision 
        //also prime number also gives hash value better

        return hash;
    }

    // User-defined class with hashCode()
    template<typename T>
    auto generate(const T& key) const //auto returns any datatype value
        -> decltype(key.hashCode())
        //trailing return type. decltype means: "Find the datatype of this expression.
    {
        return key.hashCode(); //either it is long or any dtype other than int char string
    }

    // Fallback byte-wise hash it simply looks at the raw bytes
    template<typename T>
    int generateFallback(const T& key) const { //T refers to class and key refers to its object

        const unsigned char* bytes =                     //unsigned char* gives the initial bytes of object memory
            reinterpret_cast<const unsigned char*>(&key); //reinterpret_cast it helps in this

        int hash = 0;

        for(size_t i = 0; i < sizeof(T); i++) {
            hash = hash * 31 + bytes[i];
        }

        return hash;
    }
};

#endif // HASH_FUNCTION_CPP