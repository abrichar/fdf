/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:06:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/08/11 03:59:32 by eliajin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fonction verif : Vérifie le formatage de la map.
** Attention présence de problème quand je lance pylone (?)
** Possible que ça soit a cause de la trop grosse quantite de données (?)
** fonction parsing : Parse en int la map dans un tableau en deux dimensions.
*/

static int		verif(char *line)
{
	int i;

	i = 0;
	while (((line[i] == ' ' || (line[i] < 58 && line[i] > 47)) && line[i])
		|| line[i] == '-')
		i++;
	if (line[i] == '\0')
		return (i);
	ft_putstr("Erreur dans le formatage de la map");
	ft_putstr(",veuillez n'utilisez que des nombres et des espaces.\n");
	return (0);
}

static void		cal_for_malloc(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	map->max_x = 0;
	map->max_y = 0;
	while (get_next_line(fd, &line) == 1)
    {
        i = verif(line);
		if (i > map->max_x)
			map->max_x = i;
        j++;
    }
	map->max_y = j;
}

int				parsing(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*line;
	char	**to_convert;

	j = 0;
	cal_for_malloc(fd, map);
	map->tab_pars = (int **)malloc(sizeof(int *) * map->max_y);
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		if (verif(line) == 0)
			return (0);
		to_convert = ft_strsplit(line, ' ');
		map->tab_pars[j] = (int *)malloc(sizeof(int) * map->max_x);
		while (to_convert[i])
		{
			map->tab_pars[j][i] = ft_atoi(to_convert[i]);
			i++;
		}
		j++;
	}
	map->max_y = j;
	map->max_x = i;
	ft_putstr("parsing : OK\n");
	return (1);
}
