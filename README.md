# Airport-Management-System-cpp
Console-based Airport Management System in C++ with input validation
# Airport Management System (C++)

A console-based Airport Management System developed in C++.  
This project demonstrates basic data structures, input validation, and real-world logic.

## Features
- Flight Management (fixed monthly schedule)
- Passenger Seat Information
- Ticket Booking with validation
- Update and Cancel Ticket
- Prevents invalid destination and date selection
- Safe input handling (program does not crash)

## Flight Rules
- Users can only book tickets for flights listed in the Flight Management System
- Destination and departure date must match available flights
- Ticket ID and Passenger Name can be user-defined

## Technologies Used
- C++
- Structures
- Arrays
- Input validation using cin.fail()

## How the System Works
1. User views available flights
2. User books a ticket by selecting a valid destination and date
3. System verifies flight availability
4. Ticket is stored and can be viewed, updated, or cancelled

## Future Improvements
- Seat number allocation
- Per-flight passenger tracking
- File handling for data persistence

## Author
Ifza Rizwan
