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

void searchUI() {
  std::string url;
  std::cout << "Enter URL: ";
  std::cin >> url;
  std::string response = loadHTML(url);
  std::cout << response;
}

void bookmarkUI() {
  std::string url;
  std::cout << "Enter Bookmark URL: ";
  std::cin >> url;
  bookmarkTrees bookmarks;
  bookmarks.insert(bookmarks.root, url);
  bookmarks.remove(url);
}

int main() {
  linkedList<tab> * tabs = new linkedList<tab>();
  std::cout << "Welcome to B.R.O.W.S.E.R!:\nType 'search' to load a url\n Type 'newTab' to create a new tab\n   (Type 'back' to go back one tab)\n   (Type 'forward' to go forward one tab)\n   (type 'close' to close a tab)\nType 'bookmark' to create a new bookmark\nType 'exit' to end the program";
  std::string command;
  std::cin >> command;
  bool running = true;
  while (running) {}
    if (command.compare("search") == 0) {
      searchUI();
    }
    if (command.compare("newTab")==0){
      tab * newTab = new tab();
      std::string url;
      std::string response;
      std::cout << "Enter New Tab URL: ";
      newTab->url = url;
      newTab->content = response;
      tabs->add(newTab);
    }
    if (command.compare("bookmark")==0) {
      bookmarkUI();
    }
    if (command.compare("exit")==0) {
      std::cout << "Goodbye. My brief life will now end. :(";
      running = false;
    }
    std::cin >> command;
  }
}
