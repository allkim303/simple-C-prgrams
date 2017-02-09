/****************************************************************************
	Allison Kim
	
	•	to declare an array structure to store data of common type 
	•	to use parallel arrays to associate related data
	•	to use an iteration construct to process the elements of an array
	
	display the highest temperature and the lowest temperature, and on which 
	day it occurred.
	calculate and display the mean (average) temperature for a period entered 
	by the user, until the user enters a negative number.
	
*****************************************************************************/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main(void) {

	int TemHigh[10];
	int TemLow[10];
	int NumofDay;
	int Day;
	double Total;
	double Average;
	int i;


	printf("---=== IPC Temperature Analyzer V2.0 ===---\n ");
	
	do {

		printf("Please enter the number of days between 3 and 10, inclusive:");
		scanf("%d", &NumofDay);

		if (NumofDay < 3 || NumofDay>10) {

			printf("Invalid entry, ");
		}
	} while (NumofDay < 3 || NumofDay > 10);

	for (i = 0; i < NumofDay; i++) {

		printf("Day %d - High: ", i+1);
		scanf("%d", &TemHigh[i]);
		printf("Day %d - lLow: ", i+1);
		scanf("%d", &TemLow[i]);
	}
	
	printf("Day  Hi  Low\n");

	for (i = 0; i < NumofDay; i++) {

		printf("%d   %d   %d\n", i+1, TemHigh[i], TemLow[i]);
	}

	do {
		printf("Enter a number between 1 and 4 to see the average ");
		printf("temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &Day);
		
		if (Day > 0 && Day <= NumofDay) {

			Total = 0;
			for (i = 0; i < Day; i++) {
				Total += TemHigh[i];
				Total += TemLow[i];
			}

			Average = Total / (Day * 2);
			printf("The average temperature up to day %d is: %.2f\n", Day, Average);
		}
		else if (Day == 0 || Day > NumofDay) {
			printf("Invalid entry, ");
		}
		
	} while (Day >= 0);

	printf("Goodbye!");
	
	return 0;

}