/*
This program will determine whether a number entered by the user is prime or not.

There are several steps in order to achieve this:

1) ESTABLISHING ALL PRIME NUMBERS FROM TO X (and subsequently saving these primes in an INT array, SAVE[])
2) COMPARING EACH AND EVERY PRIME NUMBER FOUND AND SAVED IN SAVE[] ARRAY WITH NUMBER X

SEE END OF OR PROGRAM FOR DETAILED RUN-THROUGH AND EXPLANATION.

REMINDER: a number is considered a prime number when and ONLY when it is divisible by 1 and itself.

Hence: the trick here is to rely on the number of divisions (n) which have occurred in our loops and which we will have calculated.

If that number of divisions is equal to 2 (which will inevitably mean: by 1 and itself==current number), as we will show below,
then it means it is prime!

In other words:

"i" represents the numerator (== outer-loop), and "j" is the denominator (== inner loop). 
In our case, "j" is a fast-changing/incrementing denominator, constantly dividing a slower-changing/incrementing "i". 
The occurring divisions are counted by our variable "n". If in the end "n" is equal to 2 (because a prime number is only divisible:
(1) by 1; (2) by itself), then the numerator "i" is a prime number! 

*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int i, j, n=0, x; //NOTE: "i" is the number which will be printed if it is prime
	static int num;
	int save[10000], count=0, a, tag, stop=0;
	
/**************************************** STEP 1 : PROMPTING THE USER TO ENTER A VALUE FOR X ****************************************/
	
	printf("Enter a number, and this program will say if it is prime or not:\n");
	scanf("%d", &x);
	

/**************************************** STEP 2 : ESTABLISHING ALL PRIME NUMBERS FROM 2 TO X ****************************************/
	
	/*
	(1) this first FOR loop is the big/outer loop: 
		every value of its iterator (I) serves as the main value to be checked by the 2nd iterator in the smaller/inner loop;
		this iterator I starts off with 2 (not with 1, because 1 is not considered a prime number), and we use the value X entered
		by the user as the limit of I
	*/
	for(i=2; i<=x; ++i) { 
		
		/*
		(2) this second FOR loop does all the calculating (dividing, modulo):
			by using I as its limit, J divides I in order to check whether the division has a remainder;
			if it has no remainder (==0), a variable N (== number of successful divisions) is incremented 
		*/
		for (j=1; j<=i; ++j) {
			
			if (i%j == 0)
				++n; 
		}
		
		/*
		(3) counting/checking the number of divisions:
			if the total number of divisions is equal to 2 ("only by 1 and itself"), the current value of iterator I is a prime!
			this value of iterator I is then saved in an integer-type array, the counter of which is then incremented.
		*/		
		if (n == 2) {
			save[count] = i;
			++count;
		}
		
		/*
		(4) starting the bigger/outer loop again:
			- number of divisions (variable N) is re-initialized to 0, and we go back to the bigger/outer loop;
			- here, iterator I is incremented (also: checked if it is not superior to number X entered by user), and the whole thing starts off again.
		
		WHEN iterator I is greater than the number X entered by the user, we exit this bigger/outer loop entirely and continue below.
		*/			
		n = 0;	
	}
	
/**************************************** STEP 3 : COMPARING ALL PRIME NUMBERS FOUND WITH X ****************************************/
		
	/*
	(1) assigning the latest value of the array's counter to another variable:
		this other variable will serve as the limit to the following FOR loop below.
	*/
	tag = count;
	
	
	/*
	(2) using a FOR loop to compare our initial number x with all the saved prime numbers in the array:
		- if there is a match, number is declared as prime;
		- a STOP variable is incremented (which stops the program from printing a COUT statement below saying that number X is not prime)
		- finally, a BREAK statement is used to exit the loop.
	*/	
	for (a=0; a<=tag; ++a) {
		
		if (save[a] == x) {
			printf("\n%d is a prime number!", x);
			stop = 1;
			break;
		}
	}
	
	/*
	(3) OPTIONAL: if ever no match has been found between all primes saved in the array and number X entered by the user,
					an IF statement checks whether the variable STOP has indeed NOT been incremented, the case of which then
					signals the program to print a COUT statement saying that number X is not a prime.
	*/	
	if (stop == 0)
		printf("\n%d is not a prime number.", x);	
		
	return 0;
}




