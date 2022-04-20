/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:22:42 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:22:43 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	strcounter(char const *s, char c)
{
	int	i;
	int	counter;
	int	size;

	i = 0;
	counter = 0;
	while (s[i])
	{
		size = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			size = 1;
			i++;
		}
		counter += size;
	}
	return (counter);
}

static int	count_strings(char const *s, char c, int *k)
{
	int	slenght;

	slenght = 0;
	while (s[*k] == c)
		++*k;
	while (s[*k] != c && s[*k])
	{
		slenght++;
		++*k;
	}
	return (slenght);
}

static char	**ft_freearray(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**fillarray(char **res, char const *s, char c, t_program *prog)
{
	int	i;
	int	k;
	int	slenght;
	int	previous_lenght;

	i = 0;
	k = 0;
	previous_lenght = 0;
	while (i < prog->glob.map_d.line)
	{
		slenght = count_strings(s, c, &k);
		if (previous_lenght == 0)
			previous_lenght = slenght;
		else if (previous_lenght != slenght)
			put_error_msg(0, prog);
		if (slenght != 0)
			res[i] = ft_substr(s, k - slenght, slenght);
		if (res[i] == 0)
			return (ft_freearray(res));
		i++;
	}
	prog->glob.map_d.column = slenght;
	res[i] = 0;
	return (res);
}

char	**ft_split(char *s, char c, t_program *prog)
{
	char	**res;

	if (!s)
		return (0);
	prog->glob.map_d.line = strcounter(s, c);
	res = (char **)malloc(sizeof(res) * (prog->glob.map_d.line + 1));
	if (res == 0)
		put_error_msg(-1, prog);
	res = fillarray(res, s, c, prog);
	return (res);
}
