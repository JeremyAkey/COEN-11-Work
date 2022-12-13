#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_SIZE 10
#define MAX_NAME_LENGTH 10
//#define NODE struct NODE
// This code was written by Jeremy Akey for Lab 6 of COEN11
void addName(void);
void fulfill(void);
void list(void);
void smallerThan(int);

typedef struct NODE {
char name[MAX_NAME_LENGTH];
int size;
struct NODE* next;
}*Pnode;

Pnode head = NULL;
Pnode tail = NULL;



//Main function with a switch statement
int main(void){
 int i,answer, input;
  
head = (struct NODE*)malloc(sizeof(struct NODE));
tail = (struct NODE*)malloc(sizeof(struct NODE));
head->next = tail;
tail->next = NULL;

head->name[0] = '\0';
tail->name[0] = '\0';

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
int i;
char holder[MAX_NAME_LENGTH];
holder[0] = '\0';
Pnode p;
Pnode q;
p = head;

printf("Enter a name for the order!\n");
scanf("%s",holder);
if(p->name[0] == '\0' || p->size == 0){ // Entering the order at the Head.
    strcpy(p->name, holder);
    printf("Enter the amount of drinks ordered\n"); 
    scanf("%d",&p->size);
    if(tail == NULL){
        tail = (struct NODE*)malloc(sizeof(struct NODE));
    }
    p->next = tail;
    tail->next = NULL;
    
    

return;
} else { //Entering the order somewhere other than the head.
 
 while(p->next != NULL){
        if(strcmp(holder, p->name) == 0){
            printf("This name is already taken, please enter a different name\n");
            return;
        }
        q = p;
        p = p->next;
    }
    struct NODE* new = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy(new->name, holder);
    printf("Enter the amount of drinks ordered\n"); //Add names to the name array depending on the number of names already in it, and it lets you know if the list is full.
    scanf("%d",&new->size);
    q->next = new;
    new->next = p;
    tail = new;
}

    return;
}

//Function to fulfill orders
void fulfill(void){

    int i,j,num,holder;
    Pnode p;
    Pnode q;
    q = head;
    p = head;


    if(p->name[0] == '\0'){
    printf("There is nothing to fulfill!\n");
    return;
    }

    printf("Enter the number of orders that you want to fulfill\n");
    scanf("%d",&num);
    while(p != NULL){ //Compares the input size to the size of each order, and shifts everything up if an order is fulfilled. It keeps doing this until it can fulfill any more orders.
	   holder = p->size;
        if(num >= holder && holder != 0) {
	        printf("You fulfilled %s's order of %d drinks!\n",p->name,p->size);
	        num = num - holder;
            if(p == head){ //If I'm fulfilling the head
    
                    head = p->next;
                    free(p);
                
            } else if(p == tail){ //I'm fullfilling the tail 
                tail = q;
		p->size = 0;
                free(p);

            } else { //I'm fulfilling the middle
                q->next = p->next;
                free(p);
            }
        }else if(num == 0){
            return;
        }
	q = p;
        p = p->next;
    }
    
return;
}

//List function
void list(void){
int i;
Pnode p;
p = head;
        if (p->name[0] == '\0' || p == NULL || p->size == 0) {
            printf("The schedule is empty\n");
		    return;
	    } 
        while (p != NULL) { //Lists all of the orders in the list, and it says Free if there is no order in that location.
	        if (p->name[0] == '\0' || p->size == 0) {
                printf("Free\n");
            }
            else {
                printf("%s has this order for %d \n", p->name, p->size);
            }
            p = p->next;
        }
        return;
}

void smallerThan(int input){
    Pnode p;
    p = head;

    while(p != NULL){
        if(input >= p->size){
            if(p->name[0] == '\0'){
                return;
            }
            printf("%s's order of %d drinks\n",p->name,p->size);
        }
        p = p->next;
    }
    return;
}


// Cases for input:
//Input is at the beginning (the head)
//Input is not at the head.
// Cases for Fulfill:
//Fulfilling at the head.
//Fulfilling in the middle.
//Fulfilling at the tail.








