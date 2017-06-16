/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrichar <abrichar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 16:23:25 by abrichar          #+#    #+#             */
/*   Updated: 2017/06/16 18:38:25 by abrichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/includes/libft.h"

int key_react(int keycode, void **tab)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(tab[0], tab[1]);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int parsing(int fd)
{
	int ret;
	char *line;

	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}
	return (0);
}

int main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	int		*tab[2];

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	else
		parsing(fd);
	if (close(fd) == -1)
		ft_putstr("Erreur dans la fermeture du fichier");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "fdf");
	tab[0] = mlx;
	tab[1] = win;
	mlx_key_hook(win, key_react, tab);
	mlx_loop(mlx);
}
