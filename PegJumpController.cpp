//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpController.h"
#include "PegJumpView.h"

const int numGames = 1;
const string gameNames[] = {"Peg Jump"};

void printMenu(int gameScore[])
{
	int menuChoice;

	do
	{
		cout << endl;
		cout << "Please enter the number corresponding to what you would like to do:" << endl;
		cout << "1.) Display cumulative game scores for each game" << endl;
		cout << "2.) Exit the program" << endl;
		cout << "3.) Return to what you were doing" << endl;
		if (!(cin >> menuChoice))
		{
			cin.clear();
			cin.ignore();
		}

		if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
			cout << "Please enter a valid menu choice" << endl;

	} while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

	switch(menuChoice)
	{
		case 1:
			for(int i = 0; i < numGames; i++)
				cout << gameNames[i] << " Score: " << gameScore[i] << endl;
			break;
		case 2:
			exit(EXIT_SUCCESS);
			break;
		case 3:
			break;
	}
}

int main()
{
  PegJumpView View;
  int gameScore[numGames] = {0};
	int gameSelected;
  string gameRestart;

  View.printStart();

	do
	{
		do
		{
      View.gameSelect();

			if (!(cin >> gameSelected))
			{
				cin.clear();
				cin.ignore();
			}

			if (gameSelected == 9)
				printMenu(gameScore);

			else if (gameSelected != 1)
        View.invalidChoice();

		} while (gameSelected != 1);

    do
    {
      View.playAgain();

      if (!(cin >> gameRestart))
      {
        cin.clear();
        cin.ignore();
      }

      if (gameRestart == "9")
        printMenu(gameScore);

    } while (gameRestart == "9");

  } while (gameRestart == "y" || gameRestart == "yes");

  return 0;
}
