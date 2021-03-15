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
    std::cout<<"1 Push Elem)\n";
    std::cout<<"2 PushFront Elem ElemFront\n";
    std::cout<<"3 PushBack Elem ElemBack\n";
    std::cout<<"4 PushEnd Elem\n";
    std::cout<<"5 PushRepeat Elem ElemBack\n";
    std::cout<<"6 PopFront\n";
    std::cout<<"7 PopBack\n";
    std::cout<<"8 Pop Elem\n";
    std::cout<<"9 PrintList\n";
    std::cout<<"10 Cancel\n";
    /*For example,
     * Please input command:
     * 1(Push)
     * 3(Elem)
     * 2(PushFront)
     * 2(Elem) 3(ElemFront)
     * */
    std::cout<<"Please input command:\n";
    int command;
    std::cin>>command;
    while(command != 10){
        if(command == 1){
            int el;
            std::cin>>el;
            push(head,el);
        }else if(command == 2){
            int el, el_f;
            std::cin>>el;
            std::cin>>el_f;
            push_front(head,el, el_f);
        }else if(command == 3){
            int el, el_b;
            std::cin>>el;
            std::cin>>el_b;
            push_back(head,el, el_b);
        }else if(command == 4){
            int el;
            std::cin>>el;
            push_end(head,el);
        }else if(command == 5){
            int el, el_b;
            std::cin>>el;
            std::cin>>el_b;
            push_repeat(head,el, el_b);
        }else if(command == 6){
            int el = pop_front(head);
            std::cout<<el<<"\n";
        }else if(command == 7){
            int el = pop_back(head);
            std::cout<<el<<"\n";
        }else if(command == 8){
            int elem;
            std::cin>>elem;
            int el = pop_element(head, elem);
            std::cout<<el<<"\n";
        }else if(command == 9){
            print_list(head);
        }
        std::cin>>command;
    }
    return 0;
}
