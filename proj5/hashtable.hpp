#include "hashtable.h"
using namespace cop4530;
using namespace std;

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
template <typename T>
unsigned long HashTable<T>::prime_below (long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector <long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename T>
void HashTable<T>::setPrimes(std::vector<long>& vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}

template <typename T>
HashTable<T>::HashTable(size_t size) {
    hashTable.resize(prime_below(size));
}

template <typename T>
HashTable<T>::~HashTable() {
    //int size = hashTable.size();
    //for (int i = 0; i < size; i++) {
    hashTable.clear();
    //}
}

template <typename T>
bool HashTable<T>::contains(const T &x) const {
    int size = hashTable.size();
    for (int i = 0; i < size; i++) {
        for (auto j = hashTable[i].begin(); j != hashTable[i].end(); j++) {
            if (*j == x) {
                return true;
            }
        }
    }
    return false;
}

template <typename T>
bool HashTable<T>::insert(const T & x) {
    int index = myhash(x);
    for (auto j = hashTable[index].begin(); j != hashTable[index].end(); j++) {
        if (*j == x) {
            return false;
        }
    }
    numEntries++;
    hashTable[index].push_back(x);
    return true;
}

template <typename T>
bool HashTable<T>::insert (T &&x) {
    int index = myhash(x);
    for (auto j = hashTable[index].begin(); j != hashTable[index].end(); j++) {
        if (*j == x) {
            return false;
        }
    }
    numEntries++;
    hashTable[index].push_back(x);
    return true;
}

template <typename T>
size_t HashTable<T>::myhash(const T &x) const {
    return hash(x) % hashTable.size();
}

template <typename T>
void HashTable<T>::dump() const {
    int size = hashTable.size();
    for (int i = 0; i < size; i++) {
        cout << "v[" << i << "]: ";
        for (auto j = hashTable[i].begin(); j != hashTable[i].end(); j++) {
            cout << *j;
            // if (j++ != hashTable[i].end()) {  to do later
            cout << "\t";
            //}
        }
        cout << endl;
    }
}

template <typename T>
bool HashTable<T>::remove(const T &x) {
    int index = myhash(x);
    for (auto j = hashTable[index].begin(); j != hashTable[index].end(); j++) {
        if (*j == x) {
            numEntries--;
            hashTable[index].erase(j);
            return true;
        }
    }
    return false;
}

template <typename T>
void HashTable<T>::clear() {
    makeEmpty();
}

template <typename T>
void HashTable<T>::makeEmpty() {
    int size = hashTable.size();
    for (int i = 0; i < size; i++) {
        int math = distance(hashTable[i].begin(), hashTable[i].end());
        numEntries -= math;
        hashTable[i].erase(hashTable[i].begin(), hashTable[i].end());
    }
}

template <typename T>
void HashTable<T>::rehash() {
    vector<list<T>> oldHashTable = hashTable;
    hashTable.resize(prime_below(2*hashTable.size()));
    int size = hashTable.size();
    for (int i = 0; i < size; i++) {
        int math = distance(hashTable[i].begin(), hashTable[i].end());
        numEntries -= math;
        hashTable[i].erase(hashTable[i].begin(), hashTable[i].end());
    }
    int oldSize = oldHashTable.size();
    for (int i = 0; i < oldSize; i++) {
        for (auto j = oldHashTable[i].begin(); j != oldHashTable[i].end(); j++) {
            insert(*j);
        }
    }
}

template <typename T>
int HashTable<T>::getSize() {
    return numEntries;
}
