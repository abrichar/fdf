/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:23:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/07 15:38:14 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_react(int keycode, void **tab)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tab[0], tab[1]);
		exit(EXIT_SUCCESS);
	}
	else if (keycode <= 126 && keycode >= 123)
		move_graph(tab, tab[2], keycode);
	else if (keycode == 6 || keycode == 2)
		zoom_graph(keycode, tab[2], tab);
	else if (keycode == 8)
		change_color(tab[2], tab);
	return (1);
}

static int	secure_variable(t_map *map, int argc, char **argv)
{
	int fd;

	map->moving_h = 0;
	map->moving_v = 0;
	map->zoom = 1;
	map->color_high = "AE642D";
	map->color_bottom = "0000FF";
	map->color_center = "568203";
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	call_for_malloc(fd, map, argv[1]);
	if (parsing(fd, map) == 0)
		return (0);
	if (close(fd) == -1)
		ft_putstr("Erreur dans la fermeture du fichier");
	return (1);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	**tab;
	t_map	map;

	if (secure_variable(&map, argc, argv) != 1)
		return (0);
	mlx = mlx_init();
	if (!mlx)
		exit(0);
	win = mlx_new_window(mlx, PIXEL_Y, PIXEL_X, "fdf");
	if (!win)
		exit(0);
	tab = (void**)malloc(sizeof(void*) * 2 + sizeof(t_map) * 1);
	if (tab == NULL)
		exit(0);
	tab[0] = mlx;
	tab[1] = win;
	tab[2] = &map;
	display_spot(tab[2], tab);
	mlx_key_hook(tab[1], key_react, tab);
	mlx_loop(tab[0]);
	return (0);
}
