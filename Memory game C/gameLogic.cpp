#include "prototypes.h"

int main(int argc, char* argv[]) {

	srand(time(NULL));
#pragma warning (disable : 4996);
	struct lineDefault gameValues[kNumberOfRows];

	int userOneScore = 0;
	int userTwoScore = 0;
	char userOneName[kMaxSizeOfChar] = "";
	char userTwoName[kMaxSizeOfChar] = "";
	char userChoiceRow[kMaxSizeOfChar] = "";
	char userChoiceElement[kMaxSizeOfChar] = "";
	int usersPointsCombined = 0;

	int arrayOfComapring[4] = { 0 };

	int arrayOfRandomNumbers[20] = { 0 };

	int arrayOfTakenElements[20] = { 0 };

	/*Get users names and checks for the errors*/
	printf("Welcome!\n");
	printf("This is a Memory game! \nThe rules are simple: \nEvery user enters the number of the row and then the number of element he wants to open. \n");
	printf("There are 10 paris of numbers from 0 to 9. \nFor each correct pair, user gets 1 point. Whoever got 6 points first - wins!\n");
	printf("Both users having 5 points will result in a draw!\nIf the user correctlly guesses the pair on his move, he gets to make his move 1 more time!\n");
	printf("Goodluck and lets begin!\n");
	printf("User 1 - enter your name: ");
	for (;;) {
		fgets(userOneName, kMaxSizeOfChar, stdin);
		if (userOneName[0] == '\n') {
			printf("Error getting the name for User 1, try again\n");
			continue;
		}
		else {
			takeOffNewlineChar(userOneName);
			break;
		}
	}
	printf("User 2 - enter your name: ");
	for (;;) {

		fgets(userTwoName, kMaxSizeOfChar, stdin);
		if (userTwoName[0] == '\n') {
			printf("Error getting the name for User 2, try again\n");
			continue;
		}
		else {
			takeOffNewlineChar(userTwoName);
			break;
		}
	}
	clearScreen();

	randomValueAssign(gameValues, arrayOfRandomNumbers);

	displayGrid(gameValues);

	/*Game loop*/
	for (int index = 3; userOneScore < 5 || userTwoScore < 5 || usersPointsCombined != 10; index++) {
		int userChoiceRowAtoi = 0;
		int userChoiceElementAtoi = 0;
		int funcResult = 0;

		/*call display grid somewhere herew*/
		if ((index % 2) != 0) {
			for (int i = 0; i < 2; i++) {
				printf("%s, choose the row: \n", userOneName);
				fgets(userChoiceRow, kMaxSizeOfChar, stdin);
				takeOffNewlineChar(userChoiceRow);
				userChoiceRowAtoi = isIntegerRow(userChoiceRow);
				if (userChoiceRowAtoi == -1) {
					printf("Error: input is not an integer, or too long, try again\n");
					i--;
					continue;
				}
				/*asking user 1 for element*/
				printf("Now choose the element number: \n");
				fgets(userChoiceElement, kMaxSizeOfChar, stdin);
				takeOffNewlineChar(userChoiceElement);
				userChoiceElementAtoi = isIntegerElement(userChoiceElement);
				if (userChoiceElementAtoi == -1) {
					printf("Error: input is not an integer, or too long, try again\n");
					i--;
					continue;
				}
				if ((checkAllowence(userChoiceRowAtoi - 1, userChoiceElementAtoi - 1, gameValues)) == -1) {
					printf("The icon has already been opened\n");
					i--;
					continue;
				}
				/*if the user input is correct, then this fucntion will open the icon*/
				else {
					storeValuesForArray(arrayOfComapring, userChoiceRowAtoi - 1, userChoiceElementAtoi - 1, i);
					openTheIcon(userChoiceRowAtoi, userChoiceElementAtoi, gameValues);
					clearScreen();
					displayGrid(gameValues);
				}
			}
			if ((funcResult = compareValuesOfIcons(gameValues, arrayOfComapring)) == 0) {
				stopTheProgram(2000);
				closeIcons(gameValues, arrayOfComapring);
				clearScreen();
				displayGrid(gameValues);
			}
			else if ((compareValuesOfIcons(gameValues, arrayOfComapring)) == 1) {
				printf("%s gets 1 point\n", userOneName);
				userOneScore++;
				index--;
				usersPointsCombined++;
			}
			setToZero(arrayOfComapring, 4);

			/*asking user 1 for row*/
			/*i get the input with fgets, get rid of new line char
			then store the value from the type char into int using isInteger function
			at the same time checking weather the number is within 0 to 9 range
			in case of error it will start the loop again to ask the same user to enter values again*/
		}
		else if ((index % 2) == 0) {
			for (int i = 0; i < 2; i++) {
				/*asking user 2 for row*/
				printf("%s, choose the row: \n", userTwoName);
				fgets(userChoiceRow, kMaxSizeOfChar, stdin);
				takeOffNewlineChar(userChoiceRow);
				userChoiceRowAtoi = isIntegerRow(userChoiceRow);
				if (userChoiceRowAtoi == -1) {
					printf("Error: input is not an integer, or too long, try again\n");
					i--;
					continue;
				}
				/*asking user 2 for element*/
				printf("Now choose the element number: \n");
				fgets(userChoiceElement, kMaxSizeOfChar, stdin);
				takeOffNewlineChar(userChoiceElement);
				userChoiceElementAtoi = isIntegerElement(userChoiceElement);
				if (userChoiceElementAtoi == -1) {
					printf("Error: input is not an integer, or too long, try again\n");
					i--;
					continue;
				}
				if ((checkAllowence(userChoiceRowAtoi - 1, userChoiceElementAtoi - 1, gameValues)) == -1) {
					printf("The icon has already been opened\n");
					i--;
					continue;
				}
				else {
					storeValuesForArray(arrayOfComapring, userChoiceRowAtoi - 1, userChoiceElementAtoi - 1, i);
					openTheIcon(userChoiceRowAtoi, userChoiceElementAtoi, gameValues);
					clearScreen();
					displayGrid(gameValues);
				}
			}
			if ((funcResult = compareValuesOfIcons(gameValues, arrayOfComapring)) == 0) {
				stopTheProgram(2000);
				closeIcons(gameValues, arrayOfComapring);
				clearScreen();
				displayGrid(gameValues);
			}
			else if ((compareValuesOfIcons(gameValues, arrayOfComapring)) == 1) {
				printf("%s gets 1 point\n", userOneName);
				userTwoScore++;
				index--;
				usersPointsCombined++;
			}
			setToZero(arrayOfComapring, 4);

		}


	}

	/*Final part which shows which user won or if there was a draw*/
	if (userOneScore >= 5 && userTwoScore >= 5) {
		printf("It's a draw!\n");
	}
	else if (userOneScore == 6) {
		printf("%s wins!\n", userOneName);
	}
	else if (userTwoScore == 6) {
		printf("%s wins!\n", userTwoName);
	}

	return 0;
}