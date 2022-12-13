#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//This code was written by Jeremy Akey for COEN 11 Lab 1
int division(int, int);


int main(void){

    srand(time(0)); //Seeds the random
    int i;
	int correct;
    for(i = 0; i<10; i++){ //For loop to generate the random numbers, then to run the function with those numbers

	int divs = (rand() % (12 - 1 + 1)) + 1;

	int quo = (rand() % (12 - 1 + 1)) + 1;

	correct += division(divs, quo); //Counting the number of correct answers
    }
    printf("You got %d/10 right!\n", correct);
    if(correct == 10){ //If they got all the questions right, hire them
	printf("You're Hired!\n");
    } else { //Else don't
	printf("You didnt make the cut!\n");
    }
}

int division(int divs, int quo){ //This function takes a user input and compares it to the correct answer, and outputs accordingly

int divi = divs * quo;
int ans;
int frc = divi/divs;
printf("%d / %d\n", divi, divs);


printf("Please answer:\n");

scanf("%d",&ans);
if(ans == frc){
    printf("Correct!\n");
	return 1;
} else {
    printf("Wrong!\n");
    printf("The right answer was %d\n",frc);
	return 0;
}
	
}

//Answers to the questions
//1.
//Without the srand the random generates the same numbers in the same order.
//2. 
//The compiler sends an error because it reads everything you put after REPETITIONS when you define it, so it also takes the semicolon, which leads to there being an extra one in the for loop.
//3.
//I prevent the divisor from being 0 by having the random number generator generate between 1 and 12, rather than 0 and 12, which solves the divide by zero errors you might otherwise encounter.
//4. 
//The compiler says that all the randoms, and print functions that I am using are implicitly defined, aka they aren't, and it doesn't know what they are or what to do with them.
//
//
//




