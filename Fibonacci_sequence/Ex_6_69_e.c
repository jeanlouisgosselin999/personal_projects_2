/*
This program will calculate Fibonacci numbers.
Remember: the Fibonacci is defined by this sequence:

F(i) = F(i-1) + (i-2)

...whereby each number is equal to the sum of the previous two numbers.

NOTE: the sequence usually starts from F0 == 0 and  F1 == 1;
		|
		|--> NOTE: a Fibonacci program ALWAYS starts off with these two values (0 and 1), they are COMPULSORY!
		
then after that: F2 = F1 + F0 = 1+0 = 1;
then: F3 = F2 + F1 = 1+1 = 2;
and: F4 = F3 + F2 = 2+1 = 3;
and: F5 = F4 + F3 = 3+2 = 5;
and: F6 = F5 + F4 = 5+3 = 8;
and: F7 = F6 + F5 = 8+5 = 13;
and: F8 = F7 + F6 = 13+8 = 21;
and: F9 = F8 + F7 = 21+13 = 34;
and so forth...
 
Also: this is not a hard exercise. It involves 6 very simple steps: *******
1) declaring and defining the first two initial values of both Fibonacci variables, as well as the sum variable;
2) prompting the user to define a value which will determine the limit of the sequence (otherwise: we have an infinite loop!);
3) assigning the result of the addition of both variables into a current sum variable;
4) checking if the sum variable is greater than the limit number the user has entered (in which case: we exit the loop and program terminates);
5) printing the sum (ie: new Fibonacci number);
6) swapping the values of these variables.

Fibonacci is first and foremost a VISUAL exercise, which requires minimal observation. 
Observe the explanation notes at the end of this program to understand why.

******* We will notice two things:
- we use TRUE as the condition in the WHILE loop
- we check if the sum variable is greater than the limit number INSIDE the WHILE loop, for a specific reason:

if we check if the sum variable is greater than the limit number in the loop's CONDITION (so: if we place this condition
between the brackets instead of the TRUE value), the program will inevitably print ONE MORE value GREATER than the limit the user
has entered (verify this myself, pen on paper).

It is why we place a TRUE value as the condition of the WHILE loop and place the checking code immediately AFTER the sum of
both previous Fibonacci numbers has been done.

The use of this TRUE constant requires us to #DEFINE this before MAIN(), as we have done below (the value 1 being the "true" value)

*/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

int main(int argc, char *argv[]) {
	
	//1) declaring and defining the first two initial values of both Fibonacci variables, as well as the sum variable:
	int first=0; // == first "f" number (left)
	int second=1; // == second "f" number (right)		
	int currentSum;


	//2) prompting the user to define a value which will determine the limit of the sequence (otherwise: we have an infinite loop!)	
	int n; 
	printf("Enter an integer, and the program will print all Fibonacci numbers from 0 to that integer: \n\n");
	scanf("%d", &n);
	
	printf("\nHere are your numbers: 0 ");
	
	
	while(TRUE) {

		//3) assigning the result of the addition of both variables into a current sum variable:
		currentSum = first + second;
		
		//4) checking if the sum variable is greater than the limit number the user has entered (in which case: we exit the loop and program terminates):
		if (currentSum > n)
			break;
		
		//5) printing the sum (ie: new Fibonacci number):
		printf("%d ", currentSum);
			
		//6) swapping the values of these variables:
		second = first;
		first = currentSum;
	
	}
				
	getchar();	
	
	return 0;
}


		/*
		NOTE:
		we can also use a much simpler syntax, by using a conditional statement:
	
		n -= 1;
		for(i = 0; i <n; ++i){
			currentSum = (i < 2) ? 1 : first + second;
			printf("%d\n", currentSum);
			
			second = first;
			first = currentSum;
		}
		
		NOTE: this alternative syntax is slightly different, in the sense that variable "n" is the value not of the integer value
			at which the sequence must stop (for instance: for n==10, the program would print: 0 1 1 2 3 5 8), 
			but rather the NUMBER OF VALUES BEING PRINTED (so in this case: 0 1 1 2 3 5 8 13 21 34)
			
		NOTE: the "n -= 1;" expression is needed before the start of the loop, since we already give the value 0 in the initial
		PRINTF() statement.
				
		*/


/**********************************************************************************************************************************/


/*
EXPLANATION OF THE ALGORITHM:

The sequence is thus:

first: F1 = F2 = 1;

then try to visualise the shifting process in all three numbers at the end of each expression
(NOTE: between 1st and 2nd lines, the difference isn't that obvious):

F3 = F2 + F1 = 1 + 1 = 2

				compare this last operation with the next one:
				"first"(1), above, is transferred to "second", below (===> NOT OBVIOUS, BECAUSE THIS FIRST OPERATION HAS TWO "1")
				"currentSum(2), above, is transferred to "first", below.

F4 = F3 + F2 = 2 + 1 = 3

				compare this last operation with the next one:
				"first"(2), above, is transferred to "second", below;
				"currentSum(3), above, is transferred to "first", below.

F5 = F4 + F3 = 3 + 2 = 5

				compare this last operation with the next one:
				"first"(3), above, is transferred to "second", below;
				"currentSum(5), above, is transferred to "first", below.

F6 = F5 + F4 = 5 + 3 = 8

				compare this last operation with the next one:
				"first"(5), above, is transferred to "second", below;
				"currentSum(8), above, is transferred to "first", below.

F6 = F6 + F5 = 8 + 5 = 13

				compare this last operation with the next one:
				"first"(8), above, is transferred to "second", below;
				"currentSum(13), above, is transferred to "first", below.

F8 = F7 + F6 = 13 + 8 = 21

				compare this last operation with the next one:
				"first"(13), above, is transferred to "second", below;
				"currentSum(21), above, is transferred to "first", below.

F9 = F8 + F7 = 21 + 13 = 34

etc etc etc.....


*/
