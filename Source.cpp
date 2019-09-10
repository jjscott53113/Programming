// Assignment #2 
// If statements, Loops, and Random Numbers
// Josh Scott
// Beginning C++ through Game Programming

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));  //seed random number generator

	int health = rand() % 20 + 1; // random number between 1 and 20 for health
	// int health = 10;
	int doctor = rand() % 6 + 1;  // random number between 1 and 6 for doctor
	int turns = rand() % 10 + 1; // 1. random number between 1 and 10 for rounds
	// int turns = 0;
	string input1; // Setup a variable just to allow a stop in the program and get user input to continue on 
	string name; // Variable to welcome the player by name 
	string answer; // Variable to allow for doctor visit 
	char display; // Variable to allow for debug 


	cout << "Welcome to the brand new Game of Attack.\n";
	cout << "Please enter your name: ";
	cin >> name; // User Input

	cout << "Hello " << name << ", let's have a little fun.\n";
	cout << "Would you like to display all the game numbers for Debug mode (y/n)??? ";
	cin >> display; // User Input

	cout << endl; // Blank Line

	do // Start of loop 
	{
		int attack = rand() % 4;  // random number between 0 and 4 for attack
		int block = rand() % 4;  // random number between 0 and 4 for block
		cout << "Here we go, Let's fight!!!\n";

		if (display == 'y') { // Setup this if statement to output all variable values for debug 
			cout << "Attack = " << attack << endl;
			cout << "Block = " << block << endl;
			cout << "Health = " << health << endl;
			cout << "Rounds = " << turns << endl;
			cout << "Doctor = " << doctor << endl;
		}

		cout << endl; // Blank Line

		if (display == 'y') { // Setup this if statement to output all variable values for debug
			cout << "Number of Turns left = " << turns << endl;
		}

		if (attack > block) {
			cout << "Attack!!!\n";
			cout << "Health has been decreased this round" << endl;
			health -= attack;

			if (display == 'y') { // Setup this if statement to output all variable values for debug
				cout << "Health loses " << attack << " pts, now health = " << health << endl;
			}
		}
		else if (attack < block) {
			cout << "Block!!!\n";
			cout << "Health has been increased this round" << endl;
			health += block;

			if (display == 'y') { // Setup this if statement to output all variable values for debug
				cout << "Health gains " << block << " pts, now health = " << health << endl;
			}
		}
		else if (attack == block) {
			cout << "Draw!!!";
			cout << "Health stays the same as the last battle\n";

			if (display == 'y') { // Setup this if statement to output all variable values for debug
				cout << "health = " << health << endl;
			}
		}

		turns--;

		if (turns < 1) { // If turns is less than 1 then the game is over  
			break;
		}

		if (health < 1) { // If player health is less than 1 (equal to 0 or less), player is dead and game over 
			break;
		}

		if (health <= 6) { // 2. Player health is getting low, ask if they want to see the doctor 
			cout << "Your health is critically low, please go see the doctor.\n";
			cout << "Your health = " << health << endl;
			cout << "Do you want to visit the doctors office to gain back " << doctor << " health pts?\n";
			cout << "y or n\n";
			cin >> answer; // User input to visit doctor if they choose 
		}
		else if (answer == "y") {
			cout << "You have chosen to visit the doctor at a great time.\n";
			cout << "Your health was very low, you have been treated by the doctor, have a good day.\n";
			health += doctor;
			cout << "Your health has been increased to " << health << endl;
		}
		else if (answer == "n") {
			cout << "You have chosen to skip the Doctor visit, Good Luck!!!\n";
		}

		answer = 'a'; // Re-initilize variable answer so that the next iteration won't output the above info

		cout << endl; // Blank Line

		if (health <= 0) { // If player health is less than or equal to 0, player dead and game over 
			cout << "Sorry player, you are dead. Better luck next time\n";
		}
		else if (health > 0) {
			cout << "Congratualations, you have not been defeated, Continue to next battle!\n";
		}

		cout << endl; // Blank Line

		cout << "Player wants to take a nap, continue with battle when ready\n";
		cout << "Press any key to continue\n";
		cin >> input1; // 3. User Input to slow the pace of the game 

		cout << endl; // Blank Line

	} while (turns != 0); //Run loop as long as turns is greater than 0 

	cout << endl; // Blank Line

	if (health > 0) {
		cout << "Congratualations you have survived, You win the War!\n";
	}
	else {
		cout << "You have no Player Health remaining, You are dead!!!\n";
	}

	return 0;
}