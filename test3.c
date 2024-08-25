#include "minilibx/mlx.h"
#include <stdlib.h>

#define WIDTH 500
#define HEIGHT 500

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello World!");
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, rand() % 0x1000000);
	}
	mlx_string_put(mlx, mlx_window, WIDTH * 0.8, HEIGHT * 0.95, rand() % 0x1000000, "ATBICER");
	mlx_loop(mlx);
}
