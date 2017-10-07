/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 21:00:01 by eliajin           #+#    #+#             */
/*   Updated: 2017/10/07 15:48:02 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color(t_map *map, void **tab)
{
	if (strcmp("AE642D", map->color_high) == 0)
	{
		map->color_high = "8B6C42";
		map->color_bottom = "26C4EC";
		map->color_center = "096A09";
	}
	else if (strcmp(map->color_high, "8B6C42") == 0)
	{
		map->color_high = "AFA77B";
		map->color_bottom = "25FDE9";
		map->color_center = "00FF00";
	}
	else
	{
		map->color_high = "AE642D";
		map->color_bottom = "0000FF";
		map->color_center = "568203";
	}
	mlx_clear_window(tab[0], tab[1]);
	display_spot(tab[2], tab);
}
