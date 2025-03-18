// C15-Multiple-Inheritance-DiamondProblem.cpp 
#include <iostream>
using namespace std;
/*
 In the context of multiple inheritance, the diamond problem describes
 the ambiguity that results when a class inherits from two classes that,
 in turn, inherit from a single common base class. This ambiguity,
 regarding which base class member to utilize, is resolved in C++
 through the mechanism of virtual inheritance.
*/

// Base class
class Person {
public:
    string name;
    Person(string personName) : name(personName) {}

    void introduce() {
        cout << "Person=>   " << "Hi, my name is " << name
            << ", i live at " << this << endl;
    }
};

// Intermediate classes inheriting from Person
class Teacher : virtual public Person {
public:
    Teacher(string teacherName) : Person(teacherName) {}

    void teach() {
        cout << "Teacher=>  " << name << " is teaching Data Structures." << endl;
    }
};

class Student : virtual public Person {
public:
    Student(string studentName) : Person(studentName) {}

    void study() {
        cout << "Student=>  " << name << " is studying at ECC." << endl;
    }
};

// Derived class inheriting from both Teacher and Student
class TeachingAssistant : public Teacher, public Student {
public:
    TeachingAssistant(string taName) : Person(taName), Teacher(taName), Student(taName) {}

    void assist() {
        cout << "T.A.=>     " << name << " is assisting in CS2 class." << endl;
    }
};

int main() {
    TeachingAssistant ta("Diego");

    ta.introduce(); // No ambiguity due to virtual inheritance
    ta.teach();
    ta.study();
    ta.assist();


}
