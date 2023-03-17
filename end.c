/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:40:45 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/17 17:33:08 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(struct s_data *d)
{
	if (d->map)
		free(d->map);
	if (d)
		free(d);
	exit(0);
}

void	ft_error(struct s_data *d)
{	
	write(1, "ERROR\n-> Lo siento bro, el jueguito", 35);
	write(1, " tuvo problemas para iniciar. :(\n", 33);
	ft_free(d);
}
