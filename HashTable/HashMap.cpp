#include "HashMap.h"
#include <string>
#include <functional>
#include <cmath>
#include <iostream>

// constructor
template<class Key, class Value>
HashMap<Key, Value>::HashMap(int size) {
  count = 0;
  numBuckets = size;
  buckets = new Node* [numBuckets];
  for (int i = 0; i < numBuckets; ++i) buckets[i] = NULL;
}

template<class Key, class Value>
HashMap<Key, Value>::~HashMap() {
  for (int i = 0; i < numBuckets; ++i) {
    Node *curr = buckets[i];

    while (curr != NULL) {
      Node *next = curr->next;
      delete curr;
      curr = next;
    }
  }
}

template<class Key, class Value>
int HashMap<Key, Value>::hash(const Key& key) const {
  std::hash<Key> hashObject; // built in C++ function <functional>
  return std::abs(static_cast<int>(hashObject(key)))%numBuckets;
}

template<class Key, class Value>
void HashMap<Key, Value>::put(const Key& key, const Value& value) {
  ensureNodeExists(key)->value = value;
}

template<class Key, class Value>
const typename HashMap<Key, Value>::Node* HashMap<Key, Value>::findNode(const Key &key) const {
  const Node *curr = buckets[hash(key)];

  while (curr != NULL) {
    if (curr->key != key)
      curr = curr->next;
    else
      break;
  }
  
  return curr;
}

template<class Key, class Value>
typename HashMap<Key, Value>::Node* HashMap<Key, Value>::ensureNodeExists(const Key& key) {
  Node *found = const_cast<Node*> (findNode(key));

  if (found == NULL) {
    found = new Node();
    found->key = key;

    // calculate #HashCode to point to correct Bucket
    int hashCode = hash(key);
    //
    found->next = buckets[hashCode];
    buckets[hashCode] = found;

    count++;
  }

  return found;
}

template<class Key, class Value>
Value& HashMap<Key, Value>::operator[](const Key& key) {
  Node *found = const_cast<Node*> (findNode(key));

  if (found != NULL)
    return found->value;
  else {
    Value value;
    return static_cast<Value&> (value);
  }
}

template<class Key, class Value>
bool HashMap<Key, Value>::containsKey(const Key& key) {
 return (findNode(key) != NULL);
}
