# Air-Line-Management

This program is a C++ application for simulating an airline reservation system. It allows users to view flight schedules, make reservations, manage seats, and calculate billing information. Designed specifically for Ganavaram International Airport, the system includes features for handling multiple passengers.

Features
View Flight Schedule: Displays a predefined flight schedule from a text file (Flight_data.txt).
Flight Details: Lists available flights sorted by economy price for easy selection.
Reservation Management:
Accepts details for multiple passengers, including name, age, gender, phone number, and meal preference.
Handles seat selection with real-time availability checks.
Supports vegetarian, non-vegetarian, or no-meal options.
Billing: Generates the total bill based on the number of passengers and the chosen destination.
Seat Availability:
Displays a list of reserved seats.
Shows a report of all available seats.
How to Run
Compile the Program:

g++ AirlinesReservation.cpp -o AirlinesReservation
Run the Program:

./AirlinesReservation
Prepare Flight Schedule File: Ensure a file named Flight_data.txt is in the same directory as the executable. The file should contain the flight schedule details.

Usage Instructions
Run the program and choose from the following menu options:

Option 1: View the flight schedule.
Option 2: Make a reservation for passengers.
Option 3: Print a list of reserved seats.
Option 4: Generate a seat availability report.
Option 5: Quit the system.
Follow the prompts to provide passenger details and make reservations.

After completing a reservation, you can view passenger details, reserved seats, and total billing.

******************** AIRLINE RESERVATION SYSTEM *********************
Options:
1. Flight Schedule
2. Make Reservation
3. Print Reserved Seats
4. Seat Availability Report
5. Quit

Enter your option:
Requirements
A C++ compiler (e.g., GCC or Clang).
A Flight_data.txt file in the same directory as the executable. The file should include the flight schedule.
Limitations
The system supports seat numbers from 1 to 100.
The destinations and flights are predefined.
The program does not allow modification or cancellation of reservations once made.
Future Enhancements
Add functionality for canceling or modifying reservations.
Support dynamic addition of flights and destinations.
Improve user input validation and error handling.
