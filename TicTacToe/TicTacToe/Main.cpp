#include <iostream>
#include <string>
#include <iomanip>


void output(char gameBoard[3][3]) //this clears the output and rewrites it after every turn
{
	system("cls");
	std::cout << std::setw(8) << "0 1 2\n"
			  << "0" << std::setw(2) << gameBoard[0][0] << "|" << gameBoard[0][1] << "|" << gameBoard[0][2] << std::endl
			  << std::setw(8) << "-----\n"
			  << "1" << std::setw(2) << gameBoard[1][0] << "|" << gameBoard[1][1] << "|" << gameBoard[1][2] << std::endl
			  << std::setw(8) << "-----\n"
			  << "2" << std::setw(2) << gameBoard[2][0] << "|" << gameBoard[2][1] << "|" << gameBoard[2][2] << std::endl;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
bool winCheck(char gameBoard[3][3], char player) //go through every combination of winning conditions and if any of them are met, output "true"
{
	for (int i = 0; i < 3; i++)
	{
		if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) //check rows for a win
		{
			return true;
		}
		if (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player) //check collumns for a win
		{
			return true;
		}
	}
	if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player)	 //check diag (top left to bottom right) 
	{
		return true;
	}
	if (gameBoard[2][0] == player && gameBoard[1][1] == player && gameBoard[0][2] == player)	 //check diag (bottom left to top right)
	{
		return true;
	}

	return false;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
void playerTurn(char gameBoard[3][3], char playerTurn)
{
	int choiceRow = 0;
	int choiceCollumn = 0;

	bool correct = false;
	bool same = true;


	std::cout << "\n" << playerTurn << "'s Turn!\n";
	
	while (same)
	{
		while (!correct)
		{
			std::cout << "Choose a Row (How far down): ";
			std::cin >> choiceRow;

			switch (choiceRow)
			{
			case 0:
				correct = true;	break;
			case 1:
				correct = true;	break;
			case 2:
				correct = true;	break;
			default:
				correct = false;
				std::cout << "Please choose a value from 0-2" << std::endl;
				break;
			}
		}
		correct = false;

		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());


		while (!correct)
		{
			std::cout << "Now choose a collumn (How far across): ";
			std::cin >> choiceCollumn;

			switch (choiceCollumn)
			{
			case 0:
				correct = true;	break;
			case 1:
				correct = true;	break;
			case 2:
				correct = true;	break;
			default:
				correct = false;
				std::cout << "Please choose a value from 0-2" << std::endl;
				break;
			}
		}
		if (gameBoard[choiceRow][choiceCollumn] != ' ')
		{
			std::cout << "Someone's already played in that spot, try again!" << std::endl;
			correct = false;
		}
		else 
		{
			same = false;
		}
	}
	
	gameBoard[choiceRow][choiceCollumn] = playerTurn;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
bool drawCheck(char gameBoard[3][3])
{
	bool draw = true;

	for (int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		if (gameBoard[col][row] == ' ')
		{
			draw = false;                       //should run through the game board to see if there are empty spots, if there are, draw is false, if there are not, draw is true
		}
	}
	if (draw)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
	char gameBoard[3][3] = 
	{
		{' ', ' ', ' '},
		{' ', ' ', ' '},
		{' ', ' ', ' '} 
	};
	char playerNaught = 'O';
	char playerCross = 'X';

	bool xWins = false;
	bool oWins = false;
	bool draw = false;

	output(gameBoard);
	while (!xWins && !oWins && !draw)
	{
		if (!xWins)
		{
			draw = drawCheck(gameBoard);
			if (!draw)
			{
				playerTurn(gameBoard, playerNaught);
				oWins = winCheck(gameBoard, playerNaught);

				output(gameBoard);
				//std::cout << oWins << std::endl;
			}
		}
		if (!oWins)
		{
			draw = drawCheck(gameBoard);
			if (!draw)
			{
				playerTurn(gameBoard, playerCross);
				xWins = winCheck(gameBoard, playerCross);

				output(gameBoard);
				//std::cout << oWins << std::endl;
			}
		}

		
	}

	if (oWins)
	{
		std::cout << playerNaught <<"'s Win!" << std::endl;
	}
	if (xWins)
	{
		std::cout << playerCross << "'s Win!" << std::endl;
	}
	if (draw)
	{
		std::cout << "No more spots left, you came a draw!" << std::endl;
	}

	system("pause");

	return 0;
}
