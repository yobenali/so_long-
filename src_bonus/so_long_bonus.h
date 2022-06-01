/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:22:08 by yobenali          #+#    #+#             */
/*   Updated: 2022/04/12 20:22:11 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include "../gnl_bonus/get_next_line_bonus.h"
# include "../ft_printf_bonus/ft_printf_bonus.h"
# include <mlx.h>

# define K_A 0
# define K_D 2
# define K_S 1
# define K_W 13
# define K_ESC 53

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*pr;
	void	*wall;
	void	*cl;
	void	*e[5];
	void	*gd;
	char	*ptr;
	char	**map;
	int		count;
	int		lines;
	int		c;
	int		size_x;
	int		size_y;
	int		x;
	int		y;
	int		i;
	int		j;
	int		weed;
	int		img_w;
	int		img_h;
}				t_s;

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	initialization_data(t_s *d, char *ptr);
void	check_sep(char *str, t_s *d);
void	check_len_lines(char **ptr, char *str, t_s *d);
void	check_walls(char **ptr, t_s *d);
void	help_render(char **tab, t_s *d, int i, int j);
void	render_player(t_s *d, int i, int j);
void	render_exit(t_s *d);
int		render(t_s *d);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
int		cal_x(char **tab);
int		cal_y(char **tab);
int		mov(int keycode, t_s *d);
int		ft_close(void);
int		check_exit(t_s *d);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_component(char *ptr);

#endif
