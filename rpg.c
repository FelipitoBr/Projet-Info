#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tc.h"
typedef struct
{
	int x;
	int y;
} Player;

void init_map(int map[][MAP_SIZE]){
	for (int i = 0; i < MAP_SIZE; i++){
		for (int k = 0; k < MAP_SIZE; k++) {
		map[i][k] = 0;
		}
	}
}

void print_map(Player player, int map[][MAP_SIZE]){
	system("clear");
	for (int i = 0; i < MAP_SIZE; i++){
		for (int k = 0; k < MAP_SIZE; k++) {
			if (i == player.y && k == player.x) {
				printf("P ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
}

void move_player(char input, Player player, int map[][MAP_SIZE] ) {
	int new_x = player.x;
	int new_y = player.y;
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
	player.x = new_x;
	player.y = new_y;
	}
}

int main() {
	int map[MAP_SIZE][MAP_SIZE];
	Player player;
	init_map(map);
	player.x = 50;
	player.y = 50;
	char input;
	while (1) {
		print_map(player,map);
		printf("\nup:%c left:%c down:%c right:%c\n\n", MOVE_UP, MOVE_LEFT, MOVE_DOWN, MOVE_RIGHT);
	scanf("%c", &input);
	move_player(input,player, map);
	}
	return 0;
}
