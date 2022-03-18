/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:38:37 by schung            #+#    #+#             */
/*   Updated: 2022/03/18 20:20:42 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo.h"

int	set_param(char **argv, t_param *param)
{
	ft_bzero(param, sizeof(param));
	param->number_of_philosophers = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]) * 1000;
	param->time_to_eat = ft_atoi(argv[3]) * 1000;
	param->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		param->number_of_times = ft_atoi(argv[5]);
	return (0);
}


int main(int argc, char **argv)
{
	t_param param;

	if ((argc == 5) || (argc == 6))
	{
		set_param(argv, &param);
	}
}