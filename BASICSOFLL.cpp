#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head=tail=NULL;
        size=0;
    }
    void insertatend(int val)
    {
        Node * temp =new Node(val);
        if(size==0)head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertatbeginning(int val)
    {
        Node * temp =new Node(val);
        if(size==0)head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertat(int idx,int val)
    {
        if(size==0)
        {
            cout<<"empty list";
            return;
        }
        else if(idx<0||idx>size)
        {
            cout<<"INVALID";
        }
        else if(idx==0)
        {
            insertatbeginning(val);
        }
        else if(idx==size) insertatend(val);
        else{
            Node * t =new Node(val);
                Node* temp=head;
                for(int i=0;i<idx-1;i++)
                {
                    temp=temp->next;
                }
                t->next=temp->next;
                temp->next=t;
                size++;
        }
    }
    void deleteathead()
    {
        if(size==0)
        {
            cout<<"empty list";
            return;
        }
        if(size>=1)
        {
            head=head->next;
            size--;
        }
    }
    void deleteattail()
    {
        if(size==0)
        {
            cout<<"empty list";
            return;
        }
            Node* temp=head;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
    }
    void deleteat(int idx)
    {
        if(size==0)
        {
            cout<<"empty list";
            return;
        }
        else if(idx<0||idx>=size)
        {
        cout<<"INVALID";
        return;
        }
        else if(idx==0)
        {
            deleteathead();
        }
        else if(idx==size) deleteattail();
        else{
            Node* temp=head;
                for(int i=0;i<idx-1;i++)
                {
                    temp=temp->next;
                }
                temp->next=temp->next->next;
                size--;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp =temp->next;
        }
    }
};
int main(){
    LinkedList ll;
    ll.insertatend(10);
    ll.insertatend(20);
    ll.insertatend(30);
    ll.insertatend(40);
    ll.insertatend(50);
    ll.insertatbeginning(60);
    ll.display();
    cout<<endl;
    ll.insertat(1,80);
    ll.display();
    cout<<endl;
    ll.deleteathead();
    ll.display();
    cout<<endl;
    ll.deleteattail();
    ll.display();
    cout<<endl;
    ll.deleteat(1);
    ll.display();
    return 0;
}