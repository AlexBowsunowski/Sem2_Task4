#include <iostream>
#include "list.h"

void build_random(list *& head, int size){
    list * curr = head;
    for(int i = 0; i < size; ++i){
        list * new_node = new list;
        new_node->id = 1 + rand()%100;
        new_node->next = nullptr;
        curr->next = new_node;
        curr = curr->next;
    }
}


void push(list* &head, int el){

    list *new_node = new list;
    new_node->id = el;
    new_node->next = head;
    head = new_node;

}

void push_front(list* &head, int el, int front) {
    list *new_node = new list;
    new_node->id = el;
    list *curr = head;
    if (head->id == front) {
        new_node->next = head;
        head = new_node;
    } else {
        while (curr->next != nullptr && curr->next->id != front) {
            curr = curr->next;
        }
        if (curr->next->id == front) {
            list *next = curr->next;
            curr->next = new_node;
            new_node->next = next;
        }
    }
}

void push_back(list* &head, int el, int back){
    if (head == nullptr) {
        return;
    }

    list* curr = head;
    while (curr != nullptr && curr->id != back) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        return;
    }

    list* newNode = new list;
    newNode->id = el;
    newNode->next = curr->next;
    curr->next = newNode;
}

void push_end(list* &head, int el){
    if(head == nullptr){
        head = new list;
        head->id = el;
    }else {
        list *curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        list* newNode = new list;
        newNode->id = el;
        newNode->next = nullptr;
        curr->next = newNode;
    }
}
void push_repeat(list* &head, int e1, int e){
    list* curr = head;
    while(curr != nullptr){
        if(curr->id == e){
            list* new_node = new list;
            new_node->id = e1;
            new_node->next = curr->next;
            curr->next = new_node;
        }
        curr = curr->next;
    }
}


void print_list(list* &head){
    list* curr = head;
    std::cout<<curr->id<<" ";
    while(curr->next){
        std::cout<< curr->next->id << " ";
        curr = curr->next;
    }
    std::cout<<"\n";
}



int pop_front(list* & head){
    int el = head->id;
    list* temp = head;
    head = head->next;
    delete temp;
    return el;
}

int pop_back(list* &head){
    list* curr = head;
    int el;
    if(head->next == nullptr){
        el = head->id;
        head = nullptr;
    }else {
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        el = curr->next->id;
        list* temp = curr->next;
        curr->next = nullptr;
        delete temp;
    }
    return el;
}

int pop_element(list* & head, int el){
    list* curr = head;
    if(curr == nullptr) {
        return -1;
    }else if(curr->id == el){
        head = curr->next;
        delete curr;
    }else {
        while (curr->next != nullptr && curr->next->id != el) {
            curr = curr->next;
        }
        if (curr->next == nullptr) {
            return -1;
        } else {
            list* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    return el;
}

