/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 20:22:44 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 21:12:35 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/philo_bonus.h"

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
