/*
This is the main file.
*/
#include <iostream> //cout, cin
#include <stdlib.h> //system
#include <string> //string
#include <fstream> //ifstream file response
#include "linkedList.h"
#include "bookmark.h"

struct tab {
  std::string url;
  std::string content;
};

std::string loadHTML(std::string url) {
  url = "curl -o data.txt " + url;
  system(url.c_str());
  system("clear");
  std::ifstream file("data.txt");//Retrieving response from data.txt
  std::string response;
  std::string res;
  while (std::getline(file, res)) {
    response += res;
  }
  file.close(); 
  remove("data.txt");
  return response;
}

int main() {
  linkedList<tab> * tabs = new linkedList<tab>();
  std::cout << "URL: ";
  std::string url;
  std::cin >> url;
  std::string response = loadHTML(url);
  std::cout << response;
  tab * newTab = new tab();
  newTab->url = url;
  newTab->content = response;
  tabs->add(newTab);
  
  bookmarkTrees bookmarks;
  bookmarks.insert(bookmarks.root, url);
  bookmarks.remove(url);
}
