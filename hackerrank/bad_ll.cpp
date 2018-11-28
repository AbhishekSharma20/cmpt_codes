/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* next;
};
typedef struct node node;


node* reverse(node* root){
    node *temp, * temp2 = root;
    if(root && root-> next){
        temp = root->next->next;
        temp2 = root->next;
        
        root->next->next = root->next;
        root-> next = reverse(temp);
    }
    return temp2;
}

void printList(node* root){
    while(root){
        cout<< root->data <<" ";
        root = root-> next;
    }
    cout<<endl;
        
    
}
int main()
{
    
    node* root = new node();
    root-> data = 10;
    root-> next = new node();
    root->next->data = 20;
    root->next->next = new node();
    root->next->next->data = 30;
    root->next->next->next = new node();
    root->next->next->next->data = 40;
    root->next->next->next->next = NULL;
    
    printList(root);
    node* root2 = reverse(root);
    printList(root2);
    return 0;
}
