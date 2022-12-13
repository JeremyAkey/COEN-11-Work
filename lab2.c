#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_SIZE 10
#define MAX_NAME_LENGTH 10
// This code was written by Jeremy Akey for Lab 2 of COEN11
void addName(void);
void fulfill(void);
void list(void);

char names[MAX_LIST_SIZE][MAX_NAME_LENGTH];
int size[MAX_LIST_SIZE];
int count = 0;

//Main function with a switch statement
int main(void){
 int i,answer;
   for(i=0;i<MAX_LIST_SIZE;i++){
       names[i][0] = '\0';
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
int i;
if(count < 9){
printf("Enter a name for the order!\n");
scanf("%s",names[count]);
printf("Enter the amount of drinks ordered\n"); //Add names to the name array depending on the number of names already in it, and it lets you know if the list is full.
scanf("%d",&size[count]);
count++;
} else if(count == 9){
printf("The queue is full! Please wait for an order to be fulfilled!\n");
} 



    return;
}
//Function to fulfill orders
void fulfill(void){

    int i,j,num;
    printf("Enter the number of orders that you want to fulfill\n");
    scanf("%d",&num);
    for(i=0;i<MAX_LIST_SIZE;i++){ //Compares the input size to the size of each order, and shifts everything up if an order is fulfilled. It keeps doing this until it can fulfill any more orders.
	    if(num >= size[i]) {
	        printf("You fulfilled %s's order of %d drinks!\n",names[i],size[i]);
	        num = num - size[i];
		count--;
            for(j=i;j<MAX_LIST_SIZE;j++){
	        strcpy(names[j], names[j+1]);
                size[j] = size[j+1];
                
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
	  if (names[i][0] == '\0') {
                printf("Free\n");
            }
            else {
                printf("%s has this order for %d \n", names[i], size[i]);
            }
        }
        return;
}






//1. The output is two different entries, one with the correct amount of items, and one that is just 'n' with no items. This happens becuase Musurlian is 9 characters long, so setting the max to 8 is one over the limit leading to the last character being put into another part of the string array. This can be prevented by raising the maximum length of the names, or by keeping your name inputs below the max.

//2. The program can handle any input that isnt listed by having a default in the switch that allows it to take every input, not just the ones you specify, and have an output for them.

//3. You can use true and false instead of 1 and 0 in C because of the way the language sees true and false. In C, true and false are 1 and 0, they mean the same thing. In order to change to true and false you would have to use booleans instead of integer functions, but the process remains nearly identical.






