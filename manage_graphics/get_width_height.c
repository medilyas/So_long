/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:46 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/22 16:56:13 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_allocate(t_program *prog, int enemy)
{
	int	height;
	int	width;

	height = prog->glob.map_d.line;
	width = prog->glob.map_d.column;
	prog->t.x = (int *)malloc(sizeof(int) * enemy);
	prog->t.y = (int *)malloc(sizeof(int) * enemy);
	if (!prog->t.x || !prog->t.y)
		put_error_msg(-1, prog);
}

static void	ft_realloc(t_program *prog)
{
	int		i;
	char	*p;

	p = (char *)malloc(sizeof(char) * ft_strlen(prog->glob.str) + 2);
	if (!p)
	{
		free(prog->glob.str);
		put_error_msg(-1, NULL);
	}
	i = 0;
	while (prog->glob.str != NULL && prog->glob.str[i])
	{
		p[i] = prog->glob.str[i];
		i++;
	}
	p[i] = 0;
	if (prog->glob.str != NULL)
		free(prog->glob.str);
	prog->glob.str = p;
}

static void	ft_read_map(t_program *prog, int *enemy)
{
	int	r;
	int	i;

	r = 1;
	i = 0;
	while (r > 0)
	{
		ft_realloc(prog);
		r = read(prog->glob.fd, (prog->glob.str + i), 1);
		if (prog->glob.str[i] == 'T')
			*enemy += 1;
		i++;
		prog->glob.str[i] = '\0';
		if (r <= 0 && i > 1 && prog->glob.str[i - 2] == '\n')
		{
			free(prog->glob.str);
			put_error_msg(4, NULL);
		}
	}
}

void	get_width_height(t_program *prog)
{
	int		enemy;

	enemy = 0;
	prog->glob.str = NULL;
	prog->t.x = NULL;
	prog->t.y = NULL;
	prog->glob.map = NULL;
	ft_read_map(prog, &enemy);
	prog->glob.map = ft_split(prog->glob.str, '\n', prog);
	free(prog->glob.str);
	prog->glob.str = NULL;
	ft_allocate(prog, enemy);
}
