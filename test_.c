#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int x;
    int y;
} Position;

bool is_valid_position(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool is_map_valid(char map[MAX_ROWS][MAX_COLS], int rows, int cols) {
    Position player_pos;
    Position collectibles[MAX_ROWS * MAX_COLS];
    Position exit_pos;
    int collectibles_count = 0;
    int visited_collectibles = 0;
    bool visited[MAX_ROWS][MAX_COLS] = { false };

    // Find player's initial position
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'P') {
                player_pos.x = i;
                player_pos.y = j;
            }
        }
    }

    Position queue[MAX_ROWS * MAX_COLS];
    int front = 0;
    int rear = 0;

    // Enqueue player's position
    queue[rear++] = player_pos;
    visited[player_pos.x][player_pos.y] = true;

    while (front != rear) {
        Position current_pos = queue[front++];

        // Check if current position is a collectible or the exit
        char current_tile = map[current_pos.x][current_pos.y];
        if (current_tile == 'C') {
            collectibles[collectibles_count++] = current_pos;
        } else if (current_tile == 'E') {
            exit_pos = current_pos;
        }

        // Generate neighboring positions
        Position neighbors[4] = {
            { current_pos.x - 1, current_pos.y },
            { current_pos.x + 1, current_pos.y },
            { current_pos.x, current_pos.y - 1 },
            { current_pos.x, current_pos.y + 1 }
        };

        for (int i = 0; i < 4; i++) {
            int nx = neighbors[i].x;
            int ny = neighbors[i].y;

            if (is_valid_position(nx, ny, rows, cols) && map[nx][ny] == '0' && !visited[nx][ny]) {
                // Enqueue neighbor position
                queue[rear++] = neighbors[i];
                visited[nx][ny] = true;
            }
        }
    }

    // Check if all collectibles are visited
    for (int i = 0; i < collectibles_count; i++) {
        if (visited[collectibles[i].x][collectibles[i].y]) {
            visited_collectibles++;
        }
    }

    return exit_pos.x != -1 && visited_collectibles == collectibles_count;
}

int main() {
    char map[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the map:\n");
    for (int i = 0; i < rows; i++) {
        scanf("%s", map[i]);
    }

    if (is_map_valid(map, rows, cols)) {
        printf("Map is valid!\n");
    } else {
        printf("Map is invalid!\n");
    }

    return 0;
}