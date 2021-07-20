/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 17:31:23 by dbaron            #+#    #+#             */
/*   Updated: 2021/07/16 17:31:26 by dbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int 			left;
	int 			right;
	pthread_t		tr;
	uint64_t		t_eat;
	int 			is_eating;
	int				must_eat;
	pthread_mutex_t eat;
}				t_philo;

typedef struct s_arg
{
	int	nb;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_eat;
	uint64_t	t_start;
	pthread_mutex_t *forks;
	pthread_mutex_t	print;
	pthread_mutex_t eat;
	int time;
}				t_arg;


//utils
int				ft_atoi(const char *str);
uint64_t		get_time(void);
void			accurate_usleep(int tine);
//parsing
int				parsing(t_arg *arg, char **argv, int argc);
//init
pthread_mutex_t	*forks_init(t_arg arg);
t_philo			*philo_init(t_arg arg, pthread_mutex_t *forks);

#endif
