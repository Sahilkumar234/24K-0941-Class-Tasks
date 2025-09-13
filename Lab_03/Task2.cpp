#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   string BookTitle;
   Node *next;

   Node(string title) : BookTitle(title)
   {
      next = NULL;
   }
};

class LinkList
{

   Node *head;
   Node *tail;

public:
   LinkList()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtTail(string data)
   {
      Node *temp = new Node(data);

      if (tail != NULL)
      {

         tail->next = temp;
         tail = temp;
      }
      else
      {
         tail = temp;
         head = temp;
      }
   }

   void display()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->BookTitle << endl;
         temp = temp->next;
      }
   }

   void deleteNode()
   {
      Node *temp = head;
      if (temp != NULL)
      {
         head = temp->next;
         delete temp;
      }
   }

   void search(string val)
   {
      bool flag = false;
      Node *temp = head;
      while (temp != NULL)
      {

         if (temp->BookTitle == val)
         {
            cout << temp->BookTitle << " Found! " << endl;
            flag = true;
            break;
         }
         temp = temp->next;
      }
      }

   void Pos(int pos)
   {

      int count = 0;
      Node *temp = head;
      while (temp != NULL)
      {

         if (count == pos)
         {
            cout << temp->BookTitle << " " << "Found At Positon: " << count << endl;
            return;
         }
         temp = temp->next;
      }
   }
};

int main()
{

   LinkList B2;
   B2.insertAtTail("Crime and Punishment");
   B2.insertAtTail("Ego is Enemy");
   B2.insertAtTail("The Great GatsBy");
   B2.display();
   cout << endl;
   cout << "Inserting Book At end of Tail: " << endl;
   B2.insertAtTail("Solar Bones");
   B2.display();

   cout << endl;
   cout << "Deleting Book At Front! " << endl;
   B2.deleteNode();
   B2.display();

   
   string str;
   cout << "Enter the Name of Book to Search! " << endl;
   getline(cin, str);

   B2.search(str);
}
