#include "game.h"

void		drawui(t_pr *g)
{
	mlx_string_put(g->mlx_ptr, g->win_ptr, 5, 5, g->pointscolor, "Points: ");
	mlx_string_put(g->mlx_ptr, g->win_ptr, 76, 5, g->pointscolor, ft_itoa((int)g->points));
	mlx_string_put(g->mlx_ptr, g->win_ptr, 400, 5, g->pointscolor, "Level: ");
	mlx_string_put(g->mlx_ptr, g->win_ptr, 465, 5, g->pointscolor, ft_itoa(g->lev));
}

void	init_bullet(t_bullet *bullet, t_pr *g)
{
	const int type[] = {NORMAL, NORMAL, NORMAL, EXPLOSIVE, EXPLOSIVE, EXPLOSIVE};
	const int speed[] = {4, 7, 10};

	bullet->type = type[rand() % (g->lev * 2)];
	bullet->speed = rand() % speed[rand() % g->lev] + 1;
	bullet->x = rand() % (g->w_width - g->w);
	bullet->y = rand() % 30;
}


void	bullet_fire(t_pr *g)
{
	if (!((int)g->points % (rand() % 200 + 1)) || g->points == 0)
	{
		if (g->bullet_count != MAX_BULLETS)
			init_bullet(&g->bullets[g->bullet_count], g);
		g->bullet_count++;
	}
	for (int i = 0; i < g->bullet_count; i++)
	{
		g->bullets[i].y += g->bullets[i].speed;
		if (g->bullets[i].y >= g->w_height) {
			init_bullet(&g->bullets[i], g);
		}
		drawdrop(g, g->bullets[i].x, g->bullets[i].y);
	}
}

void		move(int i, t_pr *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	if (i == 123 || i == 0)
	{
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy2.xpm", &g->w, &g->w);
		if (g->lev >= 3)
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace2.xpm", &g->w, &g->w);
		if (g->xguy > 0)
			g->xguy -= 8;
	}
	else if (i == 124 || i == 1)
	{
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
		if (g->lev >= 3)
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
		if (g->xguy < g->w_width - 64)
			g->xguy += 8;
	}
	g->points += 1;
	if (g->points == 500)
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
	bullet_fire(g);
	mlx_loop(g->mlx_ptr);
}
