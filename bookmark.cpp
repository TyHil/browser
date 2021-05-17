#include <iostream>
#include <cstdlib>
#include "bookmark.h"

using namespace std;

int bookmarkTrees::urlToBookmarkIndex(string url){
	urlVec[vectorInd] = url;
	vectorInd++;
	return vectorInd - 1;
}

string bookmarkTrees::indexToUrl(int i){
	return urlVec[i];
}

void bookmarkTrees::find(int item_key, node **prnt, node **loc)
{
    node *ptr, *ptrsave;
    if (root == NULL)
    {
        *loc = NULL;
        *prnt = NULL;
        return;
    }
    if (item_key == root->key_value)
    {
        *loc = root;
        *prnt = NULL;
        return;
    }
    if (item_key < root->key_value)
        ptr = root->p_left;
    else
        ptr = root->p_right;
    ptrsave = root;
    while (ptr != NULL)
    {
        if (item_key == ptr->key_value)
        {
            *loc = ptr;
            *prnt = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item_key < ptr->key_value)
            ptr = ptr->p_left;
	else
	    ptr = ptr->p_right;
    }
    *loc = NULL;
    *prnt = ptrsave;
}

// newnode's key is the index in the array of URLs
void bookmarkTrees::insert(node *tree, string urlToInsert)
{
	node *newnode;
	int newnode_key = urlToBookmarkIndex(urlToInsert);
	newnode->key_value = newnode_key;
    if(root == nullptr)
    {
        root = newnode;
        return;
    }
    if(tree->key_value == newnode->key_value)
    {
        return;
    }
    if(newnode->key_value < tree->key_value)
    {
        if(tree->p_left != nullptr)
        {
            insert(tree->p_left, newnode);
      	}
      	else
      	{
            tree->p_left = newnode;
            return;
        }
    }
    else
    {
        if(tree->p_right != nullptr)
        {
             insert(tree->p_right, newnode);
        }
        else
        {
            tree->p_right = newnode;
            return;
        }	
    }
}

void bookmarkTrees::remove(string urlToRemove)
{
	int item = urlToBookmarkIndex(urlToRemove);
    node *parent, *location;
    if (root == NULL)
    {
        cout<<"Tree empty"<<endl;
        return;
    }
    find(item, &parent, &location);
    if (location == NULL)
    {
        cout<<"Item not present in tree"<<endl;
        return;
    }
    if(location->p_left == nullptr && location->p_right == nullptr){
        case_0(parent, location);
    }
    else if(location->p_left != nullptr && location->p_right == nullptr){
        case_1(parent, location);
    }
    else if(location->p_right != nullptr && location->p_left == nullptr){
        case_1(parent, location);
    }
   else{
        case_2(parent, location);
   }
}

// Case 0: node is removed, no other updates
void bookmarkTrees::case_0(node *prnt, node *loc )
{
    if(loc == root)
    {
        root = nullptr;
    }
    else
    {
      if(prnt->p_left == loc){
        prnt->p_left = nullptr;
      }
      else{
        prnt->p_right = nullptr;
      }
    }
    free(loc);
}

// Case 1: one child so promote the child and replace the node to delete
void bookmarkTrees::case_1(node *prnt, node *loc)
{
    node *child;
    if(loc->p_left != nullptr){
      child = loc->p_left;
    }
    else{
      child = loc->p_right;
    }
    if(loc == root)
    {
       root = child;
    }
    else
    {
        if(prnt->p_left == loc){
          prnt->p_left = child;
        }
        else{
          prnt->p_right = child;
        }
    }
    free(loc);
}

// Case 2: find and promote a successor or predecessor
void bookmarkTrees::case_2(node *prnt, node *loc)
{
    node* successor;
    node* prnt_s;
    successor = loc->p_right;
    prnt_s = loc;
    while(successor != nullptr && successor->p_left != nullptr){
      prnt_s = successor;
      successor = successor->p_left;
    }
	
    if(successor->p_left == nullptr && successor->p_right == nullptr){
      loc->key_value = successor->key_value;
      case_0(prnt_s, successor);
      
    }
    else{
        loc->key_value = successor->key_value;
        case_1(prnt_s, successor);
    }
    
    if(loc == root)
    {
        root = successor;
    }
    else
    {
        loc = successor;
    }
	
    successor->p_right = loc->p_right;
    successor->p_left = loc->p_left;
}

/*
void bookmarkTrees::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->p_right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	      }
        cout<<ptr->key_value;
        display(ptr->p_left, level+1);
    }
}
*/
