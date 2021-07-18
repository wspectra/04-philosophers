#include "../includes/philo.h"

void *print_id(void *philo)
{
	char *id;
	pthread_mutex_lock((((t_philo *) philo)->left));
	id = ft_itoa(((t_philo *) philo)->id);
//	printf("%d\n", ((t_philo*)philo)->id);
	write(1, id, ft_strlen(id));
//	usleep(300000);
	write(1, "\n", 1);
	pthread_mutex_unlock((((t_philo *) philo)->left));
	return (NULL);
}

//void *philo(void *philo)
//{
//	int id;
//
//	id = ((t_philo *) philo)->id;
//
//}
void init_philo(t_philo **philo, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		philo[i]->id = i + 1;
		i++;
	}
	philo[i] = NULL;
}

int main(int argc, char **argv)
{
	t_arg arg;
	int i;
	t_philo *philo;
	pthread_mutex_t *forks;

	if (parsing(&arg, argv, argc) == 1)
		return (-1);
	forks = forks_init(arg);
	if (!forks)
	{
		write(1, "Memory allocation fail\n", 23);
		return (-1);
	}
	philo = philo_init(arg, forks);
	if (!philo)
	{
		write(1, "Memory allocation fail\n", 23);
		return (-1);
	}



	i = 0;
	while (i < arg.nb)
	{
		if (i % 2 == 0)
			usleep(10);
		pthread_create(&(philo[i].tr), NULL, print_id, (void *) (&philo[i]));
		i++;
	}
	i = 0;
	while (i < arg.nb)
	{
		pthread_join(philo[i].tr, 0);
		i++;
	}
	return 0;
}
