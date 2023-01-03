/*
This program will demonstrate TWO WAYS to add all digits of an integer entered by the user.

************************************************************************************************************************************************
*																																			   *
*																																			   *
*											WAY 1 : USING WHILE LOOP																		   *
*																																			   *
*																																			   *
************************************************************************************************************************************************


The important code in this programme lies in the FUNC() function below:

	int addingDigits(int enteredVal) { 
		
		int sum=0, singleDigit=0;
		
		while(enteredVal!=0) {
			
			singleDigit = enteredVal % 10;
			
			sum += singleDigit;
			
			enteredVal = enteredVal / 10;
		}
			
		return (sum);
	}
	
What does all this mean?

All in all, the point of this is to isolate each digit of integer 124 (so: 1, 2 and 4) to add them up (giving us 7). Our operations will isolate 
these digits from RIGHT to LEFT.

Say a number: enteredVal = 124


****************** step 1 **********************

firstly: we will isolate digit 4:

		enteredVal % 10; =====> here: modulus of 124 is 4 (124 / 10 == 120 + 4, 4 being the remainder of the division)
		
we then assign 4 to variable singleDigit:

		singleDigit = enteredVal % 10;
		
		

****************** step 2 **********************
		
secondly: we add this digit to variable "sum":

		sum += singleDigit;
		
		
		
****************** step 3 **********************			

lastly: we truncate the initial integer by 1 digit (the RIGHTMOST digit), by diving it by 10 and assigning the result to itslef:

		enteredVal = enteredVal / 10;
		
		
****************** step 4 **********************

The whole process is repeated (so: with integer 12 this time) in a WHILE loop:

		while(enteredVal!=0) {
			
			...
			...
			...
		}

The terminating factor of this loop is the integer being equal/inferior to 0.

Let's fast-forward to the very last operation of the series:

		1 % 10 == 0;
		
When the result is indeed equal/inferior, then the programme quits the above lines and 
simply returns the last value of sum to a variable in MAIN():

		return (sum);
		
		
************************************************************************************************************************************************
*																																			   *
*																																			   *
*											WAY 2 : USING RECURSION																		   	   *
*																																			   *
*																																			   *
************************************************************************************************************************************************

Recursion can also be used to add digits of a given integer.

The process in the adding-digit function is very much similar to the first one above, apart from TWO differences:

		1) variable SUM no longer takes its final definitive value through repetitious addition and assignment as in:
		
			while (...) {
			
				sum += singleDigit;
			}
			
			Rather, it takes its final definitive value from the addition of the "singleDigit" variable with the returned result of the
			repetitive call of the function it is itself in until a value is matched with that of an IF statement (this IF statement 
			being itself "sucked into" the recursive call of the function!):
			
			if(enteredVal!=0) {
			
				...
				...
				sum = singleDigit + addingDigits2(enteredVal);
			}
			
			As soon as the integer is equal/inferior to 0, the function returns the last value of SUM to MAIN():
			
			if(enteredVal != 0) {
			
				singleDigit = enteredVal % 10;	
				enteredVal = enteredVal / 10;	
				sum = singleDigit + addingDigits2(enteredVal);
				
			}
		
		
		2)	contrary to the first function above, the order of these 3 steps in the IF's body MUST be observed, since the recursive call of function
			addingDigits2(enteredVal) requires a NEW/CHANGED/TRUNCATED value of variable "enteredVal" to procede (if we simply
			interchange the order of the setps 2 and 3, as we can do above in the first function, then the loop is infinite, the
			value of variable "enteredVal" never changing and the IF statement never detecting FALSE!!)			

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
/************************************************************************************************************************************************
*																																			   *
*																																			   *
*											WAY 1 : USING WHILE LOOP																		   *
*																																			   *
*																																			   *
***********************************************************************************************************************************************/

	printf("********** CASE 1: USING WHILE LOOP ************");
	
	int a;
	
	//calling  our input function:
	a = enterVal();
	
	while (a != 0) {
		
		//calling our FIRST digit-adding function:
		a = addingDigits1(a);
				
		//printing:
		printf("a = %d", a);
		
		//repeat (if desired) 		
		a = enterVal();		
	}
	
	//END OF WAY 1.
	
/***********************************************************************************************************************************************
*																																			   *
*																																			   *
*												WAY 2 : USING RECURSION																		   *
*																																			   *
*																																			   *
***********************************************************************************************************************************************/

	printf("\n\n********** CASE 2: USING RECURSION ***********");
	
	int b;
	
	b = enterVal();	
	
	while (b != 0) {
		
		//calling our SECOND digit-adding function:
		b = addingDigits2(b);
				
		//printing:
		printf("b = %d", b);
		
		//repeat (if desired) 		
		b = enterVal();		
	}

	//END OF WAY 2.
	
	printf("\nThanks, bye!");
		
	return 0;
}

int enterVal() {
	
	int var1;
		
	printf("\n\nEnter number (press 0 to terminate)\n");
	scanf("%d", &var1);
	
	return (var1);		
}


//****************************************** WAY 1: USING WHILE LOOP **************************************************************

int addingDigits1(int enteredVal) { 
		
	int sum=0, singleDigit=0;
		
	while(enteredVal!=0) {
		
		//step 1: assigning each digit of the integer from RIGHT to LEFT:	
		singleDigit = enteredVal%10;
		
		//step 2: adding this digit to variable SUM (THIS STEP COULD HAVE BEEN STEP 3 ==> interchangeable):	
		sum += singleDigit;
		
		//step 3: truncating the initial integer by one digit (THIS STEP COULD HAVE BEEN STEP 2 ==> interchangeable):	
		enteredVal = enteredVal/10;
		
		//step 4: repeating the process until integer == 0
	}
			
	return (sum);
}

//****************************************** WAY 2: USING RECURSION **************************************************************

int addingDigits2(int enteredVal) { 
		
	int sum=0, singleDigit=0;
		
	if(enteredVal!=0) {
		
		//step 1: assigning each digit of the integer from RIGHT to LEFT:	
		singleDigit = enteredVal%10;
		
		//step 2: truncating the initial integer by one digit:	
		enteredVal = enteredVal/10;
		
		//step 3: adding this digit to variable sum AS WELL AS ALL OTHER VALUES FROM RECURSIVE CALL OF FUNCTION:	
		sum = singleDigit + addingDigits2(enteredVal);
		
		/*
			NOTE: contrary to the first function above, the order of these 3 steps MUST be observed, since the recursive call of function
					addingDigits2(enteredVal) requires a NEW/CHANGED/TRUNCATED value of variable "enteredVal" to procede (if we simply
					interchange the order of the setps 2 and 3, as we can do above in the first function, then the loop is infinite, the
					value of variable "enteredVal" never changing and the IF statement never detecting FALSE!!)
		*/
	}
			
	return (sum);
}
