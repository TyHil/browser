#ifndef BSTREE_H
#define BSTREE_H

struct node
{
    int key_value;
    struct node *p_left;
    struct node *p_right;
};

class bookmarkTrees
{
public:
	node* root;
	vector<string> urlVec;
	int vectorInd = 0;
	int urlToBookmarkIndex(string url);
	string indexToUrl(int i);
        void find(int, node **, node **);    
        void insert(node *, node *);
        void remove(int);
        void case_0(node *,node *);
        void case_1(node *,node *);
        void case_2(node *,node *);
        // void display(node *, int);
        BST()
        {
            root = NULL;
        }
};


#endif
