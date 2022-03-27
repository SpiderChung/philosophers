/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:00:36 by schung            #+#    #+#             */
/*   Updated: 2022/03/27 20:57:55 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void	check_dead(t_param *param)
{
	int			i;

	i = 0;
	usleep(param->time_to_die);
	while (param->stop_life != param->quantity_of_philo)
	{
		if (param->time_to_die < (ft_current_time() - param->philo[i].last_eat)
			* 1000)
			dead_on_time(i, param);
		i++;
		if (i == param->quantity_of_philo)
			i = 0;
	}
}

void	is_eating(t_param *param, int i)
{
	unsigned long	time;

	time = ft_current_time();
	if (param->stop_life != param->quantity_of_philo)
	{
		pthread_mutex_lock(&param->fork[param->philo[i].left_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(param->philo[i].index, time, TAKE_FORK);
		pthread_mutex_lock(&param->fork[param->philo[i].right_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(param->philo[i].index, time, TAKE_FORK);
		print_of_action(param->philo[i].index, time, EAT);
	}
	usleep(param->time_to_eat * 1000);
	param->philo[i].last_eat = ft_current_time();
	pthread_mutex_unlock(&param->fork[param->philo[i].left_fork].fork_taken);
	pthread_mutex_unlock(&param->fork[param->philo[i].right_fork].fork_taken);
}

void	is_sleeping(t_param *param, int i)
{	
	unsigned long	time;

	time = ft_current_time() - param->start_time;
	if (param->stop_life != param->quantity_of_philo)
		print_of_action(param->philo[i].index, time, SLEEP);
	usleep(param->time_to_sleep * 1000);
}

void	is_thinking(t_param *param, int i)
{	
	unsigned long	time;

	time = ft_current_time() - param->start_time;
	if (param->stop_life != param->quantity_of_philo)
		print_of_action(param->philo[i].index, time, THINK);
}

void	*is_living(void *param)
{
	t_param	*temp;
	int		i;

	temp = (t_param *)param;
	i = 0;
	while (i < temp->number_of_times || temp->number_of_times == -1)
	{
		is_eating(temp, temp->index_philo);
		is_sleeping(temp, temp->index_philo);
		is_thinking(temp, temp->index_philo);
		i++;
	}
	temp->stop_life++;
	return (0);
}
