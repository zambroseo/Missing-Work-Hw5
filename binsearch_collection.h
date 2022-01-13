# ifndef BINSEARCH_COLLECTION_H
# define BINSEARCH_COLLECTION_H

# include <iostream>
# include <vector>
# include <algorithm>
# include <iostream>
# include "collection.h"

template <typename K, typename V>
class BinSearchCollection : public Collection <K ,V >
{
 public :

// insert a key - value pair into the collection
void insert(const K& key , const V& val);

// remove a key - value pair from the collection
void remove(const K& key);

// find and return the value associated with the key
bool find(const K& key , V& val) const ;

// find and return the list of keys >= to k1 and <= to k2
void find(const K& k1 , const K& k2 , std :: vector <K >& keys) const ;

// return all of the keys in the collection
void keys(std :: vector <K >& keys) const ;

// return all of the keys in ascending ( sorted ) order
void sort(std :: vector <K >& keys) const ;

// return the number of keys in collection
int size() const ;

 private :

// helper function for binary search
bool binsearch(const K& key , int& index) const ;

// vector storage
std :: vector <std::pair<K ,V>> kv_list ;

};


template<typename K, typename V>
void BinSearchCollection<K, V>::sort(std::vector<K>& keys) const
{
 keys=keys;
}

template<typename K, typename V>
void BinSearchCollection<K, V>::keys(std::vector<K>& keys) const
{
 for(int i=0;i<kv_list.size();++i)
 {
  keys.push_back(kv_list[i].first);
 }
}

template<typename K, typename V>
int BinSearchCollection<K, V>::size() const
{
 return kv_list.size();
}

// This function returns true and sets index if key is found in
// kv_list , and returns false and sets index to where key should go in
// kv_list otherwise . If list is empty , index is unchanged .
template <typename K, typename V >
bool BinSearchCollection <K ,V >:: binsearch(const K& key , int& index ) const
{
 int max=kv_list.size() - 1;
 int min=0;
 int mid=0;
 bool TF = false;

 if(kv_list.size() == 0)
   return TF;

 while(min <= max)
 {
  mid=(max + min)/2;
  if(kv_list[mid].first == key)
  {
   index=mid;
   TF=true;
   break;
  }
  else if(kv_list[mid].first < key){
   min=mid + 1;
  }
  else if(kv_list[mid].first > key) {
   max=mid - 1;
  }
 }
 index=mid;
 return TF;
}

template<typename K, typename V>
void BinSearchCollection<K, V>::insert(const K& key, const V& val)
{
 std::pair<K, V> p(key, val);
 int i=0;

 if(kv_list.size() == 0)
 {
   kv_list.insert(kv_list.begin(), p);
 }

 else
 {
  bool TF = binsearch(p.first, i);
  kv_list.insert(kv_list.begin() + i+1, p);
 }
}

template<typename K, typename V>
void BinSearchCollection<K, V>::remove(const K& key)
{
 int del;
 bool TF = binsearch(key, del);
 if(TF)
  kv_list.erase(kv_list.begin()+del);
}

template<typename K, typename V>
bool BinSearchCollection<K, V>::find(const K& key, V& val) const
{
 int fval;
 bool TF = binsearch(key, fval);

 if(TF == false)
 {
  val = fval;
  return false;
 }
 val = kv_list[fval].second;
 return TF;
}

template<typename K, typename V>
void BinSearchCollection<K, V>::find(const K& k1, const K& k2, std::vector<K>& keys) const
{
 int k1val, k2val;
 bool TF1 = binsearch(k1, k1val);
 bool TF2 = binsearch(k2, k2val);

 if(TF1 == true && TF2 == true)
 {
  while(k1val <= k2val)
  {
   keys.push_back(kv_list[k1Val].first);
   k1val++;
  }
 }
}

#endif
