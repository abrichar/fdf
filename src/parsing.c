/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 16:06:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/17 16:12:34 by abrichar         ###   ########.fr       */
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
    ft_putstr("Erreur dans le formatage de la map\n");
    return (0);
}

int parsing(int fd)
{
    int ret;
    int **tab_pars;
    char *line;
    char **to_convert;

    while (get_next_line(fd, &line) == 1)
    {
        if (verif(line) == 0)
            return (-1);
        to_convert = ft_strsplit(line, ' ');
    }
    return (0);
}
