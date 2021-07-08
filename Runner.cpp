//
//  Runner.cpp
//  Project 5 - Templates
//
//  Created by Amarjot Gill 4/26/2021
// Runner class for vector class includes a menu for user to select options 

#ifndef RUNNER_CPP
#define RUNNER_CPP

#include <cstdlib>
#include "Vector.cpp"
using namespace std;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int SIX = 6;
const int SEVEN = 7;
const int EIGHT = 8;
const int NINE = 9;


template <class T>
class Runner {
public:
    // Name: Default Constructor
    // Precondition: None
    // Postcondition: Initiates state/environment
    Runner(Vector<T>*, Vector<T>*);
    
    // Name: mainMenu
    // Desc: Main Menu
    // Precondition: Existing Vectors
    // Postcondition: Handles various menu commands
    int mainMenu();
    
private:
    Vector<T> m_vector1;
    Vector<T> m_vector2;
};

// **** Add class definition below ****
template <class T>
Runner<T>::Runner(Vector<T>* vec_one, Vector<T>* vec_two){
    bool keepRunning = true;
    // creates two new Vectors using copy constructors
   Vector<T> *m_vector1 = new Vector<T>(*vec_one);
    Vector<T> *m_vector2 = new Vector<T>(*vec_two);
    do{
        int option = mainMenu();
         if (option == ONE){
            cout << "Vector 1: ";
            m_vector1->Display();
            cout << endl;
            cout << "Vector 2: ";
            m_vector2->Display();
            cout << endl;
            
        }else if (option == TWO){
            cout << "Vector 1 < Vector 2: ";
           Vector<char> *temp = *m_vector1 < *m_vector2;
            temp->Display();
            delete temp;
           temp = nullptr;

        }else if(option == THREE){
            cout << "Vector 1 == Vector 2: ";
            Vector<char> *temp = *m_vector1 == *m_vector2;
            temp -> Display();
            delete temp;
            temp = nullptr;

        }else if(option == FOUR){
            cout << "Vector 1 + Vector 2: ";
            // sets temp to the result vector
            Vector<T> *temp = *m_vector1 + *m_vector2;
            temp -> Display();
            // deletes since it was dynamically allocated
            delete temp;
            temp = nullptr;

        }else if(option == FIVE){
            cout << "Vector 1 * Vector 2: ";
            Vector<T> *temp = *m_vector1 * *m_vector2;
            temp -> Display();
            // deletes because it was dynamically allocated
            delete temp;
            temp = nullptr;

        }else if(option == SIX){
            cout << "Vector 1 median: " << m_vector1->Median() << endl;
            cout << "Vector 2 median: " << m_vector2->Median() << endl;

        }else if(option == SEVEN){
            cout << "Vector 1 mean: " << m_vector1->Mean() << endl;
            cout << "Vector 2 mean: " << m_vector2->Mean() << endl;
        }else if(option == EIGHT){
            cout << "Vector 1 StDev: " << m_vector1->StDev() << endl;
            cout << "Vector 2 StDev: " << m_vector2->StDev() << endl; 
        // if user selects nine the loop ends and program ends
        }else if(option == NINE){
            keepRunning = false;
        }
    } while (keepRunning);
    // deletes the dynamically allocated vectors
    delete m_vector1;
    delete m_vector2;
}

template <class T>
int Runner<T>::mainMenu(){
    int option;
        cout << "Choose an option" << endl;
        cout << "1. Display Vectors" << endl;
        cout << "2. Vector Comparison (<)" << endl;
        cout << "3. Vector Compaison (==) " << endl;
        cout << "4. Vector addition" << endl;
        cout << "5. Vector multiplication " << endl;
        cout << "6. Compute median" << endl;
        cout << "7. Compute mean "<< endl;
        cout << "8. Compute Standard Derivation" << endl;
        cout << "9. Exit" << endl;
        cin >> option;
        // returns whatever number user selects will bounds check in constructor
    return option;
}

#endif /* Runner_h */


