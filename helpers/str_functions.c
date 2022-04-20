/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:22:54 by mkabissi          #+#    #+#             */
/*   Updated: 2022/02/21 23:24:49 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_free(char *res, char *buff, char *stat)
{
	if (res)
		free(res);
	if (buff)
		free(buff);
	if (stat)
		free(stat);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	lenght;

	lenght = 0;
	while (s != NULL && s[lenght])
		++lenght;
	return (lenght);
}

char	*ft_strdup(char *s1, int to_free)
{
	char	*p;
	int		len;
	size_t	i;

	i = -1;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == 0)
		put_error_msg(-1, NULL);
	while (s1[++i])
		p[i] = s1[i];
	p[i] = '\0';
	if (s1 && to_free)
		s1 = ft_free(0, 0, s1);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1lenght;
	size_t	s2lenght;
	size_t	i;
	char	*p;

	i = -1;
	if (!s1 || !s2)
		return (0);
	s1lenght = ft_strlen(s1);
	s2lenght = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (s1lenght + s2lenght + 1));
	if (!p)
		return (0);
	while (++i < s1lenght)
		p[i] = s1[i];
	p[s1lenght] = '\0';
	i = -1;
	while (++i < s2lenght)
		p[s1lenght + i] = s2 [i];
	p[s1lenght + i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (0);
	p = (char *)malloc(sizeof(char) * len + 1);
	if (!p)
		put_error_msg(-1, NULL);
	i = -1;
	while (++i < len && s[i])
		p[i] = s[start + i];
	p[i] = '\0';
	return (p);
}
