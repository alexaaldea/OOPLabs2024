template<typename K, typename V>
class Map {
private:
    struct MapItem {
        int index;
        K key;
        V value;
    };

    MapItem items[100];
    int nrElemente = 0;

public:
    Map() : nrElemente(0) {}

    int Count() {
        return this->nrElemente;
    }

    void Clear() {
        nrElemente = 0;
    }

    bool Get(const K& key, V& value) {
        for (int i = 0; i < nrElemente; i++) {
            if (items[i].key == key) {
                value = items[i].value;
                return true;
            }
        }
        return false;
    }

    void Set(const K key, V value) {
        for (int i = 0; i < nrElemente; i++) {
            if (items[i].key == key) {
                items[i].value = value;
                return;
            }
        }
        items[nrElemente] = { nrElemente, key, value };
        nrElemente++;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < nrElemente; i++) {
            if (items[i].key == key) {
                for (int j = i + 1; j < nrElemente; j++)
                    items[j - 1] = items[j];
                nrElemente--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map) {
        if (map.nrElemente > nrElemente)
            return false;
        for (int i = 0; i < map.nrElemente; i++) {
            bool found = false;
            for (int j = 0; j < nrElemente; j++) {
                if (map.items[i].key == items[j].key) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }

    class Iterator {
    private:
        const Map<K, V>& map;
        int index;

    public:
        Iterator(const Map<K, V>& m, int i) : map(m), index(i) {}

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        void operator++() {
            ++index;
        }

        struct Entry {
            K key;
            V value;
            int index;
        };

        Entry operator*() const {
            return { map.items[index].key, map.items[index].value, index };
        }
    };

    Iterator begin() const {
        return Iterator(*this, 0);
    }

    Iterator end() const {
        return Iterator(*this, nrElemente);
    }

    V& operator[](K key) {
        for (int i = 0; i < nrElemente; i++) {
            if (key == items[i].key)
                return items[i].value;
        }
        items[nrElemente].index = nrElemente;
        items[nrElemente].key = key;
        nrElemente++;
        return items[nrElemente - 1].value;
    }

    bool operator!=(const Map<K, V>& map) {
        if (nrElemente != map.nrElemente)
            return true;
        for (int i = 0; i < nrElemente; i++) {
            if (items[i].key != map.items[i].key || items[i].value != map.items[i].value)
                return true;
        }
        return false;
    }
};
