#include <gtest/gtest.h>
#include "parser.h"
#include "redis.h"

class ParserTest : public ::testing::Test {
protected:
    Redis db;
    
    // We don't need a complex SetUp for these tests, 
    // a fresh Redis db is created for each test automatically.
};

TEST_F(ParserTest, ParseSetCommandSetsValue) {
    parse("SET name John Doe", db);
    EXPECT_TRUE(db.exists("name"));
    EXPECT_EQ(db.get("name"), "John Doe");
}

TEST_F(ParserTest, ParseSetCommandOverwritesValue) {
    parse("SET color blue", db);
    EXPECT_EQ(db.get("color"), "blue");
    
    parse("SET color green", db);
    EXPECT_EQ(db.get("color"), "green");
}

TEST_F(ParserTest, ParseDelCommandDeletesKey) {
    db.set("session", "xyz123");
    EXPECT_TRUE(db.exists("session"));
    
    parse("DEL session", db);
    EXPECT_FALSE(db.exists("session"));
}

TEST_F(ParserTest, ParseIsCaseInsensitiveForCommands) {
    // lowercase set
    parse("sEt mykey val", db);
    EXPECT_TRUE(db.exists("mykey"));
    EXPECT_EQ(db.get("mykey"), "val");
    
    // uppercase del
    parse("DEL mykey", db);
    EXPECT_FALSE(db.exists("mykey"));
}

TEST_F(ParserTest, ParseUnknownCommandDoesNotCrash) {
    // Should safely print "Unknown Command" without crashing
    parse("MAGICKEY do something", db);
    
    // db should remain empty
    EXPECT_TRUE(db.empty());
}
