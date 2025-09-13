#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;

		Node(int val){
			data = val;
			prev = NULL;
			next = NULL;
		}
};

class DoublyList{
	private:
		Node* head;
		Node* tail;

	public:
		DoublyList(){
			head = NULL;
			tail = NULL;
		}

		void insertAtEnd(int val){
			Node* newNode = new Node(val);
			if(head == NULL){
				head = newNode;
				tail = newNode;
			} 
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
		}

		void deleteAtFront(){
			if(head == NULL){
				cout<<"List is empty"<<endl;
				return;
			}
			Node* tmp = head;
			if(head == tail){
				head = NULL;
				tail = NULL;
			} 
			else{
				head = head->next;
				head->prev = NULL;
			}	delete tmp;
		}

		int search(int val){
			Node* current = head;
			while(current != NULL){
				if(current->data == val){
					return 1;
				}   current = current->next;
			}       return 0;
		}

		void display(){
			Node* current = head;
			while(current != NULL){
				cout<<current->data<<" ";
				current = current->next;
			}
			cout<<endl;
		}
};

int main(){
	DoublyList DD;

	DD.insertAtEnd(7);
	DD.insertAtEnd(2);
	DD.insertAtEnd(9);

	cout<<"List: ";
	DD.display();

	DD.deleteAtFront();
	cout<<"After deleting: ";
	DD.display();

	if(DD.search(7)){
		cout<<"7 Found"<<endl;
	}
	else
		cout<<"7 Not Found"<<endl;

	if(DD.search(27)){
		cout<<"27 Found"<<endl;
	}
	else
		cout<<"27 Not Found"<<endl;
}
