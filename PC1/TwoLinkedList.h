//
// Created by ruben on 4/12/19.
//

#ifndef PC1_TWOLINKEDLIST_H
#define PC1_TWOLINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

namespace UTEC {
  struct Node {
	int value;
	Node *next;
	Node(const int &value) : value(value), next(nullptr) { }
  };


  class TwoLinkedList {
	public:
	  TwoLinkedList();
	  ~TwoLinkedList();
	  void push_back1(int value);
	  void push_back2(int value);
	  std::string merge(int value);
	  bool is_merged();
	  std::string getlist(unsigned int v);
	  Node *search(int value);
	  void save(std::string out);
	  void load(std::string in);

	private:
	  Node *head1, *head2;
	  Node *tail1, *tail2;
	  Node *tail;
	  bool merged = false;
	  int count1 = 0, count2 = 0;
  };
}


#endif //PC1_TWOLINKEDLIST_H
