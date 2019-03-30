#include "game.h"

void	unpause(t_pr *g)
{
	g->pauseswitch = 0;
	g->bullet_count = 0;
	drawback(g);
	drawland(g);
	drawui(g);
	drawguy(g);
	bullet_fire(g);
}

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
	const int speed[] = {5, 8, 13, 19, 25, 35, 45, 55};

	bullet->type = type[rand() % (g->lev * 2)];
	bullet->speed = speed[g->lev - 1] + rand() % 10;
	bullet->x = rand() % (g->w_width - g->w);
	bullet->y = rand() % 30;
}

void	game_over(t_pr *g) {
	g->gameoverswitch = 1;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_gameover, 0, 0);
}

int		bullet_kills(t_pr *g, t_bullet *bullet) {
	return (bullet->y >= 535 && bullet->x >= g->xguy - 8 && bullet->x <= g->xguy + 44);
}

void	bullet_fire(t_pr *g)
{
	if (!((int)g->points % (rand() % 200 + 1)) || g->points == 0)
	{
		if (g->bullet_count != MAX_BULLETS) {
			init_bullet(&g->bullets[g->bullet_count], g);
		}
		g->bullet_count++;
	}
	for (int i = 0; i < g->bullet_count; i++)
	{
		g->bullets[i].y += g->bullets[i].speed;
		if (g->bullets[i].y >= g->w_height) {
			init_bullet(&g->bullets[i], g);
		}
		if (bullet_kills(g, &g->bullets[i])) {
			game_over(g);
		}
		drawdrop(g, g->bullets[i].x, g->bullets[i].y);
	}
}

void		move(int i, t_pr *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	if ((i == 123 || i == 0) && g->pauseswitch == 0)
	{
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy2.xpm", &g->w, &g->w);
		if (g->lev >= 3)
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace2.xpm", &g->w, &g->w);
		if (g->xguy > 0)
			g->xguy -= 8;
	}
	else if ((i == 124 || i == 1) && g->pauseswitch == 0)
	{
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
		if (g->lev >= 3)
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
		if (g->xguy < g->w_width - 64)
			g->xguy += 8;
	}
	else if ((i == 125 || i == 1) && g->lev >= 3 && g->pauseswitch == 0)
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	if (g->pauseswitch == 0)
		g->points += 0.5;
	if (g->points == 500 )
	{
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/cloud.xpm", &g->w, &g->w);
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back2.xpm", &g->w, &g->w);
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet2.xpm", &g->w, &g->w);
		g->img_level2 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level2.xpm", &g->w, &g->w);
		g->xguy = g->w_width/2 - 32;
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level2, 0, 0);
		g->pauseswitch = 1;
		g->pointscolor = 14277081;
		g->lev = 2;
	}
	else if (g->points == 1000 && g->pauseswitch == 0)
	{
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/rocket.xpm", &g->w, &g->w);
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back3.xpm", &g->w, &g->w);
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet3.xpm", &g->w, &g->w);
		g->img_level3 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level3.xpm", &g->w, &g->w);
		g->xguy = g->w_width/2 - 32;
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level3, 0, 0);
		g->pauseswitch = 1;
		g->lev = 3;
	}
	else if (g->points == 1500 && g->pauseswitch == 0)
	{
		g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/door.xpm", &g->w, &g->w);
		g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back4.xpm", &g->w, &g->w);
		g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
		g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bulletzapas.xpm", &g->w, &g->w);
		g->img_level4 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level4.xpm", &g->w, &g->w);
		g->xguy = g->w_width/2 - 32;
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level4, 0, 0);
		g->pauseswitch = 1;
		g->lev = 4;
	}
	if (g->pauseswitch == 0)
	{
		drawback(g);
		drawland(g);
		drawui(g);
		drawguy(g);
		bullet_fire(g);
	}
	mlx_loop(g->mlx_ptr);
}
