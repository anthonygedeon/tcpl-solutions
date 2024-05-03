/*
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in runtime
*/

#include <stdio.h>
#include <stdlib.h>

int binsearch(int needle, int haystack[], int length);

int main(void) {
	int arr[] = {0, 1, 3, 5, 9};
	printf("%i\n", binsearch(5, arr, 5));
	return EXIT_SUCCESS;
}

// find needle in haystack[0] <= haystack[1] <= ... <= haystack[n-1] 
int binsearch(int needle, int haystack[], int length) {
	int low = 0;
	int mid = 0;
	int high = length - 1;

	while (low <= high && needle != haystack[mid]) { // len check T T
		mid = (low+high) / 2; 
		if (needle < haystack[mid]) {
			high = mid - 1; 
		} else { 
			low = mid + 1;
		} 
			
	}

	return (needle == haystack[mid]) ? mid : -1;
}

