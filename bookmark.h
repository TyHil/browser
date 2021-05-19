#ifndef BOOKMARK_H
#define BOOKMARK_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <typename T> struct Node
{
    int key_value;
    struct Node<T> *p_left;
    struct Node<T> *p_right;
};

template <typename T> class bookmarkTrees
{
public:
	Node<T>* root;
	vector<string> urlVec;
	int vectorInd = 0;
	int urlToBookmarkIndex(string);
	string indexToUrl(int);
        void find(int, T **, T **);    
        void insert(T *, int);
        void remove(string);
        void case_0(T *, T *);
        void case_1(T *, T *);
        void case_2(T *, T *);
        BST()
        {
            root = NULL;
        }
};


#endif
