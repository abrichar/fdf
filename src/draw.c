/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:49 by abrichar          #+#    #+#             */
/*   Updated: 2017/09/12 18:58:51 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void new_position(t_pixel *pixel)
{
	if (!pixel->A && !pixel->B && !pixel->C)
	{
		pixel->A = 0;
		pixel->B = 0;
		pixel->C = 0;
	}
	pixel->x_display = pixel->y * cos(pixel->B) * cos(pixel->C);
    pixel->x_display += pixel->x * -sin(pixel->C) * cos(pixel->B);
    pixel->x_display += pixel->z * sin(pixel->B);
	pixel->y_display = (int)(pixel->y * (cos(pixel->C) * -sin(pixel->A) * -sin(pixel->B) + sin(pixel->C) *  cos(pixel->A)) + pixel->x * (-sin(pixel->C) * -sin(pixel->A) * -sin(pixel->B) + cos(pixel->C) * cos(pixel->A)) + pixel->z * -sin(pixel->A) * cos(pixel->B));

}

static void	draw_vertical(t_pixel pixel, t_map *map, int begin, void **tab)
{
	t_pixel	pixel_next;

	pixel_next.x = pixel.x;
	pixel_next.y = pixel.y + ((PIXEL_X - (begin * 2)) / (map->max_y - 1));
	new_position(&pixel_next);
	line (pixel, pixel_next, tab);
}

static void	draw_horizontal(t_pixel pixel, t_map *map, int begin, void **tab)
{
	t_pixel pixel_next;

	pixel_next.x = pixel.x + ((PIXEL_Y - (begin * 2)) / (map->max_x - 1));
	pixel_next.y = pixel.y;
	new_position(&pixel_next);
	line (pixel, pixel_next, tab);
}

void		line(t_pixel pixel0, t_pixel pixel1, void **tab)
{
	t_line	line;

	line.dx = abs(pixel1.x_display - pixel0.x_display);
	line.sx = (pixel0.x_display < pixel1.x_display) ? 1 : -1;
	line.dy = abs(pixel1.y_display - pixel0.y_display);
	line.sy = (pixel0.y_display < pixel1.y_display) ? 1 : -1;
	line.err = ((line.dx > line.dy) ? line.dx : -(line.dy))/2;
	while (1)
	{
		mlx_pixel_put(tab[0], tab[1], pixel0.x_display, pixel0.y_display, COLOR);
		if (pixel0.x_display == pixel1.x_display
			&& pixel0.y_display == pixel1.y_display)
			break;
		line.e2 = line.err;
		if (line.e2 > -(line.dx))
		{
			line.err -= line.dy;
			pixel0.x_display += line.sx;
		}
		if (line.e2 < line.dy)
		{
			line.err += line.dx;
			pixel0.y_display += line.sy;
		}
	}
}

void		display_spot(t_map *map, void **tab)
{
	int		i;
	int		j;
	t_pixel pixel;
	int		begin;

	begin = 40;
	pixel.y = begin;
	j = 0;
	while (j < map->max_y)
	{
		i = 0;
		pixel.x = begin;
		while (i < map->max_x)
		{
			//changer la fonction pour qu elle affiche la bonne position de x
			//et d'y, grace a la fonction new_position.
			//actuellement, part dans line mais dans line, les nouvelles
			//valeurs ne sont pas encore actualisés.
			pixel.z = map->tab_pars[j][i];
			if (pixel.z != 0)
				new_position(&pixel);
			mlx_pixel_put(tab[0], tab[1], pixel.x_display, pixel.y_display, COLOR);
			if (i + 1 < map->max_x)
				draw_horizontal(pixel, map, begin, tab);
			if (j + 1 < map->max_y)
				draw_vertical(pixel, map, begin, tab);
			pixel.x += ((PIXEL_Y - (begin * 2)) / (map->max_x - 1));
			i++;
		}
		j++;
		pixel.y += ((PIXEL_Y - (begin * 2)) / (map->max_x - 1));
	}
}
