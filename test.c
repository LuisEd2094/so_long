#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>



#define RED 0xFFA07A
#define BLUE 0x00BFFF

#define HEIGHT 600
#define WIDTH 800
#define KEY_A 97
#define KEY_D 100
#define KEY_W 119
#define KEY_S 115


typedef struct s_mlx
{
    void *ptr;
    void *window;
} t_mlx;


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		height;
	int		width;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_enemy
{
    unsigned int x;
    unsigned int y;
} t_enemy;

typedef struct s_prg
{
    time_t lastRefreshTime;
    t_mlx   *mlx;
    t_img   sprites[6];
    t_enemy enemy_1;
    int moves;
    char str[100];
    int refreshInterval;
    int x;
    int y;
    int color;
    int sprite;


}   t_prg;


void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base) {
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);

    return str;
}

void update_window(t_prg *prg)
{
    mlx_clear_window(prg->mlx->ptr, prg->mlx->window);

    if (prg->x >= prg->enemy_1.x && prg->x <= prg->enemy_1.x && prg->y <= 32)
    {
        printf("you died\n");
        exit(1);
    }

    mlx_pixel_put(prg->mlx->ptr, prg->mlx->window, prg->x, prg->y, prg->color);
    mlx_put_image_to_window(prg->mlx->ptr, prg->mlx->window, prg->sprites[prg->sprite].img, prg->enemy_1.x, prg->enemy_1.y);
    mlx_string_put(prg->mlx->ptr, prg->mlx->window,  60, 60, RED, "HOLA");
    itoa(prg->moves, prg->str, 10);
    mlx_string_put(prg->mlx->ptr, prg->mlx->window,  100, 60, RED, prg->str );



}

int idle(t_prg *prg)
{
    static int count = 0;
    static int move = 1;
    time_t currentTime;

    time(&currentTime);

    if (currentTime - prg->lastRefreshTime >= prg->refreshInterval) 
    {
        if (prg->color == RED)
            prg->color = BLUE;
        else if (prg->color == BLUE)
            prg->color = RED;
        prg->sprite++;
        if (prg->sprite == 5)
            prg->sprite = 0;

        prg->enemy_1.x += 32 * move;
        if (prg->enemy_1.x >= WIDTH / 2)
            move = -1;
        else if (prg->enemy_1.x <= 64)
            move = 1;
        update_window(prg);
        time(&prg->lastRefreshTime);
    }
    return (1);
}

int key(int key, t_prg *prg)
{
    if (key == KEY_A)
        prg->x -= 10;
    else if (key == KEY_D)
        prg->x += 10;
    else if (key == KEY_W)
        prg->y -= 10;
    else if (key == KEY_S)
        prg->y += 10;
    prg->moves++;
    update_window(prg);

    //printf("%i\n", key);
}

int main ()
{
    t_mlx mlx;
    t_prg prg;



    time(&prg.lastRefreshTime);


    prg.moves = 0;
    prg.mlx = &mlx;
    prg.refreshInterval = 1;
    prg.color = RED;
    prg.x = WIDTH / 2;
    prg.y = HEIGHT / 2; 
    prg.sprite = 0; 
    prg.enemy_1.x = 64 + 32;
    prg.enemy_1.y = 0;


    mlx.ptr = mlx_init();
    prg.sprites[0].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_1.xpm", &prg.sprites[0].width, &prg.sprites[0].height);
    prg.sprites[1].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_2.xpm", &prg.sprites[1].width, &prg.sprites[1].height);
    prg.sprites[2].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_3.xpm", &prg.sprites[2].width, &prg.sprites[2].height);
    prg.sprites[3].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_4.xpm", &prg.sprites[3].width, &prg.sprites[3].height);
    prg.sprites[4].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_5.xpm", &prg.sprites[4].width, &prg.sprites[4].height);
    prg.sprites[5].img = mlx_xpm_file_to_image(prg.mlx->ptr, "imgs/torch_6.xpm", &prg.sprites[5].width, &prg.sprites[5].height);
    mlx.window = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "so_long");

    mlx_loop_hook(mlx.ptr, idle, &prg);
    mlx_key_hook(mlx.window, key, &prg);

    mlx_loop(mlx.ptr);

}