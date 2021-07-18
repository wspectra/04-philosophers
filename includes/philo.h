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

typedef struct s_arg
{
	int	nb;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_eat;
}				t_arg;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		tr;

}				t_philo;
//utils
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_strlen(const char *str);
//parsing
int				parsing(t_arg *arg, char **argv, int argc);
//init
pthread_mutex_t	*forks_init(t_arg arg);
t_philo			*philo_init(t_arg arg, pthread_mutex_t *forks);

#endif
