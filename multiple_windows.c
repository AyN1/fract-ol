#include "minilibx/mlx.h"
/*
 * With MinilibX, you can open multiple windows from a single program.
 * Each window will have its own unique identifier (a window pointer),

	* but they can all be managed through a single connection to the display (the MLX pointer).
 */

#include <stdlib.h>
#include <time.h>

#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400

void	ft_art(void *mlx, void *window, int color1, int color2, int color3)
{
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.1; x < WIDTH * 0.9; ++x)
			mlx_pixel_put(mlx, window, x, y, color1);
	}
	for (int y = 0; y < HEIGHT * 0.1; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
			mlx_pixel_put(mlx, window, x, y, color2);
	}
	for (int y = HEIGHT * 0.9; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
			mlx_pixel_put(mlx, window, x, y, color2);
	}
	for (int y = HEIGHT * 0.2; y < HEIGHT * 0.8; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, window, x, y, color2);
	}
	for (int y = HEIGHT * 0.2; y < HEIGHT * 0.8; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, window, x, y, color2);
	}
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.2; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, window, x, y, color3);
	}
	for (int y = HEIGHT * 0.8; y < HEIGHT * 0.9; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, window, x, y, color3);
	}
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.2; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, window, x, y, color3);
	}
	for (int y = HEIGHT * 0.8; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, window, x, y, color3);
	}
}

int	main(void)
{
	void	*mlx_connection;
	void	*window1;
	void	*window2;

	srand(time(NULL));
	mlx_connection = mlx_init();
	if (NULL == mlx_connection)
		return (MALLOC_ERROR);
	window1 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 1");
	window2 = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "Window 2");
	ft_art(mlx_connection, window1, rand() % 0x1000000, rand() % 0x1000000,
		rand() % 0x1000000);
	ft_art(mlx_connection, window2, rand() % 0x1000000, rand() % 0x1000000,
		rand() % 0x1000000);
	mlx_loop(mlx_connection);
	return (0);
}
