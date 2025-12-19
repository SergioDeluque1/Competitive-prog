#include "IntHash.h"

// Constructor: Initialize the hash table with a number of buckets
IntHash::IntHash(int buckets) : size(buckets) {
    table.resize(buckets);
}

// Hash function to map a string key to an index
int IntHash::hashFunction(const string& key) {
    unsigned int hashValue = 0;
    for (char ch : key) {
        hashValue = hashValue * 31 + ch;  // multiply by prime
    }
    return hashValue % size;
}

// Insert a key-value pair into the hash table
void IntHash::insert(const string& key, int value) {
    int index = hashFunction(key);

    // Check if the key already exists in the chain at this index
    // recorre el par y reasigna memoria
    for (auto& kv : table[index]) {
        if (kv.first == key) {
            kv.second = value;  // Update the existing value
            return;
        }
    }

    // If key does not exist, add a new (key, value) pair to the list
    // array, list pair
    table[index].push_back(make_pair(key, value));
}

// Remove a key-value pair from the hash table
void IntHash::remove(const string& key) {
    int index = hashFunction(key);

    // Iterate over the list at the computed index and remove key if found
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);  // Remove the key-value pair
            return;
        }
    }
    cout << "Key not found: " << key << endl;
}

// Search for a value by key in the hash table
int IntHash::get(const string& key) {
    int index = hashFunction(key);

    // Search the list at the computed index for the key
    for (const auto& kv : table[index]) {
        if (kv.first == key) {
            return kv.second;  // Return the associated value
        }
    }

    return -1;  // Key not found, return -1
}
//no compila, no tiene main
// Print the contents of the hash table
void IntHash::print() {
    for (int i = 0; i < size; ++i) {
        cout << "Bucket " << i << ": ";
        for (const auto& kv : table[i]) {
            cout << "[" << kv.first << ": " << kv.second << "] ";
        }
        cout << endl;
    }
}
