#include "minilibx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1280, 720, "Hello World!");
	mlx_loop(mlx);
}
