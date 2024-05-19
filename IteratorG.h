#ifndef ITERATORG_H_
#define ITERATORG_H_

#include "DNodeG.h"

template <typename K, typename V>
class IteratorG {
public:
    IteratorG(DNodeG<K,V>* u);
    IteratorG<K,V>& operator++();
    IteratorG<K,V>& operator--();
    Entry<K,V>& operator*() const;
    bool operator==(const IteratorG<K,V>& p) const;
    bool operator!=(const IteratorG<K,V>& p) const;

    friend class NodeDictionaryG<K,V>;

private:
    DNodeG<K,V>* v;
};

#include "IteratorG.cpp"
#endif
