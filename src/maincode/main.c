#include "../headers/game.h"

int closewin(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int			key_release(int key, void *param)
{
	t_pr	*g;

	g = (t_pr *)param;
	if ((key == 123 || key == 124) && g->menubar == 4)
	{
		g->img_diff = mlx_xpm_file_to_image(g->mlx_ptr, "textures/diff.xpm", &g->w, &g->w);
		menu(g);
	}
	return (0);
}

int			key_press(int key, void *param)
{
	if (key == 53)
		exit(0);
	if ((key == 123 || key == 124 || key == 0 || key == 2 || key == 125 || key == 1) &&
		((t_pr*)param)->menuswitch == 0 && ((t_pr*)param)->pauseswitch == 0 && ((t_pr*)param)->gameoverswitch == 0)
		move(key, ((t_pr*)param));
	if (key == 36 && ((t_pr*)param)->pauseswitch == 1)
		unpause(((t_pr*)param));
	if ((key == 126 || key == 125 || key == 123 || key == 124 || key == 36) && ((t_pr*)param)->menuswitch == 1)
		menumove(key, ((t_pr*)param));
	if (key == 15 && ((t_pr*)param)->gameoverswitch == 1)
	{
		((t_pr*)param)->lev = 1;
		((t_pr*)param)->points = 0;
		((t_pr*)param)->gameoverswitch = 0;
		((t_pr*)param)->menuswitch = 1;
		Mix_HaltMusic();
		Mix_PlayMusic(((t_pr*)param)->menuSound, -1);
		menu(((t_pr*)param));
	}
	return (0);
}

void		setup_controls(t_pr *g)
{
	mlx_hook(g->win_ptr, 2, 0, key_press, g);
	mlx_hook(g->win_ptr, 3, 0, key_release, g);
	mlx_hook(g->win_ptr, 17, 0, closewin, g);
}

int main(void)
{
	t_pr	g;

	init(&g);
	setup_controls(&g);
	Mix_PlayMusic(g.menuSound, -1);
	menu(&g);
	mlx_loop(g.mlx_ptr);
	return (0);
}
