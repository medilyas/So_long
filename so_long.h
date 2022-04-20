/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:24:39 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:24:40 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"

typedef struct s_image
{
	void	*empty;
	void	*wall;
	void	*player[2];
	void	*collect[8];
	void	*trap[2];
	void	*exit[2];
}	t_image;

typedef struct s_map
{
	int	column;
	int	line;
}	t_map;

typedef struct s_data {
	t_map	map_d;
	char	**map;
	char	*str;
	char	*path;
	void	*empty;
	void	*wall;
	void	*player;
	void	*collect;
	void	*trap;
	void	*exit;
	int		fd;
	int		c;
	int		e;
	int		p;
	int		t;
	int		w;
	int		epty;
}	t_data;

typedef struct s_player
{
	int		x;
	int		y;
	int		count_moves;
	int		count_collect;
}	t_player;

typedef struct s_enemy
{
	int	*x;
	int	*y;
}	t_enemy;

typedef struct s_program
{
	t_image			img;
	t_data			glob;
	t_player		p;
	t_enemy			t;
	void			*mlx;
	void			*win;
	unsigned int	frame;
}	t_program;

/* Close the game */

int		ft_close(t_program *prog);
void	game_win(t_program *prog);
void	game_over(t_program *prog);

/* Manage Graphics */

void	define_images(t_program *prog);
void	put_image(t_program *prog);
void	map_checker(t_program *prog, char *path);
void	ft_put_moves(t_program *prog);

/* Manage Assets  */

int		player_moves(int keycode, t_program *prog);
void	enemy_moves(t_program *prog);

/* Helpers (Checking MAP & Manage Messeges) */

void	get_width_height(t_program *prog);
void	check_map_path(t_program *prog);
char	*ft_strdup(char *s1, int to_free);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_free(char *res, char *buff, char *stat);
char	**ft_split(char *s, char c, t_program *prog);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
void	put_error_msg(int m, t_program *prog);
char	*ft_itoa(int n);

#endif
