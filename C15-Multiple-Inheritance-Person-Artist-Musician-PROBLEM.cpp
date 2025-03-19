// C15-Multiple-Inheritance-Person-Artist-Musician.cpp 
/*
The provided C++ code demonstrates the concept of multiple inheritance using three classes: 
Person, Artist, and Musician. 
Classes and Inheritance
1.	Base Class: Person
•	The Person class represents a person with a name and age.
•	It has a constructor to initialize the name and age attributes.
•	The displayPersonInfo method prints the person's name and age.
2.	Base Class: Artist
•	The Artist class represents artistic skills.
•	It has a method performArt that prints a message indicating artistic performance.
3.	Derived Class: Musician
•	The Musician class inherits from both Person and Artist.
•	It has an additional attribute instrument to represent the musical instrument 
    the musician plays.
•	The constructor initializes the name and age attributes using the Person constructor 
    and sets the instrument.
•	The playInstrument method prints a message indicating the musician is playing 
    the instrument and calls the performArt method from the Artist class.
•	The displayMusicianInfo method calls the displayPersonInfo method from 
    the Person class and prints the instrument information.
Main Function
•	The main function creates an instance of the Musician class with the 
    name "Lisa Simpson", age 8, and instrument "Saxophone".
•	It then calls the displayMusicianInfo method to print the musician's information.
•	Finally, it calls the playInstrument method to print the message indicating 
    the musician is playing the instrument and performing art.
*/
#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
public:
    Person(const string& name, int age) : name(name), age(age) {}

    void displayPersonInfo() const {
        cout << "Person=>   Name: " << name << ", Age: " << age << endl;
    }

protected:
    string name;
    int age;
};

// Base class: Artist (representing artistic skills)
class Artist {
public:
    void performArt() const {
        cout << "Artist=>   Performing artistic expression." << endl;
    }
};

// Derived class: Musician (inherits from Person and Artist)
class Musician : public Person, public Artist {
public:
    Musician(const string& name, int age, const string& instrument)
        : Person(name, age), instrument(instrument) {
    }

    void playInstrument() const {
        cout << "Musician=> " << name << " is playing the " << instrument << "." << endl;
        performArt(); // Use the inherited Artist method
    }

    void displayMusicianInfo() const {
        displayPersonInfo();
        cout << "Musician=> Instrument: " << instrument << endl;
    }

private:
    string instrument;
};

int main() {
    Musician musician("Lisa Simpson", 8, "Saxophone");
    musician.displayMusicianInfo();
    musician.playInstrument();

}
