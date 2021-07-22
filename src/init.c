#include "../includes/philo.h"

pthread_mutex_t	*mutex_init(t_arg arg)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t) * arg.nb);
	if (!forks)
	{
		return (NULL);
	}
	i = 0;
	while (i < arg.nb)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
	return (forks);
}

t_philo	*philo_init(t_arg arg, pthread_mutex_t *forks)
{
	t_philo			*philo;
	int				i;
	pthread_mutex_t	*tmp;

	philo = (t_philo *) malloc(sizeof(t_philo) * (arg.nb));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < arg.nb)
	{
		philo[i].id = i;
		if (philo[i].id % 2 == 0)
		{
			philo[i].left = philo[i].id;
			philo[i].right = (philo[i].id + 1) % arg.nb;
		}
		else
		{
			philo[i].right = philo[i].id;
			philo[i].left = (philo[i].id + 1) % arg.nb;
		}
		i++;
	}
	philo->is_eating = 0;
	return (philo);
}

void	threads_init(t_philo *philo)
{
	int	i;

	i = 0;
	get_struct()->t_start = get_time();
	while (i < get_struct()->nb)
	{
		pthread_create(&(philo[0].tr), NULL, philosophers,
			(void *)(&philo[i]));
		philo[i].t_eat = get_time();
		i++;
		accurate_usleep(1);
	}
}
