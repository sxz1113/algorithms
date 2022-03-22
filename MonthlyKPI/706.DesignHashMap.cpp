#include "../Common.h"


class MyHashMap {
/**
 * Ref: 1. https://www.programiz.com/dsa/hash-table
 *      2. https://www.cs.purdue.edu/cgvlab/courses/251/lectures/slides/03.01-HashTables.pdf
 */
public:
    MyHashMap() {
        // init key value pairs
        for (int i = 0; i < size; ++i) {
            buckets[i] = NULL;
        }
    }

    void put(int key, int value) {
        int i = hash(key);
        Bucket *node = buckets[i];
        // check if key already exists in the map
        while (node) {
            if (node->k == key) {
                // update value if key DOES exist
                node->v = value;
                return;
            }
            node = node->next;
        }

        Bucket *head = new Bucket(key, value, buckets[i]);
        buckets[i] = head;
    }
    
    int get(int key) {
        int i = hash(key);
        Bucket *node = buckets[i];
        while (node) {
            if (node->k == key)
                return node->v;

            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int i = hash(key);
        Bucket *node = buckets[i];
        if (!node)
            return;

        if (node && node->k == key) {
            buckets[i] = node->next;
            delete node;
            return;
        }

        Bucket *tmp;
        while (node->next) {
            if (node->next->k == key) {
                tmp = node->next;
                node->next = tmp->next;
                delete tmp;
                return;
            }
            node = node->next;
        }
    }

private:
    const static int size = 10000;
    Bucket *buckets[size];

    // linear probing
    int hash(int i) {
        return i % size;
    }
};

struct Bucket {
    int k;
    int v;
    Bucket *next;
    Bucket() : k(0), v(0), next(nullptr) {}
    Bucket(int key, int value) : k(key), v(value), next(nullptr) {}
    Bucket(int key, int value, Bucket* next) : k(key), v(value), next(next) {}
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */