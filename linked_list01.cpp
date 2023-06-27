#include <iostream>
using namespace std;

class Node
{
    public :
    int val;
    Node* next;
    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class linkedList
{
    public :
    Node* head;
    Node* last;
    linkedList()
    {
        this->head = new Node();
        this->last = head;
    }
    void insertAtLast(int val)
    {
        Node* n = new Node();
        last->val = val;
        last->next = n;
        last = n;
        return;
    }
    void insertAtStart(int val)
    {
        Node* n = new Node(val);
        n->next = head;
        head = n;
        return;
    }
    void insertAtIndex(int val, int index) // 1 based index followed
    {
        if(index==1)
        {
            Node* n = new Node(val);
            n->next = head;
            head = n;
            return;
        }
        Node* temp = head;
        Node* prev = new Node();
        prev->next = temp;
        for(int i=0; i<index-1; i++)
        {
            temp = temp->next;
            prev = prev->next;
        }
        Node* n = new Node(val);
        prev->next = n;
        n->next = temp;
        // delete prev; //generates runtime error
        // delete temp; //generates runtime error
        return;
    }
    void deleteAtStart()
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    void deleteAtLast()
    {
        if(head==last)
        {
            head->val = 0;
            return;
        }
        Node* temp = head;
        while(temp!=NULL)
        {
            if(temp->next==last)
            {
                break;
            }
            temp = temp->next;
        }
        Node* n = last;
        last = temp;
        last->next = n->next;
        delete n;
        return;
    }
    void traversalOfLinkedList()
    {
        cout<<"Elements in linked list : ";
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
        delete temp;
        return;
    }
};

int main()
{
    linkedList L;
    L.deleteAtLast();
    L.traversalOfLinkedList();
    L.insertAtLast(10);
    L.traversalOfLinkedList();
    L.insertAtLast(20);
    L.traversalOfLinkedList();
    L.insertAtLast(40);
    L.traversalOfLinkedList();
    L.insertAtLast(80);
    L.traversalOfLinkedList();
    L.insertAtLast(160);
    L.traversalOfLinkedList();
    L.insertAtStart(5);
    L.traversalOfLinkedList();
    L.insertAtIndex(60, 4);
    L.traversalOfLinkedList();
    L.deleteAtStart();
    L.traversalOfLinkedList();
    L.deleteAtLast();
    L.traversalOfLinkedList();
    L.deleteAtLast();
    L.traversalOfLinkedList();
    return 0;
}
