/**
* @file project_main.c
* main C file of the program.
* Flowchart of project_main.c
* \image html main.jpg
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <phoneheader.h>

/// Global variable to store total no of contacts.Initially no contacts.
int no_of_contacts=0;


//main function

/**
 * This is the main function \n
 * It will take the choice from the user to select the option in the Menu and proceeds to switch statement. \n
 * Switch statement selects the case according to the choice and calls the respective function.
*/
int main()
{
    int choice;
    char f_name[30];
    printf("\t\t\t\t-------------PHONEBOOK MANAGEMENT SYSTEM---------------\n\n\n\n");
first: printf("\t\t\t\tList of operations\n\n");
       printf("\t 1)LIST THE RECORDS \t 2)ADD A RECORD \t 3)DELETE A RECORD \n \t 4)MODIFY A RECORD \t 5)SEARCH A RECORD \t 6)EXIT");
       printf("\n\nEnter your choice:");
       scanf("%d",&choice);
       switch(choice)
       {
          case 1: printf("-----------Listing the contacts-----------");
                  listing(no_of_contacts);
                  break;
          case 2: printf("-----------Adding a contact-------------");
                  printf("\nEnter first name:");
                  scanf("%29s",f_name);
                  string_upper(f_name);
                  no_of_contacts=adding(no_of_contacts,f_name);
                  break;
          case 3: printf("-----------Deleting a contact--------------------");
                  printf("\nEnter the first name of the contact to be deleted:");
                  scanf("%29s",f_name);
                  string_upper(f_name);
                  no_of_contacts=deleting(no_of_contacts,f_name);
                  break;
          case 4: printf("Modifying");
                  printf("\nEnter the first name of the contact to be modified:");
                  scanf("%29s",f_name);
                  string_upper(f_name);
                  modifying(no_of_contacts,f_name);
                  break;
          case 5: printf("Searching");
                  printf("\nEnter the first name of the contact to be searched:");
                  scanf("%29s",f_name);
                  string_upper(f_name);
                  searching(no_of_contacts,f_name);
                  break;
          case 6: printf("exit");
                  //exit();
                  for(int i=0;i<no_of_contacts;i++)
                  {
                      free(contact[i]);
                  }
                  return(0);
         default: printf("\n\nWrong choice!!!!->please enter between 1 to 6\n\n");
                  goto first;//return to enter choice
      }
      printf("\n\nPress any key to continue to Menu\n");
      getch();
      goto first;
      return 1;
}
