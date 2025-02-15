#include <iostream>
using namespace std;
class Node;
Node *head = NULL;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class LinkedList
{
public:
// Lab 3 _ Singly Linked List(Insert at start, Insert at End)
    void insert_at_start(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insert_at_last(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
// Lab 4 _ Singly Linked List (Insert at specific Location)
    void insert_at_pos(int pos, int d)
    {

        Node *newNode = new Node(d);
        Node *temp = head;
        {
            if (pos < 1)
            {
                cout << "Invalid Position!" << endl;
            }
            else if (pos == 1)
            {
                Node *newNode = new Node(d);
                newNode->next = head;
                return;
            }
            else
            {
                for (int i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                    if (temp == NULL)
                    {
                        cout << "Invalid Position." << endl;
                        break;
                    }
                }
            }
            if (temp != NULL)
            {

                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
// Lab 6 _ Singly Linked List (Delete Nodes)
    void delete_at_start(){
        if(head != NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
            temp = NULL;
        }
    }

// Lab 5 _ Singly Linked List (Display Nodes)
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main()
{
    LinkedList list;
    list.insert_at_start(10);
    list.insert_at_start(20);
    list.insert_at_start(30);
    list.insert_at_pos(2, 50);
    list.insert_at_last(40);
    list.delete_at_start(10);
    list.display();
    return 0;
}
