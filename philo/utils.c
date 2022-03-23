/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:00:30 by schung            #+#    #+#             */
/*   Updated: 2022/03/23 19:03:45 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

long	ft_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	init_philos(t_param *param)
{
	param->fork = malloc(sizeof(param->fork[param->quantity_of_philo]));
	if (!param->fork)
	{
		free(param->thread);
		return (1);
	}
	param->philo = malloc(sizeof(param->philo[param->quantity_of_philo]));
	if (!param->philo)
	{
		free(param->thread);
		free(param->fork);
		return (1);
	}
	return (0);
}


void	print_of_action(t_param *param, unsigned long time, int option)
{
	if (option == TAKE_FORK)
		printf("%lu\t %d has taken a fork\n", time, param->philo[n].index);
	else if (option == EAT)
		printf("%lu\t %d is eating\n", time, p->philo[n].index);
	else if (option == SLEEP)
		printf("%lu\t %d is sleeping\n", time, p->philo[n].index);
	else if (option == THINK)
		printf("%lu\t %d is think\n", time, p->philo[n].index);
}