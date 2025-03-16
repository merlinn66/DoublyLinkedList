#include <iostream> 

using namespace std;

class DoublyLinkedList{
  private: 
  class Node {
    public:
    int data;
    Node* next;
    Node * prev;

    Node(int d) {
      data = d;
      next = nullptr;
      prev = nullptr;
    }
  };
  Node * head;
  Node * tail;

  public: 

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
}
~DoublyLinkedList();

  void addFront(int d);
  void addEnd(int d);
  void displayForward();
  void displayBackward();
  void erase(int d);

};

int main(){

  DoublyLinkedList list;

  list.addFront(10);
  list.addFront (20);
  list.addEnd (30);
  list .addFront(40);
  list.addEnd (50);
  list.addFront(60);
  cout << "Displaying list forward..." << endl;
  list.displayForward();
  cout << "Displaying list backwards..." << endl;
  list.displayBackward();
  cout << "Erasing Nodes..." << endl;
  list.erase(40);
  list.erase(20);
  list.erase(50);
  cout << "Displaying list forward..." << endl;
  list.displayForward();
  cout << "Displaying list backwards..." << endl;
  list.displayBackward();
  
  return 0;
}

void DoublyLinkedList::addFront(int d) {
  Node * newNode = new Node(d);
  if (head == nullptr) { // if list is empty
    head = tail = newNode; // make first node in list
  }
  else {
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
  }
}
void DoublyLinkedList::addEnd(int d) {
  Node* newNode = new Node(d);
  if (tail == nullptr) {
    head = tail = newNode;
  } 
  else {
    tail -> next = newNode;
    newNode -> prev = tail;
    tail = newNode;
  }
}

void DoublyLinkedList::displayForward() {
  Node * temp = head;
  while (temp != nullptr) {
    cout << temp -> data << "<->" ;
    temp = temp -> next;
  }
  cout << "NULL";
  cout << endl;
}

void DoublyLinkedList::displayBackward() {
  Node * temp = tail;
  while (temp != nullptr) {
    cout << temp -> data << "<->";
    temp = temp -> prev;
  }
  cout << "NULL" << endl;
}

void DoublyLinkedList::erase(int d){
  Node * temp = head;
  if (head == nullptr) { return; }

      if (head -> data == d) {
        head = head -> next;
        if (head) {
          head -> prev = nullptr;
          delete temp;
          return;
      }
    }

  while (temp != nullptr && temp -> data != d) {
    temp = temp -> next;
  }

  if (temp == nullptr) {
    return;
  }

  if (temp == tail) {
    tail = tail -> prev;
    if (tail) {
      tail -> next =  nullptr;
    }
    
  }

  else {
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
  }

  delete temp;

}

DoublyLinkedList::~DoublyLinkedList(){
  Node * temp = head;
  while (temp !=  nullptr) {
    Node * nextNode =  temp -> next;
    delete temp;
    temp = nextNode;
  }

  cout << "Destructor is active." << endl;
}