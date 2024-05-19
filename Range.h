#ifndef RANGE_H_
#define RANGE_H_

#include "IteratorG.h"

template <typename K, typename V>
class Range {
public:
    Range(IteratorG<K,V> start, IteratorG<K,V> finish);
    IteratorG<K,V> first;
    IteratorG<K,V> second;
};

#include "Range.cpp"
#endif
