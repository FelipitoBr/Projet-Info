#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 100

#define MOVE_UP 'z'
#define MOVE_DOWN 's'
#define MOVE_LEFT 'q'
#define MOVE_RIGHT 'd'

int map[MAP_SIZE][MAP_SIZE];
int player_x, player_y;

void init_map(){
	for (int i = 0; i < MAP_SIZE; i++){
		for (int k = 0; k < MAP_SIZE; k++) {
		map[i][k] = 0;
		}
	}
}

void print_map(){
	system("clear");
	for (int i = 0; i < MAP_SIZE; i++){
		for (int k = 0; k < MAP_SIZE; k++) {
			if (i == player_y && k == player_x) {
				printf("P ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
}

void move_player(char input) {
	int new_x = player_x;
	int new_y = player_y;
	switch (input) {
		case MOVE_UP :
			new_y--;
			break;
		case MOVE_DOWN :
			new_y++;
			break;
		case MOVE_LEFT :
			new_x--;
			break;
		case MOVE_RIGHT :
			new_x++;
			break;
		}
	if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE && map[new_x][new_y] == 0) {
	player_x = new_x;
	player_y = new_y;
	}
}

int main() {
	init_map();
	player_x = 50;
	player_y = 50;
	char input;
	while (1) {
		print_map();
		printf("\nup:%c left:%c down:%c right:%c\n\n", MOVE_UP, MOVE_LEFT, MOVE_DOWN, MOVE_RIGHT);
	scanf("%c", &input);
	move_player(input);
	}
	return 0;
}






