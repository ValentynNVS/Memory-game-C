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


int numberTracker(int numberGenerated, int arrayOfRandNumbers[]) {

	int count = 0;
	for (int i = 0; i < 20; i++) {
		if (arrayOfRandNumbers[i] == numberGenerated) {
			count++;
		}
	}
	return count < 2 ? 1 : -1;
}



int openTheIcon(int row, int element, struct lineDefault* gameValues) {

	gameValues[row - 1].iconStruct[element - 1].showImage = 1;


	return 0;
}

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

int setToZero(int arrayToSet[], int lenght) {

	for (int i = 0; i < lenght; i++) {
		arrayToSet[i] = '\0';
	}


	return 0;
}

int stopTheProgram(int lenghtOfStop) {

	Sleep(lenghtOfStop);

	return 0;
}


int closeIcons(struct lineDefault* gameValues, int arrayOfCompareValues[]) {



	gameValues[arrayOfCompareValues[0]].iconStruct[arrayOfCompareValues[1]].showImage = 0;
	gameValues[arrayOfCompareValues[2]].iconStruct[arrayOfCompareValues[3]].showImage = 0;



	return 0;
}

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


/*function to take off the last new line charachter that adds automaticly with fgets*/
int takeOffNewlineChar(char* string) {

	size_t len = strlen(string);
	if (len != 0) {

		string[len - 1] = '\0';

	}


	return 0;
}
int openedIconsChecker(int row, int element) {

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