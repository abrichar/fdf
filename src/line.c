/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:00:26 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/07 15:40:52 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	line2(t_pixel *pixel0, t_line *line)
{
	if (line->e2 > -(line->dx))
	{
		line->err -= line->dy;
		pixel0->x_display += line->sx;
	}
	if (line->e2 < line->dy)
	{
		line->err += line->dx;
		pixel0->y_display += line->sy;
	}
}

void		line(t_pixel pixel0, t_pixel pixel1, void **tab)
{
	t_line line;

	line.dx = abs(pixel1.x_display - pixel0.x_display);
	line.sx = (pixel0.x_display < pixel1.x_display) ? 1 : -1;
	line.dy = abs(pixel1.y_display - pixel0.y_display);
	line.sy = (pixel0.y_display < pixel1.y_display) ? 1 : -1;
	line.err = ((line.dx > line.dy) ? line.dx : -(line.dy)) / 2;
	while (1)
	{
		if (pixel0.x_display > 0 && pixel0.y_display > 0
				&& pixel0.x_display < PIXEL_X && pixel0.y_display < PIXEL_Y)
			pixel_colored(tab, pixel0, tab[2]);
		if (pixel0.x_display == pixel1.x_display
				&& pixel0.y_display == pixel1.y_display)
			break ;
		line.e2 = line.err;
		line2(&pixel0, &line);
	}
}
