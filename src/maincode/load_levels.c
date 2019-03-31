#include "../headers/game.h"

void		load_second_level(t_pr *g)
{
	Mix_HaltMusic();
	Mix_PlayMusic(g->secondLevel, -1);
	g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/cloud.xpm", &g->w, &g->w);
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back2.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteam.xpm", &g->w, &g->w);
	g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet2.xpm", &g->w, &g->w);
	g->img_level2 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level2.xpm", &g->w, &g->w);
	g->xguy = (g->menubar == 2) ? 0 : g->w_width/2 - 32;
	g->xteammate = g->w_width - 64;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level2, 0, 0);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keyscoop, 0, 0);
	else	
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keys, 0, 0);
	g->pauseswitch = 1;
	g->pointscolor = 14277081;
	g->lev = 2;
}

void		load_third_level(t_pr *g)
{
	Mix_HaltMusic();
	Mix_PlayMusic(g->thirdLevel, -1);
	g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/rocket.xpm", &g->w, &g->w);
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back3.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteamspace.xpm", &g->w, &g->w);
	g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet3.xpm", &g->w, &g->w);
	g->img_level3 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level3.xpm", &g->w, &g->w);
	g->xguy = (g->menubar == 2) ? 0 : g->w_width/2 - 32;
	g->xteammate = g->w_width - 64;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level3, 0, 0);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keyscoop, 0, 0);
	else	
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keys, 0, 0);
	g->pauseswitch = 1;
	g->lev = 3;
}

void		load_fourth_level(t_pr *g)
{
	Mix_HaltMusic();
	Mix_PlayMusic(g->fourthLevel, -1);	
	g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/door.xpm", &g->w, &g->w);
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back4.xpm", &g->w, &g->w);
	g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyspace.xpm", &g->w, &g->w);
	g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guyteamspace.xpm", &g->w, &g->w);
	g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bulletzapas.xpm", &g->w, &g->w);
	g->img_level4 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level4.xpm", &g->w, &g->w);
	g->xguy = (g->menubar == 2) ? 0 : g->w_width/2 - 32;
	g->xteammate = g->w_width - 64;
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level4, 0, 0);
	if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keyscoop, 0, 0);
	else	
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_keys, 0, 0);
	g->pauseswitch = 1;
	g->lev = 4;
}
