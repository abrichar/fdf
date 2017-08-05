/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 17:37:30 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/05 20:29:31 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(int **tab, int *pixel_un, int *pixel_deux)
{
	int d[2];

	d[0] = pixel_deux[0] - pixel_un[0];
	d[1] = pixel_deux[1] - pixel_deux[1];
	if (d[0] != 0)
		if (d[0] > 0)
			if (d[1] != 0)
				if (d[1] > 0)
					line_oct1(tab, pixel_un, pixel_deux, d);
				else
					line_oct2(tab, pixel_un, pixel_deux, d);
			else
				if (d[0] >= -d[1])
					line_oct8(tab, pixel_un, pixel_deux, d);
				else
					line_oct7(tab, pixel_un, pixel_deux, d);
		else
			line_right(tab, pixel_un, pixel_deux);
	else if (d[1] != 0)
		if (d[1] > 0)
			if (-(d[0]) >= d[1])
				line_oct4(tab, pixel_un, pixel_deux, d);
			else
				line_oct3(tab, pixel_un, pixel_deux, d);
		else if (d[0] <= d[1])
			line_oct5(tab, pixel_un, pixel_deux, d);
		else
			line_oct6(tab, pixel_un, pixel_deux, d);
	else if (d[0] < 0)
		line_left(tab, pixel_un, pixel_deux);
	else if (d[1] != 0)
	{
		if (d[1] > 0)
			line_up(tab, pixel_un, pixel_deux);
		else
			line_down(tab, pixel_un, pixel_deux);
	}
}

void	draw(int **tab, int **tab_pars)
{
	int pixel_un[2];
	int pixel_deux[2];
	int index[2];

	index[0] = 0;
	index[1] = 0;
	if (!tab_pars)
		ft_putstr("prout");
	while (tab_pars[index[0]][index[1]])
	{
		if (tab_pars[index[0]][index[1] + 1])
		{
			pixel_un[0] = tab_pars[index[0]][index[1]];
			pixel_un[1] = index[1];
			pixel_deux[0] = tab_pars[index[0]][index[1] + 1];
			pixel_deux[1] = index[1] + 1;
			draw_line(tab, pixel_un, pixel_deux);
		}
		if (tab_pars[index[0] + 1][index[1]])
		{
			pixel_un[0] = tab_pars[index[0]][index[1]];
			pixel_un[1] = index[1];
			pixel_deux[0] = tab_pars[index[0] + 1][index[1]];
			pixel_deux[1] = index[1];
			draw_line(tab, pixel_un, pixel_deux);
		}
		index[1]++;
		if (!tab_pars[index[0]][index[1]])
		{
			index[0]++;
			index[1] = 0;
		}
	}
}
