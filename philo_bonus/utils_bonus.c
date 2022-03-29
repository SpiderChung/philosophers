/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:46:54 by schung            #+#    #+#             */
/*   Updated: 2022/03/29 21:05:59 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo_bonus.h"

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

int	init_sem(t_param *param)
{
	int	i;

	sem_unlink(SEM_DEAD);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_WRITE);
	i = 0;
	param->forks = ft_sem_open(SEM_FORK, param->quantity_of_philo);
	param->dead = ft_sem_open(SEM_DEAD, 0);
	param->writing = sem_open(SEM_WRITE, 1);
	if (param->forks < 0 || param->dead < 0 || param->writing < 0)
		return (1);
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
	if (argv[5])
		param->number_of_times = ft_atoi(argv[5]);
	else
		param->number_of_times = -1;
	if (param->quantity_of_philo < 2 || param->quantity_of_philo > 200
		|| param->time_to_die < 60 || param->time_to_eat < 60
		|| param->time_to_sleep < 60 || param->number_of_times < 0)
		return (1);
	param->philo = malloc(sizeof(t_philo[param->quantity_of_philo]));
	if (!param->philo)
	{
		free(param->thread);
		return (1);
	}
	return (init_sem(param) || init_philos(param));
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
