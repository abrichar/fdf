/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_oct2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 19:50:55 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/05 20:28:39 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_oct5(int **tab, int *pixel_un, int *pixel_deux, int *d)
{
	int e;

	e = d[0];
	d[0] *= 2;
	d[1] *= 2;
	while (pixel_un[0] - 1 != pixel_deux[0])
	{
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
		if ((e - d[1]) >= 0)
		{
			pixel_un[1]--;
			e += d[0];
		}
	}
}

void	line_oct6(int **tab, int *pixel_un, int *pixel_deux, int *d)
{
	int e;

	e = d[1];
	d[0] *= 2;
	d[1] *= 2;
	while (pixel_un[1] - 1 != pixel_deux[1])
	{
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
		if ((e - d[0]) >= 0)
		{
			pixel_un[0]--;
			e += d[1];
		}
	}
}

void	line_oct7(int **tab, int *pixel_un, int *pixel_deux, int *d)
{
	int e;

	e = d[1];
	d[0] *= 2;
	d[1] *= 2;
	while (pixel_un[1] - 1 != pixel_deux[1])
	{
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
		if ((e + d[0]) > 0)
		{
			pixel_un[0]++;
			e += d[1];
		}
	}
}

void	line_oct8(int **tab, int *pixel_un, int *pixel_deux, int *d)
{
	int e;

	e = d[0];
	d[0] *= 2;
	d[1] *= 2;
	while (pixel_un[0] + 1 != pixel_deux[0])
	{
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
		if ((e + d[1]) < 0)
		{
			pixel_un[1]--;
			e += d[0];
		}
	}
}
