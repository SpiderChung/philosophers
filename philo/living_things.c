/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   living_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 21:00:36 by schung            #+#    #+#             */
/*   Updated: 2022/03/26 21:03:12 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void	is_eating(t_param *param, int i)
{
	unsigned long	time;

	time = ft_current_time();
	if (param->times != param->number_of_times)
	{
		pthread_mutex_lock(&param->fork[param->philo[i].left_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(i, time, TAKE_FORK);
		pthread_mutex_lock(&param->fork[param->philo[i].right_fork].fork_taken);
		time = ft_current_time() - param->start_time;
		print_of_action(i, time, TAKE_FORK);
		print_of_action(i, time, EAT);
	}
	ft_usleep(time);
	param->philo[i].last_eat = ft_current_time();
	pthread_mutex_unlock(&param->fork[param->philo[i].left_fork].fork_taken);
	pthread_mutex_unlock(&param->fork[param->philo[i].right_fork].fork_taken);
}

void	is_sleeping(t_param *param, int i)
{	
	unsigned long	time;
	
	time = ft_current_time() - param->start_time;

	return (0);
}

void	is_thinking(t_param *param, int i)
{	
	unsigned long	time;
	
	time = ft_current_time() - param->start_time;
	return (0);
}

void	*is_living(void *param)
{
	t_param	*temp;
	int i;

	temp = (t_param *)param;
	i = 0;
	while (i < temp->number_of_times || temp->number_of_times == -1)
	{
		is_eating(temp, temp->index_philo);
		is_sleeping(temp, temp->index_philo);
		is_thinking(temp, temp->index_philo);
		i++;
	}
	temp->times++;
	return (0);
}
