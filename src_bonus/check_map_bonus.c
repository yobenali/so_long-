/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:12:06 by yobenali          #+#    #+#             */
/*   Updated: 2022/04/12 06:12:08 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_walls(char **ptr, t_s *d)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[0][j] != '1' || ptr[d->lines - 1][j] != '1')
				exit(write(2, "Error, Wall not valide\n", 24));
			if (ptr[i][d->c - 1] != '1' || ptr[i][0] != '1')
				exit(write(2, "Error, Wall not valide\n", 24));
			j++;
		}
		i++;
	}
}

void	check_sep(char *str, t_s *d)
{
	int	count;
	int	index;

	count = 1;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '\n')
			count++;
		index++;
	}
	if (d->lines != count)
		exit(write(2, "Error, map not valide\n", 23));
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == 'P')
			count++;
		index++;
	}
	if (count != 1)
		exit(write(2, "Error, map not valide\n", 23));
}

void	check_len_lines(char **ptr, char *str, t_s *d)
{
	d->c = ft_strlen(ptr[d->lines]);
	while (ptr[d->lines])
	{
		if (d->c != ft_strlen(ptr[d->lines]))
			exit(write(2, "Error, map not valide\n", 23));
		d->lines++;
	}
	check_sep(str, d);
	check_walls(ptr, d);
}

int	check_component(char *ptr)
{
	int	i;

	i = ft_strlen(ptr);
	if (ft_strchr(ptr, 'C'))
		if (ft_strchr(ptr, 'E'))
			if (ft_strchr(ptr, 'P'))
				return (0);
	return (1);
}

void	initialization_data(t_s *d, char *ptr)
{
	d->c = 0;
	d->count = 0;
	d->lines = 0;
	d->ptr = ptr;
	d->map = ft_split(ptr, '\n');
	d->img_h = 0;
	d->img_w = 0;
	d->mlx = mlx_init();
	d->size_x = cal_x(d->map);
	d->size_y = cal_y(d->map);
	d->mlx_win = mlx_new_window(d->mlx, d->size_x, d->size_y, "so_long");
	d->pr = mlx_xpm_file_to_image(d->mlx, "ig/p.xpm", &d->img_w, &d->img_h);
	d->wall = mlx_xpm_file_to_image(d->mlx, "ig/w.xpm", &d->img_w, &d->img_h);
	d->e[0] = mlx_xpm_file_to_image(d->mlx, "ig/p1.xpm", &d->img_w, &d->img_h);
	d->e[1] = mlx_xpm_file_to_image(d->mlx, "ig/p2.xpm", &d->img_w, &d->img_h);
	d->e[2] = mlx_xpm_file_to_image(d->mlx, "ig/p3.xpm", &d->img_w, &d->img_h);
	d->e[3] = mlx_xpm_file_to_image(d->mlx, "ig/p4.xpm", &d->img_w, &d->img_h);
	d->e[4] = mlx_xpm_file_to_image(d->mlx, "ig/p5.xpm", &d->img_w, &d->img_h);
	d->cl = mlx_xpm_file_to_image(d->mlx, "ig/cl.xpm", &d->img_w, &d->img_h);
	d->gd = mlx_xpm_file_to_image(d->mlx, "ig/gd.xpm", &d->img_w, &d->img_h);
}
