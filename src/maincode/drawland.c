#include "../headers/game.h"

void	drawdrop(t_pr *g, int x, int y)
{
	//g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet4.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_proj, x, y);
}

void	drawguy(t_pr *g)
{
	//g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_guy, g->xguy, g->w_height - 80);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_teammate, g->xteammate, g->w_height - 80);
}

void	drawback(t_pr *g)
{
	//g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back4.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_back, 0, 0);
}

void	drawland(t_pr *g)
{
	int 	i = 0;
	int 	c = 480;
	if (g->lev == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 40);
	else if (g->lev == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 160);
	else if (g->lev == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 218);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 275);
}