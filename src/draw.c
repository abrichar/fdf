/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:37:30 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/03 14:02:17 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(int **tab, int **tab_pars)
{
	int pixel[2];
	int index[2];
	int to_go;

	index[0] = 0;
	index[1] = 0;
	pixel[1] = 200;
	mlx_pixel_put(tab[0], tab[1], pixel[0], pixel[1], 0x00FF00FF);
	if (!tab_pars)
		ft_putstr("prout");
	while (tab_pars[index[0]][index[1]])
	{
		if (tab_pars[index[0]][index[1] + 1])
			draw_line(tab_pars[index[0]][index[1]],
					tab_pars[index[0][index[1] + 1]));
		if (tab_pars[index[0] + 1][index[1]])
			draw_line(tab_pars[index[0]][index[1]],
					tab_pars[index[0] + 1][index[1]]);
		index[1]++;
		if (!tab_pars[index[0]][index[1]])
		{
			index[0]++;
			index[1] = 0;
		}
	}
}

void	draw_line(int **tab, int *pixel_un, int *pixel_deux)
{
	int y1;
	int x;
	float y;

	y1 = 0;
	y = 0;
	x = 0;
	while (x < pixel)
	{
		y = 0,7 * x + y1;
		mlx_pixel_put(tab[0], tab[1], )
		x++;
	}
}
