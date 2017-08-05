/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_straight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 20:00:38 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/05 20:29:15 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_right(int **tab, int *pixel_un, int *pixel_deux)
{
	while (pixel_un[0]++ != pixel_deux[0])
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
}

void	line_left(int **tab, int *pixel_un, int *pixel_deux)
{
	while (pixel_un[0]-- != pixel_deux[0])
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
}

void	line_up(int **tab, int *pixel_un, int *pixel_deux)
{
	while (pixel_un[1]++ != pixel_deux[0])
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
}

void	line_down(int **tab, int *pixel_un, int *pixel_deux)
{
	while (pixel_un[1]-- != pixel_deux[0])
		mlx_pixel_put(tab[0], tab[1], pixel_un[0], pixel_un[1], 0x00FFFFFF);
}
