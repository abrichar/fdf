/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:08:59 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/12 17:39:55 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdio.h> ///////////////////////////////////////////////
# include "../libft/includes/libft.h"
# define PIXEL_Y 1000
# define PIXEL_X 750

typedef struct s_pixel
{
	int x;
	int y;
}				t_pixel;

typedef struct	s_map
{
	int max_y;
	int max_x;
	int **tab_pars;
}				t_map;

int		key_react (int keycode, void **tab);
int		main (int argc, char **argv);
int		parsing (int fd, t_map *map);
int		call_for_malloc(int fd, t_map *map, char *file);
void	display_spot(t_map *map, void **tab);

#endif
