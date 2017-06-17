/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:08:59 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/17 18:07:34 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "../libft/includes/libft.h"

int key_react(int keycode, void **tab);
int main (int argc, char **argv);
int parsing (int fd, int *tab_pars);

#endif