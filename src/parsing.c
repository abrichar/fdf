/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:06:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/07/12 17:39:37 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fonction verif : Vérifie le formatage de la map.
** fonction parsing : Parse en int la map dans un tableau en deux dimensions.
*/

static int	verif(char *line)
{
	int i;

	i = 0;
	while ((line[i] == ' ' || (line[i] < 58 && line[i] > 47)) && line[i])
		i++;
	if (line[i] == '\0')
		return (1);
	ft_putstr("Erreur dans le formatage de la map,veuillez n'utiliser
				que des nombres et des espaces.\n");
	return (0);
}

int			parsing(int fd, int **tab_pars)
{
	int		i;
	int		j;
	char	*line;
	char	**to_convert;

	j = 0;
	tab_pars = (int **)malloc(sizeof(to_convert) + 1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("ligne : %s \n", line);
		i = 0;
		if (verif(line) == 0)
			return (-1);
		to_convert = ft_strsplit(line, ' ');
		tab_pars[j] = (int *)malloc(sizeof(to_convert[j]) + 1);
		while (to_convert[i])
		{
			tab_pars[j][i] = ft_atoi(to_convert[i]);
			i++;
		}
		j++;
	}
	return (0);
}
