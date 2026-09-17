#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// ==========================================
// Part 1: Base Class (Person)
// ==========================================
class Person {
protected:
    string  name;
    int     age;

public:
    // Constructor (uses lazy-initializers)
    Person(string n = "n.a", int a = 0) : name(n), age(a) {}

    // Virtual display function for runtime polymorphism (Part 3)
    virtual void display() const {
        cout << "Name: " << name 
            << ", Age: " << age << endl;
    }

    // Virtual destructor to ensure proper cleanup in inheritance chains
    virtual ~Person() {
        cout << "+ Person destructor called for " << name << endl;
    }
};

// ==========================================
// Part 2: Derived Classes (Student & Professor)
// ==========================================

class Student : public Person {
private:
    double gpa;

public:
    // Constructor
    Student(string n, int a, double g) : Person(n, a), gpa(g) {}

    // Override display() to show gpa
    void display() const override {
        cout << "[Student] Name: " << name 
            << ", Age: " << age 
            << ", GPA: " << gpa << endl;
    }

    // Destructor (Part 4.1)
    ~Student() override {
        cout << "+ Student destructor called for " << name << endl;
    }
};

class Professor : public Person {
private:
    int yearsExperience;

public:
    // Constructor
    Professor(string n, int a, int exp) : Person(n, a), yearsExperience(exp) {}

    // Override display() to show years of experience
    void display() const override {
        cout << "[Professor] Name: " << name 
            << ", Age: " << age 
            << ", Experience: " << yearsExperience << endl;
    }

    // Destructor (Part 4.1)
    ~Professor() override {
        cout << "+ Professor destructor called for " << name << endl;
    }
};

// ============================================
// Part 4.3: Additional Employee Class Example
// ============================================
class Employee : public Person {
private:
    int employeeID;

public:
    Employee(string n, int a, int id) : Person(n, a), employeeID(id) {}

    void display() const override {
        cout << "[Employee] Name: " << name 
            << ", Age: " << age 
            << ", ID: " << employeeID << endl;
    }

    int getID() const { return employeeID; }

    ~Employee() override {
        cout << "+ Employee destructor called for " << name << endl;
    }
};

// ==========================================
// Part 5: Department Composition Class
// ==========================================
class Department {
private:
    string deptName;
    string officeNumber;
    vector<Professor*> professors; // Composition: Department has zero or many professors

public:
    Department(string name, string office) : deptName(name), officeNumber(office) {}

    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }

    void display() const {
        cout << "\n--- Department: " << deptName 
            << " (Office: " << officeNumber << ") ---" << endl;

        if (professors.empty()) {
            cout << "No professors assigned." << endl;
        }
        else {
            for (const auto& prof : professors) {
                prof->display();
            }
        }
    }
};
//--------------------------------------------------------------
void experiment01()
{
    cout << "experiment01 " << endl;
    Person* p1 = new Student("Bart Simpson", 10, 2.13);
    Person* p2 = new Professor("Edna Krabapple", 45, 28);

    p1->display(); // Calls Student’s display()
    p2->display(); // Calls Professor’s display()

    delete p1;
    delete p2;
}

//--------------------------------------------------------------
void experiment02() {
    cout << "\nexperiment02" << endl;

    // Required Core Main Function (Part 3)[cite: 1]
    cout << "=== Part 3: Runtime Polymorphism ===" << endl;
    Person* p1 = new Student("Bart Simpson", 10, 2.13);
    Person* p2 = new Professor("Edna Krabappel", 45, 28);

    p1->display(); // Calls Student's display()[cite: 1]
    p2->display(); // Calls Professor's display()[cite: 1]

    delete p1;
    delete p2;

    // ==========================================
    // Part 4.2: Vector of Person Pointers
    // ==========================================
    cout << "\n=== Part 4.2: Vector of Person Pointers ===" << endl;
    vector<Person*> people;
    people.push_back(new Student("Milhouse Van Houten", 10, 2.85));
    people.push_back(new Professor("Elizabeth Hoover", 40, 15));
    people.push_back(new Employee("Groundskeeper Willie", 50, 1004));

    for (const auto& person : people) {
        person->display();
    }

    // ===========================================================
    // Part 4.3: Experimenting with dynamic_cast<>
    // ===========================================================
    cout << "\n=== Part 4.3: Testing dynamic_cast ===" << endl;
    for (auto person : people) {
        // Try casting Person* to Employee*
        Employee* emp = dynamic_cast<Employee*>(person);
        if (emp != nullptr) {
            cout << "Found an Employee object!" << endl;
        }
    }

    // =========================================================
    // Part 5: Composition with Department
    // =========================================================
    cout << "\n=== Part 5: Composition Experiment ===" << endl;
    Professor* prof1 = new Professor("Seymour Skinner", 50, 20);
    Professor* prof2 = new Professor("Coach Krup", 42, 12);

    Department generalStudies("General Studies", "Building B, Room 101");
    generalStudies.addProfessor(prof1);
    generalStudies.addProfessor(prof2);

    generalStudies.display();

    // Clean up dynamic memory for vector elements and department professors
    for (auto person : people) {
        delete person;
    }
    delete prof1;
    delete prof2;
}

// ==========================================
// Main Function
// ==========================================
int main() {
    experiment01();     //initial test (Person, Student, Professor)
    experiment02();     //extended test
    cout << "all done!" << endl;
    
}