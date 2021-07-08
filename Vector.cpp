//
//  Vector.cpp
//  Project 5 - Templates
//
//  Created by Amarjot Gill 4/26/2021
// creates a Vector which is a linked list, can do various things with another vector and it's self.


#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
const int ONE = 1;
const int TWO = 2;
const char TRUE = 'T';
const char FALSE = 'F';

template <class T> 
struct Node {
public:
  Node(T value) {
    m_value = value;
    next = nullptr;
  }
  
  Node(T value, Node* _next) {
    m_value = value;
    next = _next;
  }
  
  T getValue() {
    return m_value;
  }
  
  Node<T>* getNextNode() {
    return next;
  }
  
  void setNextNode(Node<T>* newNode) {
    next = newNode;
  }
  
private:
  T m_value;
  Node<T>* next;
};


template <class T>
class Vector {
public:
  // Name: Default Constructor
  // Precondition: None (Must be templated)
  // Postcondition: Creates a vector using a linked list
  Vector();
   
  // Name: Destructor
  // Desc: Frees memory
  // Precondition: Existing Vector
  // Postcondition: Destructs existing Vector
  ~Vector();  

  // Name: Copy Constructor
  // Desc: Copies an existing vector
  // Precondition: Existing Vector
  // Postcondition: Two identical vectors (in separate memory spaces)
  // Hint: Utilize overloaded [] operator
  Vector (Vector<T> & source);
  
  // Name: Overloaded Assignment operator
  // Desc: Assingns a vector
  // Precondition: Existing Vector
  // Postcondition: Assigns a vector
  // Hint: Utilize overloaded [] operator
  Vector<T>* operator=(Vector<T>* source);  
  
  // Name: Overloaded [] operator
  // Desc: to retrive use [indx]
  // Precondition: Existing Vector
  // Postcondition: Returns the value of the element at the given index
  T operator[](int indx);
    
  // Name: Insert
  // Desc: insert a node to the end of the vector
  // Precondition: Existing Vector
  // Postcondition: A vector with the newly added value
  void Insert(T);  
    
  // Name: SortedInsert
  // Desc: Inserts a node into the vector at it's correct position (sorted ascendingly)
  // Precondition: Existing Vector
  // Postcondition: sorted vector (low to high)
  void SortedInsert(T);
      
  // Name: Remove
  // Desc: removes a node from the vector
  // Precondition: Existing Vector
  // Postcondition: A vector that holds the results of the vectors added
  void Remove(int indx);
    
  // Name: Overloaded + operator | Vector Addition
  // Desc: Adds two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: A vector that holds the results of the vectors added
  Vector<T>* operator+(Vector<T>& source);
    
  // Name: Overloaded * operator | Vector Multiplication
  // Desc: Multiplys two vectors and returns the result
  // Precondition: Existing Vector, vectors can be of different size
  // Postcondition: returns a vector that holds the results of the vectors multiplied
  Vector<T>* operator*(Vector<T>& other);
    
  // Name: Overloaded < operator | Vector Comparision
  // Desc: Compares two vectors [using the < operator] and returns the result
  // Precondition: Existing Vector -> vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char>* operator<(Vector<T>& other);
      
  // Name: Overloaded == operator | Vector Comparision
  // Desc: Compares two vectors [using the == operator] and returns the result
  // Precondition: Existing Vector, vectors need to be of the same size
  // Postcondition: returns a vector that holds the boolean char (T or F) value of each node comparison
  Vector<char>* operator==(Vector<T>& other);
    
  // Name: Size
  // Desc: number of nodes in Vector
  // Precondition: Existing Vector
  // Postcondition: returns the size of the vector
  int Size();  
    
  // Name: Display
  // Desc: displays the contents of the vector
  // Precondition: Existing Vector
  // Postcondition: prints to console the contents of Vector
  void Display();
    
  // Name: median
  // Desc: Computes the median of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the median value
  float Median();  
    
  // Name: Mean
  // Desc: Computes the mean of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the mean value
  float Mean();
    
  // Name: StDev
  // Desc: Computes the standard derivation of the vector
  // Precondition: Existing Vector
  // Postcondition: returns the standard derivation
  float StDev();
      
private:
    Node<T>* m_head;
};


// **** Add class definition below ****
template <class T>
Vector<T>::Vector(){
  m_head = nullptr;
}

