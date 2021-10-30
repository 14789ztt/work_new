#ifndef MYLIST_H
#define MYLIST_H

#include<iostream>
using namespace std;

typedef int Datetype;

// node type
class node{
    public:
        Datetype val;
        node *next;
};

// list type
class Mylist{
public:
    Mylist(); 
    ~Mylist(); 
    
    // add the node in the end of the list;
    node *app_end(Datetype val);
    void mprint();
    void insertList(node *data,int n);
    void delList(int n);
    int getLen();
    bool isEmpty();

private:
    node *head;
    int size;
};

Mylist::Mylist(){
    head = nullptr;
    size = 0;
}
Mylist::~Mylist(){
    delete head;
}

// add the node in the end of the list;
node *Mylist::app_end(Datetype x){
    node *newptr = new node;
    newptr->val = x;
    newptr->next = nullptr;

    node *ptr = head;

    // the head  == nullptr
    if(head == nullptr){
        head = newptr;
    }
    else{
        // head  != nullptr
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }
    ++size;

    return head;
}

void Mylist::mprint(){
    node *ptr = head;
    if(size == 0){
        cout << "node is none" << endl;
        return;
    }
    while(ptr != nullptr){
        cout << ptr->val << endl;
        ptr = ptr->next;
        //cout << -1 << endl;
    }
}

int Mylist::getLen(){
    return size;
}

bool Mylist::isEmpty(){
    return (size > 0)?false:true; 
}


void Mylist::delList(int n){
    node *ptemp;
    node *ptemp2;
    if(n > size){
        cout << "wrong,n is out of range" << endl;
        return;
    }

    // delete first node
    if(n < 2){
        ptemp = head;
        head = head->next;
        free(ptemp);
    }
    else if(n == size){
        // delete the last one
        ptemp = head;
        while(ptemp->next->next != nullptr){
            ptemp = ptemp->next;
        }
        ptemp2 = ptemp->next;
        ptemp->next = nullptr;
        free(ptemp2);
    }
    else{
        // delete normal
        ptemp = head;
        for(int i = 2;i < n;++i){
            ptemp = ptemp->next;
        }
        ptemp2 = ptemp->next;
        ptemp->next = ptemp->next->next;
        free(ptemp2);
    }
    --size;
    return;

}

// 
// 插入元素，不允许插入空节点，
// n<2时，将元素插到首节点之前，
// n>size时，一律将元素插入到尾结点之后。
void Mylist::insertList(node *x,int n){
    node *pnew = new node;
    pnew->val = x->val;
    pnew->next = x->next;

    node *ptr = head;

    // when x=null or head =null,output wrong.
    if(x == nullptr){
        cout << "the insert node is null,wrong!" << endl;
        return;
    }
    if(head == nullptr){
        pnew->next = nullptr;
        head = pnew;
        size = 1;
        return;
    }

    // inesert begin
    if(n < 2 ){
        node *ptemp = new node;
        ptemp = head;
        pnew->next = ptemp;
        head = pnew;
    }
    else if(n > size){
        // insert end
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        pnew->next = nullptr;
        ptr->next = pnew;
    }
    else{
        // insert medial
        for(int i = 1;i < n;++i){
            ptr = ptr->next;
        }
        node *ptemp = new node;
        ptemp = ptr->next;
        pnew->next = ptemp;
        ptr->next = pnew;
    }
    ++size;
}

#endif
