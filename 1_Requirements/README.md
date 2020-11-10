# Requirements

This is a basic phonebook management system developed using C programming language.
phonebook stores the basic contact inforamtion such as Name,Phone Number,Gender,Email ID etc.
phonebook uses database to store contacts.here database is array of structures.An array of pointers of type structure is used to store the contacts.whenever a new contact is being added,memory is allocated in heap and stores it in that location.similarly when a contact is deleted,the memory is freed in that location where the contact was stored.

**Functional requirements**  
There are 5 operations supported by phonebook management system.
1) Listing:Listing all the contacts in the database.
2) Adding:Adding contacts to the database.
3) Deleting:Deleting contacts from the database.
4) Modifying:Modifying contacts in the database.

**Non-functional requirements**
1) Initially user should define the maximum number of contacts.
2) program should handle maximum number of contacts without affecting its performance.

**Testing** 
cunit library is used for testing.

**Requirements:**  
OS:- Windows/linux  
Compiler:- gcc compiler.  
Doxygen:- To document the code.  
Make:- To build and manage the project automatically.

*	Capture all the requirements wrt system, module, interface, integration, testing, Functional and Non-functional
*	Captures Basic Planning of the project through - Sample Gantt Chart attached
*	Tools: MS Excel, MS word or Similar
