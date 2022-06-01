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

#include "so_long_bonus.h"

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
	}
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

void	render_exit(t_s *d)
{
	static int	i;
	static int	frames;

	if (i >= 5)
		i = 0;
	if (d->weed != 0)
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->e[0], d->img_w, d->img_h);
	else if (d->weed == 0)
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->e[i], d->img_w, d->img_h);
	if (frames == 7)
	{
		frames = 0;
		i++;
	}
	frames++;
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
		render_exit(d);
	else if (tab[i][j] == '0')
		mlx_put_image_to_window(d->mlx, \
		d->mlx_win, d->gd, d->img_w, d->img_h);
	else
		exit(write(2, "Error, map not valide\n", 23));
}

int	render(t_s *d)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	d->weed = 0;
	while (d->map[i])
	{
		if (i >= 0)
			d->img_h = 64 * i;
		j = 0;
		while (d->map[i][j])
		{
			help_render(d->map, d, i, j);
			j++;
		}
		i++;
	}
	ptr = ft_itoa(d->count);
	mlx_string_put(d->mlx, d->mlx_win, 32, (d->lines * 64 - 36), 0, "Moves: ");
	mlx_string_put(d->mlx, d->mlx_win, 97, (d->lines * 64 - 36), 0, ptr);
	free(ptr);
	ptr = NULL;
	return (0);
}
