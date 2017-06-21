
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:06:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/21 17:21:06 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int verif(char *line)
{
    int i;

    i = 0;
    while ((line[i] == ' ' || (line[i] < 58 && line[i] > 47)) && line[i])
        i++;
    if (line[i] == '\0')
        return (1);
    ft_putstr("Erreur dans le formatage de la map,veuillez n'utiliser que des nombres et des espaces.\n");
    return (0);
}

int parsing(int fd, char **tab_pars)
{
	int i;
	int j;
    char *line;
    char **to_convert;

	j = 0;
    while (get_next_line(fd, &line) == 1)
    {
		i = 0;
        if (verif(line) == 0)
            return (-1);
        to_convert = ft_strsplit(line, ' ');
		while (to_convert[i])
		{
			tab_pars[i] = (char*)malloc(sizeof(to_convert[i]) + 1);
			tab_pars[j][i] = to_convert[0][i];
			i++;
		}
		j++;
    }
    return (0);
}
