#ifndef HASH_MAP_H
#define HASH_MAP_H

template<class Key, class Value>
class HashMap {
  public:
  HashMap(int size=10000);
  ~HashMap();

  bool isEmpty() const { return size() == 0; }
  int size() const { return count; }
  bool containsKey(const Key&);

  // method to insert new Key to HashMap
  void put(const Key&, const Value&);
  Value& operator[](const Key&);

  private:

  struct Node {
    Key key;
    Value value;
    Node *next;
  };

  int numBuckets;
  Node **buckets;
  int count;
  int hash(const Key&) const;
  Node *ensureNodeExists(const Key&);
  const Node *findNode(const Key&) const;
};

#endif
