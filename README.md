# Airline_Management_System
Flight Management System | OOPs | C++ 

The above program is an Airline Management System implemented in C++. It provides functionality for both administrators and users. The program uses classes to organize the code and implement the different features.

The program begins with a main function that displays a menu with options to login as an administrator or a user, or to exit the program. 

If the administrator option is chosen, the user is prompted to enter their email address and password for authentication. If the credentials match the predefined values, the administrator is granted access to the admin menu. The admin menu provides options to add a flight, view existing flights, update flight details, or exit the program.

If the user option is chosen, the user can either sign up or log in. The sign-up process collects user information such as name, age, email address, and PIN. This information is stored in a file. The login process validates the user's email address and PIN against the stored values. Upon successful login, the user is presented with a user menu. The user menu offers options to view the flight schedule, book a flight, view bookings, cancel bookings, or exit the program.

The program uses file handling to store flight and user data. The flight details are stored in a text file, and the user information is stored in a separate text file.

Overall, the program provides basic functionality for an airline management system, allowing administrators to manage flights and users to book and manage their bookings. It demonstrates the use of classes, file handling, and menu-driven interfaces in C++.
