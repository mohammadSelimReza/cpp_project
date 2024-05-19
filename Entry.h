#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>

template <typename K, typename V>
class Entry {
public:
    Entry(const K& k = K(), const V& v = V());
    const K& getK() const;
    const V& getV() const;
    void setK(const K& k);
    void setV(const V& v);

    friend std::ostream& operator<<(std::ostream& os, const Entry& entry) {
        os << "{" << entry._key << " ; " << entry._value << "}";
        return os;
    }

private:
    K _key;
    V _value;
};

#include "Entry.cpp"

#endif