template<typename K, typename V>
Entry<K, V>::Entry(const K &k, const V &v): _key(k), _value(v) {}

template<typename K, typename V>
const K& Entry<K, V>::getK() const {
    return _key;
}

template<typename K, typename V>
const V& Entry<K, V>::getV() const {
    return _value;
}

template<typename K, typename V>
void Entry<K, V>::setK(const K &k) {
    _key = k;
}

template<typename K, typename V>
void Entry<K, V>::setV(const V &v) {
    _value = v;
}
