#include "Range.h"

template<typename K, typename V>
Range<K, V>::Range(IteratorG<K, V> start, IteratorG<K, V> finish): first(start), second(finish) {}
