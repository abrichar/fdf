/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:49 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/13 20:48:15 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_vertical(t_pixel pixel, t_map *map, int begin, void **tab)
{
	t_pixel	pixel_next;

	pixel_next.x = pixel.x;
	pixel_next.y = pixel.y + ((PIXEL_X - (begin * 2)) / (map->max_y - 1));
	line (pixel, pixel_next, tab);
}

static void	draw_horizontal(t_pixel pixel, t_map *map, int begin, void **tab)
{
	t_pixel pixel_next;

	pixel_next.x = pixel.x + ((PIXEL_Y - (begin * 2)) / (map->max_x - 1));
	pixel_next.y = pixel.y;
	line (pixel, pixel_next, tab);
}

void		line(t_pixel pixel0, t_pixel pixel1, void **tab)
{
	t_line	line;

	line.dx = abs(pixel1.x - pixel0.x);
	line.sx = (pixel0.x < pixel1.x) ? 1 : -1;
	line.dy = abs(pixel1.y - pixel0.y);
	line.sy = (pixel0.y < pixel1.y) ? 1 : -1;
	line.err = ((line.dx > line.dy) ? line.dx : -(line.dy))/2;
	while (1)
	{
		mlx_pixel_put(tab[0], tab[1], pixel0.x, pixel0.y, COLOR);
		if (pixel0.x == pixel1.x && pixel0.y == pixel1.y)
			break;
		line.e2 = line.err;
		if (line.e2 > -(line.dx))
		{
			line.err -= line.dy;
			pixel0.x += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pixel0.y += line.sy;
		}
	}
}

void		display_spot(t_map *map, void **tab)
{
	int		i;
	int		j;
	t_pixel p_active;
	int		begin;

	begin = 5;
	p_active.y = begin;
	j = 0;
	while (j < map->max_y)
	{
		i = 0;
		p_active.x = begin;
		while (i < map->max_x)
		{
			mlx_pixel_put(tab[0], tab[1], p_active.x, p_active.y, COLOR);
			if (i + 1 < map->max_x)
				draw_horizontal(p_active, map, begin, tab);
			if (j + 1 < map->max_y)
				draw_vertical(p_active, map, begin, tab);
			p_active.x += ((PIXEL_Y - (begin * 2)) / (map->max_x - 1));
			i++;
		}
		j++;
		p_active.y += ((PIXEL_X - (begin * 2)) / (map->max_y - 1));
	}
}
