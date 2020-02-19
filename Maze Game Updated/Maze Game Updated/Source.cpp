#include <iostream>
#include <cmath> 
#include <time.h> 
#include <conio.h>


using namespace std;

struct Pirates
{
	int PositionX;
	int PositionY;
	char PIRATE;
}; // this struct is made for the enemies with positions given

struct Player
{
	int PositionX;
	int PositionY;
	char player;
	int Lives;
}character; //this struct is made for the user/player with posX & Y



void user_HURT()
{
	character.PositionX = 1;
	character.PositionY = 1;
	character.Lives--;
}// this function is for the player when he hits an enemy

int main()
{
	int Rand_Movement;

	character.PositionX = 1; //this is the position of the player
	character.PositionY = 1;
	character.player = 'H';
	character.Lives = 4; // number of lives given to the player

	Pirates E_Xaxis = { 13, 9, 'B' }; //this enemy is placed at the position 13 and 9 horizontally
	Pirates E_Yaxis = { 11, 9, 'P' };  //this one is placed next to it
	Pirates E_Jump = { 1, 15, 'R' };	//random placement for the third enemy	


	const char H = 18, W = 18; // Width and Height of maze
	bool UPD = false; // boolean for the map if it needs to be changed
	char Movement_Key = 'd';

	unsigned char MAZE[W][H] =
	{
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
		'#',' ','#',' ',' ',' ','#','#','#',' ',' ','#','#',' ','#',' ','#','#',
		'#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ',
		'#',' ','#','#',' ',' ',' ',' ','#',' ','#','#',' ','#','#',' ',' ',' ',
		'#',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',
		'#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ','#',' ',' ','#',
		'#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#',' ',' ','#','#','#','#',' ',' ','#',' ',' ','#','#',' ','#','#',
		'#','#','#',' ','#','#','#','#','#',' ','#',' ','#','#','#',' ','#','#',
		'#',' ','#',' ',' ',' ','#','#','#',' ',' ',' ','#',' ','#',' ','#','#',
		'#',' ','#','#',' ','#','#',' ','#',' ','#','#',' ',' ','#',' ','#','#',
		'#',' ','#','#',' ',' ',' ',' ',' ',' ','#','#',' ','#','#',' ',' ','#',
		'#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ',' ','#','#','#',' ','#',
		'#',' ','#','#',' ','#',' ','#','#',' ','#','#',' ',' ',' ',' ',' ','#',
		'#','#','#',' ',' ','#',' ','#','#',' ',' ','#',' ','#','#',' ','#','#',
		'#','#','#','#',' ','#','#','#','#',' ','#',' ',' ','#','#',' ','#','#',
		'#','#','#',' ',' ',' ',' ','#','#',' ',' ',' ','#','#','#',' ','#','#',
		'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',
	};
	cout << "press any movement key to start the game" << endl;
	cout << "press q then enter to exit the game" << endl;



	while (Movement_Key != 'q') //as long as the player does not press q, he can move the character anywhere in the maze and everything thats within the maze
	{

		srand(time(NULL));
		Rand_Movement = rand() % 2 + 1;
		Movement_Key = '\0';
		fflush(stdin); //this clears the keyboard memory which is necessary when working with chars
		while (Movement_Key == '\0')
			Movement_Key = _getche();

		switch (Movement_Key)
		{
		case 'w':
			UPD = true; //this updates the maze
			if (MAZE[character.PositionX][character.PositionY - 1] != '#')
			{
				MAZE[character.PositionX][character.PositionY] = ' ';
				character.PositionY--;

				if (MAZE[character.PositionX][character.PositionY] == MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Jump.PositionX][E_Jump.PositionY])
				{
					user_HURT();
				}

				cout << character.PositionX << " " << character.PositionY << endl;
			}
			else
				cout << "oh no, looks like you hit a roadblock.";
			break;

		case 's':
			UPD = true;
			if (MAZE[character.PositionX][character.PositionY + 1] != '#')
			{
				MAZE[character.PositionX][character.PositionY] = ' ';
				character.PositionY++;

				if (MAZE[character.PositionX][character.PositionY] == MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Jump.PositionX][E_Jump.PositionY])
				{
					user_HURT();
				}

				cout << character.PositionX << " " << character.PositionY << endl;
			}
			else
				cout << "oh no, looks like you hit a roadblock.";
			break;

		case 'a':
			UPD = true;
			if (MAZE[character.PositionX - 1][character.PositionY] != '#')
			{
				MAZE[character.PositionX][character.PositionY] = ' ';
				character.PositionX--;

				if (MAZE[character.PositionX][character.PositionY] == MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Jump.PositionX][E_Jump.PositionY])
				{
					user_HURT();
				}

				cout << character.PositionX << " " << character.PositionY << endl;
			}
			else
				cout << "  oh no, looks like you hit a roadblock";

			break;

		case 'd':
			UPD = true;
			if (MAZE[character.PositionX + 1][character.PositionY] != '#')
			{
				MAZE[character.PositionX][character.PositionY] = ' ';
				character.PositionX++;

				if (MAZE[character.PositionX][character.PositionY] == MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] ||
					MAZE[character.PositionX][character.PositionY] == MAZE[E_Jump.PositionX][E_Jump.PositionY])
				{
					user_HURT();
				}

				cout << character.PositionX << " " << character.PositionY << endl;
			}
			else
				cout << "  oh no, looks like you hit a roadblock";
			break;
		}

		switch (Rand_Movement) // this switch helps this pirate move in a randomised pattern making it hard for the player to predict its movement, this pirate is smart and you dont want to mess with him.
		{
		case 1:


			if
				(MAZE[E_Xaxis.PositionX + 1][E_Xaxis.PositionY] != '#')
			{
				MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] = ' ';
				E_Xaxis.PositionX++;
			}

			break;


		case 2:
			if
				(MAZE[E_Xaxis.PositionX - 1][E_Xaxis.PositionY] != '#')
			{
				MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] = ' ';
				E_Xaxis.PositionX--;
			}

			break;
		}

		if (MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY + 1] != '#') //this enemy moves in one direction only, making his moves predicatable, the player needs to learn his pattern in order to move out
		{
			MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] = ' ';
			E_Yaxis.PositionY++;
		}
		else if
			(MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY - 5] != '#')
		{
			MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] = ' ';
			E_Yaxis.PositionY -= 6;
		}


		if (MAZE[E_Jump.PositionX + 2][E_Jump.PositionY] != '#')

		{
			MAZE[E_Jump.PositionX][E_Jump.PositionY] = ' ';
			E_Jump.PositionX += 2;
		}
		else if
			(MAZE[E_Jump.PositionX - 13][E_Jump.PositionY] != '#')
		{
			MAZE[E_Jump.PositionX][E_Jump.PositionY] = ' ';
			E_Jump.PositionX -= 13;
		}

		if (character.Lives == 0)// if the player loses all three lives, then the Game Over screen.
		{
			Movement_Key = 'q';
			cout << " Game Over" << endl;
		}

		if (character.PositionY == 17)// if the player reaches the end, a winner screen should show up.
		{
			cout << "\n Mission Passed, +Respect\n";
		}

		UPD = true;

		if (UPD == true)
		{
			system("CLS");

			MAZE[E_Xaxis.PositionX][E_Xaxis.PositionY] = E_Xaxis.PIRATE;
			MAZE[E_Yaxis.PositionX][E_Yaxis.PositionY] = E_Yaxis.PIRATE;
			MAZE[E_Jump.PositionX][E_Jump.PositionY] = E_Jump.PIRATE;

			MAZE[character.PositionX][character.PositionY] = character.player;


			for (int y = 0; y < H; y++)
			{
				cout << "\n";
				for (int x = 0; x < W; x++)
				{
					cout << MAZE[x][y];
				}
			}
			cout << "\n" << endl << "    health: " << character.Lives << endl << "____________________\n \n";
			UPD = false;
		}

	}// end of while loop
	return 0;

}