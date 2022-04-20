/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/22 17:04:54 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_program *prog)
{
	if (prog->glob.map[prog->p.x - 1][prog->p.y] == '0' \
	|| prog->glob.map[prog->p.x - 1][prog->p.y] == 'C')
	{
		if (prog->glob.map[prog->p.x - 1][prog->p.y] == 'C')
			prog->p.count_collect -= 1;
		prog->glob.map[prog->p.x - 1][prog->p.y] = 'P';
		prog->glob.map[prog->p.x][prog->p.y] = '0';
		prog->p.x = prog->p.x - 1;
		prog->p.count_moves++;
	}
	else if (prog->glob.map[prog->p.x - 1][prog->p.y] == 'T')
		game_over(prog);
	else if (prog->glob.map[prog->p.x - 1][prog->p.y] == 'E' \
	&& prog->p.count_collect == 0)
		game_win(prog);
}

static void	move_down(t_program *prog)
{
	if (prog->glob.map[prog->p.x + 1][prog->p.y] == '0' \
	|| prog->glob.map[prog->p.x + 1][prog->p.y] == 'C')
	{
		if (prog->glob.map[prog->p.x + 1][prog->p.y] == 'C')
			prog->p.count_collect -= 1;
		prog->glob.map[prog->p.x + 1][prog->p.y] = 'P';
		prog->glob.map[prog->p.x][prog->p.y] = '0';
		prog->p.x = prog->p.x + 1;
		prog->p.count_moves++;
	}
	else if (prog->glob.map[prog->p.x + 1][prog->p.y] == 'T')
		game_over(prog);
	else if (prog->glob.map[prog->p.x + 1][prog->p.y] == 'E' \
	&& prog->p.count_collect == 0)
		game_win(prog);
}

static void	move_right(t_program *prog)
{
	if (prog->glob.map[prog->p.x][prog->p.y + 1] == '0' \
	|| prog->glob.map[prog->p.x][prog->p.y + 1] == 'C')
	{
		if (prog->glob.map[prog->p.x][prog->p.y + 1] == 'C')
			prog->p.count_collect -= 1;
		prog->glob.map[prog->p.x][prog->p.y + 1] = 'P';
		prog->glob.map[prog->p.x][prog->p.y] = '0';
		prog->p.y = prog->p.y + 1;
		prog->p.count_moves++;
	}
	else if (prog->glob.map[prog->p.x][prog->p.y + 1] == 'T')
		game_over(prog);
	else if (prog->glob.map[prog->p.x][prog->p.y + 1] == 'E' \
	&& prog->p.count_collect == 0)
		game_win(prog);
}

static void	move_left(t_program *prog)
{
	if (prog->glob.map[prog->p.x][prog->p.y - 1] == '0' \
	|| prog->glob.map[prog->p.x][prog->p.y - 1] == 'C')
	{
		if (prog->glob.map[prog->p.x][prog->p.y - 1] == 'C')
			prog->p.count_collect -= 1;
		prog->glob.map[prog->p.x][prog->p.y - 1] = 'P';
		prog->glob.map[prog->p.x][prog->p.y] = '0';
		prog->p.y = prog->p.y - 1;
		prog->p.count_moves++;
	}
	else if (prog->glob.map[prog->p.x][prog->p.y - 1] == 'T')
		game_over(prog);
	else if (prog->glob.map[prog->p.x][prog->p.y - 1] == 'E' \
	&& prog->p.count_collect == 0)
		game_win(prog);
}

int	player_moves(int keycode, t_program *prog)
{
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0 \
	|| keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
	{
		if (keycode == 13 || keycode == 126)
			move_up(prog);
		if (keycode == 1 || keycode == 125)
			move_down(prog);
		if (keycode == 2 || keycode == 124)
			move_right(prog);
		if (keycode == 0 || keycode == 123)
			move_left(prog);
	}
	if (keycode == 53)
		ft_close(prog);
	return (0);
}
