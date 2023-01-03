/*
This program will determine whether an input number is prime.

It will use the method called THE SIEVE OF ERATOSTHENES:

It is a simple, ancient algorithm for finding all prime numbers up to any given limit.

It does so by iteratively marking as composite (ie: NOT prime) the multiples of each prime, starting with
multiples of 2, then 3.

Here, after multiples of 3 have been checked, the iterative variable is incremented not by 1 but by 2 (++2), therefore
going through multiples of odd numbers (REMEMBER: the previous tests on multiples of 2 then 3 will have already discarded 
many values; further tests will then become, themsevles, past tests, and so will have, in their turn, discarded many more values etc...)

NOTE:

in cases 1 and 2, we simply check if the number entered by the user is equal to 0, 1 (== not a prime), 2 or 3 (is prime).

The real challenge lies in cases 3 and 4:

- in case 3: we verify if the number is even (ie: if the remainder is equal to 0); if it is, the number is not considered as prime

- in case 4: if the number hasn't proved to be dividable by 2, we then check if the number is dividable by 3 and further odd values
	|
	=> for this: we start the dividor (which is also an iterator) at 3; if the number is not dividable by 3 (ie: if the remainder
		of the division with 3 is not equal to 0), we then increment this dividor/iterator not by 1 as we usually do, 
		but by 2, thereby keeping the dividor/iterator odd.
		If the number is dividable by any of these following dividors/iterators, the program displays a PRINTF statement sating
		that the number is NOT prime and it exits with the function EXIT(0); if however, the number is never dividable by 
		any of these following values, and if the dividor/iterator is GREATER than the number divided by 2, then we exit 
		the loop and the program displays a PRINTF statement stating that the number is indeed prime.
		|
		=> NOTE ON THE LOOP'S LIMIT:
									in the FOR loop, we have set the limit as N/2. The reason for this is simple:
									if no dividor/iterator can be found for the first half of the number, then it
									surely will not be found either in the second half of it! Same goes for the case
									whereby a dividor CAN be found: if it CAN be found in the first half of the number,
									there is no need for us to search in the second half of the number! 
									
									Also, and more importantly: by dividing the number entered by the user in two, we will, 
									at this stage, make sure that the remainder of this division is equal to one, thereby 
									leaving aside the (obvious and unnecessary) prospect that the number is dividable by 1, <
									- which, in this case, would rule out the number of ever being prime! 

*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	
	int n, d, stop = 0;
	
	printf("Enter a positive integer:\n");
	scanf("%d", &n);

	
	//case 1: for numbers 0 and 1:
	if (n < 2)
		printf("%d is not a prime number.", n);
		
		//case 2: for numbers 2 and 3:
		else if (n < 4)
			printf("%d is a prime number!", n);
			
			//case 3: for all even numbers (dividable by 2)
			else if (n%2 == 0)
				printf("%d is not a prime number: %d = 2*%d", n, n, n);
			
				//case 4: for ALL other numbers (dividable by odd values: 3, 5, 7, 9, 11, 13, etc...):
				else {
					
					for (d = 3; d <= n/2; d += 2) //************ see below for explanations
						if (n%d == 0) {	
							printf("%d is not a prime number: %d = %d*%d", d, d, d, n/d);						
							stop = 1;
							break;
			 			}
			 		
					 //exiting FOR loop:
					if (stop == 0)	
			 			printf("%d is a prime number!", n);
				}	
		
	return 0;
}


/*

************ EXPLANATIONS:

In this last FOR loop, the point is to divide the number entered by the user by an ODD number (3, 5, 7, 9, 11, 13, etc...):

1) we start the dividing value (d) at 3, having covered all previous values beforehand;

2) in order to minimise the range of operations by half (and thus save computation time), we set the loop limit at N/2 (N being the number entered by the user)
	|
	==> note: this serves, also, to identify the value 5 as a prime number (n/2 == 5/2 == 2 which is < to d, set at 3)
	==> ALSO: more importantly, by dividing the number entered by the user in two, we will, at this stage, make sure
			  that the remainder of this division is equal to one, thereby leaving aside the (obvious and 
			  unnecessary) prospect that the number is dividable by 1, - which, in this case, would rule
			  out the number of ever being prime! 
	
3) in order to constantly have odd numbers as dividers, we increment this divider (d) by 2, not by 1 (remember: d starts at 3).

Inside this FOR loop, we have an IF statement, which verifies if the remainder of the division of number entered by the user 
by the diviser (d) is equal to 0:
- if it is equal to 0, the number is not prime, since it is dividable by d;
- if it isn't equal to 0, the number is prime.


**************************************************************************************************************************
*																												         *
*																												         *
*													DUMMY RUN															 *
*																												         *
*																												         *
**************************************************************************************************************************
	
									   ***************************************
									   * number entered by the user (X): 83 *
									   ***************************************

	case 1: is 83 < 2?
					|
					=> NO! skip
		
		case 2: is 83 < 4:
						|
						=> NO! skip
			
			case 3: is 83 dividable by 2 (ie: is 83 an even number)?
										|
										=> NO! skip
			
				case 4: is 83 divible by any odd number?
				
							************* 1st loop **************
							
							d == 3;
							
							is 3 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%3 == 0 ? => NO!
												|
												=> END OF 1st LOOP
												=> incrementing d to 5 (++2)
												
												
							************* 2nd loop **************
							
							d == 5;
							
							is 5 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%5 == 0 ? => NO!
												|
												=> END OF 2nd LOOP
												=> incrementing d to 7 (++2)
												
												
							************* 3rd loop **************
							
							d == 7;
							
							is 7 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%7 == 0 ? => NO!
												|
												=> END OF 3rd LOOP
												=> incrementing d to 9 (++2)
												
												
							************* 4th loop **************
							
							d == 9;
							
							is 9 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%9 == 0 ? => NO!
												|
												=> END OF 4th LOOP
												=> incrementing d to 11 (++2)
												
												
							************* 5th loop **************
							
							d == 11;
							
							is 11 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%11 == 0 ? => NO!
												|
												=> END OF 5th LOOP
												=> incrementing d to 13 (++2)
												

							************* 6th loop **************
							
							d == 15;
							
							is 15 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%15 == 0 ? => NO!
												|
												=> END OF 6th LOOP
												=> incrementing d to 17 (++2)
												

							************* 7th loop **************
							
							d == 17;
							
							is 17 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%17 == 0 ? => NO!
												|
												=> END OF 7th LOOP
												=> incrementing d to 19 (++2)
												
												
							************* 8th loop **************
							
							d == 19;
							
							is 19 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%19 == 0 ? => NO!
												|
												=> END OF 8th LOOP
												=> incrementing d to 21 (++2)
												

							************* 9th loop **************
							
							d == 21;
							
							is 21 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%21 == 0 ? => NO!
												|
												=> END OF 9th LOOP
												=> incrementing d to 23 (++2)
												
												
							************* 10th loop **************
							
							d == 23;
							
							is 23 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%23 == 0 ? => NO!
												|
												=> END OF 10th LOOP
												=> incrementing d to 25 (++2)
												
												
							************* 11th loop **************
							
							d == 25;
							
							is 25 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%25 == 0 ? => NO!
												|
												=> END OF 11th LOOP
												=> incrementing d to 27 (++2)
												
												
							************* 12th loop **************
							
							d == 27;
							
							is 27 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%27 == 0 ? => NO!
												|
												=> END OF 12th LOOP
												=> incrementing d to 29 (++2)
												
							************* 13th loop **************
							
							d == 29;
							
							is 29 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%29 == 0 ? => NO!
												|
												=> END OF 13th LOOP
												=> incrementing d to 31 (++2)
												
												
							************* 14th loop **************
							
							d == 31;
							
							is 31 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%31 == 0 ? => NO!
												|
												=> END OF 14th LOOP
												=> incrementing d to 33 (++2)
												
												
							************* 15th loop **************
							
							d == 33;
							
							is 33 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%33 == 0 ? => NO!
												|
												=> END OF 15th LOOP
												=> incrementing d to 35 (++2)
												

							************* 16th loop **************
							
							d == 35;
							
							is 35 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%35 == 0 ? => NO!
												|
												=> END OF 16th LOOP
												=> incrementing d to 37 (++2)
												
												
							************* 17th loop **************
							
							d == 37;
							
							is 37 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%37 == 0 ? => NO!
												|
												=> END OF 17th LOOP
												=> incrementing d to 39 (++2)
												
												
							************* 18th loop **************
							
							d == 39;
							
							is 39 <= 83/2(==41) ? => YES|
							|
							=> we continue
								|
								is 83%39 == 0 ? => NO!
												|
												=> END OF 18th LOOP
												=> incrementing d to 41 (++2)
												
												
							************* 19th loop **************
							
							d == 41;
							
							is 41 <= 83/2(==41) ? => YES| (exactly!!!)
							|
							=> we continue
								|
								is 83%41 == 0 ? => NO!
												|
												=> END OF 19th LOOP
												=> incrementing d to 43 (++2)
												
												
							************* 20th loop **************
							
							d == 43;
							
							is 43 <= 83/2(==41) ? => NO !!!!!!!
							|
							=> WE EXIT THE LOOP (exit(0))
								|
								=>  STOP variable has been changed (stays == 0)
									printf("%d is a prime number!", n);
*/
