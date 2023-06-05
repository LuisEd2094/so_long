#include <stdio.h>

#define ROWS 5
#define COLS 13

char map[ROWS][COLS] = {
    "1111111111111",
    "10100000000C1",
    "1010011111001",
    "1P1011E000001",
    "1111111111111"
};

int visited[ROWS][COLS] = {0};  // Track visited positions

int is_valid_move(int row, int col) {
    // Check if the move is within the map boundaries and not an obstacle
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && map[row][col] != '1' && !visited[row][col]) {
        return 1;
    }
    return 0;
}

void dfs(int row, int col) {
    visited[row][col] = 1;  // Mark current position as visited
    printf("%c Char, %i row, %i col\n", map[row][col], row, col);

    // Check if the current position is a collectable
    if (map[row][col] == 'C') {
        printf("Collectable found at (%d, %d)!\n", row, col);
    }

    // Check if the current position is the exit
    if (map[row][col] == 'E') {
        printf("Exit found at (%d, %d)! All collectables collected.\n", row, col);
        return;
    }

    // Explore all possible moves: up, down, left, right
    int dr[] = {-1, 1, 0, 0};  // Change in row coordinate
    int dc[] = {0, 0, -1, 1};  // Change in column coordinate

    for (int i = 0; i < 4; i++) {
        int new_row = row + dr[i];
        int new_col = col + dc[i];

        if (is_valid_move(new_row, new_col)) {
            dfs(new_row, new_col);
        }
    }
}

int main() {
    int start_row, start_col;

    // Find the starting position of the player
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == 'P') {
                start_row = i;
                start_col = j;
                break;
            }
        }
    }
    dfs(start_row, start_col);

    return 0;
}