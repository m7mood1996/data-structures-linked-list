#include <iostream>

#include "LinkedList.h"

void test_linked_list();

void test_linked_list_itirator();

int main() {
    //test_linked_list();
    test_linked_list_itirator();
    return 0;
}




void test_linked_list(){
    LinkedList<int> linkedList;
    int i = 1;
    linkedList.push_back(i);
    i=2;
    linkedList.push_back(i);
    i=3;
    linkedList.push_back(i);
    i=4;
    linkedList.push_back(i);

    linkedList.pop_back();
    linkedList.pop_front();

    linkedList.print();
}

void test_linked_list_itirator(){
    LinkedList<int> linkedList;
    int i = 1;
    linkedList.push_back(i);
    i=2;
    linkedList.push_back(i);
    i=3;
    linkedList.push_back(i);
    i=4;
    linkedList.push_back(i);

    LinkedList<int>::iterator it = linkedList.begin();

    for (; it != linkedList.end() ; it++) {
        std::cout << *it << std::endl;

    }

}