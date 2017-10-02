/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 16:52:49 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/02 14:58:16 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void new_position(t_pixel *pixel, t_map *map)
{
	int tmp1;
	int tmp2;

	tmp1 = PIXEL_X / map->max_x;
	tmp2 = PIXEL_Y / (map->max_y + map->max_x);
	if (tmp2 < tmp1)
		tmp1 = tmp2;
	pixel->x_display = (PIXEL_X / 2) + (pixel->x - pixel->y) * tmp1;
	pixel->y_display = (pixel->x + pixel->y) * tmp1 + pixel->z * -5;
}

static void	draw_vertical(t_pixel pixel, t_map *map, void **tab)
{
	t_pixel	pixel_next;

	pixel_next.x = pixel.x;
	pixel_next.y = pixel.y + 1;
	pixel_next.z = map->tab_pars[pixel_next.y][pixel_next.x];
	new_position(&pixel_next, map);
	line (pixel, pixel_next, tab);
}

static void	draw_horizontal(t_pixel pixel, t_map *map, void **tab)
{
	t_pixel pixel_next;

	pixel_next.x = pixel.x + 1;
	pixel_next.y = pixel.y;
	pixel_next.z = map->tab_pars[pixel_next.y][pixel_next.x];
	new_position(&pixel_next, map);
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
	t_pixel pixel;

	pixel.y = 0;
	while (pixel.y < map->max_y)
	{
		pixel.x = 0;
		while (pixel.x < map->max_x)
		{
			//changer la fonction pour qu elle affiche la bonne position de x
			//et d'y, grace a la fonction new_position.
			//actuellement, part dans line mais dans line, les nouvelles
			//valeurs ne sont pas encore actualisés.
			pixel.z = map->tab_pars[pixel.y][pixel.x];
			new_position(&pixel, map);
			mlx_pixel_put(tab[0], tab[1], pixel.x_display, pixel.y_display, COLOR);
			if (pixel.x + 1 < map->max_x)
				draw_horizontal(pixel, map, tab);
			if (pixel.y + 1 < map->max_y)
				draw_vertical(pixel, map, tab);
			pixel.x++;
		}
		pixel.y++;
	}
}
