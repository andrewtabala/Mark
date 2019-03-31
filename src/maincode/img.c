#include "../headers/game.h"

void	img(t_pr *g)
{
	int		bpp;
	int		sl;
	int		e;

	g->img_ptr = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_data = (int*)mlx_get_data_addr(g->img_ptr, &bpp, &sl, &e);
	g->img_land = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_back = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_proj = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_buttonplay = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_buttonexit = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_buttonmulti = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_buttonframe = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_level1 = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_level2 = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_level3 = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
	g->img_level4 = mlx_new_image(g->mlx_ptr, g->w_width, g->w_height);
}