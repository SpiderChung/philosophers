/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/03/28 21:23:51 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERR "Incorrect arguments\n"
# define INIT_ERR "Initialization error\n"
# define TAKE_FORK 0
# define THINK 1
# define SLEEP 2
# define EAT 3
# define DIED 4

typedef struct s_param
{
	int			number_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times;
	sem_t		sem;
}	t_param;

/*________philo_bonus.c__________*/

/*________libft.c__________*/
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *src, size_t len);
int		ft_atoi(const char *str);

#endif