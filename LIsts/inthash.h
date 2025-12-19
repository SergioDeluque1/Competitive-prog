#ifndef INTHASH_H
#define INTHASH_H

#include <vector>
#include <list>
#include <iostream>
#include <utility>

using namespace std

class Inthash{ 
    private:
        int size;
        vector<list<pair<string, int>>> table;
        int HashFunction(const string& key);
    public:
        inthash(int size);

        void insert( const string& key, int value);
        void remove(const string& key);
        int get(const string& key);
        int print();

}

#endif