/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:12 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:23:34 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	define_images1(t_program *prog)
{
	char	*path;
	int		dump;
	int		i;

	prog->img.empty = mlx_xpm_file_to_image(prog->mlx, "assets/background.xpm",
			&dump, &dump);
	path = ft_strdup("assets/key0.xpm", 0);
	i = 0;
	while (++i < 9)
	{
		path[10] = '0' + i;
		prog->img.collect[i - 1] = mlx_xpm_file_to_image(prog->mlx, path,
				&dump, &dump);
	}
	free(path);
	path = ft_strdup("assets/thief0.xpm", 0);
	i = 0;
	while (++i < 3)
	{
		path[12] = '0' + i;
		prog->img.player[i - 1] = mlx_xpm_file_to_image(prog->mlx, path,
				&dump, &dump);
	}
	free(path);
}

static void	define_images2(t_program *prog)
{
	char	*path;
	int		dump;
	int		i;

	prog->img.wall = mlx_xpm_file_to_image(prog->mlx, "assets/wall1.xpm",
			&dump, &dump);
	path = ft_strdup("assets/police0.xpm", 0);
	i = 0;
	while (++i < 3)
	{
		path[13] = '0' + i;
		prog->img.trap[i - 1] = mlx_xpm_file_to_image(prog->mlx, path,
				&dump, &dump);
	}
	free(path);
	path = ft_strdup("assets/exit0.xpm", 0);
	i = 0;
	while (++i < 3)
	{
		path[11] = '0' + i;
		prog->img.exit[i - 1] = mlx_xpm_file_to_image(prog->mlx, path,
				&dump, &dump);
	}
	free(path);
}

void	define_images(t_program *prog)
{
	define_images1(prog);
	define_images2(prog);
}
