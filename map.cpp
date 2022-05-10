#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
void map()
{
	char map[11][11] =
	{ {'#','#','#','#','#','#','#','#','#','#','\n'}
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#','\n' }
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#' ,'\n'}
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , { '#',' ',' ',' ',' ',' ',' ',' ',' ','#','\n' }
		 , {'#','#','#','#','#','#','#','#','#','#','\n' }
	};

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			cout << map[i][j];
		}
	}

}

struct FVector2D
{
	int X;
	int Y;
};

void SetLocation(FVector2D NewLocation);


int main()
{
	bool bRunning = true;
	FVector2D PlayerPosition;
	PlayerPosition.X = 1;
	PlayerPosition.Y = 1;
	map();
	while (bRunning)
	{
		int KeyCode = _getch();

		switch (KeyCode)
		{
		case 'w':
		case 'W':
			PlayerPosition.Y--;
			break;
		case 's':
		case 'S':
			PlayerPosition.Y++;
			break;
		case 'a':
		case 'A':
			PlayerPosition.X--;
			break;
		case 'd':
		case 'D':
			PlayerPosition.X++;
			break;
		case 27:// esc
			bRunning = false;
			break;

		}

		PlayerPosition.X = PlayerPosition.X < 1 ? 1 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y < 1 ? 1 : PlayerPosition.Y;
		PlayerPosition.X = PlayerPosition.X > 9 ?  9 : PlayerPosition.X;
		PlayerPosition.Y = PlayerPosition.Y >  9 ?  9 : PlayerPosition.Y;

		system("cls");
		map();
		SetLocation(PlayerPosition);

		cout << "P";

	}


	return 0;
}


void SetLocation(FVector2D NewLocation)
{
	COORD Cur;
	Cur.X = NewLocation.X;
	Cur.Y = NewLocation.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}