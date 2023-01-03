/*
This program will prompt the user to enter a password. This password is compared to a pre-defined string,
and if the comparison is successful it prints a statement accordingly; if it isn't, it prints another
statement.

The interesting thing about this program is that with every character entered by the user, a '*' character is
printed, thus encrypting the password entered by the user on user.

The crucial element to realise this is to use GATCH(), not GETCHAR().

GETCHAR() buffers the input, whereas GETCH() does not: every eneterd character is immediately returned
without waiting for the ENTER key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //---> for GETCH()

#define MAX 30

int main(int argc, char *argv[]) {
		
	char pasword[] = "hello world!";
	char password[MAX];
	char ch;
	int i=0;
	
	printf("Enter password:\n");

	ch = getch();

	while(ch != 13){
		
		printf("*");				
		password[i] = ch;		
		i++;
		ch = getch();
	}
	
	password[i] = '\0';
	
	if(strcmp(password, pasword) == 0)
		printf("\n\nPassword correct!!!");
	else
		printf("\n\nSorry: password incorrect");
	
	return 0;
}



