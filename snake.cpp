#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "conio.h"

#define X_MAX	50
#define Y_MAX	20
#define WINDOWS_LEAD_AND_MEAN

/* 定义全局变量 */
int keyDown, direction;

using namespace std;
/* 函数声明 */
void screenClear();
void hideCursor();
void opening();
void gameStart();
void autoMove();






class theWorld {
protected:
	bool	world[X_MAX][Y_MAX] = { 0 };
	int	x, y;
public:
	void setPosition(int x_temp, int y_temp)
	{
		world[x_temp][y_temp] = true;
		x = x_temp;
		y = y_temp;
	}


	void worldMake() /* 生成游戏画面 */
	{
		for (int y_counter = 0; y_counter <= Y_MAX + 2; y_counter++)
		{
			if (y_counter == 0 || y_counter == Y_MAX + 2)
			{
				for (int x_counter = 0; x_counter <= X_MAX + 2; x_counter++)
				{
					if (x_counter == 0 || x_counter == X_MAX + 2)
						cout << "|";
					else cout << "-";
				}
			}
			else for (int x_counter = 0; x_counter <= X_MAX + 2; x_counter++)
			{
				if (x_counter == 0 || x_counter == X_MAX + 2)
					cout << "|";
				else if (world[x_counter][y_counter] == true)
					cout << "#";
				else cout << " ";
			}
			cout << endl;
		}
	}


	void changeDirection() /* 移动及画面的改变 */
	{
		keyDown = _getch();
		switch (keyDown)
		{
		case 65:

			direction = 3;
			break;
		case 83:

			direction = 1;
			break;
		case 68:

			direction = 4;
			break;
		case 87:

			direction = 2;
			break;
		case 32:
			break;
		default:
			break;
		}
		
		
	}


	void changePosition(int dir) /* 自动移动 */
	{
		
			world[x][y] = 0;

			switch (dir)
			{
			case 3:
				x -= 1;

				break;
			case 1:
				y += 1;

				break;
			case 4:
				x += 1;

				break;
			case 2:
				y -= 1;

				break;

			default:
				break;
			}
			if (x >= X_MAX + 1 || x <= 1 || y >= Y_MAX + 2 || y <= 1)
			{
				screenClear();
				cout << "You Died!!HAHAHAHA!!!";
				KillTimer(NULL, 1);
				cin.get();
				exit(0);
			}
			world[x][y] = 1;
			screenClear();
			worldMake();
		
	}


	theWorld()
	{
		x = 5; y = 5;
	}


	~theWorld()
	{
	}
};
theWorld* automove;



int main(int argc, char* argv[])
{
	
	
	hideCursor();

	opening();
	return 0;
}


void screenClear()      /* 清屏 */
{
	system("cls");
}


void hideCursor()       /* 隐藏光标 */
{
	HANDLE			hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO	ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}


void opening()  /* 游戏开始 */
{
	int choice = 1;
	screenClear();
	cout << "               贪吃蛇cpp版本                 " << endl << endl << endl;
	cout << "              【A】开始游戏                  " << endl;
	cout << "              【B】退出游戏                  " << endl;
	keyDown = _getch();
	switch (keyDown)
	{
	case 65:
		gameStart();
		keyDown = NULL;
		break;
	case 83:

		break;
	default:
		break;
	}
}

void CALLBACK Timer(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
	if(_kbhit() == 0) automove->changePosition(direction);
	else automove->changeDirection();
	
}
void gameStart()
{
	theWorld first;
	automove = &first;

	direction = 4;

	
	MSG Msg;
	SetTimer(NULL, 1, 400, (TIMERPROC)Timer);

	while (GetMessage(&Msg, NULL, 0, 0)) {
		DispatchMessage(&Msg); 
		
		
			
	}

	KillTimer(NULL, 1);

	
}
				keyDown = _getch();
				switch (keyDown)
				{
				case 65:
					x -= 1;
					break;
				case 83:
					y += 1;
					break;
				case 68:
					x += 1;
					break;
				case 87:
					y -= 1;
					break;
				case 32:
					break;
				default:
					break;
				}
				if (x >= X_MAX + 1 || x <= 1 || y >= Y_MAX + 2 || y <= 1) { x = 5; y = 5; }
				world[x][y] = 1;
				screenClear();
				worldMake();
			}
		}
		theWorld(){ x = 0; y = 0; }
		~theWorld(){}
};
	theWorld one;
	int x_temp, y_temp;
	cout << "please set x value" << endl;
	cin >> x_temp;
	cout << endl;
	cout << "please set y value" << endl;
	cin >> y_temp;
	cout << endl;
	hideshrink();
	screenClear();
	one.setPosition(x_temp, y_temp);
	one.worldMake();
	one.changePosition();
	
	
	cin.get();
	cin.get();
	return 0;
}
//清屏
void screenClear() {
	system("cls");
}
//隐藏光标
void hideshrink() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

