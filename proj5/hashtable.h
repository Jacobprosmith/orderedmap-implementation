#ifndef COP4530_HASHTABLE_H
#define COP4530_HASHTABLE_H
#include <vector>
#include <iostream>
#include <list>
#include <functional>
#include <string>

// used when improper size is given (for example
// size is 0 or negatiave)
using namespace std;
namespace cop4530 {
    template<typename T>
    class HashTable {
    public:

        static const unsigned int default_capacity = 11;
        static const unsigned int max_prime = 1301081;


        void setPrimes(std::vector<long> &);
        HashTable(size_t size = 101);
        ~HashTable();
        bool contains(const T &x) const;
        bool insert(const T & x);
        bool insert (T &&x);
        void dump() const;
        bool remove(const T &x);
        void clear();
        void rehash();
        int getSize();
    private:

        unsigned long prime_below(long);
        void makeEmpty();
        std::vector<std::list<T>> hashTable;
        hash<T> hash;
        int numEntries = 0;

        size_t myhash(const T &x) const;
    };
#include "hashtable.hpp"

}
#endif