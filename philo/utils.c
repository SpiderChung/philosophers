/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:00:30 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 20:38:44 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void	ft_usleep(unsigned long time)
{
	unsigned long	t;

	t = ft_current_time();
	while (ft_current_time() - t < time)
		usleep(10);
}

long	ft_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

int	init_forks(t_param *param)
{
	int	i;

	param->fork = malloc(sizeof(t_fork[param->quantity_of_philo]));
	if (!param->fork)
	{
		free(param->thread);
		free(param->philo);
		return (1);
	}
	i = 0;
	while (i < param->quantity_of_philo)
	{
		param->philo[i].index = i + 1;
		param->philo[i].left_fork = i;
		if (i - 1 < 0)
			param->philo[i].right_fork = param->quantity_of_philo - 1;
		else
			param->philo[i].right_fork = i - 1;
		param->fork[i].index = i + 1;
		pthread_mutex_init(&param->fork[i].fork_taken, NULL);
		i++;
	}
	return (0);
}

int	set_param(char **argv, t_param *param)
{
	ft_bzero(param, sizeof(param));
	param->quantity_of_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->index_philo = 0;
	param->thread = malloc(sizeof(pthread_t[param->quantity_of_philo]));
	if (!param->thread)
		return (1);
	if (argv[5])
		param->number_of_times = ft_atoi(argv[5]);
	else
		param->number_of_times = -1;
	param->philo = malloc(sizeof(t_philo[param->quantity_of_philo]));
	if (!param->philo)
	{
		free(param->thread);
		return (1);
	}
	return (init_forks(param));
}

void	print_of_action(int index, unsigned long time, int option)
{
	if (option == TAKE_FORK)
		printf("%lu\t %d has taken a fork\n", time, index);
	else if (option == EAT)
		printf("%lu\t %d is eating\n", time, index);
	else if (option == SLEEP)
		printf("%lu\t %d is sleeping\n", time, index);
	else if (option == THINK)
		printf("%lu\t %d is thinking\n", time, index);
	else if (option == DIED)
		printf("%lu\t %d died\n", time, index);
}
