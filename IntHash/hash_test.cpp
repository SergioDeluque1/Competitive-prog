#include "IntHash.h"
//cambiar nombre genérico de table a my-table

int main() {
    // Create a hash table with 10 buckets
    IntHash table(10);
    
    // Insert key-value pairs
    table.insert("apple", 5);
    table.insert("banana", 2);
    table.insert("orange", 10);
    table.insert("grape", 8);

    // Print the hash table
    cout << "Hash table contents:" << endl;
    table.print();

    // Search for values by key
    cout << "Search for 'apple': " << table.get("apple") << endl;
    cout << "Search for 'banana': " << table.get("banana") << endl;
    cout << "Search for 'cherry': " << table.get("cherry") << endl;
    
    // Remove a key-value pair
    table.remove("banana");
    table.print();
    return 0;
}
