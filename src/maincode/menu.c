#include "../headers/game.h"

void	diffinit(int i, t_pr *g)
{
	if (i == 123) {
		g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffl.xpm", &g->w, &g->w);
		if (BS > 1 && BS <= 10)
			BS-=1;
	}
	else if (i == 124) {
		g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diffr.xpm", &g->w, &g->w);
		if (BS < 10)
			BS+=1;
	}
}

void	menumove(int i, t_pr *g)
{
	if (i == 125 && g->menubar < 5)
		g->menubar++;
	else if (i == 126 && g->menubar > 1)
		g->menubar--;
	else if (i == 36 && (g->menubar == 1 || g->menubar == 2 || g->menubar == 3))
		startgameinit(g);
	else if (g->menubar == 4)
		diffinit(i, g);
	else if (i == 124 && g->menubar == 5 && BS == 10)
		BS = 100;
	else if (i == 123 && g->menubar == 5 && BS == 100)
		BS = 10;
	else if (i == 36 && g->menubar == 5)
		exit(0);
	menu(g);
}

void	menu(t_pr *g)
{
	textmenuinit(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonplay, 140, 150);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttoncoop, 140, 250);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonmulti, 140, 350);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_diff, 140, 450);
	if (BS < 10)
		mlx_string_put(g->mlx_ptr, g->win_ptr, 235, 464, g->pointscolor, ft_itoa(BS));
	else if (BS == 10)
		mlx_string_put(g->mlx_ptr, g->win_ptr, 230, 464, g->pointscolor, ft_itoa(BS));
	else if (BS == 100)
		mlx_string_put(g->mlx_ptr, g->win_ptr, 225, 464, g->pointscolor, ft_itoa(BS));
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_buttonexit, 140, 550);
	mlx_loop(g->mlx_ptr);
}