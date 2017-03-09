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

// Function: Autosolve's the peg jump game at whatever state the passed in "tempBoard" is at
// Retutns: bool value that is true if there was a solution found, false if not
bool autoSolver(Board tempBoard, vector<Peg> remainingPegs, vector<char> &solutionList)
{
	for (int i = 0; i < remainingPegs.size(); i++)
	{
		for (int j = i+1; j < remainingPegs.size(); j++)
		{
			if (tempBoard.checkMove(remainingPegs[i].getPeg(), remainingPegs[j].getPeg()))
			{
				Board newBoard = tempBoard;
				vector<Peg> newPegs = remainingPegs;
				vector<char> newSolutions = solutionList;

				newBoard.updateBoard(newPegs[i].getPeg(), newPegs[j].getPeg());
				newSolutions.push_back(newPegs[i].getPeg());
				newSolutions.push_back(newPegs[j].getPeg());
				newPegs = newBoard.remainingPegs();

				if (newBoard.checkWin())
				{
          cout << endl << "The following moves, in order, are the solution to the current Peg Board." << endl << endl;
        	for(int i = 0; i < newSolutions.size(); i+=2)
        		cout << newSolutions[i] << " " << newSolutions[i+1] << endl;

          solutionList = newSolutions;

          cout << endl << "The following moves, in order, are the solution to the current Peg Board." << endl << endl;
        	for(int i = 0; i < solutionList.size(); i+=2)
        		cout << solutionList[i] << " " << solutionList[i+1] << endl;

          solutionList.clear();
          solutionList.push_back('A');
          solutionList.push_back('B');

          return true;
				}
				else
				{
					if (autoSolver(newBoard, newPegs, newSolutions))
						return true;
				}
			}

			if (tempBoard.checkMove(remainingPegs[j].getPeg(), remainingPegs[i].getPeg()))
			{
				Board newBoard = tempBoard;
				vector<Peg> newPegs = remainingPegs;
				vector<char> newSolutions = solutionList;

				newBoard.updateBoard(newPegs[j].getPeg(), newPegs[i].getPeg());
				newSolutions.push_back(newPegs[j].getPeg());
				newSolutions.push_back(newPegs[i].getPeg());
				newPegs = newBoard.remainingPegs();

				if (newBoard.checkWin())
				{
          solutionList = newSolutions;
          return true;
				}
				else
				{
					if (autoSolver(newBoard, newPegs, newSolutions))
						return true;
				}
			}
		}
	}

	return false;
}

int main()
{
  PegJumpView View;
  int gameScore[numGames] = {0};
  int gameSelected;
  string gameRestart;
  int difficulty;
  char input1 = SPACE, input2 = SPACE;
  vector<Peg> pegRemainder;
  vector<char> solutionList;
	bool invalidMove;
  Board pegBoard;

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
          View.invalidChoice();
        }

      } while (invalidMove);

      pegBoard.updateBoard(input1, input2);
      gameScore[gameSelected-1]++;

      while (pegBoard.checkBoard())
      {
        do
        {
          pegRemainder = pegBoard.remainingPegs();

          pegBoard.printBoard();
          View.twoPeg();
          invalidMove = false;

          if (!(cin >> input1))
          {
            cin.clear();
            cin.ignore();
          }

          if (input1 == '8')
          {
            if (autoSolver(pegBoard, pegRemainder, solutionList))
                View.solutionFound(solutionList);
            else
              View.noSolution();

            invalidMove = true;
          }

          else if (input1 == '9')
          {
            printMenu(gameScore);
            invalidMove = true;
          }

          else
          {
            if (!(cin >> input2))
            {
              cin.clear();
              cin.ignore();
            }
          }

          if (!pegBoard.checkMove(input1, input2) && input1 != '9' && input1 != '8')
          {
            invalidMove = true;
            View.invalidChoice();
          }

        } while (invalidMove);

        pegBoard.updateBoard(input1, input2);
        gameScore[gameSelected-1]++;
      }

      pegBoard.printBoard();

      if (pegBoard.checkWin())
        View.win();
      else
        View.lose();

      View.cumScore(gameScore, gameSelected);
      pegBoard.clearBoard();
      solutionList.clear();
      pegRemainder.clear();
      break;
    }

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
