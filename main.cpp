#include <iostream>
#include <cstring>
#include "list.h"

int main() {
    std::cout<<"Input size of random list before executing commands:\n";
    int size;
    std::cin>>size;
    list* head = new list;
    head->id = 1 + rand()%100;
    head->next = nullptr;
    build_random(head, size);
    std::cout<<"Your random list:\n";
    print_list(head);
    std::cout<<"Command list:\n";
    std::cout<<"--Push Elem\n";
    std::cout<<"--PushFront Elem ElemFront\n";
    std::cout<<"--PushBack Elem ElemBack\n";
    std::cout<<"--PushEnd Elem\n";
    std::cout<<"--PushRepeat Elem ElemBack\n";
    std::cout<<"--PopFront\n";
    std::cout<<"--PopBack\n";
    std::cout<<"--Pop Elem\n";
    std::cout<<"--PrintList\n";
    std::cout<<"--Cancel\n";
    std::cout<<"Please input command:\n";
    char* command = (char*) malloc(sizeof(char) * MAXSIZE);
    fgets(command,MAXSIZE, stdin);
    while(strlen(command) != 0){
        char *istr = strtok(command, " ");
        if(strcmp(istr, "Push") == 0){
            istr = strtok(NULL, " ");
            int el = atoi(istr);
            push(head,el);
        }else if(strcmp(istr, "PushFront") == 0){
            istr = strtok(NULL, " ");
            int el = atoi(istr);
            istr = strtok(NULL, " ");
            int front = atoi(istr);
            push_front(head,el, front);
        }else if(strcmp(istr, "PushBack") == 0){
            istr = strtok(NULL, " ");
            int el = atoi(istr);
            istr = strtok(NULL, " ");
            int back = atoi(istr);
            push_back(head,el, back);
        }else if(strcmp(istr, "PushEnd") == 0){
            istr = strtok(NULL, " ");
            int el = atoi(istr);
            push_end(head,el);
        }else if(strcmp(istr, "PushRepeat") == 0){
            istr = strtok(NULL, " ");
            int el = atoi(istr);
            istr = strtok(NULL, " ");
            int back = atoi(istr);
            push_repeat(head,el, back);
        }else if(strcmp(istr, "PopFront") == 10){
            int el = pop_front(head);
            std::cout<<el<<"\n";
            istr = strtok(NULL, " ");
        }else if(strcmp(istr, "PopBack") == 10){
            int el = pop_back(head);
            std::cout<<el<<"\n";
            istr = strtok(NULL, " ");
        }else if(strcmp(istr, "Pop") == 0){
            istr = strtok(NULL, " ");
            int elem = atoi(istr);
            int el = pop_element(head, elem);
            std::cout<<el<<"\n";
        }else if(strcmp(istr, "PrintList") == 10){
            print_list(head);
        }else if(strcmp(istr, "Cancel") == 10){
            break;
        }
        fgets(command, MAXSIZE, stdin);
    }
    return 0;
}
