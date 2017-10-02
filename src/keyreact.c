/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyreact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:31:12 by eliajin           #+#    #+#             */
/*   Updated: 2017/10/02 18:51:43 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void clear_windows(void **tab)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (i++ < PIXEL_Y)
		while (j++ < PIXEL_X)
			mlx_pixel_put(tab[0], tab[1], j, i, 000000);
}

void move_graph(void **tab, t_map *map, int keycode)
{
	clear_windows(tab);
	if (keycode == 123)
		map->moving_h -= 5;
	else if (keycode == 124)
		map->moving_h += 5;
	else if (keycode == 125)
		map->moving_v -= 5;
	else
		map->moving_v += 5;
	display_spot(map, tab);
}
