#include "../headers/game.h"

void	drawdrop(t_pr *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_proj, x, y);
}

void	drawguy(t_pr *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_guy, g->xguy, g->w_height - 80);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_teammate, g->xteammate, g->w_height - 80);
}

void	drawback(t_pr *g)
{
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_back, 0, 0);
}

void	drawland(t_pr *g)
{
	if (g->lev == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 40);
	else if (g->lev == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 160);
	else if (g->lev == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 218);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_land, 0, g->w_height - 275);
}
