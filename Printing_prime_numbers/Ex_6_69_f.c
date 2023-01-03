/*

This program will display N prime numbers (from 2 [1 is not considered a prime number] to an end number of our choice).

IMPORTANT: a number is considered a prime number when and ONLY when it is divisible by 1 and itself.

Hence: the trick here is to rely on the number of divisions (n) which have occurred in our loops and which we have calculated!

If that number of divisions is equal to 2 (which will inevitably mean: by 1 and itself==current number), as we will show below,
then it means it is prime!

In other words:

"i" represents the numerator (== outer-loop), and "j" is the denominator (== inner loop). 
In our case, "j" is a fast-changing/incrementing denominator, constantly dividing a slower-changing/incrementing "i". 
The occurring divisions are counted by our variable "n". If in the end "n" is equal to 2 (because a prime number is only divisible:
(1) by 1; (2) by itself), then the numerator "i" is a prime number! 

*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	
	
	int i, j, n=0, x; //NOTE: "i" is the number which will be printed if it is prime
	static int num;
	
	printf("Enter a number, and the program will display all prime numbers from 2 to that   number:\n");
	scanf("%d", &x);
	printf("\n\n");
	
	//(1) this first FOR loop is the BIG loop: we start off with 2 (not with 1, because 1 is not considered a prime number), and we set the limit to the number entered by the user
	for(i=2; i<=x; ++i) { 
		
		//(2) this second FOR loop does all the calculating (dividing, modulo) and the printing
		for (j=1; j<=i; ++j) {
			
			if (i%j == 0)
				++n; //explaining this "++n" expression:
					/*
					we know that prime numbers are only divisible by 1 and themselves;
					so, "n" represents the NUMBER OF DIVISIONS which have so far ocurred;
					it also serves as that first digit 1 AND the "itself" number it represents ==> meaning: 
					the current number being processed
					So: if the rest of the division is equal to 0, "n" will be incremented;
					otherwise, the incrementation of "n" will simply not occur and we go to counting the final number of divisions
					whih have occurred.
					*/
		}
		
		if (n == 2) {// so: if the total number of divisions is equal to 2 (==> (1) division by 1; (2) division by 2), the current number is a prime!
			printf("%d - ", i);
			++num;
		}
			
		n = 0;	
	}
	printf("\n\nThere are %d prime numbers from 2 to %d", num, x);
	return 0;	
}
	
	/*
	example of a run:
	
	number entered by the user: 25 
	
	x (limit) = 25
	
****  BIG OUTER LOOP:  ******************
	
	is "i"(2) <= 25 ? YES (=> remember: the minimum number we start off with is 2, not 1, as 1 is not a primary number)
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
									
	==>END OF BIG OUTER LOOP 
	   *********************								
		
	"n" reset to 0;
				
****************************************  starting a new outer loop (incrementing i == 3)  (n set to zero, j set to 1)  ************************************
	
	x (limit) = 25
	
****  BIG OUTER LOOP:  ******************
	
	is "i"(3) <= 25 ? YES
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
									
	==>END OF BIG OUTER LOOP 
	   *********************
	   
	"n" reset to 0;
								
****************************************  starting a new outer loop (incrementing i == 4)  (n set to zero, j set to 1)  ************************************

	x (limit) = 25
	
	is "i"(4) <= 25 ? YES
					==> we continue
					
	is "j"(1) <= "i"(4) ? YES
					==> we continue
	j = 1 	==> i(4)%j(1) == 0 
			==> good, we do the loop again
			==> we also increment "n" (==1)
			==> we also increment "j" (==2)
				
				
	is "j"(2) <= "i"(4) ? YES
					==> we continue
	j = 2 	==> i(4)%j(2) == 0 
			==> good, we do the loop again
			==> we also increment "n" (==2)
			==> we also increment "j" (==3)	
			
			
	is "j"(3) <= "i"(4) ? YES
					==> we continue
	j = 3 	==> i(4)%j(3) != 0 
			==> we do the loop again
			==> here: we do NOT increment "n" (STILL == 2)
			==> we also increment "j" (==4)
			
			
	is "j"(4) <= "i"(4) ? YES
					==> we continue
	j = 4 	==> i(4)%j(4) == 0 
			==> good, we do the loop again
			==> we also increment "n" (==3)
			==> we also increment "j" (==5)
			
			
	is "j"(5) <= "i"(4) ? NO
					==> WE QUIT THE INNER LOOP
			
			
	is "n" (number of divisions) == 2 ? ==> NO !!
								==> so: i (== 4) is NOT a prime!!
								
								
****************************************  starting a new loop (incrementing i == 5)  (n set to zero, j set to 1)  ************************************

	x (limit) = 25
	is "i"(5) <= 25 ? YES
					==> we continue
					
					
	is "j"(1) <= "i"(5) ? YES
					==> we continue
	j = 1 	==> i(5)%j(1) == 0 
			==> good, we do the loop again
			==> we also increment "n" (==1)
			==> we also increment "j" (==2)
			
			
	is "j"(2) <= "i"(5) ? YES
					==> we continue
	j = 2 	==> i(5)%j(2) != 0 
			==> we do the loop again
			==> here: we do NOT increment "n" (STILL == 1)
			==> we also increment "j" (==3)
			

	is "j"(3) <= "i"(5) ? YES
					==> we continue
	j = 3 	==> i(5)%j(3) != 0 
			==> we do the loop again
			==> here: we do NOT increment "n" (STILL == 1)
			==> we also increment "j" (==4)
			
			
	is "j"(4) <= "i"(5) ? YES
					==> we continue
	j = 2 	==> i(5)%j(4) != 0 
			==> we do the loop again
			==> here: we do NOT increment "n" (STILL == 1)
			==> we also increment "j" (==5)
			
			
	is "j"(5) <= "i"(5) ? YES
					==> we continue
	j = 5 	==> i(5)%j(5) == 0 
			==> good, we do the loop again
			==> we increment "n" (== 2)
			==> we also increment "j" (==6)
			
			
	is "j"(6) <= "i"(5) ? NO
					==> WE QUIT THE INNER LOOP
					
					
	is "n" (number of divisions) == 2 ? ==> YES !!
								==> so: i (== 5) is a prime!!
								
 ETC ETC ETC ETC ETC.........
 			
*/
	
