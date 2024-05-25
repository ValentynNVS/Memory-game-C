#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <random>
#include <time.h>
#include <windows.h>


#pragma warning(disable: 4996)
const int kMaxSizeOfChar = 200;
const int kNumberOfRows = 4;
const int kNumberOfElements = 5;

struct icon {
	char frontValue = '+';
	int hiddenValue = 0;
	int showImage = 0;
};

struct lineDefault {

	struct icon iconStruct[kNumberOfElements];

};

/*fucntion to generate random numbers and store them*/
int randomValueAssign(struct lineDefault* gameValues, int array[]);
/*function to keep track of random number so they dont repeat themselfs more than twice*/
int numberTracker(int numberGenerated, int array[]);
/*takes of new line character*/
int takeOffNewlineChar(char* string);
/*clear the screen so the user cannnot se the previous moves*/
void clearScreen();
/*this fucntion will open the icon that the user chose*/
int openTheIcon(int row, int element, struct lineDefault* gameValues);
/*function to stop the program to let the user memorize the cards*/
int stopTheProgram(int lenghtOfStop);
/*this function compare the values of number and if they are the same the user gets a point*/
int compareValuesOfIcons(struct lineDefault* gameValues, int arrayOfCompareValues[]);
/*the fucntion to check if the users choice of the icon has not been opened yet*/
int openedIconsChecker(int row, int element);
/*checks if the input is a number*/
int isIntegerRow(const char* str);
int isIntegerElement(const char* str);
/*fucntion for grid display*/
int displayGrid(struct lineDefault* gameValues);
/*function to store values into the array which i will use to compare them*/
int storeValuesForArray(int arrayOfValues[], int userRow, int userElement, int count);
/*sets values of an array to 0*/
int setToZero(int arrayToSet[], int lenght);
/*fucntion to check if it is allowed to choose a row and element*/
int checkAllowence(int row, int element, struct lineDefault* gameValues);
/*closes the icons*/
int closeIcons(struct lineDefault* gameValues, int arrayOfCompareValues[]);