/*
This program will demonstrate how to create the game Towers of Hanoi, using a recirsive function "transfer(int, char, char, char)".
The point of this game is to transfer n disks (which are placed, bottom up, from biggest to smallest)
from the leftmost pole to the rightmost pole, using the centre pole as a temporary storage pole.
When transferring disks, a bigger disk must never lie on top of a smaller one.

HINT:

The trick to understand this algorithm is to bear in mind that the essential, most crucial step to complete this game is to 
shift the biggest disk (N) from the leftmost pole to the rightmost pole. If the player manages to do this, then he can 
easily complete the game.

So: suppose you are solving the TOH problem with N disks. To move everything to the last pole, you need, as we've just said,
to ultimately move the bottom-most disk to the last pole first. 
However, to do so, you would ideally (and i do mean "ideally", since this is not allowed in the game) need to move 
all N-1 disks above the bottom-most disk to some other pole first (==> here: the Centre/temp pole).
Moving the N-1 disks away from the bottommost disk is equivalent to solving the TOH problem with N-1 disks. 
Therefore, you can write a recursive algorithm.

Basically, the skeletal structure of it is resumed in these three basic steps:

SolveTowersOfHanoi(N disks) {
1) SolveTowersOfHanoi(N-1 disks) to move them away;
2) Move the bottom-most disk to right pole;
3) SolveTowersOfHanoi(N-1 disks) to move them on top of the bottom-most disk.

This is exactly the same structure we find in our function:

1) moving n-1 disks from origin to temporary: transfer (n-1, from, temp, to);
		
2) moving nth disk from origin to destination: printf("Move disk %d from %c to %c \n", n, from, to);
		
3) moving n-1 disks from temporary to destination: transfer(n-1, temp, to, from); 

The question, of course, is WHY are we considering these three steps as vaild, since we know we are not allowed to
shift all N-1 disks in one single pile and in one single go onto our temp pile.

This is why we are using our function RECURSIVELY:

Each time the function is called, our function receives a different set of values for its arguments.
These different values will be pushed onto the STACK independantly of one another, and then popped 
from the stack at the proper time during the execution of the program (REMEMBER: a stack works in a 
"last in - first out" manner!). It is this ability to store and retrieve these independant sets of values 
that allows the recursion to work.

SO: when instructing our program to shift all N-1 disks to the centre/temporary pole (in order to shift the N disk
to the rightmost/destination pole), we leave it up to him to RECURSIVELY do the necessary previous steps in order to achieve
this "N-1 shifting" goal. All we do is benefit from this recursive process by asking the programme to PRINT all these steps
in proper order.

### TRICK 2 ###

Here's another trick to understand the problem:

Let's start with the EASIEST case, whereby N = 1!
So you only have ONE disk to displace, from leftmost pole to rightmost pole:

		|							|							|
		|							|							|
		|							|							|
	----|---- (big disk)			|							|
		|							|							|
-----------------------		-----------------------		---------------------


		|							|							|
		|							|							|
		|							|							|
	    |							|						----|---- (big disk)
		|							|							|
-----------------------		-----------------------		---------------------

Job done. However, to do this single step, we have no use of our three-step function (another, one-step function like
OneStep() would suffice).

Now:
Let'sdo the SECOND EASIEST case, whereby N = 2!
So: you'd have to displace the smallest disk (== N-1) to the CENTRE/TEMPORARY pole, move the biggest disk ( == N) to the
RIGHTMOST/DESTINATION pole, then FINALLY shifting the smallest disk from CENTRE/TEMPORARY pole on top of the biggest disk:



		|							|							|
	  --|-- (small disk == N-1)		|							|
		|							|							|
	----|---- (big disk)			|							|
		|							|							|
-----------------------		-----------------------		---------------------


		|							|							|
		|							|							|
		|							|							|
	----|---- (big disk)		  --|-- (small disk == N-1)		|
		|							|							|
-----------------------		-----------------------		---------------------


		|							|							|
		|							|							|
		|							|							|
	    |		                  --|-- (small disk == N-1)	----|---- (big disk)
		|							|							|
-----------------------		-----------------------		---------------------


		|							|							|
		|							|						  --|-- (small disk == N-1)
		|							|							|
	    |							|						----|---- (big disk)
		|							|							|
-----------------------		-----------------------		---------------------

As we can see, the crucial step was to liberate "big disk" by moving "small disk" to the CENTRE/TEMPORARY,
for us to place "big disk" on the rightmost/destination pole.

THIS IS THE SKELETAL/FUNDAMENTAL FRAME WITH WHICH WE MUST UNDERSTAND THE WHOLE "TOWERS OF HANOI" ALGORITHM.

By using all variables and parameters at their bare minimum (N, N-1, from==origin), to==destination, temp==centre)
in this 2-disk example, we have basically structured our whole algorithmic process, regardless of the value of N!

So if N==38, and so N-1==37, the solution of the whole thing is still THE SAME: we shift N-1 to the centre/temporary pole, 
we shift the bottommost disk (N) to the destination pole and we finish by plaing (N-1) on top of N on the destination pole.

All the other previous steps, we let the computer sort them out through recursion!
 
*/


/*
UNSOLVED PROBLEM : HOW TO COUNT THE TOTAL NUMBER OF MOVES WHICH HAVE OCCURRED DURING THE RECURSIVE CALL OF THE FUNCTON!
*/


#include <stdio.h>
#include <stdlib.h>


//prototype:
void transfer(int, char, char, char);

int main(int argc, char *argv[]) {
	
	int n;
	
	printf("Welcome to the TOWERS OF HANOI.\n\n");
	
	printf("How many disks are you playing with?");
	scanf("%d", &n);
	
	printf("\n");
	
	//"initializing" our function:
	transfer(n, 'L', 'R', 'C');
	
	printf("\nAll done!!");
	
	return 0;
}

//function:
void transfer(int n, char from, char to, char temp) {
	
	/*transferring n disks from one pole to another
	
	/*
	n = number of disks
	from = origin (left pole)
	to = destination (right pole)
	temp = (centre pole)
	*/
	
	if (n > 0) {
			
		//moving n-1 disks from origin to temporary:
		transfer (n-1, from, temp, to);
		
		//moving nth disk from origin to destination:
		printf("Move disk %d from %c to %c \n", n, from, to);
		
		//moving n-1 disks from temporary to destination:
		transfer(n-1, temp, to, from);
	}
		
	return;
}


