#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <utility>

using namespace std;

namespace cop4530{
    template <typename K, typename V>
        class HashTable{
            public:
                HashTable(size_t size = 101);
                ~HashTable();
                bool contains(const K & k) const;
                bool match(const pair<K, V> &kv) const;
                bool insert(const pair<K, V> & kv);
                bool insert (pair<K, V> && kv);
                bool remove(const K & k);
                void clear();
                bool load(const char *filename);
                void dump() const;
                size_t size() const;
                bool write_to_file(const char *filename) const;
            
            private: 
                void makeEmpty();
                void rehash();
                size_t myhash(const K &k) const;
                unsigned long prime_below (unsigned long);
                void setPrimes(vector<unsigned long>&);
                // max_prime is used by the helpful functions provided
                // to you.
                static const unsigned int max_prime = 1301081;
                // the default_capacity is used if the initial capacity 
                // of the underlying vector of the hash table is zero. 
                static const unsigned int default_capacity = 101;

                size_t si;
                vector<list<pair<K,V>>> lst;

        };
    
    #include "hashtable.hpp"
}

#endif
