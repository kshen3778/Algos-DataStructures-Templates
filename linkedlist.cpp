#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *next;
};

class List {
  private:
    Node *head, *tail;
    int length;
  public:
    List(){
      head = NULL;
      tail = NULL;
    }

    int getLength(){
      return length;
    }

    void createnode(int value){
      //create the node
      Node *temp = new Node();
      temp->data=value;
      temp->next=NULL;
      //if there is no head, make temp the head
      if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
      }
      else{
        tail->next = temp;
        tail = temp;
      }


      length++;
    }

    void display(){
      Node *temp = new Node();
      temp = head;
      //Loop through the list
      while(temp != NULL){
        cout << temp->data << "\t";
        temp = temp->next; //go to the next node
      }
    }

    void insert_start(int value){
      Node *newStart = new Node();
      newStart->data = value;
      newStart->next = head;
      //the new head is set
      head = newStart;
      length++;
    }

    void insert_end(int value){
      Node *newEnd = new Node();
      newEnd->data = value;
      tail->next = newEnd;
      tail = newEnd;
      length++;
    }

    void insert_position(int pos, int value){
      Node *pre = new Node();
      Node *cur = new Node();
      Node *temp = new Node(); //node we want to insert
      cur = head;
      for (int i=0; i<pos; i++){
        pre = cur;
        cur = cur->next;
      }
      //set values and insert
      temp->data = value;
      pre->next = temp; //temp is inserted after pre but before cur
      temp->next = cur;
      length++;
    }

    void delete_position(int pos){
      Node *current = new Node();
      Node *previous = new Node();
      current = head;
      for(int i=0;i<pos;i++){
        previous = current;
        current = current->next;
      }
      previous->next = current->next;
      length--;
    }
};


int main()
{

  /*
  I can use List* obj = new List() too
  but I will need to use obj->display() to call functions
  */
  List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
}