template <class T>
Vector<T>::Vector(Vector<T> & source){
    int i = 0;
    // if source m_head is null then Vector is empty
   if (source.m_head == nullptr)
        return;

    Node<T>* tmp = source.m_head;
    // allocates m_head as same as source
    m_head = new Node<T>(source.m_head -> getValue());
    // current starts at m_head
    Node<T>* current = m_head;
    tmp = tmp-> getNextNode();
    while (tmp != nullptr){    
        // Allocates new node with same value as source
        Node<T>* newNode = new Node<T>(source.operator[](i));
        i++;
         // Point to this new node.
        current-> setNextNode(newNode);
        current = current -> getNextNode();
        current -> setNextNode(nullptr);
        tmp = tmp-> getNextNode();
    }
}

template <class T>
Vector<T>* Vector<T>::operator=(Vector<T>* source){
      // = operator does exact same as copy makes deep copy
      int i = 0;
   if (source -> m_head == nullptr)
        return *this;
    Node<T>* tmp = source -> m_head;
    m_head = new Node<T>(tmp -> getValue());
    m_head -> setNextNode(nullptr);
    Node<T>* current = m_head;
    tmp = tmp->getNextNode();
    while (tmp != nullptr){ 
        // since deep copy making new nodes completely  
        Node<T>* newNode = new Node<T>(source->operator[](i));
        i++;
        current-> setNextNode(newNode);
        current = current -> getNextNode();
        // set the 'next' to null
        current -> setNextNode(nullptr);
        tmp = tmp-> getNextNode();
    }
    cout << &source -> m_head << endl;
    cout << &m_head << endl;
    return *this;
}

template <class T>
void Vector<T>::Insert(T nodeData){
  // makes new node
  Node<T> *newNode = new Node<T>(nodeData);
  if (m_head == nullptr){
    m_head = newNode;
  }else{
    Node<T> *temp = m_head;
    // traverses to end of list
    while (temp -> getNextNode() != nullptr){
      temp = temp -> getNextNode();
    }
    // sets end of list = to newNode
    temp -> setNextNode(newNode);
  }
}

template <class T>
void Vector<T>::SortedInsert(T nodeData){
    Node<T>* newNode = new Node<T>(nodeData);
    /* Special case for the head end */
    if (m_head == nullptr|| m_head-> getValue() >= newNode -> getValue()){
        newNode -> setNextNode(m_head);
        m_head = newNode;
    }
    else{
        Node<T>* current = m_head;
        // will run will current isnt at end and currents value is smaller then newNodes
        while (current-> getNextNode() != nullptr && current -> getNextNode()-> getValue() < newNode -> getValue()){
            current = current -> getNextNode();
        }
        // once the spot is found newNodes next is currents next 
        newNode -> setNextNode(current -> getNextNode());
        // currents new next is newNode
        current-> setNextNode(newNode);
    }
}

template <class T>
int Vector<T>::Size(){
    int size = 0;
    Node<T> *temp = m_head;
    // traverses linked list and updates size as it goes
    while (temp != nullptr){
      size++;
      temp = temp -> getNextNode();
    }
    temp = nullptr;
    return size;
}

template <class T>
T Vector<T>::operator[](int indx){
      Node<T> *temp = m_head;
      for (int i = 0; i < Size(); i++){
        // once i = the indx it returns temps value
        if (i == indx){
          return temp -> getValue();
          // else temp will go to the next node
        }else{
          temp = temp -> getNextNode();
        }
      }
    return temp -> getValue();
}

template <class T>
void Vector<T>::Display(){
      if (Size() == 0){
        cout << "Vector is empty" << endl;
        return;
    }
    else{
      // traverses linked list and displays each value in it
        Node<T> *temp = m_head;
        while (temp != nullptr){
          if (temp -> getNextNode() == nullptr){
            cout << temp -> getValue() << endl;
            return;
          }else{
            cout << temp -> getValue() << ",";
            temp = temp -> getNextNode();
          }
        }
        return;
    }  
}

template <class T>
void Vector<T>::Remove(int index){
  Node<T> *curr = m_head;
  Node<T> *prev = m_head;
  int counter = 0;
  // travereses linked list until counter is same as the index to remove
  while (curr != nullptr){
    if (counter == index){
      // previous's new node is set to curr's next node ending the link with curr
        prev -> setNextNode(curr ->getNextNode);
        // deletes curr
        delete curr;
        return;
    }
    prev = curr;
    curr = curr -> getNextNode();
    counter++;
  }
}

