#ifndef REDIS_H
#define REDIS_H

#include <string>
#include "HashMap.h"

class Redis
{
private:
    // Main in-memory database
    HashMap<std::string, std::string> database;

public:

    // Constructor
    Redis();

    // Destructor
    ~Redis();

    // Redis Commands
    void set(const std::string& key, const std::string& value);

    std::string get(const std::string& key) const;

    bool del(const std::string& key);

    bool exists(const std::string& key) const;

    void clear();

    int size() const;

    bool empty() const;
};

#endif