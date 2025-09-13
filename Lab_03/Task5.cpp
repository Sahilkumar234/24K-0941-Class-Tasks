#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   string song;
   Node *next;

   Node(string data) : song(data)
   {
      next = NULL;
   }
};
class LinkList
{
public:
    Node *head;
    Node *tail;

    LinkList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(string data)
    {
        Node *temp = new Node(data);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp->next = head; 
        }
        else
        {
            temp->next = head;
            head = temp;
            tail->next = head; 
        }
    }

    void insertAtTail(string data)
    {
        Node *temp = new Node(data);

        if (tail == NULL)
        {
            head = tail = temp;
            tail->next = head;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = head; 
        }
    }

    void print()
    {
        if (head == NULL)
        {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->song;
            temp = temp->next;
        } while (temp != head);
        cout << " back to head " << endl;
    }
};

int main()
{
    LinkList playlist;

    playlist.insertAtHead("Alive");
    playlist.insertAtTail("Selfish");
    playlist.insertAtHead("Raat");
    playlist.insertAtTail("Moonrise");

    cout << "Playlist songs in circular linked list:" << endl;
    playlist.print();

    return 0;
}
