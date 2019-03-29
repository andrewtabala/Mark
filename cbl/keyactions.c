#include "game.h"

void		drawui(t_pr *g)
{
	mlx_string_put(g->mlx_ptr, g->win_ptr, 5, 5, g->pointscolor, "Points: ");
	mlx_string_put(g->mlx_ptr, g->win_ptr, 76, 5, g->pointscolor, ft_itoa((int)g->points));
}

void		move(int i, t_pr *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	if (i == 123 || i == 0)
	{
		if (g->xguy > 0)
		{
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy2.xpm", &g->w, &g->w);
			g->xguy -= 8;
		}
	}
	else
	{
		if (g->xguy < g->w_width - 64)
		{
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
			g->xguy += 8;
		}
	}
	g->ybull += 6;
	g->points += 5;
	if (g->points == 400)
	{
		g->pointscolor = 14277081;
		g->lev = 2;
	}
	else if (g->points == 1000)
		g->lev = 3;
	drawback(g);
	drawland(g);
	drawui(g);
	drawguy(g);
	drawdrop(g, 50, 50);
	mlx_loop(g->mlx_ptr);
}