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
	mlx_loop(mlx);
}
