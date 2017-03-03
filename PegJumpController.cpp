//Group Members: Alfonso Miguel Santos-Tankia and Zachary Wileman
#include "PegJumpController.h"
#include "PegJumpView.h"
#include "Board.h"

const int numGames = 1;
const string gameNames[] = {"Peg Jump"};

void printMenu(int gameScore[])
{
  PegJumpView View;
	int menuChoice;

	do
	{
    View.menu();

		if (!(cin >> menuChoice))
		{
			cin.clear();
			cin.ignore();
		}

		if (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
			View.invalidChoice();

	} while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

	switch(menuChoice)
	{
		case 1:
      View.printScores(numGames, gameNames, gameScore);
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
<<<<<<< Updated upstream
  int difficulty;
=======
  char input1 = SPACE, input2 = SPACE;
	bool invalidMove;
  Board pegBoard;
>>>>>>> Stashed changes

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

    switch (gameSelected)
		{
			case 1:
				do
				{
          View.selectDifficulty();

					if (!(cin >> difficulty))
					{
						cin.clear();
						cin.ignore();
					}

					if (difficulty == 9)
						printMenu(gameScore);

					else if (difficulty != 1 && difficulty != 2 && difficulty != 3)
						View.invalidChoice();

				} while (difficulty != 1 && difficulty != 2 && difficulty != 3);

        break;
    }
    /////////////

    // Resets peg board
    pegBoard.setupBoard(difficulty);

    do
    {
      pegBoard.printBoard();
      View.firstPeg();
      invalidMove = false;
      input2 = SPACE;

      if (!(cin >> input1))
      {
        cin.clear();
        cin.ignore();
      }

      if (input1 == '9')
      {
        printMenu(gameScore);
        invalidMove = true;
      }

      else if (!pegBoard.checkMove(input1, input2))
      {
        invalidMove = true;
        View.invalidMove();
      }

    } while (invalidMove);

    /////////////
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
