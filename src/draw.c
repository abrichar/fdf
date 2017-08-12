/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:49 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/12 18:11:34 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_spot(t_map *map, void **tab)
{
	int x;
	int y;
	t_pixel p_active;

	p_active.y = 50;
	y = 0;
	while (y < map->max_y)
	{
		x = 0;
		p_active.x = 50;
		while (x < map->max_x)
		{
			mlx_pixel_put(tab[0], tab[1], p_active.x, p_active.y, 0x0000FFFF);
			p_active.x += 10;
			x++;
		}
		y++;
		p_active.y += 10;
	}
}
