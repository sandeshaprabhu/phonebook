/**
* @file test_phonebook.c
* phonebook application with 5 operations for testing
*
*/
#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* Modify these two lines according to the project */
#include <phoneheader.h>
#define PROJECT_NAME    "phonebook"

/* Prototypes for all the test functions */
void test_listing(void);
void test_adding(void);
void test_deleting(void);
void test_modifying(void);
void test_searching(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */
  
  
  /* Add your test functions in this format for testing*/
  CU_add_test(suite, "listing", test_listing);
  CU_add_test(suite, "adding", test_adding);
  CU_add_test(suite, "deleting", test_deleting);
  CU_add_test(suite, "modifying", test_modifying);
  CU_add_test(suite, "searching", test_searching);


/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  
  /* run the unit test framework*/
  CU_basic_run_tests();
  
  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */ 
//test listing without adding a contact
void test_listing(void) 
{
   int no=0;
  CU_ASSERT(-1 == listing(no));
  
  /* Dummy fail*/
  CU_ASSERT(1 == listing(no));
}

//testing adding with same name
void test_adding(void) 
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
	
	
  CU_ASSERT(3 == adding(no,"ram"));
  
  /* Dummy fail*/
  CU_ASSERT(4 == adding(no,"bham"));
  //freed allocated space
  for(int i=0;i<no;i++)
   {
       free(contact[i]);
   }
}

void test_deleting(void)
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
   
  CU_ASSERT(2 == deleting(no,"sham"));
  
  /* Dummy fail*/
  CU_ASSERT(1 == deleting(2,"laxman"));
  free(contact[0]);
  free(contact[1]);
}

void test_modifying(void) 
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
   
   
  CU_ASSERT(0 == modifying(no,"laxman"));
  
  /* Dummy fail*/
  CU_ASSERT(1 == modifying(0,"bharath"));
  
  for(int i=0;i<no;i++)
   {
       free(contact[i]);
   }
}

void test_searching(void) 
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
   
   
  CU_ASSERT(1 == searching(no,"ram"));
  
  /* Dummy fail*/
  CU_ASSERT(1 == searching(no,"laxman"));
  
  for(int i=0;i<no;i++)
   {
       free(contact[i]);
   }
}