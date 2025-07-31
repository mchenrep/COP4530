#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include "hashtable.h"
#include <vector>
#include <list>
#include <utility>
#include <fstream>
#include <iostream>
#include <crypt.h>

using namespace std;
using namespace cop4530;

// CONSTRUCTORS/DESTRUCTORS ------------------------------------------------------------------------
template <typename K, typename V>
HashTable<K,V>::HashTable(size_t size): si{0}
{
  lst.resize(prime_below(size));
  si = lst.size();
}

template <typename K, typename V>
HashTable<K, V>::~HashTable(){
  clear();
}

// FUNCTIONS ---------------------------------------------------------------------------------------

template <typename K, typename V>
bool HashTable<K, V>::contains(const K & k) const
{
  auto &lt = lst[myhash(k)];
  for(auto &i: lt)
  {
    if(i.first == k)
      return true;
  }
  return false;
}

template <typename K, typename V>
bool HashTable<K, V>::match(const pair<K, V> &kv) const
{
  auto &wl = lst[myhash(kv.first)];
  for(const auto &i : wl)
  {
    if(i == kv)
      return true;
  }
  return false;
}

template <typename K, typename V>
bool HashTable<K, V>::insert(const pair<K, V> & kv)
{
  auto &wl = lst[myhash(kv.first)];
  for(auto &i : wl)
  {
    if(i.first == kv.first)
    {
      if(i.second == kv.second)
        return false;
      i.second = kv.second; // change password
      return true;
    }
  }
  wl.push_back(kv);
  if(++si > lst.size())
    rehash();
  return true;
}

template <typename K, typename V>
bool HashTable<K, V>::insert(pair<K, V> && kv)
{
  auto &wl = lst[myhash(kv.first)];
  for(auto &i : wl)
  {
    if(i.first == kv.first)
    {
      if(i.second == kv.second)
        return false;
      i.second = kv.second; // change password
      return true;
    }
  }
  wl.push_back(move(kv));
  if(++si > lst.size())
    rehash();
  return true;
}

template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k)
{
  auto &wl = lst[myhash(k)];

  auto itr = wl.begin();
  while (itr != wl.end()) {
    if (itr->first == k) {
      wl.erase(itr);
      si--;
      return true;
    }
  }

  return false;
}

template <typename K, typename V>
void HashTable<K, V>::clear()
{
  makeEmpty();
}

template <typename K, typename V>
bool HashTable<K, V>::load(const char *filename)
{
  ifstream filein(filename);
  if(!filein)
  {
    return false; 
  }

  K key;
  V value;
  while(filein >> key >> value)
  {
    pair<K,V> kv(key, value);
    insert(kv);
  }
  filein.close();
  return true;
}

template <typename K, typename V> 
void HashTable<K, V>::dump() const
{
  for(size_t i = 0; i < lst.size(); ++i)
  {
    cout<<"v["<<i<<"]: ";
    if(!lst[i].empty())
    {
      auto itr = lst[i].begin();
      while(itr != lst[i].end())
      {
        cout<<itr->first<<" "<<itr->second;
        if(itr != lst[i].end())
          cout<<" : ";
        ++itr;
      }
    }
    cout<<"\n";
  }
}

template <typename K, typename V>
size_t HashTable<K, V>::size() const
{
  return si;
}

template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename) const
{
  ofstream fileout(filename);
  if(!fileout)
    return false;
  
  for(const auto &b: lst)
  {
    for(const auto &i: b)
      fileout << i.first <<" "<<i.second<<"\n";
  }

  fileout.close();
  return true;
}

// PRIVATE FUNCTIONS -----------------------------{--------------------------------------

template <typename K, typename V>
void HashTable<K, V>::makeEmpty()
{
  lst.clear();
  si = 0;
}

template <typename K, typename V>
void HashTable<K, V>::rehash()
{
  vector<pair<K,V>> temp;
  for(const auto &b : lst)
  {
    for(const auto &kv: b)
      temp.push_back(kv);
  }
  
  size_t newSize = prime_below(2*si);
  lst.clear();
  si = 0;
  lst.resize(newSize);
  for(const auto &kv: temp)
    insert(kv);
}

template <typename K, typename V>
size_t HashTable<K, V>::myhash(const K &k) const
{
  static hash<K> hashFunction;
  size_t hashValue = hashFunction(k);
  return hashValue % lst.size();
}

template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n
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
  std::vector<unsigned long> v(n+1);
  setPrimes(v);
  while (n > 2)
    {
      if (v[n] == 1)
	return n;
      --n;
    }

  return 2;
}

template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes) //Sets all prime number indexes to 1. Called by method prime_below(n) 
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

#endif

