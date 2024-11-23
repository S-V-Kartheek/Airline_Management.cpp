#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>  // For seat management
#include <algorithm>      // For sorting
using namespace std;

#define SIZE 100
int reserve = 999;

// Flight struct to help with sorting
struct Flight {
    string name;
    int code;
    int price;
};

// Airlines class for managing flights and reservations
class Airlines {
public:
    int to;
    string name[100];
    int age[100];
    long long int phone_number[100];
    char gender[100];
    int seat_number[100];
    int meal[100];
    int choice;
    int n = 0;
    int bill;

    unordered_map<int, bool> seats;  // Hash table for seat management

    void flight_schedule();
    void flight_details();
    void get_details(int n);
    void printdetails(int n);
    void billing(int n);
    void print_list(int n);
    void print_report(int n);
    void initializeSeats();
};

// Menu class that inherits from Airlines
class Menu : public Airlines {
public:
    void displayMenu();
};

// Initialize all seats as available
void Airlines::initializeSeats() {
    for (int i = 1; i <= SIZE; ++i) {
        seats[i] = true;
    }
}

// Display flight schedule
void Airlines::flight_schedule() {
    ifstream file("Flight_data.txt");
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Error: Unable to open flight data file." << endl;
    }
}

// Display available flights sorted by price
void Airlines::flight_details() {
    cout << "Available Flights (sorted by economy price):" << endl;
    Flight flights[] = {
        {"IndiGo", 1, 1000},
        {"Air India", 2, 1250},
        {"Go First", 3, 1100},
        {"SpiceJet", 4, 950},
        {"Vistara", 5, 1300}
    };

    // Sort flights by price
    sort(begin(flights), end(flights), [](Flight a, Flight b) {
        return a.price < b.price;
    });

    for (const auto& flight : flights) {
        cout << "\t" << flight.name << " ------ [" << flight.code << "] - Price: " << flight.price << endl;
    }

    cout << "Enter your flight choice: ";
    cin >> choice;
    if (choice < 1 || choice > 5) {
        cout << "Error: Invalid choice. Please enter a valid choice." << endl;
    }
}

// Get passenger details
void Airlines::get_details(int n) {
    cout << "Enter destination preference (1-3): ";
    cout << "\n1. Ganavaram to Hyderabad\n2. Ganavaram to Renigunta\n3. Ganavaram to Chennai" << endl;
    cout << "Enter Destination Choice: ";
    cin >> to;

    cout << "Enter passenger details: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Passenger " << i << " name: ";
        cin >> name[i];
        cout << "Passenger " << i << " age: ";
        cin >> age[i];
        cout << "Passenger " << i << " phone number: ";
        cin >> phone_number[i];
        cout << "Passenger " << i << " gender (M/F): ";
        cin >> gender[i];

        do {
            cout << "Enter seat number (1-100): ";
            cin >> seat_number[i];
            if (!seats[seat_number[i]]) {
                cout << "Seat taken. Choose another." << endl;
            }
        } while (!seats[seat_number[i]]);
        seats[seat_number[i]] = false;  // Mark seat as taken

        cout << "Meal preference (1=Veg, 2=Non-Veg, 3=No meal): ";
        cin >> meal[i];
    }
}

// Generate bill
void Airlines::billing(int n) {
    int base_price = 1000; // Sample base price

    if (to == 2) base_price += 200; // Adjust prices for different destination
    if (to == 3) base_price += 300;

    bill = n * base_price;
    cout << "Total Bill: " << bill << endl;
}

// Display passenger details
void Airlines::printdetails(int n) {
    cout << "\nPassenger Details:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Passenger " << i << " - Name: " << name[i]
             << ", Age: " << age[i] 
             << ", Phone: " << phone_number[i] 
             << ", Gender: " << gender[i] 
             << ", Seat No: " << seat_number[i] 
             << ", Meal: " << (meal[i] == 1 ? "Veg" : meal[i] == 2 ? "Non-Veg" : "No meal") << endl;
    }
}

// Print list of reserved seats
void Airlines::print_list(int n) {
    cout << "\nList of Reserved Seats:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Passenger " << i << " - Seat No: " << seat_number[i] << endl;
    }
}

// Print report on seat availability
void Airlines::print_report(int n) {
    cout << "\nSeat Availability Report:" << endl;
    for (int i = 1; i <= SIZE; i++) {
        if (seats[i]) {
            cout << "Seat " << i << " is available." << endl;
        }
    }
}

// Display main menu
void Menu::displayMenu() {
    int menu_option;
    do {
        cout << "******************** AIRLINE RESERVATION SYSTEM *********************\n";
        cout << "Options:\n";
        cout << "1. Flight Schedule\n";
        cout << "2. Make Reservation\n";
        cout << "3. Print Reserved Seats\n";
        cout << "4. Seat Availability Report\n";
        cout << "5. Quit\n";

        cout << "Enter your option: ";
        cin >> menu_option;

        switch (menu_option) {
            case 1:
                flight_schedule();
                break;
            case 2:
                flight_details();
                cout << "Enter Number of Passengers: ";
                cin >> n;
                get_details(n);
                printdetails(n);
                billing(n);
                break;
            case 3:
                print_list(n);
                break;
            case 4:
                print_report(n);
                break;
            case 5:
                cout << "Exiting system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
                break;
        }
    } while (menu_option != 5);
}

// Main Function
int main() {
    cout << "*************** WELCOME TO GANAVARAM INTERNATIONAL AIRPORT ***************\n";
    Menu m;
    m.initializeSeats();
    m.displayMenu();
    return 0;
}