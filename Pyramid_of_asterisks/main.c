/*
This program will demonstrate how to create a pyramid of starisks, the numbers of lines of which is decided by the user.

It will print the pattern below:


				_ _ _ _ _ *
				_ _ _ _ * * *
				_ _ _ * * * * *
				_ _ * * * * * * *
				_ * * * * * * * * *
				
NOTE: for further explanations on the algorithm, see below.

*/


#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	
	int a, b, lines, n;
	
	printf("How many lines of asterisks do you want displayed in a pyramid?\n");
	scanf("%d", &n);
	printf("\n");
	
	for (lines = 1; lines <= n; ++lines) { 	
		 
		//first inner loop (for spaces before asterisks):   
		for (a = 1; a <= n - lines; ++a)    			
			putchar(' ');							    
		
		//second inner loop (for printing asterisks):		
		for (b = 1; b <= 2*lines - 1; ++b)  			
			putchar('*');								
				
		printf("\n");									
	}
				
	return 0;
}


/*
EXPLANATION OF ALGORITHM:

This algorithm breaks down into 3 distinct parts or loops:

- 1 OUTER loop, which generates and regulates the LINES of data being printed;

- 2 successive INNER loops:

	(a) the first inner loop generates and counts BLANK SPACES;
	(b) the second inner loop generates and counts ASTERISKS;
	
The main OUTER loop is straightforward: the user enters the numbers of lines (N) to be printed (which, logically, has to start with line number 1
[hence: LINES = 1, at the start of this FOR loop]), and this loop prints out/regulates the number of lines of data being printed according
to the user's entered number (LINES <= N).

Within this OUTER loop lie two INNER loops, which are not themselves embedded but SUCCESSIVE.

Let us start by saying that the tricky thing about this pyramid exercise, first of all, is inserting the blank spaces BEFORE 
each first asterisk of each line.

Therefore, let us change, for one second, the aim of this exercise in order to visualize the display of blank spaces and asterisks more easily.

Say the user enters 6 for variable N, which is the total number of lines of data to be printed. And let's say that, without immediately showing
the code, the program displays the following image:

				_ _ _ _ _ *
				_ _ _ _ * *
				_ _ _ * * *
				_ _ * * * *
				_ * * * * * 
				
What we have here is a 'perfect square' of 6 lines, each line containing 6 elements of blank spaces and asterisks 
(the symbol "_" representing blank spaces).

So let's break the computational process down for this specific image:

(1) LINE=1 and LINE <= 6 (n==6)

			---BLANK SPACES FIRST: 

			==> a=1 and a<=6-1 (LINE==1) //=====> print BLANK SPACE ==> ++a
			
				==> a=2 and a<=6-1 (LINE==1) //=====> print BLANK SPACE ==> ++a
				
					==> a=3 and a<=6-1 (LINE==1) //=====> print BLANK SPACE ==> ++a	
					
						==> a=4 and a<=6-1 (LINE==1) //=====> print BLANK SPACE ==> ++a
						
							==> a=5 and a<=6-1 (LINE==1) //=====> print BLANK SPACE ==> ++a
							
								==> a=6 and a NOT <=6-1 (LINE==1) //=====> END OF INNER LOOP 1 (therefore: 5 blank spaces in total); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=1 (LINE==1) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b NOT <=1 (LINE==1) //=====> END OF INNER LOOP 2 (therefore: 1 asterisk in total);	
				 
	++LINE;
	change of line (PRINTF("\n"));
	
(2) LINE=2 and LINE <= 6

			---BLANK SPACES FIRST: 

			==> a=1 and a<=6-2 (LINE==2) //=====> print BLANK SPACE ==> ++a
			
				==> a=2 and a<=6-2 (LINE==2) //=====> print BLANK SPACE ==> ++a
				
					==> a=3 and a<=6-2 (LINE==2) //=====> print BLANK SPACE ==> ++a	
					
						==> a=4 and a<=6-2 (LINE==2) //=====> print BLANK SPACE ==> ++a
							
							==> a=5 and a NOT <=6-2 (LINE==2) //=====> END OF INNER LOOP 1 (therefore: 4 blank spaces in total); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=2 (LINE==2) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b<=2 (LINE==2) //=====> print ASTERISK ==> ++b
			 
			 		==> b=3 and b NOT <=1 (LINE==2) //=====> END OF INNER LOOP 2 (therefore: 2 asterisks in total);	
				 
	++LINE;
	change of line (PRINTF("\n"));	
	
	
(3) LINE=3 and LINE <= 6 (n==6)

			---BLANK SPACES FIRST: 

			==> a=1 and a<=6-3 (LINE==3) //=====> print BLANK SPACE ==> ++a
			
				==> a=2 and a<=6-3 (LINE==3) //=====> print BLANK SPACE ==> ++a
				
					==> a=3 and a<=6-3 (LINE==3) //=====> print BLANK SPACE ==> ++a	
							
						==> a=4 and a NOT <=6-3 (LINE==3) //=====> END OF INNER LOOP 1 (therefore: 3 blank spaces in total); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=3 (LINE==3) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b<=3 (LINE==3) //=====> print ASTERISK ==> ++b
			 	
			 		==> b=3 and b<=3 (LINE==3) //=====> print ASTERISK ==> ++b
			 
			 			==> b=4 and b NOT <=3 (LINE==3) //=====> END OF INNER LOOP 2 (therefore: 3 asterisks in total);	
				 
	++LINE;
	change of line (PRINTF("\n"));
	
	
(4) LINE=4 and LINE <= 6 (n==6)

			---BLANK SPACES FIRST: 

			==> a=1 and a<=6-4 (LINE==4) //=====> print BLANK SPACE ==> ++a
			
				==> a=2 and a<=6-4 (LINE==4) //=====> print BLANK SPACE ==> ++a
	
					==> a=3 and a NOT <=6-4 (LINE==4) //=====> END OF INNER LOOP 1 (therefore: 2 blank spaces in total); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=4 (LINE==4) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b<=4 (LINE==4) //=====> print ASTERISK ==> ++b
			 	
			 		==> b=3 and b<=4 (LINE==4) //=====> print ASTERISK ==> ++b
			 		
			 			==> b=4 and b<=4 (LINE==4) //=====> print ASTERISK ==> ++b
			 
			 				==> b=5 and b NOT <=4 (LINE==4) //=====> END OF INNER LOOP 2 (therefore: 4 asterisks in total);	
				 
	++LINE;	
	change of line (PRINTF("\n"));			
		
			
(5) LINE=5 and LINE <= 6 (n==6)

			---BLANK SPACES FIRST: 

			==> a=1 and a<=6-5 (LINE==5) //=====> print BLANK SPACE ==> ++a
							
				==> a=2 and a NOT <=6-5 (LINE==5) //=====> END OF INNER LOOP 1 (therefore: 1 blank space in total); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=5 (LINE==5) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b<=5 (LINE==5) //=====> print ASTERISK ==> ++b
			 	
			 		==> b=3 and b<=5 (LINE==5) //=====> print ASTERISK ==> ++b
			 		
			 			==> b=4 and b<=5 (LINE==5) //=====> print ASTERISK ==> ++b
			 			
			 				==> b=5 and b<=5 (LINE==5) //=====> print ASTERISK ==> ++b
			 
			 					==> b=6 and b NOT <=5 (LINE==3) //=====> END OF INNER LOOP 2 (therefore: 5 asterisks in total);	
				 
	++LINE;
	change of line (PRINTF("\n"));

	
(6) LINE=6 and LINE <= 6 (n==6)

			---BLANK SPACES FIRST: 

			==> a=1 and a NOT <=6-6 (LINE==6) //=====> END OF INNER LOOP 1 (therefore: no blank space); 
			
			 ---ASTERISKS:
			 
			 ==> b=1 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b	
			 
			 	==> b=2 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b
			 	
			 		==> b=3 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b
			 		
			 			==> b=4 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b
			 			
			 				==> b=5 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b
			 				
			 					==> b=6 and b<=6 (LINE==6) //=====> print ASTERISK ==> ++b
			 
			 						==> b=7 and b NOT <=6 (LINE==6) //=====> END OF INNER LOOP 2 (therefore: 6 asterisks in total);	
				 
	++LINE;
	change of line (PRINTF("\n"));
	
	
(7) LINE=7 and LINE not <= 6 (n==6) //=====> END OF OUTER LOOP //=====> END OF PROGRAM




We can therefore deduct, from this process, that the code for diplaying the pattern below is the following:

				_ _ _ _ _ *
				_ _ _ _ * *
				_ _ _ * * *
				_ _ * * * *
				_ * * * * * 
				

for (lines = 1; lines <= n; ++lines) { 		 
	
	for (a = 1; a <= n - lines; ++a)
		putchar(' ');
								   
	for (b = 1; b <= lines; ++b)  			
		putchar('*');								
				
	printf("\n");								
}


Now: to print the pattern below:


				_ _ _ _ _ *
				_ _ _ _ * * *
				_ _ _ * * * * *
				_ _ * * * * * * *
				_ * * * * * * * * *
				
...we can notice that, starting from line 2, the number of asterisks is equal to:

	number of line (==> int this case: 2) minus 1 == 3
	
Same thing happens for line 3:

	number of line (==> int this case: 3) minus 1 == 5
	
Therefore, all we need to do is slightly change the second inner FOR loop from:

...{

	...
	
		for (b = 1; b <= lines; ++b)  			
		putchar('*');
		
	...
}

to:

...{

	...
	
		for (b = 1; b <= 2*lines - 1; ++b)  			
		putchar('*');
		
	...
}

Et voila!


*/
