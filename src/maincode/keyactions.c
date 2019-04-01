#include "../headers/game.h"

void	unpause(t_pr *g)
{
	g->pauseswitch = 0;
	g->bullet_count = 0;
	playframes(g);
}

void		drawui(t_pr *g)
{
	char		*tmp;

	mlx_string_put(g->mlx_ptr, g->win_ptr, 5, 5, g->pointscolor, "Points: ");
	tmp = ft_itoa((int)g->points);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 76, 5, g->pointscolor, tmp);
	free(tmp);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 400, 5, g->pointscolor, "Level: ");
	tmp = ft_itoa(g->lev);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 465, 5, g->pointscolor, tmp);
	free(tmp);
}

void	game_over(t_pr *g) {
	g->gameoverswitch = 1;
	if (g->points == 2000)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_win, 0, -60);
	else
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_gameover, 0, 0);
}

void		move(int i, t_pr *g)
{
	mlx_clear_window(g->mlx_ptr, g->win_ptr);
	if ((i == 123 || i == 0) && g->pauseswitch == 0)
		move_left(i, g);
	else if ((i == 124 || i == 2) && g->pauseswitch == 0)
		move_right(i, g);
	if (g->pauseswitch == 0)
		g->points += 0.5;
	if (g->points == 500)
		load_second_level(g);
	else if (g->points == 1000 && g->pauseswitch == 0)
		load_third_level(g);
	else if (g->points == 1500 && g->pauseswitch == 0)
		load_fourth_level(g);	
	if (g->pauseswitch == 0 && g->gameoverswitch == 0)
		playframes(g);
	if (g->points == 2000 && g->pauseswitch == 0 && (g->menubar == 1 || g->menubar == 2))
		game_over(g);
}
