/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schung <schung@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:44:38 by schung            #+#    #+#             */
/*   Updated: 2022/03/27 20:46:20 by schung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define ERR "Incorrect arguments\n"
# define TAKE_FORK 0
# define THINK 1
# define SLEEP 2
# define EAT 3
# define DIED 4

typedef struct s_philo
{
	int		index;
	int		left_fork;
	int		right_fork;
	long	last_eat;
}	t_philo;

typedef struct s_fork
{
	int				index;
	pthread_mutex_t	fork_taken;

}	t_fork;

typedef struct s_param
{
	int				quantity_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times;
	int				number_of_times;
	int				index_philo;
	int				stop_life;
	unsigned long	start_time;
	pthread_t		*thread;
	t_philo			*philo;
	t_fork			*fork;
}	t_param;

/*________philo.c__________*/
void	start(t_param *param);
int		the_end(t_param *param);
void	dead_on_time(int n, t_param *param);

/*________libft.c__________*/
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_bzero(void *src, size_t len);
int		ft_atoi(const char *str);

/*________living_things.c__________*/
void	is_thinking(t_param *param, int i);
void	is_sleeping(t_param *param, int i);
void	is_eating(t_param *param, int i);
void	*is_living(void *param);
void	check_dead(t_param *param);

/*________utils.c__________*/
void	ft_usleep(unsigned long time);
long	ft_current_time(void);
void	print_of_action(int index, unsigned long time, int option);
void	init_forks(t_param *param);
int		set_param(char **argv, t_param *param);

#endif