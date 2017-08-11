/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:23:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/11 03:05:23 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_react(int keycode, void **tab)
{
	if (keycode == 53)
	{
		mlx_destroy_window(tab[0], tab[1]);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	void	**tab;
//	t_map	map;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
//	if (parsing(fd, &map) == 0)
//		return (0);
	if (close(fd) == -1)
		ft_putstr("Erreur dans la fermeture du fichier");
	mlx = mlx_init();
	ft_putstr("test00\n");
  	win = mlx_new_window(mlx, PIXEL_Y, PIXEL_X, "fdf");
	ft_putstr("test00\n");
	tab = (void**)malloc(sizeof(void*) * 2);
	tab[0] = mlx;
	ft_putstr("test00\n");
	tab[1] = win;
	ft_putstr("test00\n");
	mlx_key_hook(win, key_react, tab);
	ft_putstr("test00\n");
	mlx_loop(mlx);
}
