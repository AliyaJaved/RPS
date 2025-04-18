#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

class Game {
    private:
	int playerScore;
	int computerScore;
	char playerName[50];

    public:
	// Constructor
	Game() {
	    playerScore = 0;
	    computerScore = 0;
	}

	// Function to get player name
	void getPlayerName() {
	    clrscr();
	    cout << "\n\t\tROCK PAPER SCISSORS GAME";
	    cout << "\n\t\t----------------------";
	    cout << "\n\nEnter your name: ";
	    gets(playerName);
	}

	// Function to display rules
	void displayRules() {
	    clrscr();
	    cout << "\n\tRULES OF THE GAME";
	    cout << "\n\t-----------------";
	    cout << "\n-> Press 1 for Rock";
	    cout << "\n-> Press 2 for Paper";
	    cout << "\n-> Press 3 for Scissors";
	    cout << "\n-> First to win 3 rounds wins the game!";
	    cout << "\n\nPress any key to continue...";
	    getch();
	}

	// Function to get computer's choice
	int getComputerChoice() {
	    return (rand() % 3) + 1;
	}

	// Function to convert choice number to string
	char* getChoiceName(int choice) {
	    switch(choice) {
		case 1: return "Rock";
		case 2: return "Paper";
		case 3: return "Scissors";
		default: return "Invalid";
	    }
	}

	// Function to determine winner of a round
	void determineWinner(int playerChoice, int computerChoice) {
	    clrscr();
	    cout << "\n" << playerName << "'s choice: " << getChoiceName(playerChoice);
	    cout << "\nComputer's choice: " << getChoiceName(computerChoice);

	    if (playerChoice == computerChoice) {
		cout << "\n\nIt's a tie!";
	    }
	    else if ((playerChoice == 1 && computerChoice == 3) ||
		     (playerChoice == 2 && computerChoice == 1) ||
		     (playerChoice == 3 && computerChoice == 2)) {
		cout << "\n\n" << playerName << " wins this round!";
		playerScore++;
	    }
	    else {
		cout << "\n\nComputer wins this round!";
		computerScore++;
	    }

	    cout << "\n\nScores:";
	    cout << "\n" << playerName << ": " << playerScore;
	    cout << "\nComputer: " << computerScore;
	    cout << "\n\nPress any key to continue...";
	    getch();
	}

	// Function to play the game
	void playGame() {
	    int playerChoice;
	    randomize();  // Initialize random number generator

	    while (playerScore < 3 && computerScore < 3) {
		clrscr();
		cout << "\nCurrent Score - " << playerName << ": " << playerScore 
		     << " Computer: " << computerScore;
		cout << "\n\nEnter your choice (1-Rock, 2-Paper, 3-Scissors): ";
		cin >> playerChoice;

		if (playerChoice >= 1 && playerChoice <= 3) {
		    determineWinner(playerChoice, getComputerChoice());
		}
		else {
		    cout << "\nInvalid choice! Press any key to try again...";
		    getch();
		}
	    }
	}

	// Function to display final result
	void displayResult() {
	    clrscr();
	    cout << "\n\t\tGAME OVER!";
	    cout << "\n\t\t---------";
	    cout << "\n\nFinal Scores:";
	    cout << "\n" << playerName << ": " << playerScore;
	    cout << "\nComputer: " << computerScore;
	    cout << "\n\n" << (playerScore > computerScore ? playerName : "Computer") 
		 << " wins the game!";
	    cout << "\n\nPress any key to exit...";
	    getch();
	}
};

void main() {
    Game game;
    game.getPlayerName();
    game.displayRules();
    game.playGame();
    game.displayResult();
}