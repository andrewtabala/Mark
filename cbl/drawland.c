#include "game.h"

void	drawdrop(t_pr *g, int x, int y)
{
	if (g->lev == 1)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet1.xpm", &g->w, &g->w);
	else if (g->lev == 2)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet2.xpm", &g->w, &g->w);
	else if (g->lev == 3)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet3.xpm", &g->w, &g->w);
	else
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet4.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_proj, 90, g->ybull);
}

void	drawguy(t_pr *g)
{
	if (g->lev == 1)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	else if (g->lev == 2)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	else if (g->lev == 3)
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	else
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_guy, g->xguy, g->w_height - 80);
}

void	drawback(t_pr *g)
{
	if (g->lev == 1)
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back1.xpm", &g->w, &g->w);
	else if (g->lev == 2)
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back2.xpm", &g->w, &g->w);
	else if (g->lev == 3)
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back3.xpm", &g->w, &g->w);
	else
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back4.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_back, 0, 0);
}

void	drawland(t_pr *g)
{
	int 	i = 0;
	int 	c = 480;
	if (g->lev == 1)
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/grass.xpm", &g->w, &g->w);
	else if (g->lev == 2)
	{
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/cloud.xpm", &g->w, &g->w);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 160);
		return;
	}
	else if (g->lev == 3)
	{
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/rocket.xpm", &g->w, &g->w);
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 218);
		return;
	}
	else
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/mossy.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 64, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 128, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 192, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 256, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 320, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 384, g->w_height - 40);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 448, g->w_height - 40);
}