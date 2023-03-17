/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saazcon- <saazcon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:02:54 by saazcon-          #+#    #+#             */
/*   Updated: 2023/03/16 19:46:51 by saazcon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//INCLUDES
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "mlx.h"

struct s_data {
	void	*mlx;
	void	*win;
	void	*main;
	void	*exit;
	void	*coin;
	void	*floor;
	void	*wall;
	int		w;
	int		h;
	int		x;
	int		y;
	int		letter_c;
	int		letter_p;
	int		letter_e;
	int		num_c;
	int		num_l;
	int		num_mov;
	int		main_init;
	int		path;
	char	*map;
};

int		ft_free(struct s_data *d);
int		ft_strlen(char *str);
int		ft_read_mov(int key, struct s_data *d);
char	*ft_itoa(int n);
char	*ft_strjoin(char *stash, char *buff);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(struct s_data *d);
void	ft_check_ext(struct s_data *d, char *file);
void	ft_check_file(struct s_data *d, char *file);
void	ft_check_map(struct s_data *d);
void	ft_init_map(struct s_data *d);
void	ft_init_img(struct s_data *d);

#endif