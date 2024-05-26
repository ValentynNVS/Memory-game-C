#include "prototypes.h"

/*
Function: checkAllowence
Parameters:
	int row : the row index to check in the gameValues structure
	int element : the element index within the specified row to check
	struct lineDefault* gameValues : a pointer to the game values structure
Description: This function checks if a specific element in a specified row is allowed by
			 examining the showImage property in the iconStruct. If the showImage property
			 is set to 1, the function returns -1 indicating disallowance; otherwise, it
			 returns 0 indicating allowance.
Return value: int : -1 if the element is not allowed, 0 if it is allowed
*/
int checkAllowence(int row, int element, struct lineDefault* gameValues) {

	if (gameValues[row].iconStruct[element].showImage == 1) {

		return -1;
	}
	else {
		return 0;
	}

}

/*
Function: randomValueAssign
Parameters:
	struct lineDefault* gameValues : a pointer to the game values structure
	int arrayOfRandValues[] : an array to store the assigned random values
Description: This function assigns random values to the hiddenValue field of the iconStruct
			 in the gameValues structure. It ensures that each number between 0 and 9 is
			 generated exactly twice. The assigned values are also stored in the
			 arrayOfRandValues array.
Return value: int : always returns 0
*/
int randomValueAssign(struct lineDefault* gameValues, int arrayOfRandValues[]) {


	int generatedNumbers[10] = { 0 }; // To keep track of how many times each number has been generated
	int index = 0;
	while (index < kNumberOfRows * kNumberOfElements) {
		int generatedNumberTracker = rand() % 10;
		if (generatedNumbers[generatedNumberTracker] < 2) {
			gameValues[index / kNumberOfElements].iconStruct[index % kNumberOfElements].hiddenValue = generatedNumberTracker;
			arrayOfRandValues[index] = generatedNumberTracker;
			generatedNumbers[generatedNumberTracker]++;
			index++;
		}
	}
	return 0;
}


/*
Function: numberTracker
Parameters:
	int numberGenerated : the number to track in the array
	int arrayOfRandNumbers[] : an array of generated random numbers
Description: This function counts the occurrences of numberGenerated in the arrayOfRandNumbers array.
			 If the number appears less than twice, the function returns 1 indicating it can be
			 generated again; otherwise, it returns -1 indicating it should not be generated again.
Return value: int : 1 if numberGenerated appears less than twice, -1 if it appears twice or more
*/
int numberTracker(int numberGenerated, int arrayOfRandNumbers[]) {

	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (arrayOfRandNumbers[i] == numberGenerated) {
			count++;
		}
	}
	return count < 2 ? 1 : -1;
}


/*
Function: openTheIcon
Parameters:
	int row : the row index of the icon to be opened
	int element : the element index of the icon to be opened
	struct lineDefault* gameValues : a pointer to the game values structure
Description: This function sets the showImage property of the specified icon
			 in the gameValues structure to 1, indicating that the icon should be shown.
Return value: int : always returns 0
*/
int openTheIcon(int row, int element, struct lineDefault* gameValues) {

	gameValues[row - 1].iconStruct[element - 1].showImage = 1;


	return 0;
}

/*
Function: storeValuesForArray
Parameters:
	int arrayOfValues[] : an array to store the user-specified row and element values
	int userRow : the row index specified by the user
	int userElement : the element index specified by the user
	int count : the count indicating which set of values to store (0 or 1)
Description: This function stores the user-specified row and element values into the
			 arrayOfValues array. If count is 0, the values are stored at the first two
			 positions of the array. If count is 1, the values are stored at the third
			 and fourth positions of the array.
Return value: int : always returns 0
*/
int storeValuesForArray(int arrayOfValues[], int userRow, int userElement, int count) {

	if (count == 0) {
		arrayOfValues[0] = userRow;
		arrayOfValues[1] = userElement;
	}

	else if (count == 1) {
		arrayOfValues[2] = userRow;
		arrayOfValues[3] = userElement;
	}

	return 0;
}

/*
Function: setToZero
Parameters:
	int arrayToSet[] : an array whose elements are to be set to zero
	int length : the length of the array
Description: This function sets all elements of the arrayToSet array to zero.
Return value: int : always returns 0
*/
int setToZero(int arrayToSet[], int lenght) {

	for (int i = 0; i < lenght; i++) {
		arrayToSet[i] = '\0';
	}


	return 0;
}

/*
Function: stopTheProgram
Parameters:
	int lengthOfStop : the length of time, in milliseconds, to pause the program execution
Description: This function pauses the program execution for the specified length of time
			 using the Sleep function from the Windows API.
Return value: int : always returns 0
*/
int stopTheProgram(int lenghtOfStop) {

	Sleep(lenghtOfStop);

	return 0;
}

