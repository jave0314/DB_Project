#include <stdio.h>
#include <Windows.h>
#include "init_display.h"

#define UP 0
#define DOWN 1

void gotoxy(int, int);
int keyControl();
int menuDraw();
void init_display();

void init_display() {
	printf("\n\n\n\n");
	printf("---------------------------------------------------\n\n");
	printf("    ######  #  #        ######  #  #         ######\n");
	printf("    #       #  #        #       #  #         #####\n");
	printf("    #       ####        #       ####         ####\n");
	printf("    #       #  #        #       #  #         ###\n");
	printf("    ######  #  #        ######  #  #         ##\n");
	printf("                                             #\n");
	printf("       #######             #######           \n");
	printf("      ##     ##           ##     ##          ##\n");
	printf("       #######             #######           #\n");
	printf("\n");
	printf("---------------------------------------------------\n");

	menuDraw();
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int keyControl() {
	char temp = _getch();

	if (temp == 'w' || temp == 'W') {
		return UP;
	}
	else if (temp == 's' || temp == 'S')
		return DOWN;
}

int menuDraw() {
	int x = 20;
	int y = 18;
	gotoxy(x - 2, y);
	printf("> 회원등록");
	gotoxy(x, y + 1);
	printf("회원조회");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 18) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 20) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}
		}
	}

}