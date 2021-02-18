/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *link;
};

class List{
    public:
        Node *createNode(int data){
            Node *temp = new Node();
            temp->data = data;
            temp->link = NULL;
            return temp;
        }
        
        Node *insertRear(Node *head, int data){
            if(head == NULL)
            {
                head = createNode(data);
                return head;
            }
            
            Node *cur = head;
            while(cur->link!=NULL){
                cur = cur->link;
            }
            
            cur->link = createNode(data);
            
            return head;
        }
        
        void display(Node *head){
            Node *cur = head;
            while(cur!=NULL){
                cout<<cur->data<<" ";
                cur = cur->link;
            }
            cout<<endl;
        }
        
        Node *reverseList(Node *head){
            Node *prev = NULL;
            Node *cur = head;
            
            while(cur->link!=NULL){
                Node *temp = cur->link;
                cur->link = prev;
                prev = cur;
                cur = temp;
            }
            
            cur->link = prev;
            head = cur;
            return head;
        }
        
        Node *reverseListAtPosition(Node *head, int m , int n){
            int count = 1;
            Node *cur = head;
            Node *temp = NULL;
            Node *temp2 = NULL;
            while(cur!=NULL){
                if(count == m){
                    break;
                }
                temp = cur;
                cur = cur->link;
                count++;
            }
            
            Node *prev = cur;
            cur = cur->link;
            prev->link = NULL;
            //cout<<"cur->data"<<cur->data<<endl;
            //cout<<"prev->data"<<prev->data<<endl;
            count++;
            while(cur->link!=NULL && count!=n){
                Node *temp1 = cur->link;
                cur->link = prev;
                prev = cur;
                cur = temp1;
                count++;
            }
            if(cur->link)
                temp2 = cur->link;
            if(cur->link && temp){
                cur->link = prev;
                temp->link = cur;
                
                while(cur->link!=NULL)
                {
                    cur = cur->link;
                }
            }
            else{
                cur->link = prev;
            }            
            if(temp2 == NULL && temp){
                temp->link = cur;
                while(cur->link!=NULL)
                {
                    cur = cur->link;
                }
                return temp;
            }
            
            //cout<<"temp2->data"<<temp2->data<<endl;
            //cout<<"temp->data"<<temp->data<<endl;
            if(temp == NULL && temp2){
                Node *tempo = cur;
                while(cur->link!=NULL)
                {
                    cur = cur->link;
                }
                cur->link = temp2;
                return tempo;
            }
            
            if(temp2 && temp){
                cur->link = temp2;
                head = temp;
            }else{
                head = cur;
            }
            return head;
        }
    
};

int main()
{
    //printf("Hello World");
    List l;
    Node *head = NULL;
    head = l.insertRear(head,10);
    head = l.insertRear(head,20);
    head = l.insertRear(head,30);
    head = l.insertRear(head,40);
    head = l.insertRear(head,50);
    head = l.insertRear(head,60);
    head = l.insertRear(head,70);
    
    cout<<"before reversing"<<endl;
    l.display(head);
    
    head = l.reverseList(head);
    
    cout<<"After reversing"<<endl;
    l.display(head);
    
    head = l.reverseList(head);
    cout<<"After reversing back"<<endl;
    l.display(head);
    
    cout<<"deleting at a particular position"<<endl;
    head = l.reverseListAtPosition(head,1,3);
    l.display(head);
    return 0;
}
