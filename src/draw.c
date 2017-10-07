/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:49 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/07 15:01:16 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	new_position(t_pixel *pixel, t_map *map)
{
	int		distance;
	int		hauteur;
	double	tmp1;
	double	tmp2;

	distance = PIXEL_Y / (map->max_y + map->max_x) * map->zoom;
	hauteur = pixel->z * -10 * map->zoom;
	tmp1 = (double)pixel->x - ((double)map->max_x / 2);
	tmp2 = (double)pixel->y - ((double)map->max_y / 2);
	pixel->x_display = ((PIXEL_X / 2) + ((tmp1 - tmp2) * distance))
		+ map->moving_h;
	pixel->y_display = ((PIXEL_Y / 2) + ((tmp1 + tmp2) * distance) + hauteur)
		+ map->moving_v;
}

static void	draw_vertical(t_pixel pixel, t_map *map, void **tab)
{
	t_pixel	pixel_next;

	pixel_next.x = pixel.x;
	pixel_next.y = pixel.y + 1;
	pixel_next.z = map->tab_pars[pixel_next.y][pixel_next.x];
	new_position(&pixel_next, map);
	line(pixel, pixel_next, tab);
}

static void	draw_horizontal(t_pixel pixel, t_map *map, void **tab)
{
	t_pixel pixel_next;

	pixel_next.x = pixel.x + 1;
	pixel_next.y = pixel.y;
	pixel_next.z = map->tab_pars[pixel_next.y][pixel_next.x];
	new_position(&pixel_next, map);
	line(pixel, pixel_next, tab);
}

void		display_spot(t_map *map, void **tab)
{
	t_pixel pixel;

	pixel.y = 0;
	while (pixel.y < map->max_y)
	{
		pixel.x = 0;
		while (pixel.x < map->max_x)
		{
			pixel.z = map->tab_pars[pixel.y][pixel.x];
			new_position(&pixel, map);
			if (pixel.x + 1 < map->max_x)
				draw_horizontal(pixel, map, tab);
			if (pixel.y + 1 < map->max_y)
				draw_vertical(pixel, map, tab);
			pixel.x++;
		}
		pixel.y++;
	}
}