/*
Function: closeIcons
Parameters:
	struct lineDefault* gameValues : a pointer to the game values structure
	int arrayOfCompareValues[] : an array containing row and element indices of icons to be closed
Description: This function sets the showImage property of the specified icons in the
			 gameValues structure to 0, indicating that the icons should be hidden.
Return value: int : always returns 0
*/
int closeIcons(struct lineDefault* gameValues, int arrayOfCompareValues[]) {

	gameValues[arrayOfCompareValues[0]].iconStruct[arrayOfCompareValues[1]].showImage = 0;
	gameValues[arrayOfCompareValues[2]].iconStruct[arrayOfCompareValues[3]].showImage = 0;

	return 0;
}

/*
Function: compareValuesOfIcons
Parameters:
	struct lineDefault* gameValues : a pointer to the game values structure
	int arrayOfCompareValues[] : an array containing row and element indices of two pairs of icons to compare
Description: This function compares the hidden values of two pairs of icons specified by the
			 arrayOfCompareValues array. If the hidden values match, the showImage property
			 of both icons in each pair is set to 1, indicating that the icons should be shown.
			 Returns 1 if the values match, indicating a successful comparison; otherwise,
			 returns 0.
Return value: int : 1 if the hidden values of the icons match, 0 otherwise
*/
int compareValuesOfIcons(struct lineDefault* gameValues, int arrayOfCompareValues[]) {

	if (gameValues[arrayOfCompareValues[0]].iconStruct[arrayOfCompareValues[1]].hiddenValue == gameValues[arrayOfCompareValues[2]].iconStruct[arrayOfCompareValues[3]].hiddenValue) {

		gameValues[arrayOfCompareValues[0]].iconStruct[arrayOfCompareValues[1]].showImage = 1;
		gameValues[arrayOfCompareValues[2]].iconStruct[arrayOfCompareValues[3]].showImage = 1;

		return 1;
	}
	else {

		return 0;
	}

}

/*
Function: isIntegerRow
Parameters:
	const char* str : the input string to be converted to an integer
Description: This function attempts to convert the input string to an integer using atoi.
			 It then checks if the result is within the range of 0 to 4 inclusive. If the
			 input string is "0" or atoi fails to convert it to an integer, the function
			 returns -1. If the result is within the specified range, it returns the
			 converted integer.
Return value: int : the converted integer if successful and within the range 0 to 4,
			 otherwise -1
*/
int isIntegerRow(const char* str) {
	int result = atoi(str);

	/*checks if the input string is 0 or it is a text*/
	if (result == 0 && strcmp(str, "0") != 0) {
		return -1; // Return 0 if the input string is not "0" and atoi failed to convert it to an integer
	}

	/*makes sure the result is between 0 and 4*/
	if (result > 0 && result <= 4) {
		return result; // Return result if the input is an integer between 0 and 9
	}

	return -1;
}

/*
Function: isIntegerElement
Parameters:
	const char* str : the input string to be converted to an integer
Description: This function attempts to convert the input string to an integer using atoi.
			 It then checks if the result is within the range of 0 to 5 inclusive. If the
			 input string is "0" or atoi fails to convert it to an integer, the function
			 returns -1. If the result is within the specified range, it returns the
			 converted integer.
Return value: int : the converted integer if successful and within the range 0 to 5,
			 otherwise -1
*/
int isIntegerElement(const char* str) {
	int result = atoi(str);

	/*check if the result is 0 or it is a text*/
	if (result == 0 && strcmp(str, "0") != 0) {
		return -1;
	}

	/*makes sure the result is between 0 and 5*/
	if (result > 0 && result <= 5) {
		return result;
	}

	return -1;
}

/*
Function: displayGrid
Parameters:
	struct lineDefault* gameValues : a pointer to the game values structure
Description: This function displays the grid of icons stored in the gameValues structure.
			 It iterates through each row and element of the grid, printing either the
			 hidden value or the front value of each icon based on the showImage property.
			 If showImage is 1, it prints the hidden value; if it is 0, it prints the front
			 value. It then moves to the next row.
Return value: int : always returns 0
*/
int displayGrid(struct lineDefault* gameValues) {

	for (int row = 0; row < kNumberOfRows; row++) {
		for (int element = 0; element < kNumberOfElements; element++) {

			if (gameValues[row].iconStruct[element].showImage == 1) {
				/*displays hidden value if show image is true(1)*/
				printf("%d ", gameValues[row].iconStruct[element].hiddenValue);

			}
			else if (gameValues[row].iconStruct[element].showImage == 0) {
				/*displays front value if it is false(0)*/
				printf("%c ", gameValues[row].iconStruct[element].frontValue);
			}
		}
		printf("\n"); // Move to the next row
	}


	return 0;
}


/*
Function: takeOffNewlineChar
Parameters:
	char* string : the string from which to remove the last newline character
Description: This function removes the last newline character ('\n') from the input string,
			 which is automatically added by fgets when reading input. It modifies the input
			 string in place. If the string is empty, no action is taken.
Return value: int : always returns 0
*/
int takeOffNewlineChar(char* string) {

	size_t len = strlen(string);
	if (len != 0) {

		string[len - 1] = '\0';

	}


	return 0;
}


/*clears the screen*/
void clearScreen() {

#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif

}