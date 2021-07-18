#include "../includes/philo.h"

pthread_mutex_t	*forks_init(t_arg arg)
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
	t_philo	*philo;
	int		i;

	philo = (t_philo *) malloc(sizeof(t_philo) * (arg.nb));
	if (!philo)
		return (NULL);
	i = 0;
	while (i < arg.nb)
	{
		philo[i].id = i + 1;
		if (i == arg.nb - 1)
			philo[i].left = forks;
		else
			philo[i].left = forks + i;
		if (i - 1 == -1)
			philo[i].right = forks + (arg.nb - 1);
		else
			philo[i].right = forks + (i - 1);
		i++;
	}
	return (philo);
}
