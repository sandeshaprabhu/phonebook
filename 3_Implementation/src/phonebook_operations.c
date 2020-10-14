/**
* @file phonebook_operations.c
* phonebook application with 5 operations
*
*/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <phoneheader.h>

//Listing the contact
int listing(int no)
{
    //Checking if contacts exist
    if(no==0)
    {
        printf("\n\nNO Contacts to display!!!\n\n");
        return(-1);
    }
    else
    {
        //Printing the contacts
        for(int i=0;i<no;i++)
        {
            printf("\n\nDetails of the contact %d\n",i+1);
            display(i);
        }
        return(1);
    }
}

//Adding a new contact
int adding(int no,char *f_name)
{
	if(no==MAX_CONTACTS)
	{
		printf("Database is full...!!");
		return(no);
	}
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        printf("Contact with first name %s already existed..!",contact[found_flag]->first_name);
        printf("\nDetails of the contact with name %s",contact[found_flag]->first_name);
        display(found_flag);
        return(no);
    }
    contact[no]=(records*)(malloc(sizeof(records)));
    strcpy(contact[no]->first_name,f_name);
    enter(no); // function to enter input
    no++;
    printf("\nContact added successfully.....");
    sort_contacts(no);
    return(no);
}

//deleting a contact
int deleting(int no,char *f_name)
{
    if(no==0)
    {
        printf("\n No contacts in the database....!!");
        return(no);
    }
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        printf("The contact details of %s",f_name);
        display(found_flag);
        //to prompt user to delete or not
        /*char s[1];
        printf("\nDo you want to delete this contact(Y/N):");
        scanf("%1s",s);
        string_upper(s);
        if(!(strcmp(s,"Y")==0))
        {
            printf("\nContact not deleted");
            return(no);
        }*/
        free(contact[found_flag]);
        for(int i=found_flag;i<no-1;i++)
        {
            contact[i]=contact[i+1];
        }
        no--;
        printf("\nContact deleted successfully.....\n");
        return(no);
    }
    else
    {
        //if contact not found then program will print the below statement
        printf("\nContact with name %s NOT found...!!!",f_name);
        return(no);
    }
}


//Modifying the contact
int modifying(int no,char *f_name)
{
    if(no==0)
    {
        printf("\n No contacts in the database....!!");
        return(-1);
    }

    int found_flag=searches(no,f_name);
    //if contact found then program will print the below statement
    if(found_flag!=-1)
    {
        printf("\nThe existing details of the contact:%s",f_name);
        display(found_flag);
        printf("\n--------------------\n");
        printf("\n\n---Enter the new details of the contact---");
        printf("\nEnter first name:");
        scanf("%29s",contact[found_flag]->first_name);
        string_upper(contact[found_flag]->first_name);
        enter(found_flag);
        printf("\nContact modified successfully.....");
        sort_contacts(no);
        return(1);
    }
    //if contact not found then program will print the below statement
    else
    {
        printf("\nContact with name %s NOT found...!!!",f_name);
        return(0);
    }
}

//Searching a contact
int searching(int no,char *f_name)
{
   if(no==0)
    {
        printf("\n No contacts in the database....!!");
        return(-1);
    }
    int found_flag=searches(no,f_name);
    if(found_flag!=-1)
    {
        printf("\nContact with first name %s is found at position %d",f_name,found_flag+1);
        display(found_flag);
        return(1);
    }
    else
    {
        //if contact not found then program will print the below statement
        printf("\nContact with name %s NOT found...!!!",f_name);
        return(0);
    }

}

//extra functions to optimize the code

//Searching a contact with name and returning index
int searches(int no,char *f_name)
{
    if(no==0)
    {
        return(-1);
    }
    for(int i=0;i<no;i++)
    {
        if(strcmp(f_name,contact[i]->first_name)==0)
        {
            return(i);
        }
    }
    return(-1);
}

//displaying the contact information
void display(int n)
{
    printf("\nNAME: %s %s",contact[n]->first_name,contact[n]->last_name);
    fflush(stdin);
    printf("\nPhone number: %lld",(contact[n]->phone_number));
    fflush(stdin);
    printf("\nGender:%s",contact[n]->gender);
    fflush(stdin);
    printf("\nEmail ID:%s",contact[n]->email_id);
    fflush(stdin);
}

//Enter the contact information
void enter(int n)
{
   printf("\nEnter last name:");
   scanf("%14s",contact[n]->last_name);
   string_upper(contact[n]->last_name);
   printf("\nEnter phone number:");
   scanf("%lld",&(contact[n]->phone_number));
   printf("\nEnter Gender(M/F):");
   scanf("%1s",contact[n]->gender);
   string_upper(contact[n]->gender);
   printf("\nEnter Email ID:");
   scanf("%29s",contact[n]->email_id);
}

// To convert string to upper case
void string_upper(char *strings)
{
    for(int i=0;strings[i]!='\0';i++)
    {
        if( (strings[i]>=97) && (strings[i]<=122))
        {
            strings[i]=strings[i]-32;
        }
    }
}

///To sort the contacts in lexicographical order

void sort_contacts(int no)
{
    records *temp;
    for(int i=0;i<no-1;i++)
    {
        for(int j=i+1;j<no;j++)
        {
            if( (strcmp( (contact[i]->first_name),(contact[j]->first_name) )>0))
            {
                temp=contact[i];
                contact[i]=contact[j];
                contact[j]=temp;
            }
        }
    }
}
