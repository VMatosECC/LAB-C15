#include <iostream>
#include <vector>
using namespace std;

// Base class: Hotel
class Hotel {
protected:
    string name, location, phone;
public:
    Hotel(string n, string loc, string ph) : name(n), location(loc), phone(ph) {}

    void showHotelInfo() {
        cout << "Hotel Name: " << name << "\nLocation: " << location << "\nPhone: " << phone << endl;
    }
};

// Base class: Restaurant
class Restaurant {
protected:
    vector<string> menu;
public:
    Restaurant(vector<string> m) : menu(m) {}

    void showMenu() {
        cout << "Restaurant Menu: ";
        for (const auto& item : menu) {
            cout << item << ", ";
        }
        cout << endl;
    }
};

// Base class: Amenities
class Amenities {
protected:
    vector<string> activities;
public:
    Amenities(vector<string> a) : activities(a) {}

    void showAmenities() {
        cout << "Available Amenities: ";
        for (const auto& activity : activities) {
            cout << activity << ", ";
        }
        cout << endl;
    }
};

// Derived class: Resort (inherits from Hotel, Restaurant, and Amenities)
class Resort : public Hotel, public Restaurant, public Amenities {
public:
    Resort(string n, string loc, string ph, vector<string> menu, vector<string> activities)
        : Hotel(n, loc, ph), Restaurant(menu), Amenities(activities) {
    }

    void showResortDetails() {
        cout << "========== Resort Details ==========" << endl;
        showHotelInfo();
        showMenu();
        showAmenities();
        cout << "=====================================" << endl;
    }
};

// Main function
int main() {
    vector<string> menu = { "Steak", "Pasta", "Seafood", "Salad" };
    vector<string> activities = { "Golf", "Tours", "Fishing", "Sailing" };

    Resort myResort("Paradise Resort", "Hawaii", "123-456-7890", menu, activities);
    myResort.showResortDetails();

    cout << "\nAll done!\n";
}

