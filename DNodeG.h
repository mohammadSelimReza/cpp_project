#ifndef DNODEG_H_
#define DNODEG_H_

#include "Entry.h"

template <typename K, typename V>
struct DNodeG {
    Entry<K,V> elm;
    DNodeG* prev;
    DNodeG* next;
};

#endif
