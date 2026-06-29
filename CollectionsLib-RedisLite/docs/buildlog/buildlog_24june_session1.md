date: 24 june
Duration: 120 minutes

Goal:
start implementing hash function and hashmap.

Problem Encountered:

1. problem arises in creation of hashfunction it cannot works for objects i can create functions for int ,char,string that overloads each other and i also create a default function for user that handle other primitive datatypes and also user defined datatypes but there is an issue that shall we have to take the memory reference to return hash or we can return the sum of ascii value of the objects data members.

2. another problem arise after creating default function user defined datatypes but there is an issue if two objects having same datamembers after calculating hash value their hash value 
will be same but they are not pointing to a single address.

What I Tried:

tried to make hash function it is working for primitive datatypes but there were several limitations of this like 

  1. the hash functions hashes pointer address not the actual string it does not hash the actual string so the two string having the same value will get different hashes.
  2. it cannot work in objects when their is string defined there and cannot hash the objects

Outcome:

learns the whole architecture of hashmap and start implementing it.