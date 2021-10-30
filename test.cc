#include<iostream>
#include "Mylist.h"

using namespace std;

int main(int argc,char *argv[]){
    
    Mylist a;
    //cout << a.isEmpty() << endl;
   

    
/*
    a.app_end(4);
    a.app_end(4);
    a.app_end(4);
    a.app_end(6);
    a.mprint();
    */
    
    node *x = new node;
    x->val = 9;
    x->next = nullptr;
    a.insertList(x,5);
    cout << a.getLen() << endl;
    a.mprint();
    cout << endl;

    node *z = new node;
    z->val = 4;
    z->next = nullptr;
    a.insertList(z,2);
    cout << a.getLen() << endl;
    a.mprint();
    cout << endl;

    node *y = new node;
    y->val = 3;
    y->next = nullptr;
    a.insertList(y,0);
    cout << a.getLen() << endl;
    a.mprint();
    cout << endl;

    a.delList(2);
    cout << a.getLen() << endl;
    a.mprint();
    cout << endl;

    a.delList(1);
    cout << a.getLen() << endl;
    a.mprint();
    cout << endl;

    cout << a.isEmpty() << endl;


    //cout << a.isEmpty() << endl;
    return 0;
}
