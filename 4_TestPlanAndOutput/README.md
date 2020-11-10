# Test plan and test output

Testing involves the design of test cases that validate that the internal program logic of the phonebook application is functioning properly.
Testing is done on functions add, delete list, modify and search.cunit library is used for unit testing.

## Testing of adding function->
1)  Test case 1-: To add the record in the database with the same name.
Expected results: Record should not be added and display message record already exists.
## Testing of deleting function->
2)  Test case 2:- To remove the record which does not exist in the database.
Expected results: The program should display records that cannot be deleted as it does not exist.      
## Testing of searching function->
3)  Test case 3:- To search the record which does not exist in the database.
Expected results: The program should display no records found in the database.
## Testing of listing function->
4)  Test case 4:- To list the records without adding any of the records.
Expected results: Display no records found.
## Testing of modifying function->
5)  Test case 5:- To modify the record which does not exist in database.
Expected results: Display records cannot be modified as they do not exist. 
