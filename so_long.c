/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:59:04 by yobenali          #+#    #+#             */
/*   Updated: 2022/03/27 15:59:06 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/so_long.h"

int	cal_x(char **tab)
{
	int	i;

	i = 0;
	while (tab[0][i])
		i++;
	i *= 64;
	return (i);
}

int	cal_y(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	i *= 64;
	return (i);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_s		d;
	int		num;
	char	*ptr;

	if (ac == 2)
	{
		num = ft_strlen(av[1]) - 4;
		if (ft_strncmp(&av[1][num], ".ber", 4))
			exit(write(2, "Error, map not valide\n", 23));
		num = open(av[1], O_RDONLY);
		if (num < 0)
			return (ft_printf("File not found\n"), 0);
		ptr = get_next_line(num);
		if (check_component(ptr))
			exit(write(2, "Error, map not valide\n", 23));
		initialization_data(&d, ptr);
		if (d.map != NULL)
			check_len_lines(d.map, ptr, &d);
		render(d.map, &d);
		mlx_key_hook(d.mlx_win, mov, &d);
		mlx_hook(d.mlx_win, 17, 1L << 5, ft_close, &d);
		mlx_loop(d.mlx);
	}
	return (0);
}
