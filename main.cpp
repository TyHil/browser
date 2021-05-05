/*
This is the main file.
*/
#include <iostream> //cout, cin
#include <stdlib.h> //system
#include <string> //string
#include <fstream> //ifstream file response
int main() {
  /*Load HTML*/
  std::cout << "URL: ";
  std::string url;
  std::cin >> url;
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
  std::cout << response;
}