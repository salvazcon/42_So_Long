/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:57:20 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/17 17:29:58 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_write_mov(struct s_data *d)
{
	char	*aux_num;

	aux_num = ft_itoa(d->num_mov);
	write(1, "-> Numero de movimientos: ", 26);
	write(1, aux_num, ft_strlen(aux_num));
	write(1, "\n", 1);
	if (aux_num)
		free(aux_num);
}

int	ft_check_step(struct s_data *d, int i)
{
	if (d->map[i] == '1')
		return (0);
	else if (d->map[i] == 'E' && d->letter_c == 0)
	{
		write(1, "-----------------------------\n", 30);
		write(1, "-> Lo lograste mi pana !!\n", 26);
		write(1, "-----------------------------\n", 30);
		ft_free(d);
	}
	else if (d->map[i] == '0')
	{
		d->map[d->main_init] = '0';
		d->map[i] = 'P';
	}
	else if (d->map[i] == 'C')
	{
		d->letter_c--;
		d->map[d->main_init] = '0';
		d->map[i] = 'P';
	}
	return (1);
}

int	ft_read_mov(int key, struct s_data *d)
{
	int		i;

	i = 0;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	else if (key == 13)
		i = d->main_init - d->num_c - 1;
	else if (key == 1)
		i = d->main_init + d->num_c + 1;
	else if (key == 0)
		i = d->main_init - 1;
	else if (key == 2)
		i = d->main_init + 1;
	if (ft_check_step(d, i))
	{
		d->num_mov++;
		ft_init_map(d);
		ft_write_mov(d);
	}
	return (0);
}
