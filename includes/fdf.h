/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:08:59 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/05 20:29:51 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"

int		key_react (int keycode, void **tab);
int		main (int argc, char **argv);
int		**parsing (int fd, int **tab_pars);
void	draw (int **tab, int **tab_pars);
void	line_oct1(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct2(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct3(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct4(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct5(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct6(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct7(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_oct8(int **tab, int *pixel_un, int *pixel_deux, int *d);
void	line_right(int **tab, int *pixel_un, int *pixel_deux);
void	line_left(int **tab, int *pixel_un, int *pixel_deux);
void	line_up(int **tab, int *pixel_un, int *pixel_deux);
void	line_down(int **tab, int *pixel_un, int *pixel_deux);

#endif
