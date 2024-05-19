#ifndef MAPG_H_
#define MAPG_H_

#include "Entry.h"

template <typename K, typename V>
class MapG {
public:
    virtual ~MapG() {}
    virtual int size() const = 0;
    virtual bool empty() const = 0;
    virtual Entry<K,V>* find(const K& k) const = 0;
    virtual void put(const K& k, const V& v) = 0;
    virtual void erase(const K& k) = 0;
};

#endif
