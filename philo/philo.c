/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:38:37 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 21:05:53 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

void	start(t_param *param)
{
	param->start_time = ft_current_time();
	while (param->index_philo < param->quantity_of_philo)
	{
		param->philo[param->index_philo].last_eat = param->start_time;
		pthread_create(&param->thread[param->index_philo], NULL,
			is_living, (void *)param);
		usleep(50);
		param->index_philo += 2;
	}
	param->index_philo = 1;
	while (param->index_philo < param->quantity_of_philo)
	{
		param->philo[param->index_philo].last_eat = param->start_time;
		pthread_create(&param->thread[param->index_philo], NULL,
			is_living, (void *)param);
		usleep(50);
		param->index_philo += 2;
	}
}

void	dead_on_time(int n, t_param *param)
{
	unsigned long	time;
	int				i;

	time = ft_current_time() - param->start_time;
	ft_usleep(10);
	print_of_action(param->philo[n].index, time, DIED);
	param->stop = param->quantity_of_philo;
	i = 0;
	while (i < param->quantity_of_philo)
	{
		pthread_detach(param->thread[i]);
		i++;
	}
}

int	the_end(t_param *param)
{
	free(param->thread);
	free(param->philo);
	free(param->fork);
	printf("\n-----------Voilà!-----------\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	param;

	if ((argc == 5) || (argc == 6))
	{
		if (set_param(argv, &param))
		{
			ft_putstr_fd(INIT_ERR, STDERR);
			return (1);
		}
		start(&param);
		check_dead(&param);
	}
	else
	{
		ft_putstr_fd(ERR, STDERR);
		return (1);
	}
	return (the_end(&param));
}