template<class T>
Vector<char>* Vector<T>::operator<(Vector<T>& other){
  Node<T> *temp = m_head;
  int counter = 0;
  // new dynamically allocated Vector
  Vector<char>* new_vec = new Vector<char>();
  while (temp != nullptr){
    // if this vectors value is less then others at this index new_vec gets a T other false
    if (operator[](counter) < other.operator[](counter)){
      new_vec -> Insert(TRUE);
    }else{
      new_vec -> Insert(FALSE);
    }
    temp = temp ->getNextNode();
    counter++;
  }
  return new_vec;
}

template<class T>
Vector<char>* Vector<T>::operator==(Vector<T>& other){
  // runs same as < operator function above just == instead of <
  Node<T> *temp = m_head;
  int counter = 0;
  Vector<char>* new_vec = new Vector<char>();
  while (temp != nullptr){
    if (operator[](counter) == other.operator[](counter)){
      new_vec -> Insert(TRUE);
    }else{
      new_vec -> Insert(FALSE);
    }
    temp = temp ->getNextNode();
    counter++;
  }
  return new_vec;
}

template<class T>
Vector<T>* Vector<T>::operator+(Vector<T>& source){
    Vector<T>* new_vec = new Vector<T>();
    Node<T>* temp = m_head;
    int counter = 0;
    // if the Size is less or they are equal, adds values together prevents going out of bounds since Size is smallers
    if (Size() < source.Size() || Size() == source.Size()){
      while (temp != nullptr){
        new_vec -> Insert(operator[](counter) + source.operator[](counter));
        temp = temp ->getNextNode();
        counter++;
        }
    }else{
      // if source's size is less then it will add all of sources index with this vectors to avoid going out of bounds
      for (int i = 0; i < source.Size(); i++){
        new_vec -> Insert(operator[](i) + source.operator[](i));
      }
    }
    return new_vec;
}

template<class T>
Vector<T>* Vector<T>::operator*(Vector<T>& source){
  // runs same as + operator function but is * the values instead
    Vector<T>* new_vec = new Vector<T>();
    Node<T>* temp = m_head;
    int counter = 0;
    if (Size() < source.Size() || Size() == source.Size()){
      while (temp != nullptr){
        new_vec -> Insert(operator[](counter) * source.operator[](counter));
        temp = temp ->getNextNode();
        counter++;
        }
    }else{
      for (int i = 0; i < source.Size(); i++){
        new_vec -> Insert(operator[](i) * source.operator[](i));
      }
    }
    return new_vec;
}

template<class T>
float Vector<T>::Mean(){
  Node<T> *temp = m_head;
  int counter = 0;
  float mean = 0.0;
  // traverses Vector and adds all sizes
  while (temp != nullptr){
    mean += operator[](counter);
    temp = temp ->getNextNode();
    counter++;
  }
  // divides mean by size to get actual mean
  mean /= Size();
  return mean;

}

template<class T>
float Vector<T>::Median(){
  // if the size is odd than the meadian can be found by intger dividing the size by 2 and returning that value
  if (Size() % TWO != 0){
    return operator[](Size() / TWO);
    // else take then middle value and one less add them then divide by two to get median
  }else{
    return float((operator[](Size() / TWO) + operator[]((Size() / TWO) - ONE)) / TWO);
  }
}

template<class T>
float Vector<T>::StDev(){
   Node<T> *temp = m_head;
  float mean = Mean();
  float numbers = 0.0;
  int counter = 0;
  while (temp != nullptr){
    // adds the value - mean ^ 2 to numbers
    numbers += (operator[](counter) - mean) * (operator[](counter) - mean);
    temp = temp ->getNextNode();
    counter++;
  }
  // divides numbers by size then takes square root to get standard deviation
  return (sqrt(numbers / Size()));

}

template<class T>
Vector<T>::~Vector(){
   Node<T>* current = m_head;
    while(current != nullptr){
        current = current -> getNextNode();
        // deletes the node
        delete m_head;
        m_head = current;
    }
    m_head = nullptr;
}

#endif /* VECTOR_CPP */
