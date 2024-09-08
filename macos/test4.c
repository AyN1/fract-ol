#include "minilibx/mlx.h"

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
			mlx_pixel_put(mlx, mlx_window,x, y, 0xff0000);
	}
	for (int y = 0; y < HEIGHT * 0.1; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x0ff00);
	}
	for (int y = HEIGHT * 0.9; y < HEIGHT; ++y)
	{
		for (int x = 0; x < WIDTH; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x0ff00);
	}
	for (int y = HEIGHT * 0.2; y < HEIGHT * 0.8; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x0ff00);
	}
	for (int y = HEIGHT * 0.2; y < HEIGHT * 0.8; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x0ff00);
	}
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.2; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x000ff);
	}
	for (int y = HEIGHT * 0.8; y < HEIGHT * 0.9; ++y)
	{
		for (int x = 0; x < WIDTH * 0.1; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x000ff);
	}
	for (int y = HEIGHT * 0.1; y < HEIGHT * 0.2; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x000ff);
	}
	for (int y = HEIGHT * 0.8; y < HEIGHT * 0.9; ++y)
	{
		for (int x = WIDTH * 0.9; x < WIDTH; ++x)
			mlx_pixel_put(mlx, mlx_window,x, y, 0x000ff);
	}
	mlx_loop(mlx);
}
