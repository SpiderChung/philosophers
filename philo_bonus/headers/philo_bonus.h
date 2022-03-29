/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/03/29 20:48:37 by schung           ###   ########.fr       */
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
# include <signal.h>

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
# define SEM_WRITE "SemWrite"
# define SEM_FORK "SemFork" 
# define SEM_DEAD "SemDeath"




typedef struct s_philo
{
	int		index;
	long	last_eat;
	int		left_fork;
	int		right_fork;
}	t_philo;

typedef struct s_param
{
	int				quantity_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times;
	int				number_of_times;
	int				index_philo;
	int				stop;
	unsigned long	start_time;
	t_philo			*philo;
	sem_t			*forks;
	sem_t			*writing;
	sem_t			*dead;
}	t_param;

/*________philo_bonus.c__________*/

/*________utils_bonus.c__________*/

/*________living_things_bonus.c__________*/
void	is_thinking(t_param *param, int i);
void	is_sleeping(t_param *param, int i);
void	is_eating(t_param *param, int i);
void	*is_living(void *param);
void	check_dead(t_param *param);

/*________libft_bonus.c__________*/
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *src, size_t len);
int		ft_atoi(const char *str);

#endif