#pragma once

class Hash
{
public:

    static unsigned int hashInt(int key)
    {
        return key * 31;
    }

    static unsigned int hashString(const char* str)
    {
        unsigned int hash = 0;

        while(*str)
        {
            hash = hash * 31 + *str;
            str++;
        }

        return hash;
    }

    template<typename T>
    static unsigned int hashObject(const T& obj)
    {
        return obj.getHash();
    }
};