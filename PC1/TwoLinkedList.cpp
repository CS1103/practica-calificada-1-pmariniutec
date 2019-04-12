//
// Created by ruben on 4/12/19.
//

#include "TwoLinkedList.h"

namespace UTEC {

  TwoLinkedList::TwoLinkedList() {
	head1 = head2 = tail1 = tail2 = tail = nullptr;
  }

  TwoLinkedList::~TwoLinkedList() {
	if (head1 != nullptr) {
	  Node *next = head1;
	  Node *cur = nullptr;
	  while (next != nullptr) {
		cur = next;
		next = next->next;
		delete cur;
	  }
	}

	int count = 0;
	if (head2 != nullptr) {
	  Node *next = head2;
	  Node *cur = nullptr;
	  while (next != nullptr && count < count2) {
		cur = next;
		next = next->next;
		delete cur;
		count++;
	  }
	}

  }

  void TwoLinkedList::push_back1(int value) {
	Node *tmp = new Node(value);
	if (merged) {
	  tail->next = tmp;
	  tail = tmp;
	} else {
	  if (head1 != nullptr) {
		tail1->next = tmp;
		tail1 = tmp;
	  } else {
		tail1 = tmp;
		head1 = tmp;
	  }
	  count1++;
	}
  }

  void TwoLinkedList::push_back2(int value) {
	Node *tmp = new Node(value);
	if (merged) {
	  tail->next = tmp;
	  tail = tmp;
	} else {
	  if (head2 != nullptr) {
		tail2->next = tmp;
		tail2 = tmp;
	  } else {
		tail2 = tmp;
		head2 = tmp;
	  }
	  count2++;
	}
  }

  std::string TwoLinkedList::merge(int value) {
	if (merged) return "Operación duplicada";
	Node *tmp = new Node(value);
	tail = tmp;
	tail1->next = tmp;
	tail2->next = tmp;
	merged = true;
	return "Operación Exitosa";
  }

  bool TwoLinkedList::is_merged() {
	return merged;
  }

  std::string TwoLinkedList::getlist(unsigned int v) {
	std::string f = "";
	Node *curr;
	int count = 0;
	if (v == 0) {
	  if (!merged) return "";
	  curr = head1;
	  for (int i = 0; i < count1; ++i) {
		curr = curr->next;
	  }
	  while (curr) {
		f += std::to_string(curr->value);
		f += " ";
		curr = curr->next;
	  }
	} else if(v == 1) {
	  curr = head1;
	  while (curr && count <= count1) {
		f += std::to_string(curr->value);
		f += " ";
		curr = curr->next;
		count++;
	  }
	} else if(v == 2) {
	  curr = head2;
	  while (curr && count <= count2) {
		f += std::to_string(curr->value);
		f += " ";
		curr = curr->next;
		count++;
	  }
	}
	return f;
  }

  Node *TwoLinkedList::search(int value) {
	Node *tmp = head1;
	while (tmp != nullptr) {
	  if (tmp->value == value) {
		return tmp;
	  }
	  tmp = tmp->next;
	}
	tmp = head2;
	int counter = 0;
	while (tmp != nullptr) {
	  if (counter >= count2) break;
	  if (tmp->value == value) {
		return tmp;
	  }
	  tmp = tmp->next;
	  counter++;
	}
	return nullptr;
  }

  void TwoLinkedList::save(std::string out) {
	std::ofstream output;
	output.open(out);
	int count = 0;
	Node *tmp1 = head1;
	while (tmp1 && count < count1) {
	  output << std::to_string(tmp1->value) + ",";
	  tmp1 = tmp1->next;
	  count++;
	}
	output << '\n';
	count = 0;
	Node *tmp2 = head2;
	while (tmp2 && count < count2) {
	  output << std::to_string(tmp2->value) + ",";
	  tmp2 = tmp2->next;
	  count++;
	}
	output << '\n';

	while (tmp1) {
	  output << std::to_string(tmp1->value) + ",";
	  tmp1 = tmp1->next;
	}
	output << '\n';
  }

  void TwoLinkedList::load(std::string in) {
	std::vector<std::string> lines;
	std::ifstream file1(in);
	std::string line;
	while (getline(file1, line)) { 
	  lines.push_back(line);	
	}
  }
}
