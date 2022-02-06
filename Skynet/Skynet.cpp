// Skynet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> //includes the isostream library
#include <exception>//includes the exception library
#include<vector>// includes the vector library
#include<cstdlib>//includes teh cstdlib library
#include<ctime> // indcludes the ctime library
#include <string>//includes the stringe library
#include <stdlib.h>// indcludes the stdlib.h


using namespace std;//std Namespace shortcut





int main()
{
	srand(time(0));// initializes the random functino
	int field[8][8]; // initializes the 8x8 array
	int enemy = rand() % 64 + 1;//sets the enemy variable to be a random number between 1 and 64
	bool enemyPresent = false; //initialize the enemyPresent boolean Variable
	int line[64];//initializes a 1 dimensional array called line
	int idx = 0;//initializes the index value
	int target = 0;//initializes the target value




	while (enemyPresent == false) {//code repeats until enemyPresent is ture
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				int myRand = rand() % 64 + 1;// sets up the myRand variable to be a random number between 1 and 64 that changes in each loop
				if (enemy == myRand) {//if the enemy variable equals the myRand variable
					field[i][j] = 1;//puts a "1" in the grid, signifying the enemy's position
					enemy = 0;//sets the enemy variable to zero so no more "1"s appear on the grid
					enemyPresent = true;//sets enemyPresent to true in order to allow the loop to end
					line[idx] = idx;//builds the 1 dimensional "line array
					target = line[idx];//converts the enemy location to a value in the 1 dimensional "line" array
					idx++;



				}
				else {//if the enemy variable does not equal the myRand variable
					field[i][j] = 0;//puts a "0" on the grid
					line[idx] = idx;//builds the 1 dimensional "line" array
					idx++;
				}
				cout << field[i][j] << " ";//prints out the grid


			}

			cout << endl;

		}
		if (enemyPresent == false) {//if the enemyPresent variable is false after the for loops are complete
			system("CLS");//delete the grid and repeat the above code
			idx = 0;//resets the index value to zero
		}

	}

	int HighGridNumber = line[63];//sets up the HighGridNumber variable, which is the highest number in the line array
	int LowGridNumber = line[0];//sets up the LowGridNumber variable, which is the lowest number in the line array
	int MidGridNumber;// initializes the MidGridNumber variable
	bool found = false; // initalizes the found variable
	int searches = 0;//initializes the searches variable

	
	while (found == false) {//if found is false

		if (target != HighGridNumber && target != LowGridNumber) {//if the target number doesn't equal the highest or lowest value in the line array

			MidGridNumber = line[((HighGridNumber - LowGridNumber) / 2 - LowGridNumber)];// sets up the MidGridNumber variable 
			HighGridNumber = line[HighGridNumber - 1];//subtracts 1 from the HighGridNumber variable
			LowGridNumber = line[LowGridNumber + 1];//adds 1 to the LowGridNumber variable
		}

			if (target < MidGridNumber) {//if the target value is less than the MidGridNumber, then the target is to the left of the MidGridNumber
				MidGridNumber = MidGridNumber - 1;//subtracts 1 from the MidGridNumber
				
			}
			else if (target > MidGridNumber) {//if the target value is greater than the MidGridNumber, then the target is to the right of the MidGridNumber
				MidGridNumber = MidGridNumber + 1;//adds 1 to the MidGridNumber value
			}
			else if (target == MidGridNumber) {//if the target value equals the MidGridNumber
				found = true;//sets the found value to true
			
			}

		
		else if (target == HighGridNumber) {// if the target value equals the HighGridNumber
			found = true;//sets the found value to true
		
			}

		else {// if the target value equals the LowGridNumber
			found = true;//sets the found value to true
			
		}
			searches++;//adds 1 to the searches variable
	}

	if (found == true) {//when the enemy is found
		int column = MidGridNumber % 8;//get the column by using modular division
		int row = MidGridNumber /8;// get the row by using division
		cout << "found enemy at (" << row << " , " << column << ") after "<< searches<<" searches on an 8x8 grid."<< endl;


		
	}	





	

		
	
	




	




		
}


