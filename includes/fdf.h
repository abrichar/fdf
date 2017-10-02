/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:08:59 by abrichar          #+#    #+#             */
/*   Updated: 2017/10/02 18:52:42 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <stdio.h> ///////////////////////////////////////////////
# include "../libft/includes/libft.h"
# include <math.h>
# define PIXEL_Y 800
# define PIXEL_X 800
# define COLOR 0x0000FFFF
# define ZOOM 1

typedef struct s_pixel
{
	int x;
	int y;
	int z;
	int x_display;
	int y_display;
	double A;
	double B;
	double C;
}				t_pixel;

typedef struct s_line
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}				t_line;

typedef struct	s_map
{
	int max_y;
	int max_x;
	int **tab_pars;
	int moving_h;
	int moving_v;
}				t_map;

int		key_react (int keycode, void **tab, t_map *map);
int		main (int argc, char **argv);
int		parsing (int fd, t_map *map);
int		call_for_malloc(int fd, t_map *map, char *file);
void	display_spot(t_map *map, void **tab);
void	line(t_pixel pixel0, t_pixel pixel1, void **tab);

#endif
