/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:57:07 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 21:09:17 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo_bonus.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_bzero(void *src, size_t len)
{
	char	*a;
	size_t	i;

	i = 0;
	a = src;
	while (len - i > 0)
	{
		a[i] = 0;
		i++;
	}
}

static int	ft_isspace(const char *src)
{
	int	i;

	i = 0;
	while ((src[i] == '\t') || (src[i] == '\n') || (src[i] == '\v')
		|| (src[i] == '\f') || src[i] == '\r' || src[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				k;
	unsigned long	n;

	k = 1;
	i = ft_isspace(str);
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			k = k * (-1);
		i++;
	}
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		if ((n > __LONG_MAX__) && (k > 0))
			return (-1);
		else if ((n > __LONG_MAX__) && (str[i] - '0' > 8) && (k < 0))
			return (0);
		else
			i++;
	}
	return ((int)n * k);
}
