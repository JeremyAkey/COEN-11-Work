#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIST_SIZE 10
#define MAX_NAME_LENGTH 10
//#define NODE struct NODE
// This code was written by Jeremy Akey for Lab 6 of COEN11
void addName(char *, int);
void fulfill(void);
void list(void);
void smallerThan(int);
void read(char *);
int duplicate(char *);
void save(char *);

typedef struct NODE {
char name[MAX_NAME_LENGTH];
int size;
struct NODE* next;
}*Pnode;

Pnode head = NULL;
Pnode tail = NULL;



//Main function with a switch statement
int main(int argc, char *argv[]){
 int i,answer, input, size;
 char name[MAX_NAME_LENGTH]; 
 FILE *source;
 char *a;

 if( argc == 2 ) {
      a = argv[1];
      printf("The argument supplied is %s\n", a);
      read(a);
   }
   else if( argc > 2 ) {
      printf("Too many arguments supplied.\n");
      return 0;
   }
   else {
      printf("One argument expected.\n");
      return 0;
   } 
  
  printf("What would you like to do?\n");
   
    while (1) {
    
    scanf("%d", &answer);
//Switch statement to run each function according to the users input
    switch (answer) {

        case 1:
            printf("What is the name you would like to insert?\n");
            scanf("%s", name);
            printf("How many orders would you like?\n");
            scanf("%d", &size);
            while(size < 1){

                printf("Enter a valid size!\n");
                scanf("d",&size);

            }
            if(duplicate(name) == 0){
                continue;
            }
            addName(name, size);
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
        case 5:
            read(a);
            break;

        case 0:
            printf("Thank you for using the Boba Shop Ordering System!\n");
            save(a);
            printf("List saved to %s!\n", a);
            return 0;
            break;
	default:
	    printf("Please enter a valid input");
	    break;
	}
    }
}
//Function to add orders
void addName(char *names, int size){

Pnode p;

	if((p=(struct NODE *)malloc(sizeof(struct NODE))) ==  (struct NODE *) NULL)
	{
		printf("Memory cannot be allocated.\n");
		return;
	}
	//Inserting at the head
	if(head == NULL)
	{
		head = p;
		tail = p;
       // printf("here\n");
	}
	//Inserting anywhere else
	else
	{
		tail->next = p;
	}
	//Insert values
	strcpy(p->name,names);
	p->size = size;
	tail = p;
	p->next = NULL;
	//printf("finished\n");
    return;

}

//Function to fulfill orders
void fulfill(){

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
        if (head == NULL) {
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

void read(char *fname)
{
	
	FILE *infp;
	if((infp = fopen(fname, "r")) == NULL)
	{
		printf("Error opening file, starting with empty wait list.\n");
		return;
	}

	fseek(infp,35,SEEK_SET);
	char name[20];
	int size;
	int i;
	while(fscanf(infp,"%s%d",name,&size) == 2)
	{
	
		i = duplicate(name);
		if(i == 0)
		{
			continue;
		}
		addName(name, size);
	}
	
	fclose(infp);
	return;
}


int duplicate(char *str)
{
	Pnode p;
	int i;
		p = head;
		while(p != NULL)
		{
			if(strcmp(str,p->name)==0)
			{
				printf("The name is taken.\n");
				return 0;
			}
			p = p->next;
		}
	return 1;
}

void save(char *fname)
{
	//Make sure file successfully opens
	FILE *outfp;
	if((outfp = fopen(fname, "w")) == NULL)
	{
		printf("Error saving wait list into file.\n");
		return;
	}
	//Put header
	fprintf(outfp,"Name\tOrder Size\n------------------\n");
	//Insert each name, group size in rows
	int i;
	Pnode p;

		p = head;
		while(p != NULL)
		{
			fprintf(outfp,"%s\t%d\n",p->name,p->size);
			p = p->next;
		}
	fclose(outfp);
	return;
}



//To go to the beginning of a file
//fseeek(file_name, 0, SEEK_SET);
//To go to the end of a file
//fseek(file_name, 0, SEEK_END);
//To find the current position
//fseek(file_name, 0, SEEK_CUR);
//Fulfilling at the tail.
//You need to use the read mode.
//You can't use the write mode because it would make an entirely new file, or truncate the existing one to 0.







