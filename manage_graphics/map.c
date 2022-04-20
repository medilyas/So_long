/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:54 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/22 16:07:35 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	initialize_variables(t_program *prog, char *path)
{
	prog->glob.path = path;
	prog->glob.fd = open(prog->glob.path, O_RDONLY);
	prog->glob.c = 0;
	prog->glob.e = 0;
	prog->glob.p = 0;
	prog->glob.t = 0;
	prog->glob.w = 0;
	prog->glob.epty = 0;
	prog->glob.str = NULL;
}

void	check_map_path(t_program *prog)
{
	int		size;

	size = 0;
	while (prog->glob.path[size])
		size++;
	if (ft_strcmp(prog->glob.path + size - 4, ".ber") != 0 || prog->glob.fd < 3)
		put_error_msg(-2, NULL);
}

static void	check_contains(t_program *prog, char c, int x, int y)
{
	if (c == 'C')
		prog->glob.c += 1;
	else if (c == 'E')
		prog->glob.e += 1;
	else if (c == 'P')
	{
		prog->glob.p += 1;
		prog->p.x = x;
		prog->p.y = y;
	}
	else if (c == 'T')
	{
		prog->t.x[prog->glob.t] = x;
		prog->t.y[prog->glob.t] = y;
		prog->glob.t += 1;
	}
	else if (c == '0')
		prog->glob.epty = 1;
	else if (c == '1')
		prog->glob.w = 1;
	if (prog->glob.p > 1)
		put_error_msg(5, prog);
}

static void	check_map(t_program *prog)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = -1;
	height = prog->glob.map_d.line - 1;
	width = prog->glob.map_d.column - 1;
	while (prog->glob.map[++i])
	{
		j = -1;
		while (prog->glob.map[i][++j])
		{
			if (prog->glob.map[0][j] != '1' || prog->glob.map[height][j] != '1'\
			|| prog->glob.map[i][0] != '1' || prog->glob.map[i][width] != '1')
				put_error_msg(1, prog);
			if (prog->glob.map[i][j] != '0' && prog->glob.map[i][j] != '1'\
			&& prog->glob.map[i][j] != 'C' && prog->glob.map[i][j] != 'E'\
			&& prog->glob.map[i][j] != 'P' && prog->glob.map[i][j] != 'T')
				put_error_msg(3, prog);
			check_contains(prog, prog->glob.map[i][j], i, j);
		}
	}
	if (prog->glob.c == 0 || prog->glob.e == 0 || prog->glob.p != 1)
		put_error_msg(2, prog);
}

void	map_checker(t_program *prog, char *path)
{
	initialize_variables(prog, path);
	check_map_path(prog);
	get_width_height(prog);
	check_map(prog);
}
