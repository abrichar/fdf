/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:37:30 by abrichar          #+#    #+#             */
/*   Updated: 2017/07/16 18:07:34 by abrichar         ###   ########.fr       */
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
	pixel[0] = 200;
	pixel[1] = 200;
	mlx_pixel_put(tab[0], tab[1], pixel[0], pixel[1], 0x00FF00FF);
	index[1]++;
	while (index[1] != 10)
	{
		if (tab_pars[index[0]][index[1]] == tab_pars[index[0]][index[1] - 1])
		{
			to_go = pixel[0] + 50;
			while (pixel[0] != to_go)
			{
				mlx_pixel_put(tab[0], tab[1], pixel[0], pixel[1], 0x00FF00FF);
				pixel[0]++;
			}
		}
		index[1]++;
	}
}
