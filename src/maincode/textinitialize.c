#include "../headers/game.h"

void	textmenuinit(t_pr *g)
{
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/backmenu.xpm", &g->w, &g->w);
	g->img_buttonplay = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonplay.xpm", &g->w, &g->w);
	g->img_buttoncoop = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttoncoop.xpm", &g->w, &g->w);
	g->img_buttonmulti = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonmulti.xpm", &g->w, &g->w);
	g->img_buttonexit = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonexit.xpm", &g->w, &g->w);
	g->img_buttonframe = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonframe.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_back, 0, 0);
	if (g->menubar == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 150);
	else if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 250);
	else if (g->menubar == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 350);
	else if (g->menubar == 4)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 450);
	else if (g->menubar == 5)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 550);
}

void	startgameinit(t_pr *g)
{
	g->menuswitch = 0;
	g->pauseswitch = 1;
	if (g->menubar == 2) {
		g->xguy = 0;
		g->xteammate = g->w_width - 64;
	}
	Mix_HaltMusic();
	Mix_PlayMusic(g->firstLevel, -1);
	g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/grass.xpm", &g->w, &g->w);
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back1.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteam.xpm", &g->w, &g->w);		
	g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet1.xpm", &g->w, &g->w);
	g->img_level1 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level1.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level1, 0, 0);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keyscoop, 0, 0);
	else	
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keys, 0, 0);
	mlx_loop(g->mlx_ptr);
}
