#include <iostream>
using namespace std;

class Node
{

public:
   Node *next;
   string book;

   Node()
   {
      next = NULL;
      book = "";
   }

   Node(string name) : book(name)
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
   void insertAtTail(string name)
   {

      Node *temp = new Node(name);

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

   void insertAtHead(string name)
   {
      Node *temp = new Node(name);

      if (head != NULL)
      {
         temp->next = head;
         head = temp;
      }
      else
      {

         head = temp;
         tail = temp;
      }
   }

   bool search(string target)
   {

      Node *temp = head;
      while (temp != NULL)
      {
         if (temp->book == target)
            return true;
         temp = temp->next;
      }
      return false;
   }

   void insertAtPos(string target, string name)
   {

      Node *temp = head;
      Node *insert = new Node(name);

      while (temp != NULL)
      {

         if (temp->book == target)
         {
            insert->next = temp->next;
            temp->next = insert;
            return;
         }
         temp = temp->next;
      }
   }

   void print()
   {

      Node *temp = head;

      while (temp != NULL)
      {
         cout << temp->book << endl;
         temp = temp->next;
      }
   }
};

int main()
{
   LinkList B1;
   B1.insertAtTail("Data Structure");
   B1.insertAtTail("Operating System");
   B1.insertAtTail("Computer Networks");
   B1.insertAtTail("Database System");

   B1.print();
   cout << endl;

   B1.insertAtHead("Artifical Intelligence");
   B1.print();

   cout << endl;
   B1.insertAtTail("Machine Learning");

   B1.print();
   cout << endl;

   B1.insertAtPos("Operating System", "Cyber Security");
   B1.print();
   cout << endl;
   return 0;
}
