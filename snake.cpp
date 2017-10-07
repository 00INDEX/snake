#include "stdafx.h"
#include "iostream"
#include "windows.h"
#include "conio.h"

#define X_MAX 50
#define Y_MAX 20
#define WINDOWS_LEAD_AND_MEAN

using namespace std;

void screenClear();
void hideshrink();


int keyDown, direction;


int main(){
	
	class theWorld {
	protected:
		bool world[X_MAX][Y_MAX] = { 0 };
		int x, y;
	public:
		void setPosition(int x_temp, int y_temp) {
			world[x_temp][y_temp] = true;
			x = x_temp;
			y = y_temp;
		}
		void worldMake() {
			for (int y_counter = 0; y_counter <= Y_MAX + 2; y_counter++) {
				if (y_counter == 0 || y_counter == Y_MAX + 2) {
					for (int x_counter = 0; x_counter <= X_MAX + 2; x_counter++) {
						if (x_counter == 0 || x_counter == X_MAX + 2) cout << "|";
						else cout << "-";
					}
				}
				else for (int x_counter = 0; x_counter <= X_MAX + 2; x_counter++) {
					if (x_counter == 0 || x_counter == X_MAX + 2) cout << "|";
					else if (world[x_counter][y_counter] == true) cout << "#";
					else cout << " ";
				}
				cout << endl;
			}
		}
		void changePosition() {
			
			for (int i = 1; i >= 0; i++) {
				world[x][y] = 0;
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
void screenClear() {
	system("cls");
}
void hideshrink() {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOutput, &ConsoleCursorInfo);
}

