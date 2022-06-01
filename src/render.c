/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 06:46:24 by yobenali          #+#    #+#             */
/*   Updated: 2022/04/12 06:46:26 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_s *d)
{
	if (d->map[d->x + d->i][d->y + d->j] == 'E' && d->weed != 0)
		return (0);
	if (d->map[d->x + d->i][d->y + d->j] == '1')
		return (0);
	return (1);
}

int	mov(int keycode, t_s *d)
{
	d->i = 0;
	d->j = 0;
	if (keycode == K_W && check_exit(d))
		d->i -= 1;
	else if (keycode == K_S && check_exit(d))
		d->i += 1;
	else if (keycode == K_A && check_exit(d))
		d->j -= 1;
	else if (keycode == K_D && check_exit(d))
		d->j += 1;
	else if (keycode == K_ESC)
		exit(1);
	if (d->weed == 0 && d->map[d->x + d->i][d->y + d->j] == 'E')
		exit(printf("YAY!! YOU WON DUMB"));
	if (check_exit(d) && (d->i != 0 || d->j != 0))
	{
		d->map[d->x][d->y] = '0';
		d->map[d->x + d->i][d->y + d->j] = 'P';
		d->count++;
		ft_printf("Moves : %d\n", d->count);
	}
	mlx_clear_window(d->mlx, d->mlx_win);
	render(d->map, d);
	return (0);
}

void	render_player(t_s *d, int i, int j)
{
	mlx_put_image_to_window(d->mlx, \
	d->mlx_win, d->gd, d->img_w, d->img_h);
	mlx_put_image_to_window(d->mlx, \
	d->mlx_win, d->pr, d->img_w + 1, d->img_h);
	d->x = i;
	d->y = j;
}

void	help_render(char **tab, t_s *d, int i, int j)
{
	if (j >= 0)
		d->img_w = 64 * j;
	if (tab[i][j] == '1')
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->wall, d->img_w, d->img_h);
	else if (tab[i][j] == 'P')
		render_player(d, i, j);
	else if (tab[i][j] == 'C')
	{
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->cl, d->img_w, d->img_h);
		d->weed++;
	}
	else if (tab[i][j] == 'E')
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->out, d->img_w, d->img_h);
	else if (tab[i][j] == '0')
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->gd, d->img_w, d->img_h);
	else
		exit(write(2, "Error, map not valide\n", 23));
}

void	render(char **tab, t_s *d)
{
	int	i;
	int	j;

	i = 0;
	d->weed = 0;
	while (tab[i])
	{
		if (i >= 0)
			d->img_h = 64 * i;
		j = 0;
		while (tab[i][j])
		{
			help_render(tab, d, i, j);
			j++;
		}
		i++;
	}
}
