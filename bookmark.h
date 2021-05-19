#ifndef BOOKMARK_H
#define BOOKMARK_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key_value;
    struct Node *p_left;
    struct Node *p_right;
};

class bookmarkTrees
{
public:
	Node* root;
	vector<string> urlVec;
	int vectorInd = 0;
	int urlToBookmarkIndex(string);
	string indexToUrl(int);
        void find(int, Node **, Node **);    
        void insert(Node *, int);
        void remove(string);
        void case_0(Node *, Node *);
        void case_1(Node *, Node *);
        void case_2(Node *, Node *);
        bookmarkTrees()
        {
            root = NULL;
        }
};


#endif
