#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>

void read_arr(FILE* f_in, char** arr, int height, int width) {
	for (int i{ 0 }; i < height; i++) {
		for (int j{ 0 }; j < width; ++j) {
			arr[i][j] = fgetc(f_in);
		}
		fgetc(f_in);
	}
}

void SetColor(short text_color, short bg_color) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (bg_color << 4) | text_color);
}

int main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_VIRTUAL_TERMINAL_INPUT);
	srand((unsigned)time(NULL));
	int width, height, quan, delay_time;
	FILE* f_in = fopen("input.txt", "r");
	fscanf(f_in, "%d", &height);
	fscanf(f_in, "%d", &width);
	fscanf(f_in, "%d", &quan);
	fscanf(f_in, "%d", &delay_time);
	fgetc(f_in);
	char** arr{ new char* [height] };
	for (int i{ 0 }; i < height; ++i) {
		arr[i] = new char[width];
	}
	read_arr(f_in, arr, height, width);
	fclose(f_in);
	while (true) {
		for (int i{ 0 }; i < height; ++i) {
			for (int k{ 0 }; k < quan; ++k) {
				for (int j{ 0 }; j < width; ++j) {
					if (arr[i][j] != ' ') {
						short text_color = rand() % 15 + 1;
						short bg_color = rand() % 15 + 1;
						SetColor(text_color, bg_color);
						std::cout << arr[i][j];
					}
					else {
						SetColor(7, 0);
						std::cout << arr[i][j];
					}
				}
				SetColor(7, 0);
				std::cout << "  ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		Sleep(delay_time);
	}
	delete[] arr;
	return 0;
}