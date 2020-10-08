/**
* @file test_phonebook.c
* phonebook application with 5 operations for testing
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "phoneheader.h"

//printing all the contacts
void test_listing(int n1)
{

   if(1==listing(n1))
   {
       printf("\n\n--------success----------------");
   }
   else
   {
       printf("\n\n--------------Failed----------------");
   }
}

//adding with same name
void test_adding(int n1)
{
    if(3==adding(n1,"sham"))
   {
       printf("\n\n--------success----------------");
   }
   else
   {
       printf("\n\n--------------Failed----------------");
   }
}


void test_deleting(int n1)
{
    if(3==deleting(n1,"laxman"))
   {
       printf("\n\n--------success----------------");
   }
   else
   {
       printf("\n\n--------------Failed----------------");
   }
}

void test_modifying(int n1)
{
    if(0==modifying(n1,"laxman"))
   {
       printf("\n\n--------success----------------");
   }
   else
   {
       printf("\n\n--------------Failed----------------");
   }

}

void test_searching(int n1)
{
    if(1==searching(n1,"ram"))
   {
       printf("\n\n--------success----------------");
   }
   else
   {
       printf("\n\n--------------Failed----------------");
   }
}

int main()
{
    int no=3;
   for(int i=0;i<no;i++)
   {
       contact[i]=(records*)(malloc(sizeof(records)));
   }
   //first contact
   strcpy(contact[0]->first_name,"ram");
   strcpy(contact[0]->last_name,"k");
   strcpy(contact[0]->gender,"m");
   contact[0]->phone_number=9876543210;
   strcpy(contact[0]->email_id,"ramk@gmail.com");

   //second contact
   strcpy(contact[1]->first_name,"sham");
   strcpy(contact[1]->last_name,"r");
   strcpy(contact[1]->gender,"m");
   contact[1]->phone_number=9874563210;
   strcpy(contact[1]->email_id,"shamr@gmail.com");

   //third contact
   strcpy(contact[2]->first_name,"bham");
   strcpy(contact[2]->last_name,"s");
   strcpy(contact[2]->gender,"m");
   contact[2]->phone_number=9873216540;
   strcpy(contact[2]->email_id,"bhams@gmail.com");

    printf("\n\n------testing list-----\n\n");
    test_listing(no);

    printf("\n\n------testing add-----\n\n");
    test_adding(no);

    printf("\n\n------testing delete-----\n\n");
    test_deleting(3);

    printf("\n\n------testing modify-----\n\n");
    test_modifying(no);

    printf("\n\n------testing searching-----\n\n");
    test_searching(no);
    return(0);
}
