/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:37:18 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/16 18:58:42 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_all(struct s_data *d, char *file)
{
	ft_check_ext(d, file);
	ft_check_file(d, file);
	ft_check_map(d);
	ft_init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	ft_init_map(d);
	d->num_mov = 0;
}

int	main(int argc, char **argv)
{
	struct s_data	*d;

	if (argc != 2)
	{
		write(1, "ERROR\n -> Numero de argumentos incorrecto.\n", 43);
		return (0);
	}
	d = ft_calloc(1, sizeof(struct s_data));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	ft_init_all(d, argv[1]);
	mlx_key_hook(d->win, ft_read_mov, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}
