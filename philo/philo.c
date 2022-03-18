/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:38:37 by schung            #+#    #+#             */
/*   Updated: 2022/03/18 20:49:05 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

int	set_param(char **argv, t_param *param)
{
	ft_bzero(param, sizeof(param));
	param->number_of_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	param->thread = malloc(sizeof(pthread_t[param->number_of_philo]));
	if (!param->thread)
		return (1);
	if (argv[5])
		param->number_of_times = ft_atoi(argv[5]);
	return (0);
}

int main(int argc, char **argv)
{
	t_param param;

	if ((argc == 5) || (argc == 6))
	{
		if (set_param(argv, &param))
			return (1);
	}
	else
	{
		ft_putstr_fd(ERR, STDERR);
		return (1);
	}
	return (0);
}