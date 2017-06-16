/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:23:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/16 17:40:58 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

int key_react(int keycode, void **tab)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(tab[0], tab[1]);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int main()
{
	void *mlx;
	void *win;
	int *tab[2];

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	tab[0] = mlx;
	tab[1] = win;
	mlx_key_hook(win, key_react, tab);
	mlx_loop(mlx);
}
