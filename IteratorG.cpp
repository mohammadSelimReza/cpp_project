#include "IteratorG.h"

template<typename K, typename V>
IteratorG<K, V>::IteratorG(DNodeG<K, V> *u): v(u) {}

template<typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator++() {
    v = v->next;
    return *this;
}

template<typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator--() {
    v = v->prev;
    return *this;
}

template<typename K, typename V>
Entry<K, V>& IteratorG<K, V>::operator*() const {
    return v->elm;
}

template<typename K, typename V>
bool IteratorG<K, V>::operator==(const IteratorG<K, V> &p) const {
    return v == p.v;
}

template<typename K, typename V>
bool IteratorG<K, V>::operator!=(const IteratorG<K, V> &p) const {
    return v != p.v;
}
