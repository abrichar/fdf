/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:16:52 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/16 16:09:59 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int my_key_funct(int keycode, void **tab)
{
	int x;
	int y;
	void *mlx;
	void *win;

	mlx = tab[0];
	win = tab[1];
	printf("key event %d\n", keycode);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FF00FF);
			x++;
		}
		y++;
	}
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int x;
	int y;
	int *tab[2];

	y = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	tab[0] = mlx;
	tab[1] = win;
	mlx_key_hook(win, my_key_funct, tab);
	mlx_loop(mlx); //rend la main au systeme graphique et gere les evenements
}
