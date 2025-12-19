#ifndef INTHASH_H
#define INTHASH_H

#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class IntHash{
  private:
    // Number of buckets in the table
    int size;
    
    // Array of lists to store <key, value> pairs (str, int)
    vector<list<pair<string, int > > > table;
    
    // Hash function: hashes the given string to an integer
    int hashFunction(const string& key);
  
  public:
    // Constructor: creates a table of the given size
    IntHash(int size);

    // Inserts the given <key, value> pair into the table
    void insert(const string& key, int value);

    // Remove the given <key, value> pair from the table
    void remove(const string& key);

    // Returns the value associated with the given key
    int get(const string& key);

    // Prints the contents of the table
    void print();
};

#endif