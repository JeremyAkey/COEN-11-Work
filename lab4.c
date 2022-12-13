#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

// This code was written by Jeremy Akey for Lab 2 of COEN11

customer customers[];
int count = 0;

//Main function with a switch statement
int main(void){
 int i,answer, input;
   for(i=0;i<MAX_LIST_SIZE;i++){
       customers[i].name[0] = '\0';
   }
//Initializing the name array with nulls in each location.

  printf("What would you like to do?\n");
   
    while (1) {
    
    scanf("%d", &answer);
//Switch statement to run each function according to the users input
    switch (answer) {

        case 1:
            addName();
             break;

        case 2:
            fulfill();
            break;

        case 3:
            list();
            break;

        case 4:
            printf("What is the largest size you would like to search for?\n");
            scanf("%d",&input);
            smallerThan(input);
            break;

        case 0:
            printf("Thank you for using the Boba Shop Ordering System!\n");
            return 0;
            break;
	default:
	    printf("Please enter a valid input");
	    break;
	}
    }
}
//Function to add orders
void addName(void){
int i, input;
char holder[MAX_NAME_LENGTH];
holder[0] = '\0';

if(count < 9){
printf("Enter a name for the order!\n");
scanf("%s",holder);
 for(i=0;i<MAX_LIST_SIZE;i++){
        if(strcmp(holder, customers[i].name) == 0){
            printf("This name is already taken, please enter a different name\n");
            return;
        }
    }
strcpy(customers[count].name, holder);
printf("Enter the amount of drinks ordered\n"); //Add names to the name array depending on the number of names already in it, and it lets you know if the list is full.
scanf("%d",&customers[count].size);
printf("What is the source of your order? (1 for Phone, 2 for Order Number)\n");
scanf("%d",&input);
switch(input){

    case 1:
    printf("Please enter the phone number associated with the order!\n");
    scanf("%s",&customers[count].confirm.phone);
    customers[count].type = 1; 
        break;

    case 2:
    printf("Please enter the order number for your order!\n");
    scanf("%d",&customers[count].confirm.ordernum);
    customers[count].type = 2;
        break;

    default:
    printf("Enter a valid number!\n");
    customers[count].name[0] = '\0';
    customers[count].size = 0;
    return;
        break;
}
count++;

} else if(count == 9){
printf("The queue is full! Please wait for an order to be fulfilled!\n");
} 



    return;
}
//Function to fulfill orders
void fulfill(void){

    int i,j,num,holder;
    printf("Enter the number of orders that you want to fulfill\n");
    scanf("%d",&num);
    for(i=0;i<MAX_LIST_SIZE;i++){ //Compares the input size to the size of each order, and shifts everything up if an order is fulfilled. It keeps doing this until it can fulfill any more orders.
	   holder = customers[i].size;
        if(num >= holder && holder != 0) {
	        printf("You fulfilled %s's order of %d drinks!\n",customers[i].name,customers[i].size);
	        num = num - holder;
		count--;
            for(j=i;j<MAX_LIST_SIZE-1;j++){
	        customers[j] = customers[j+1];
                
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
void list(void){
int i;

        for (i = 0; i < MAX_LIST_SIZE; i++) { //Lists all of the orders in the list, and it says Free if there is no order in that location.
            if (count == 0) {
               	printf("The schedule is empty\n");
		break;
	    }
	  if (customers[i].name[0] == '\0') {
                printf("Free\n");
            }
            else if(customers[i].type == 1){
                printf("%s has this order for %d, with attached phone number %s\n", customers[i].name, customers[i].size, customers[i].confirm.phone);
            } else{
                printf("%s has this order for %d, with attached order number %d\n", customers[i].name, customers[i].size, customers[i].confirm.ordernum);
            }
        }
        return;
}

void smallerThan(int input){
    int i;

    for(i=0;i<MAX_LIST_SIZE;i++){
        if(input >= customers[i].size){
            if(customers[i].name[0] == '\0'){
                return;
            }
            printf("%s's order of %d drinks\n",customers[i].name,customers[i].size);
        }
    }
    return;
}

//1. The struct definition for a customer is 
//struct customer {
//char name[MAX_NAME_LENGTH];
//int size;
//};
//
//2. I prefer this approach if its done from the start of a program. I think that it helps to keep all of your data in one place, and you don't need to fumble around with other variables. The only part I didn't like was remaking my program to work with them, it was a doozy.
//3. I could allow employees to input customers as first name space last name by recieving the First and Last name with a space in between as an input, then using a while loop to traverse the string until the space, and copying the first part to the first name definition in the structure, and the last name to the last name.









