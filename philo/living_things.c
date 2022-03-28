/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:00:36 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 20:41:39 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void	check_dead(t_param *param)
{
	int			i;

	i = 0;
	usleep(param->time_to_die);
	while (param->stop != param->quantity_of_philo)
	{
		if (param->time_to_die < (ft_current_time() - param->philo[i].last_eat))
			dead_on_time(i, param);
		i++;
		if (i == param->quantity_of_philo)
			i = 0;
	}
}

void	is_eating(t_param *param, int i)
{
	unsigned long	time;

	if (param->stop != param->quantity_of_philo)
	{
		pthread_mutex_lock(&param->fork[param->philo[i].left_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(param->philo[i].index, time, TAKE_FORK);
		pthread_mutex_lock(&param->fork[param->philo[i].right_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(param->philo[i].index, time, TAKE_FORK);
		print_of_action(param->philo[i].index, time, EAT);
	}
	ft_usleep(param->time_to_eat);
	param->philo[i].last_eat = ft_current_time();
	pthread_mutex_unlock(&param->fork[param->philo[i].left_fork].fork_taken);
	pthread_mutex_unlock(&param->fork[param->philo[i].right_fork].fork_taken);
}

void	is_sleeping(t_param *param, int i)
{	
	unsigned long	time;

	time = ft_current_time() - param->start_time;
	if (param->stop != param->quantity_of_philo)
		print_of_action(param->philo[i].index, time, SLEEP);
	ft_usleep(param->time_to_sleep);
}

void	is_thinking(t_param *param, int i)
{	
	unsigned long	time;

	time = ft_current_time() - param->start_time;
	if (param->stop != param->quantity_of_philo)
		print_of_action(param->philo[i].index, time, THINK);
}

void	*is_living(void *param)
{
	t_param	*temp;
	int		i;
	int		j;

	temp = (t_param *)param;
	j = temp->index_philo;
	i = 0;
	while (i < temp->number_of_times || temp->number_of_times == -1)
	{
		is_eating(temp, j);
		is_sleeping(temp, j);
		is_thinking(temp, j);
		i++;
	}
	temp->stop++;
	return (0);
}
