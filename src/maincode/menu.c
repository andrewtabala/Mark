#include "../headers/game.h"

void	menumove(int i, t_pr *g)
{
	if (i == 125 && g->menubar < 5)
			g->menubar++;
		else if (i == 126 && g->menubar > 1)
			g->menubar--;
		else if (i == 36 && (g->menubar == 1 || g->menubar == 2 || g->menubar == 3))
		{
			g->menuswitch = 0;
			g->pauseswitch = 1;
			if (g->menubar == 2)
			{
				g->xguy = 0;
				g->xteammate = g->w_width - 64;
			}
			g->img_land = mlx_xpm_file_to_image(g->mlx_ptr, "textures/grass.xpm", &g->w, &g->w);
			g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back1.xpm", &g->w, &g->w);
			g->img_guy = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);
			g->img_teammate = mlx_xpm_file_to_image(g->mlx_ptr, "textures/guy.xpm", &g->w, &g->w);		
			g->img_proj = mlx_xpm_file_to_image(g->mlx_ptr, "textures/bullet1.xpm", &g->w, &g->w);
			g->img_level1 = mlx_xpm_file_to_image(g->mlx_ptr, "textures/level1.xpm", &g->w, &g->w);
			mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_level1, 0, 0);
			mlx_loop(g->mlx_ptr);
		}
		else if (g->menubar == 4)
		{
			if (i == 123)
			{
				g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffl.xpm", &g->w, &g->w);
				if (BS > 1)
					BS-=1;
			}
			else if (i == 124)
			{
				g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffr.xpm", &g->w, &g->w);
				if (BS < 10)
					BS+=1;
			}
		}
		else if (i == 36 && g->menubar == 5)
			exit(0);
		menu(g);
}

void	menu(t_pr *g)
{
	g->img_back = mlx_xpm_file_to_image(g->mlx_ptr, "textures/back1.xpm", &g->w, &g->w);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_back, 0, 0);
	g->img_buttonplay = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonplay.xpm", &g->w, &g->w);
	g->img_buttoncoop = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttoncoop.xpm", &g->w, &g->w);
	g->img_buttonmulti = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonmulti.xpm", &g->w, &g->w);
	g->img_buttonexit = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonexit.xpm", &g->w, &g->w);
	g->img_buttonframe = mlx_xpm_file_to_image(g->mlx_ptr, "textures/buttonframe.xpm", &g->w, &g->w);
	if (g->menubar == 1)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 100);
	else if (g->menubar == 2)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 200);
	else if (g->menubar == 3)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 300);
	else if (g->menubar == 4)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 400);
	else if (g->menubar == 5)
		mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonframe, 140, 500);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonplay, 140, 100);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttoncoop, 140, 200);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonmulti, 140, 300);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_diff, 140, 400);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 235, 414, g->pointscolor, ft_itoa(BS));
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonexit, 140, 500);
	mlx_loop(g->mlx_ptr);
}