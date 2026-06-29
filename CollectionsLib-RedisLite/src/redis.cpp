#include "Redis.h"

Redis::Redis()
{
}

Redis::~Redis()
{
}

void Redis::set(const std::string& key,
                const std::string& value)
{
    database.insert(key, value);
}

std::string Redis::get(const std::string& key) const
{
    const std::string* value = database.find(key);

    if (value != nullptr)
    {
        return *value;
    }

    return "";
}

bool Redis::del(const std::string& key)
{
    return database.remove(key);
}

bool Redis::exists(const std::string& key) const
{
    return database.contains(key);
}

void Redis::clear()
{
    database.clear();
}

int Redis::size() const
{
    return database.size();
}

bool Redis::empty() const
{
    return database.isEmpty();
}