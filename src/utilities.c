/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:20:16 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/07 15:49:27 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hex_char_to_dec(char c)
{
	if ('0' <= c && c <= '9')
		return (c - '0');
	else if ('A' <= c && c <= 'F')
		return (c - 'A' + 10);
	else if ('a' <= c && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

static int	hex_to_dec(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		nb *= 16;
		nb += hex_char_to_dec(str[i]);
		i++;
	}
	return (nb);
}

void		pixel_colored(void **tab, t_pixel pixel0, t_map *map)
{
	if (pixel0.z > 10)
		mlx_pixel_put(tab[0], tab[1], pixel0.x_display,
				pixel0.y_display, hex_to_dec(map->color_high));
	else if (pixel0.z < 0)
		mlx_pixel_put(tab[0], tab[1], pixel0.x_display,
				pixel0.y_display, hex_to_dec(map->color_bottom));
	else
		mlx_pixel_put(tab[0], tab[1], pixel0.x_display,
				pixel0.y_display, hex_to_dec(map->color_center));
}
