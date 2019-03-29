#include "game.h"

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
	if (key == 123 || key == 124 || key == 0 || key == 2)
		move(key, g);
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
	g.w = 64;
	g.xguy = 0;
	g.lev = 1;
	g.w_width = 480;
	g.w_height = 640;
	g.mlx_ptr = mlx_init();
	g.win_ptr = mlx_new_window(g.mlx_ptr, g.w_width, g.w_height, "game");
	g.img_guy = mlx_xpm_file_to_image(g.mlx_ptr, "textures/guy.xpm", &g.w, &g.w);
	setup_controls(&g);
	drawback(&g);
	drawland(&g);
	drawguy(&g);
	drawdrop(&g, 50, 50);
	mlx_loop(g.mlx_ptr);
	return (0);
}