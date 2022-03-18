/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/03/18 20:23:17 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>
# include <pthread.h>
#include <sys/time.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERR "Error\n"

typedef struct s_param
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times;
}	t_param;

/*________philo.c__________*/

/*________libft.c__________*/
void	ft_bzero(void *src, size_t len);
int		ft_atoi(const char *str);

#endif