/*

**************************************************************************************************************************
*																												         *
*																												         *
*													DUMMY RUN															 *
*																												         *
*																												         *
**************************************************************************************************************************
	
									   **************************************
									   * number entered by the user (X): 7 *
									   **************************************
									   
									   
	
	number X (limit) = 7
	
****  BIG OUTER LOOP:  ******************
	
	is "i"(2) <= 7 ? YES (=> remember: the minimum number we start off with is 2, not 1, as 1 is not a primary number)
					==> we continue
					
	********  SMALL INNER LOOP:  *****************
		
		loop no 1:		
		is "j"(1) <= i(2) ? YES
						==> we continue	
		j == 1	i(2)%j(1) == 0 
				==> good, we do the loop again
				==> incrementing "n" (==1) ["n" being the number of divisions which have occurred]
				==> incrementing "j" (==2)

		loop no 2:		
		is "j"(2) <= i(2) ? YES
						==> we continue	
		j = 2 	==> i(2)%j(2) == 0 
				==> good, we do the loop again
				==> incrementing "n" (==2) ["n" being the number of divisions which have occurred]
				==> incrementing "j" (==3)
		
		loop no 3:
		is "j"(3) <= i(2) ? NO
						==> END OF SMALL INNER LOOP	
							***********************
			
		THE IF STATEMENT:	
		is "n" (number of divisions) == 2 ? ==> YES !!
									==> so: i (== 2) is prime!!
									==> it is saved in INT array SAVE[]
									==> incrementing "count" (for further use of this array)
									
									
	==>RESTART OF BIG OUTER LOOP (incrementing i == 3)  (n set to zero, j set to 1)
	   ****************************************************************************								

				
*********************************************  new outer loop ****************************************************************
	
	number X (limit) = 7 
	
****  BIG OUTER LOOP:  ******************
	
	is "i"(3) <= 7 ? YES
					==> we continue
					
	********  SMALL INNER LOOP:  *****************				
					
		(j == 1 [reset])
		
		loop no 1:
		is "j"(1) <= i(3) ? YES
						==> we continue
		j == 1 	==> i(3)%j(1) == 0 
				==> good, we do the loop again
				==> incrementing "n" (==1) ["n" being the number of divisions which have occurred]
				==> incrementing "j" (==2)
				
	    loop no 2:
		is "j"(2) <= i(3) ? YES
						==> we continue
		j = 2 	==> i(3)%j(2) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (still == 1) ["n" being the number of divisions which have occurred]
				==> incrementing "j" (==3)
				
		
		loop no 3:
		is "j"(3) <= "i"(3) ? YES
						==> we continue
		j = 3 	==> i(3)%j(3) == 0 
				==> good, we do the loop again
				==> incrementing "n" (==2) ["n" being the number of divisions which have occurred]
				==> incrementing "j" (==4)
				
				
		loop no 4:
		is "j"(4) <= "i"(3) ? NO
						==> END OF SMALL INNER LOOP
						    ***********************
		
		THE IF STATEMENT:				
		is "n" (number of divisions) == 2 ? ==> YES !!
									==> so: i (== 3) is prime!!
									==> it is then saved in our INT array SAVE[]
									==> incrementing "count" (for further use of this array)
									
									
	==>RESTART OF BIG OUTER LOOP (incrementing i == 4)  (n set to zero, j set to 1)
	   ****************************************************************************	
	   

								
*********************************************  new outer loop ****************************************************************

	number X (limit) = 7

****  BIG OUTER LOOP:  ******************
	
	is "i"(4) <= 7 ? YES
					==> we continue
					
	********  SMALL INNER LOOP:  *****************
	
		(j == 1 [reset])					
		
		loop no 1:			
		is "j"(1) <= "i"(4) ? YES
						==> we continue
		j = 1 	==> i(4)%j(1) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==1)
				==> we also increment "j" (==2)
					
		loop no 2:			
		is "j"(2) <= "i"(4) ? YES
						==> we continue
		j = 2 	==> i(4)%j(2) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==2)
				==> we also increment "j" (==3)	
				
		loop no 3:		
		is "j"(3) <= "i"(4) ? YES
						==> we continue
		j = 3 	==> i(4)%j(3) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 2)
				==> we also increment "j" (==4)
				
		loop no 4:		
		is "j"(4) <= "i"(4) ? YES
						==> we continue
		j = 4 	==> i(4)%j(4) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==3)
				==> we also increment "j" (==5)
				
		loop no 5:		
		is "j"(5) <= "i"(4) ? NO
						==> END OF SMALL INNER LOOP
						    ***********************
						    
		THE IF STATEMENT:				
		is "n" (number of divisions) == 2 ? ==> NO !!
									==> so: i (== 4) is NOT a prime!!
									==> therefore: not saved in array SAVE[]
									==> and: no incrementing of "count"
									

	==>RESTART OF BIG OUTER LOOP (incrementing i == 5)  (n set to zero, j set to 1)
	   ****************************************************************************	
								
								
*********************************************  new outer loop ****************************************************************

	number X (limit) = 7

****  BIG OUTER LOOP:  ******************
	
	is "i"(5) <= 7 ? YES
					==> we continue
					
	********  SMALL INNER LOOP:  *****************
	
		(j == 1 [reset])
							
		loop no.1:			
		is "j"(1) <= "i"(5) ? YES
						==> we continue
		j = 1 	==> i(5)%j(1) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==1)
				==> we also increment "j" (==2)
					
		loop no.2:		
		is "j"(2) <= "i"(5) ? YES
						==> we continue
		j = 2 	==> i(5)%j(2) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==3)
					
		lop no.3:
		is "j"(3) <= "i"(5) ? YES
						==> we continue
		j = 3 	==> i(5)%j(3) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==4)
				
		loop no.4:		
		is "j"(4) <= "i"(5) ? YES
						==> we continue
		j = 2 	==> i(5)%j(4) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==5)
				
		loop no.6:		
		is "j"(5) <= "i"(5) ? YES
						==> we continue
		j = 5 	==> i(5)%j(5) == 0 
				==> good, we do the loop again
				==> we increment "n" (== 2)
				==> we also increment "j" (==6)
				
		loop no.7:		
		is "j"(6) <= "i"(5) ? NO
						==> END OF SMALL INNER LOOP
						    ***********************
						    
		THE IF STATEMENT:				
		is "n" (number of divisions) == 2 ? ==> YES !!
									==> so: i (== 3) is prime!!
									==> it is then saved in our INT array SAVE[]
									==> incrementing "count" (for further use of this array)
									
									
	==>RESTART OF BIG OUTER LOOP (incrementing i == 6)  (n set to zero, j set to 1)
	   ****************************************************************************	
	   

*********************************************  new outer loop ****************************************************************

	number X (limit) = 7

****  BIG OUTER LOOP:  ******************
	
	is "i"(6) <= 7 ? YES
					==> we continue
					
	********  SMALL INNER LOOP:  *****************
	
		(j == 1 [reset])
							
		loop no.1:			
		is "j"(1) <= "i"(6) ? YES
						==> we continue
		j = 1 	==> i(6)%j(1) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==1)
				==> we also increment "j" (==2)
					
		loop no.2:		
		is "j"(2) <= "i"(6) ? YES
						==> we continue
		j = 2 	==> i(6)%j(2) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==2)
				==> we also increment "j" (==3)
					
		lop no.3:
		is "j"(3) <= "i"(6) ? YES
						==> we continue
		j = 3 	==> i(6)%j(3) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==3)
				==> we also increment "j" (==4)
				
		loop no.4:		
		is "j"(4) <= "i"(6) ? YES
						==> we continue
		j = 2 	==> i(6)%j(4) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 3)
				==> we also increment "j" (==5)
				
		loop no.6:		
		is "j"(5) <= "i"(6) ? YES
						==> we continue
		j = 5 	==> i(6)%j(5) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 3)
				==> we also increment "j" (==6)
				
		loop no.7:		
		is "j"(6) <= "i"(6) ? YES
						==> we continue
		j = 5 	==> i(6)%j(6) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==4)
				==> we also increment "j" (==7)
				
		loop no.7:		
		is "j"(7) <= "i"(6) ? NO
						==> END OF SMALL INNER LOOP
						    ***********************
						    
		THE IF STATEMENT:				
		is "n" (number of divisions) == 2 ? ==> NO !!
									==> so: i (== 6) is NOT a prime!!
									==> therefore: not saved in array SAVE[]
									==> and: no incrementing of "count"
									
									
	==>RESTART OF BIG OUTER LOOP (incrementing i == 7)  (n set to zero, j set to 1)
	   ****************************************************************************	
								
*********************************************  new outer loop ****************************************************************

	number X (limit) = 7

****  BIG OUTER LOOP:  ******************
	
	is "i"(7) <= 7 ? YES
					==> we continue
					
	********  SMALL INNER LOOP:  *****************
	
		(j == 1 [reset])
		
		loop no.1:			
		is "j"(1) <= "i"(7) ? YES
						==> we continue
		j = 1 	==> i(7)%j(1) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==1)
				==> we also increment "j" (==2)
					
		loop no.2:		
		is "j"(2) <= "i"(7) ? YES
						==> we continue
		j = 2 	==> i(7)%j(2) != 0
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==3)
					
		lop no.3:
		is "j"(3) <= "i"(7) ? YES
						==> we continue
		j = 3 	==> i(7)%j(3) == 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==4)
				
		loop no.4:		
		is "j"(4) <= "i"(7) ? YES
						==> we continue
		j = 4 	==> i(7)%j(4) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==5)
				
		loop no.6:		
		is "j"(5) <= "i"(7) ? YES
						==> we continue
		j = 5 	==> i(7)%j(5) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==6)
				
		loop no.7:		
		is "j"(6) <= "i"(7) ? YES
						==> we continue
		j = 6 	==> i(7)%j(6) != 0 
				==> we do the loop again
				==> here: we do NOT increment "n" (STILL == 1)
				==> we also increment "j" (==7)
				
		loop no.7:		
		is "j"(7) <= "i"(7) ? YES
						==> we continue
		j = 7 	==> i(7)%j(7) == 0 
				==> good, we do the loop again
				==> we also increment "n" (==2)
				==> we also increment "j" (==8)
				
		loop no.8:		
		is "j"(8) <= "i"(7) ? NO
						==> END OF SMALL INNER LOOP
						    ***********************
						    
		THE IF STATEMENT:								
		is "n" (number of divisions) == 2 ? ==> YES !!
									==> so: i (== 7) is prime!!
									==> it is then saved in our INT array SAVE[]
									==> incrementing "count" (for further use of this array)
									
									
	==>RESTART OF BIG OUTER LOOP (incrementing i == 8)  (n set to zero, j set to 1)
	   ****************************************************************************
	   
	   
*********************************************  new outer loop ****************************************************************

	number X (limit) = 7

****  BIG OUTER LOOP:  ******************
	
	is "i"(8) <= 7 ? NO!!!
					==> WE QUIT THE BIG/OUTER LOOP !!!
					
******************************************************************************************************************************						
******************************************************************************************************************************
******************************************************************************************************************************
******************************************************************************************************************************
******************************************************************************************************************************
   
 Once this first stage is done (ie: when index "i" of the OUTER loop is SUPERIOR to the number X entered by the user),
 we do the following:
 
 1) assign the latest value of "count" to variable "tag", which will serve in the following FOR loop:
 
 		tag = count;
 
 2) this next FOR loop will then serve to go through the SAVE[] array, inside which we have saved all the 
 prime numbers found above, comparing each of these prime numbers with number X entered by the user:
 
 
 3) if it is indeed a match, then a COUT statement will be printed, variable STOP will be set to 1, and the BREAK statement
 will lead us out of the FOR loop
			|
			==> NOTE: this STOP variable serves as a BOOLEAN-type variable: it will serve us nicely for the following statement
			
4) if it is NOT a match, then the last IF statement (which verifies that STOP is indeed NOT equal to 0) will enable the program to 
print a different COUT statement (NOTE: if STOP == 0, it means that none of the above prime numbers contained within SAVE[] array 
have matched the number X entered by the user, therefore STOP will not have been assigned the value 1, and will thus keep its 
initial assigned value of 0)
 			
*/
