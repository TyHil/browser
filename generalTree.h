#include "linkedList.h"

/*Node*/

template <typename T> struct treeNode {
  ~treeNode();
  T * dataPtr;
  linkedList<treeNode<T>> * nodes;
};
template <typename T> treeNode<T>::~treeNode() { //Destructor
  delete dataPtr;
  delete nodes;
}

/*Tree*/

template <typename T> class generalTree {
  public:
    linkedList<treeNode<T>> * root;
    generalTree();
    ~generalTree();
    void clear(linkedList<treeNode<T>> ** from);
    void add(int dir[], int depth, T * newData);
    treeNode<T> * get(int dir[], int depth);
    void set(int dir[], int depth, T * newData);
    void insert(int dir[], int depth, T * newData);
    void remove(int dir[], int depth);
    bool isEmpty();
    void swap(int dir1[], int depth1, int dir2[], int depth2);
};

template <typename T> generalTree<T>::generalTree() { //Constructor
  root = nullptr;
}

template <typename T> generalTree<T>::~generalTree() { //Destructor
  clear(&root);
}

template <typename T> void generalTree<T>::clear(linkedList<treeNode<T>> ** from) { //Clears and deletes all nodes and data inside the given list
  delete *from;
  *from = nullptr;
}

template <typename T> void generalTree<T>::add(int dir[], int depth, T * newData) { //Adds a new node with specified data to the end of the linked list found by the specified direction
  linkedList<treeNode<T>> ** i = &root;
  if (*i == nullptr) {
    *i = new linkedList<treeNode<T>>();
  }
  for (int j = 0; j < depth; j++) {
    i = &(*i)->get(dir[j])->dataPtr->nodes;
    if (*i == nullptr) {
      *i = new linkedList<treeNode<T>>();
    }
  }
  treeNode<T> * newNode = new treeNode<T>;
  newNode->dataPtr = newData;
  (*i)->add(newNode);
}

template <typename T> treeNode<T> * generalTree<T>::get(int dir[], int depth) { //Returns a pointer to the node at the specified direction
  linkedList<treeNode<T>> * temp = root;
  for (int i = 0; i < depth - 1; i++) {
    temp = temp->get(dir[i])->dataPtr->nodes;
  }
  return temp->get(dir[depth - 1])->dataPtr;
}

template <typename T> void generalTree<T>::set(int dir[], int depth, T * newData) { //Replaces the data of node at the specified direction with new data
  treeNode<T> * i = get(dir, depth);
  delete i->dataPtr;
  i->dataPtr = newData;
}

template <typename T> void generalTree<T>::insert(int dir[], int depth, T * newData) { //Inserts a new node and new data in the linked list specified by the direction and before the last index
  linkedList<treeNode<T>> ** i = &root;
  if (*i == nullptr) {
    *i = new linkedList<treeNode<T>>();
  }
  for (int j = 0; j < depth - 1; j++) {
    i = &(*i)->get(dir[j])->dataPtr->nodes;
    if (*i == nullptr) {
      *i = new linkedList<treeNode<T>>();
    }
  }
  treeNode<T> * newNode = new treeNode<T>;
  newNode->dataPtr = newData;
  (*i)->insert(dir[depth - 1], newNode);
}

template <typename T> void generalTree<T>::remove(int dir[], int depth) { //Removes the node and data at the specified direction
  linkedList<treeNode<T>> * temp = root;
  for (int i = 0; i < depth - 1; i++) {
    temp = temp->get(dir[i])->dataPtr->nodes;
  }
  temp->remove(dir[depth - 1]);
}

template <typename T> bool generalTree<T>::isEmpty() { //Returns true if the generalTree has no elements in it
  return root == nullptr;
}

template <typename T> void generalTree<T>::swap(int dir1[], int depth1, int dir2[], int depth2) { //Switches the data pointers of the nodes at the specified directions
  treeNode<T> * i = get(dir1, depth1);
  treeNode<T> * j = get(dir2, depth2);
  T * temp = i->dataPtr;
  i->dataPtr = j->dataPtr;
  j->dataPtr = temp;
}
