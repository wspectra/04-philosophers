#include "philo.h"

void *print_id(void *philo)
{
	char *id;
	pthread_mutex_lock(&mutex);
	id = ft_itoa(((t_philo*)philo)->id);
//	printf("%d\n", ((t_philo*)philo)->id);
	write(1, id, ft_strlen(id));
	write(1, "\n", 1);
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

void init_philo(t_philo **philo, int nb)
{
	int i;

	i = 0;
	while(i < nb)
	{
		philo[i]->id = i + 1;
		i++;
	}
	philo[i] = NULL;
}

int main(int argc, char **argv)
{
	int philo_nb;
	int i;
	t_philo **philo;

	philo_nb = ft_atoi(argv[1]);
	philo = (t_philo**)malloc(sizeof(t_philo*) * (philo_nb + 1));
	i = 0;
	while (i < philo_nb)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		philo[i]->id = i + 1;
		i++;
	}
	philo[i] = NULL;
	pthread_mutex_init(&mutex, NULL);
	i = 0;
	while (i < philo_nb)
	{
		pthread_create(&(philo[i]->tr), NULL, print_id, (void *)(philo[i]));
		i++;
	}
	usleep(1000000);
}
