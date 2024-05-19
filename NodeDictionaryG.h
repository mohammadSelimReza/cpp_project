#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "MapG.h"
#include "DNodeG.h"
#include "Entry.h"
#include "Range.h"
#include "IteratorG.h"

template <typename K, typename V>
class NodeDictionaryG: public MapG<IteratorG<K,V>, K, V> {
public:
    NodeDictionaryG();
    virtual ~NodeDictionaryG();

    int size() const; 
    int uniqueKeys() const; 
    bool empty() const; 
    IteratorG<K,V> begin() const; 
    IteratorG<K,V> end() const; 
    IteratorG<K,V> find(const K& k) const; 
    Range<K, V> findAll(const K& k) const;
    IteratorG<K,V> put(const K& k, const V& v); 
    void erase(const K& k); 
    void erase(const IteratorG<K,V>& p); 
    void print(bool fromFront = true);

private:
    int n; 
    DNodeG<K,V>* header; 
    DNodeG<K,V>* trailer; 
};

#include "NodeDictionaryG.cpp"

#endif
