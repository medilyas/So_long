/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:22:59 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:23:00 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	move_up(t_program *prog, int k)
{
	if (prog->glob.map[prog->t.x[k] - 1][prog->t.y[k]] == '0')
	{
		prog->glob.map[prog->t.x[k] - 1][prog->t.y[k]] = 'T';
		prog->glob.map[prog->t.x[k]][prog->t.y[k]] = '0';
		prog->t.x[k] = prog->t.x[k] - 1;
	}
	else if (prog->glob.map[prog->t.x[k] - 1][prog->t.y[k]] == 'P')
		game_over(prog);
}

static void	move_down(t_program *prog, int k)
{
	if (prog->glob.map[prog->t.x[k] + 1][prog->t.y[k]] == '0')
	{
		prog->glob.map[prog->t.x[k] + 1][prog->t.y[k]] = 'T';
		prog->glob.map[prog->t.x[k]][prog->t.y[k]] = '0';
		prog->t.x[k] = prog->t.x[k] + 1;
	}
	else if (prog->glob.map[prog->t.x[k] + 1][prog->t.y[k]] == 'P')
		game_over(prog);
}

static void	move_right(t_program *prog, int k)
{
	if (prog->glob.map[prog->t.x[k]][prog->t.y[k] + 1] == '0')
	{
		prog->glob.map[prog->t.x[k]][prog->t.y[k] + 1] = 'T';
		prog->glob.map[prog->t.x[k]][prog->t.y[k]] = '0';
		prog->t.y[k] = prog->t.y[k] + 1;
	}
	else if (prog->glob.map[prog->t.x[k]][prog->t.y[k] + 1] == 'P')
		game_over(prog);
}

static void	move_left(t_program *prog, int k)
{
	if (prog->glob.map[prog->t.x[k]][prog->t.y[k] - 1] == '0')
	{
		prog->glob.map[prog->t.x[k]][prog->t.y[k] - 1] = 'T';
		prog->glob.map[prog->t.x[k]][prog->t.y[k]] = '0';
		prog->t.y[k] = prog->t.y[k] - 1;
	}
	else if (prog->glob.map[prog->t.x[k]][prog->t.y[k] - 1] == 'P')
		game_over(prog);
}

void	enemy_moves(t_program *prog)
{
	int	enemy_mv;
	int	k;

	k = 0;
	while (k < prog->glob.t)
	{
		enemy_mv = rand() % 4;
		if (enemy_mv == 0)
			move_up(prog, k);
		if (enemy_mv == 1)
			move_down(prog, k);
		if (enemy_mv == 2)
			move_right(prog, k);
		if (enemy_mv == 3)
			move_left(prog, k);
		k++;
	}
}
