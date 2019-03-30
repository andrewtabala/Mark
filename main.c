#include "game.h"

void init(t_pr *g)
{
	srand(time(0));
	bzero(g, sizeof(t_pr));
	g->pauseswitch = 0;
	g->menuswitch = 1;
	g->menubar = 1;
	g->pointscolor = 6381921;
	g->level_speed = 3;
	g->w = 64;
	g->lev = 1;
	g->w_width = 480;
	g->w_height = 640;
	g->xguy = g->w_width/2 - 32;
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, g->w_width, g->w_height, "game");
	g->img_win = mlx_xpm_file_to_image(g->mlx_ptr, "textures/win.xpm", &g->w, &g->w);
	g->img_gameover = mlx_xpm_file_to_image(g->mlx_ptr, "textures/gameover.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);	
	g->bullets = (t_bullet *)calloc(MAX_BULLETS, sizeof(t_bullet));
	g->xteammate = g->w_width - g->w;
}

int closewin(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int			key_press(int key, void *param)
{
	t_pr	*g;

	g = (t_pr *)param;
	if (key == 53)
		exit(0);
	if ((key == 123 || key == 124 || key == 0 || key == 2 || key == 125 || key == 1) &&
		g->menuswitch == 0 && g->pauseswitch == 0 && g->gameoverswitch == 0)
		move(key, g);
	if (key == 36 && g->pauseswitch == 1)
		unpause(g);
	if ((key == 126 || key == 125 || key == 36) && g->menuswitch == 1)
		menumove(key, g);
	if (key == 15 && g->gameoverswitch == 1)
	{
		g->lev = 1;
		g->points = 0;
		g->gameoverswitch = 0;
		g->menuswitch = 1;
		menu(g);
	}
	return (0);
}

void		setup_controls(t_pr *g)
{
	mlx_hook(g->win_ptr, 2, 0, key_press, g);
	mlx_hook(g->win_ptr, 17, 0, closewin, g);
}

int main(int argc, char **argv)
{
	t_pr	g;
	init(&g);
	g.points = 999;
	setup_controls(&g);
	menu(&g);
	mlx_loop(g.mlx_ptr);
	return (0);
}