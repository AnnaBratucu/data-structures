#include "HashTable.h"
#include <iostream>

using namespace std;


// K&R
// Returns a bucket number from 0 to NUM_BUCKETS - 1
unsigned int HashTable::hashFunction(const std::string& str) {
	unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
	unsigned int hash = 0;

	for (std::size_t i = 0; i < str.length(); i++) {
		hash = (hash * seed) + str[i];
	}

	return (hash & 0x7FFFFFFF) % NUM_BUCKETS;
}

void HashTable::insert(string key, string value){
	string k=key;
	string v=value;

}

string HashTable::find(string key){

}

void HashTable::printBucketSizes(){

}


#include <string>
#include <vector>
using namespace std;

#define NUM_BUCKETS 1001

#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

//HashTable.h, the specification file for the class HashTable

class Entry {
public:
    string key;
    string value;
};

class HashTable {
public:
    // Add a key-value pair to hash table
    void insert(string key, string value);

    // Return the value associated with the given key in hash table.
    // Return empty string if key not found.
    string find(string key);

    // Print out the number of elements in each of the buckets
    void printBucketSizes();

private:
    unsigned int hashFunction(const std::string& str);
    vector<Entry> table[NUM_BUCKETS]; // an array of vectors<Entry>

};

#endif
#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
	string word;

	HashTable hashTable;
	hashTable.insert("A", "1");
	hashTable.insert("B", "2");
	hashTable.insert("C", "3");

	cout << hashTable.find("C") << endl; // Should print "3"

	while (cin >> word)
		if (hashTable.find(word) == "")
			hashTable.insert(word, word);

	hashTable.printBucketSizes();

	return 0;
}
