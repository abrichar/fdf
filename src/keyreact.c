/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyreact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliajin <abrichar@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:31:12 by eliajin           #+#    #+#             */
/*   Updated: 2017/10/03 15:30:31 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_graph(int keycode, t_map *map, void **tab)
{
	mlx_clear_window(tab[0], tab[1]);
	if (keycode == 6)
	{
		map->zoom *= 2;
	}
	else map->zoom /= 2;
	display_spot(tab[2], tab);
}

void	move_graph(void **tab, t_map *map, int keycode)
{
	mlx_clear_window(tab[0], tab[1]);
	if (keycode == 123)
		map->moving_h -= 5;
	else if (keycode == 124)
		map->moving_h += 5;
	else if (keycode == 125)
		map->moving_v += 5;
	else
		map->moving_v -= 5;
	display_spot(tab[2], tab);
}
