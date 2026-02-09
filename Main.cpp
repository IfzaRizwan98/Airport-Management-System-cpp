#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ================= FLIGHT DATA =================
const int TOTAL_FLIGHTS = 4;

string flightDestinations[TOTAL_FLIGHTS] = {
    "America",
    "Canada",
    "Dubai",
    "Turkey"
};

string flightDates[TOTAL_FLIGHTS] = {
    "05/12/2024",
    "10/12/2024",
    "16/12/2024",
    "22/12/2024"
};

// ================= STRUCT =================
struct Ticket {
    int ticketID;
    string passengerName;
    string destination;
    string departureDate;
    bool isBooked;
};

// ================= SAFE INPUT =================
int getSafeInt(const string& msg) {
    int value;
    while (true) {
        cout << msg;
        cin >> value;

        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Invalid input! Numbers only.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string getLineSafe(const string& msg) {
    string input;
    cout << msg;
    getline(cin, input);
    return input;
}

// ================= CHECK FLIGHT =================
bool isValidFlight(const string& destination, const string& date) {
    for (int i = 0; i < TOTAL_FLIGHTS; i++) {
        if (flightDestinations[i] == destination &&
            flightDates[i] == date) {
            return true;
        }
    }
    return false;
}

// ================= FLIGHT MANAGEMENT =================
void flightManagement() {
    cout << "\n===== FLIGHT MANAGEMENT SYSTEM =====\n";
    cout << "Islamabad -> America | Date: 05/12/2024\n";
    cout << "Islamabad -> Canada  | Date: 10/12/2024\n";
    cout << "Islamabad -> Dubai   | Date: 16/12/2024\n";
    cout << "Islamabad -> Turkey  | Date: 22/12/2024\n";
    cout << "===================================\n";
}

// ================= PASSENGER MANAGEMENT =================
void passengerManagement() {
    cout << "\n===== PASSENGER MANAGEMENT =====\n";
    cout << "Total Seats: 200 per flight\n";
    cout << "Business Class: 70 seats available\n";
    cout << "Normal Class: 55 seats available\n";
    cout << "===============================\n";
}

// ================= TICKET BOOKING =================
void bookTicket(Ticket tickets[], int &ticketCount) {

    Ticket t;
    cout << "\n===== TICKET BOOKING =====\n";
    cout << "NOTE: Choose destination & date from Flight Management only.\n";

    t.ticketID = getSafeInt("Enter Ticket ID (numbers only): ");

    t.passengerName = getLineSafe("Enter Passenger Name: ");

    cout << "Enter Destination (America / Canada / Dubai / Turkey): ";
    getline(cin, t.destination);

    cout << "Enter Departure Date (dd/mm/yyyy): ";
    getline(cin, t.departureDate);

    if (!isValidFlight(t.destination, t.departureDate)) {
        cout << "\n Flight unavailable!\n";
        cout << "Please choose destination and date from Flight Management System.\n";
        return;
    }

    t.isBooked = true;
    tickets[ticketCount++] = t;

    cout << "\n Ticket booked successfully!\n";
}

// ================= VIEW TICKETS =================
void viewTickets(Ticket tickets[], int ticketCount) {
    if (ticketCount == 0) {
        cout << "No tickets booked yet.\n";
        return;
    }

    cout << "\n===== BOOKED TICKETS =====\n";
    for (int i = 0; i < ticketCount; i++) {
        cout << "Ticket ID   : " << tickets[i].ticketID << endl;
        cout << "Passenger   : " << tickets[i].passengerName << endl;
        cout << "Destination : " << tickets[i].destination << endl;
        cout << "Date        : " << tickets[i].departureDate << endl;
        cout << "--------------------------\n";
    }
}

// ================= UPDATE =================
void updateTicket(Ticket tickets[], int ticketCount) {
    if (ticketCount == 0) {
        cout << "No ticket booked yet.\n";
        return;
    }

    int id = getSafeInt("Enter Ticket ID to update: ");

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketID == id) {

            tickets[i].passengerName = getLineSafe("Enter new Passenger Name: ");

            cout << "Enter new Destination: ";
            getline(cin, tickets[i].destination);

            cout << "Enter new Date (dd/mm/yyyy): ";
            getline(cin, tickets[i].departureDate);

            if (!isValidFlight(tickets[i].destination, tickets[i].departureDate)) {
                cout << " Flight unavailable! Update cancelled.\n";
                return;
            }

            cout << " Ticket updated successfully!\n";
            return;
        }
    }
    cout << "Ticket ID not found.\n";
}

// ================= DELETE =================
void deleteTicket(Ticket tickets[], int &ticketCount) {
    if (ticketCount == 0) {
        cout << "No ticket booked yet.\n";
        return;
    }

    int id = getSafeInt("Enter Ticket ID to cancel: ");

    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i].ticketID == id) {
            for (int j = i; j < ticketCount - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            ticketCount--;
            cout << "Ticket cancelled successfully!\n";
            return;
        }
    }
    cout << "Ticket ID not found.\n";
}

// ================= MAIN =================
int main() {
    Ticket tickets[50];
    int ticketCount = 0;

    while (true) {
        cout << "\n===== AIRPORT MANAGEMENT SYSTEM =====\n";
        cout << "1. Flight Management\n";
        cout << "2. Passenger Management\n";
        cout << "3. Book Ticket\n";
        cout << "4. View Tickets\n";
        cout << "5. Update Ticket\n";
        cout << "6. Cancel Ticket\n";
        cout << "0. Exit\n";

        int choice = getSafeInt("Enter choice: ");

        switch (choice) {
            case 1: flightManagement(); break;
            case 2: passengerManagement(); break;
            case 3: bookTicket(tickets, ticketCount); break;
            case 4: viewTickets(tickets, ticketCount); break;
            case 5: updateTicket(tickets, ticketCount); break;
            case 6: deleteTicket(tickets, ticketCount); break;
            case 0: cout << "Goodbye!\n"; return 0;
            default: cout << "Invalid option.\n";
        }
    }
}
