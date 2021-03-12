#ifndef TASK4_LIST_H
#define TASK4_LIST_H
#define MAXSIZE 255
typedef struct link{
    int id;
    struct link *next;
}list;


void build_random(list* &head, int size);
void push(list* &head, int el);
void push_front(list*& head, int el, int front);
void push_back(list* &head, int el, int front);
void push_end(list* &head, int el);
void push_repeat(list* &head, int e1, int e);
void print_list(list* &head);
int pop_front(list* & head);
int pop_back(list* &head);
int pop_element(list* & head, int el);

#endif //TASK4_LIST_H
