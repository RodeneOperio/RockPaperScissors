/*
	Rock Paper Scissors VS CPU
*/

#include "pch.h"
#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>

using namespace std; 

//Public Variables
int playerPoints = 0, cpuPoints = 0;
string playerName;
string playerChoice, cpuChoice;
bool winner = false;

void Menu();
void gameStart();
void winOrlose();
void cpuPick();
void winCondition();

int main()
{
	Menu();
	gameStart();
}

void Menu()
{	
	//Title Menu Display
	cout << "Welcome to Rock-Paper-Scissors! Test your luck with the CPU!" << endl;
	cout << "------------------------------------------------------------" << endl;
	// Get Player Name 
	cout << "Please enter your name: ";
	cin >> playerName;

	//Welcome player and get choice
	cout << "\nHello " << playerName << "! Do you think you can beat me?! Hahaha, I'd like to see you try!" << endl;
	cout << "This will be the a best of 5 contest! First to 3 wins, are you ready? Good!\n" << endl; 
}

void gameStart()
{
	while (!winner)
	{
		cout << "Rock, Paper or Scissors?" << endl;
		cin >> playerChoice;
		winOrlose();
		cout << "You have " << playerPoints << ". I have " << cpuPoints << "." << endl;
		winCondition();
	}
}
void winOrlose()
{	
	cpuPick();

	//Rock
	if (playerChoice == "Rock" && cpuChoice == "Scissors")
	{	
		cout << "\nRock beats Scissors. " << playerName << " gets the point!";
		cout << "\nCPU: Damnit! You got lucky!" << endl;
		playerPoints++; 
	}
	if (playerChoice == "Rock" && cpuChoice == "Rock")
	{
		cout << "\nRock vs Rock. No one gets a point!" << endl;
	}
	if (playerChoice == "Rock" && cpuChoice == "Paper")
	{
		cout << "\nHaha! I am greater than humans!" << endl; 
		cpuPoints++;
	}
	//Paper
	if (playerChoice == "Paper" && cpuChoice == "Rock")
	{
		cout << "\nPaper beats Rock. " << playerName << " gets the point!";
		cout << "\nCPU: Damnit! You got lucky!" << endl;
		playerPoints++;
	}
	if (playerChoice == "Paper" && cpuChoice == "Paper")
	{
		cout << "\nPaper vs Paper. No one gets a point!" << endl;
	}
	if (playerChoice == "Paper" && cpuChoice == "Scissors")
	{
		cout << "\nHaha! I am greater than humans!" << endl;
		cpuPoints++;
	}

	//Scissors
	if (playerChoice == "Scissors" && cpuChoice == "Paper")
	{
		cout << "\nScissors beat Paper. " << playerName << " gets the point!";
		cout << "\nCPU: Damnit! You got lucky!" << endl;
		playerPoints++;
	}
	if (playerChoice == "Scissors" && cpuChoice == "Scissors")
	{
		cout << "\nScissors vs Scissors. No one gets a point!" << endl;
	}
	if (playerChoice == "Scissors" && cpuChoice == "Rock")
	{
		cout << "\nHaha! I am greater than humans!" << endl;
		cpuPoints++;
	}
}

void cpuPick()
{	
	int r;
	srand(time(NULL));
	r = rand() % 3 + 1;

	if (r == 1)
	{
		cpuChoice = "Rock";
	}
	else if (r == 2)
	{
		cpuChoice = "Paper";
	}
	else
	{
		cpuChoice = "Scissors";
	}
}

void winCondition() 
{
	if (playerPoints == 3)
	{
		cout << "\n" << playerName << " has won the game!" << endl;
		winner = true;
	}
	else if (cpuPoints == 3)
	{
		cout << "\nCPU has won the game!" << endl;
		winner = true;
	}
}