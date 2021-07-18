#ifndef	PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo
{
	int id;
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	pthread_t tr;
}				t_philo;

typedef struct s_arg
{
	int nb;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	nb_eat;
}				t_arg;
pthread_mutex_t mutex;

int	ft_atoi(const char *str);
char	*ft_itoa(int n);
int	ft_strlen(const char *str);
int parsing(t_arg *arg, char **argv, int argc);


#endif