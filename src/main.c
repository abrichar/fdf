/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:23:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/02 18:54:00 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 123 = gauche
** 124 = droite
** 125 = bas
** 126 = haut
** 6 = z ==> Zoomer
** 2 = d ==> Dézoomer
*/

int		key_react(int keycode, void **tab, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tab[0], tab[1]);
		exit(EXIT_SUCCESS);
	}
	if (keycode <= 126 && keycode >= 123)
		move_graph(tab, map, keycode);
	ft_putnbr(keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	void	**tab;
	t_map	map;

	map.moving_h = 0;
	map.moving_v = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	call_for_malloc(fd, &map, argv[1]);
	if (parsing(fd, &map) == 0)
		return (0);
	if (close(fd) == -1)
		ft_putstr("Erreur dans la fermeture du fichier");
	mlx = mlx_init();
  	win = mlx_new_window(mlx, PIXEL_Y, PIXEL_X, "fdf");
	tab = (void**)malloc(sizeof(void*) * 2);
	tab[0] = mlx;
	tab[1] = win;
	display_spot(&map, tab);
	mlx_key_hook(win, key_react, tab);
	mlx_loop(mlx);
}
