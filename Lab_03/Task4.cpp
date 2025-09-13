#include <vector>
#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *next;

   Node(int val) : data(val)
   {
      next = NULL;
   }
};

class LinkList
{

public:
   Node *head;
   Node *tail;

   LL()
   {
      head = NULL;
      tail = NULL;
   }

   void insertAtHead(Node *&head, int data)
   {
      Node *temp = new Node(data);

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

   void insertAtTail(int data)
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

   void print()
   {
      Node *temp = head;
      while (temp != NULL)
      {
         cout << temp->data << " ";
         temp = temp->next;
      }
   }

   int getlength()
   {

      int length = 0;
      Node *temp = head;
      while (temp != NULL)
      {
         length++;
         temp = temp->next;
      }
      return length;
   }

   void sortList()
   {

      int capac = getlenth();
      Node *temp = head;
      ;

      int count = 0;

      while (count < capac- 1)
      {

         for (int i = 0; i < capac && temp != NULL; ++i)
         {
            if (temp->next != NULL)
            {
               if ((temp->data) > (temp->next->data))
               {
                  int val = temp->data;
                  temp->data = temp->next->data;
                  temp->next->data = val;
               }
               temp = temp->next;
            }
         }
         ++count;
         temp = head;
      }
   }

   void concatenate(LinkList l2)
   {

      tail->next = l2.head;
   }

   void removeDuplicate()
   {

      Node *i = head;

      while (i != NULL)
      {

         Node *prev = i, *curr = i->next;

         while (prev != NULL && curr != NULL)
         {

            if (curr->data == i->data)
            {
               prev->next = curr->next;
               delete curr;
               curr = prev->next;
            }
            else
            {
               prev = curr;
               curr = prev->next;
            }
         }
         i = i->next;
      }
   }

   void findMiddle()
   {
      Node *N1 = head, *N2 = head;

      while (N2 != NULL && N2->next != NULL)
      {
         N2 = N2->next;
         if (N2->next != NULL)
         {
            N2 = N2->next;
         }
         N1 = N1->next;
      }
      cout << "The middle Elemenet is: " << N1->data << endl;
   }

   void merge(LinkList l3)
   {

      Node *i = head, *j = l3.head;
      Node *dummy = new Node(0), *current = dummy;

      while (i != NULL && j != NULL)
      {

         if (i->data <= j->data)
         {
            current->next = i;
            current = current->next;
            i = i->next;
         }
         else if (j->data < i->data)
         {
            current->next = j;
            current = current->next;
            j = j->next;
         }
      }
      while (i != NULL)
      {
         current->next = i;
         i = i->next;
         current = current->next;
      }
      while (j != NULL)
      {
         current->next = j;
         j = j->next;
         current = current->next;
      }
   }
};

int main()
{
   LinkList L1;

   L1.insertAtTail(7);
   L1.insertAtTail(8);
   L1.insertAtTail(1);
   L1.insertAtTail(0);
   L1.insertAtTail(2);
   cout << "Before Sorting! " << endl;
   L1.print();
   cout << endl;
   L1.sortList();
   cout << "After Sorting: " << endl;
   L1.print();
   cout << endl;

   LinkList l2;
   l2.insertAtTail(4);
   l2.insertAtTail(9);
   l2.insertAtTail(13);
   l2.insertAtTail(22);
   l2.insertAtTail(69);
   cout << "Another Linked List: " << endl;
   l2.print();
   cout << endl;
   L1.concatenate(l2);
   cout << "Concat of Linked List: " << endl;
   L1.print();
   L1.removeDuplicate();
   cout << endl
        << "Removing Duplicates: " << endl;
   L1.print();

   cout << endl;
   L1.findMiddle();

   LinkList L3;
   L3.insertAtTail(33);
   L3.insertAtTail(26);
   L3.insertAtTail(12);
   L3.sortList();
   cout << "Another Linked List for Merging: " << endl;
   L3.print();

   L1.merge(L3);
   cout << endl
        << "Merged Linked List: " << endl;
   L1.print();
}
