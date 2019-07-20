// linked list in cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}node;

void print(node *head){
    node *temp;
    temp=head;
    int flag=0;
    while(temp!=NULL){
        if(flag==0){
            cout<<temp->data;
            flag=1;
        }
        cout<<"->"<<temp->data;
        temp=temp->next;
    }
    cout<<"->NULL"<<endl;
}

node* createNode(int d){
    node* nn = (struct node*)malloc(sizeof(node));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

node* createList(int n){
    node *head=NULL,*temp=NULL,*nn=NULL;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        nn=createNode(j);
        if(head==NULL){
            head=nn;
            temp=nn;
        }
        else{
            temp->next=nn;
            temp=temp->next;
        }
    }
    return head;
}

int main() {
	int n;
	cin>>n;
	node* head=NULL;
	head = createList(n);
	print(head);
	return 0;
}
