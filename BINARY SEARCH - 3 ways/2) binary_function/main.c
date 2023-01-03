#include <stdio.h>
#include <stdlib.h>

#define max_ints 30

void binary_search(int*, int, int, int, int);

int main(int argc, char *argv[]) {
	
	int array[max_ints], searched_val, length;
	
	printf("How many values in array? ");
	scanf("%d", &length);
	
	printf("Enter %d values: \n", length);
	int i;
	for(i=0; i<length; i++){
		
		printf("\nvalue no.%d: ", i+1);
		scanf("%d", &array[i]);
	}
	
	//bubble-sorting:
	int j;
	for(i=0; i<length; i++)
		for(j=0; j<length-1; j++){
			
			if(array[j] > array[j+1]){
				
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
		
	printf("\n\nYour array values in order:\n\n");
	for(i=0; i<length; i++)
		printf("%d ", array[i]);
	
	printf("\nEnter value to be found in array:\n");
	scanf("%d", &searched_val);
	
	int first = 0;
	int last = length - 1;
	int middle = (first+last)/2;
	
	binary_search(array, searched_val, first, last, middle);	
	
	return 0;
}

void binary_search(int* array, int searched_val, int first, int last, int middle){
	
	while(first <= last){
		
		if(searched_val > *(array+middle))
			first = middle + 1;
			
		else if(searched_val < *(array+middle))
			last = middle - 1;
						
		else{
			printf("Value %d found in array!", searched_val);
			break;
		}	
						
		middle = (first+last)/2;			
	}
	
	if(first > last)
		printf("\nSorry, value %d not found in array.", searched_val);	
	
	return;
}








