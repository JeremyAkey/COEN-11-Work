#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newlab5.h"

// This code was written by Jeremy Akey for Lab 2 of COEN11
int count = 0;

//Main function with a switch statement
int main(int argc, char *argv[] ){
customer *customers;
int number;

if( argc == 2 ) {
      char *a = argv[1];
      number = atoi(a);
      printf("The argument supplied is %d\n", number);
      customers = (struct customer *)malloc(number * sizeof(struct customer));
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
      return 0;
   }
   else {
      printf("One argument expected.\n");
      return 0;
   } 
 
 int i,answer, input;
   for(i=0;i<number;i++){
       (customers + 1)->name[0] = '\0';
   }
//Initializing the name array with nulls in each location.

  printf("What would you like to do?\n");
   
    while (1) {
    
    scanf("%d", &answer);
//Switch statement to run each function according to the users input
    switch (answer) {

        case 1:
             addName(number, customers);
             break;

        case 2:
            fulfill(number, customers);
            break;

        case 3:
            list(number, customers);
            break;

        case 4:
            printf("What is the largest size you would like to search for?\n");
            scanf("%d",&input);
            smallerThan(input, number, customers);
            break;

        case 5:
            printf("What size would you like the array to become?\n");
            scanf("%d",&input);
            number = reSize(input, number, customers);
            break;

        case 0:
            printf("Thank you for using the Boba Shop Ordering System!\n");
            free(customers);
            return 0;
            break;
	default:
	    printf("Please enter a valid input");
	    break;
	}
    }
}
//Function to add orders
void addName(int a, struct customer *p){
int i, input;
char holder[MAX_NAME_LENGTH];
holder[0] = '\0';

if(count < a){
    printf("Enter a name for the order!\n");
    scanf("%s",holder);
     for(i=0;i<a;i++){
        if(strcmp(holder, (p + i)->name) == 0){
            printf("This name is already taken, please enter a different name\n");
            return;
        } 
    }
    strcpy((p+count)->name, holder);
    
    printf("Enter the amount of drinks ordered\n"); //Add names to the name array depending on the number of names already in it, and it lets you know if the list is full.
    
    scanf("%d",&(p+count)->size);
    
    printf("What is the source of your order? (1 for Phone, 2 for Order Number)\n");
    
    scanf("%d",&input);
    
    switch(input){

        case 1: //Uses a switch to determine how the person ordered, and takes the proper input depending on their response.
        printf("Please enter the phone number associated with the order!\n");
        scanf("%s",&(p+count)->confirm.phone);
        (p+count)->type = 1; 
            break;

        case 2:
        printf("Please enter the order number for your order!\n");
        scanf("%d",&(p+count)->confirm.ordernum);
        (p+count)->type = 2;
            break;

        default:
        printf("Enter a valid number!\n");
        (p+count)->name[0] = '\0';
        (p+count)->size = 0;
        return;
            break;
}
    count++;

} else if(count == a){
    printf("The queue is full! Please wait for an order to be fulfilled!\n");
} 



    return;
}
//Function to fulfill orders
void fulfill(int a, struct customer *p){

    int i,j,num,holder;
    printf("Enter the number of orders that you want to fulfill\n");
    scanf("%d",&num);
    for(i=0;i<a;i++){ //Compares the input size to the size of each order, and shifts everything up if an order is fulfilled. It keeps doing this until it can fulfill any more orders.
	   holder = (p+i)->size;
        if(num >= holder && holder != 0) {
	        printf("You fulfilled %s's order of %d drinks!\n",(p+i)->name,(p+i)->size);
	        num = num - holder;
		count--;
            for(j=i;j<a-1;j++){
	        p[j] = p[j+1];
                
            }
            i--;
        }
	    if(num == 0){
	        break;
	    }
    }
    
return;
}

//List function
void list(int a, struct customer *p){
int i;

        for (i = 0; i < a; i++) { //Lists all of the orders in the list, and it says Free if there is no order in that location.
            if (count == 0) {
               	printf("The schedule is empty\n");
		break;
	    }
	  if ((p+i)->name[0] == '\0') {
                printf("Free\n");
            }
            else if((p+i)->type == 1){
                printf("%s has this order for %d, with attached phone number %s\n", (p+i)->name, (p+i)->size, (p+i)->confirm.phone);
            } else{
                printf("%s has this order for %d, with attached order number %d\n", (p+i)->name, (p+i)->size, (p+i)->confirm.ordernum);
            }
        }
        return;
}

void smallerThan(int input, int a, struct customer *p){
    int i;

    for(i=0;i<a;i++){
        if(input >= (p+i)->size){
            if((p+i)->name[0] == '\0'){
                return;
            }
            printf("%s's order of %d drinks\n",(p+i)->name, (p+i)->size);
        }
    }
    return;
}
int reSize(int input,int a, struct customer *p){


if(input >= count){
    p = (struct customer *)realloc(p, input*sizeof(struct customer)); 
    printf("The structure has been resized to size %d!\n", input);  
    return input; 
} else{
    printf("The size is too small for the current amount of elements in the list!\n");
    return a;
}
}










