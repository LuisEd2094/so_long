#include "mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>


typedef struct s_mlx
{
    void *ptr;
    void *window;
} t_mlx;

typedef struct s_prg
{
    time_t lastRefreshTime;
    int refreshInterval;

}   t_prg;


int idle(t_prg *prg)
{
    static int count = 0;
    time_t currentTime;

    time(&currentTime); // Get current time

    if (currentTime - prg->lastRefreshTime >= prg->refreshInterval) {
        count++;
            time(&prg->lastRefreshTime); // Update last refresh time
        printf("%i\n", count);

    }

    sleep(1);
    return (1);
}

int key(int key, t_prg *prg)
{
    printf("%i\n", key);
}

int main ()
{
    t_mlx mlx;
    t_prg prg;

    time(&prg.lastRefreshTime);
    prg.refreshInterval = 1; 


    mlx.ptr = mlx_init();

    mlx.window = mlx_new_window(mlx.ptr, 800, 600, "so_long");

    mlx_loop_hook(mlx.ptr, idle, &prg);
    mlx_key_hook(mlx.window, key, &prg);

    mlx_loop(mlx.ptr);

}