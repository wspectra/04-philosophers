#ifndef	PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct s_philo
{
	int id;
	pthread_t tr;
}				t_philo;

pthread_mutex_t mutex;

int	ft_atoi(const char *str);
char	*ft_itoa(int n);
int	ft_strlen(const char *str);

#endif