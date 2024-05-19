template <typename K, typename V>
NodeDictionaryG<K, V>::NodeDictionaryG()
{
    n = 0;
    header = new DNodeG<K, V>;
    trailer = new DNodeG<K, V>;
    header->next = trailer;
    trailer->prev = header;
}

template <typename K, typename V>
NodeDictionaryG<K, V>::~NodeDictionaryG()
{
    while (!empty())
    {
        erase(begin());
    }
    delete header;
    delete trailer;
}

template <typename K, typename V>
int NodeDictionaryG<K, V>::size() const
{
    return n;
}

template <typename K, typename V>
int NodeDictionaryG<K, V>::uniqueKeys() const
{
    if (empty())
    {
        return 0;
    }

    int count = 1;
    IteratorG<K, V> current = begin();

    while (current != end())
    {
        IteratorG<K, V> next = current;
        ++next;

        if (next != end() && current.v->elm.getK() != next.v->elm.getK())
        {
            ++count;
        }

        ++current;
    }

    return count;
}

template <typename K, typename V>
bool NodeDictionaryG<K, V>::empty() const
{
    return n == 0;
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::begin() const
{
    return IteratorG<K, V>(header->next);
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::end() const
{
    return IteratorG<K, V>(trailer);
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::find(const K &k) const
{
    IteratorG<K, V> p(begin());
    for (; p != end(); ++p)
        if (p.v->elm.key() == k)
            return p;
    return end();
}

template <typename K, typename V>
Range<K, V> NodeDictionaryG<K, V>::findAll(const K &k) const
{
    IteratorG<K, V> start = end();
    IteratorG<K, V> finish = end();
    bool found = false;

    for (IteratorG<K, V> p = begin(); p != end(); ++p)
    {
        if (p.v->elm.key() == k)
        {
            if (!found)
            {
                start = p;
                found = true;
            }
            finish = p;
        }
    }

    return Range<K, V>(start, ++finish);
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::put(const K &k, const V &v)
{
    IteratorG<K, V> p = find(k);
    if (p == end())
    {
        DNodeG<K, V> *w = trailer;
        DNodeG<K, V> *u = w->prev;
        DNodeG<K, V> *new_node = new DNodeG<K, V>;
        new_node->elm.setK(k);
        new_node->elm.setV(v);
        new_node->next = w;
        w->prev = new_node;
        new_node->prev = u;
        u->next = new_node;
        n++;
        return IteratorG<K, V>(new_node);
    }
    else
    {
        while (p.v->next != trailer && p.v->next->elm.key() == k)
        {
            ++p;
        }
        DNodeG<K, V> *w = p.v->next;
        DNodeG<K, V> *u = p.v;
        DNodeG<K, V> *new_node = new DNodeG<K, V>;
        new_node->elm.setK(k);
        new_node->elm.setV(v);
        new_node->next = w;
        w->prev = new_node;
        new_node->prev = u;
        u->next = new_node;
        n++;
        return IteratorG<K, V>(new_node);
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(const K &k)
{
    IteratorG<K, V> p = begin();
    while (p != end())
    {
        if (p.v->elm.key() == k)
        {
            erase(p);
            p = begin();
        }
        else
        {
            ++p;
        }
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(const IteratorG<K, V> &p)
{
    DNodeG<K, V> *v = p.v;
    DNodeG<K, V> *w = v->next;
    DNodeG<K, V> *u = v->prev;
    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::print(bool fromFront)
{
    if (fromFront)
    {
        print(header->next);
    }
    else
    {
        print(trailer->prev);
    }
}
