#include "../includes/philo.h"

void	all_free(pthread_mutex_t *forks, pthread_mutex_t *eat, t_philo *philo)
{
	if (forks)
		free(forks);
	if (eat)
		free(eat);
	if (philo)
		free(philo);
}

void	*philosophers(void *strct)
{
	t_philo	*philo;

	philo = (t_philo *)strct;
	while (1)
	{
		pthread_mutex_lock(&(get_struct()->forks[philo->right]));
		print_status('r', philo->id + 1, philo->right);
		pthread_mutex_lock(&(get_struct()->forks[philo->left]));
		print_status('l', philo->id + 1, philo->left);
		pthread_mutex_lock(&(get_struct()->eat[philo->id]));
		philo->t_eat = get_time();
		pthread_mutex_unlock(&(get_struct()->eat[philo->id]));
		print_status('e', philo->id + 1, 0);
		accurate_usleep(get_struct()->t_eat);
		philo->is_eating++;
		pthread_mutex_unlock(&(get_struct()->forks[philo->left]));
		pthread_mutex_unlock(&(get_struct()->forks[philo->right]));
		print_status('s', philo->id + 1, 0);
		accurate_usleep(get_struct()->t_sleep);
		print_status('t', philo->id + 1, 0);
	}
	return (NULL);
}

int	check_status(t_philo *philo, int i, int total)
{
	while (1)
	{
		i = 0;
		total = 0;
		while (i <= get_struct()->nb - 1)
		{
			pthread_mutex_lock(&(get_struct()->eat[philo[i].id]));
			if (get_struct()->t_die < get_time() - philo[i].t_eat)
			{
				print_status('d', philo[i].id + 1, 0);
				return (0);
			}
			pthread_mutex_unlock(&(get_struct()->eat[philo[i].id]));
			if (get_struct()->nb_eat > 0
				&& philo[i].is_eating >= get_struct()->nb_eat)
				total++;
			i++;
		}
		if (get_struct()->nb_eat > 0 && total == get_struct()->nb - 1)
		{
			print_status('A', philo[i].id + 1, 0);
			return (0);
		}
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (parsing(get_struct(), argv, argc) == 1)
		return (-1);
	get_struct()->forks = mutex_init(*get_struct());
	if (!get_struct()->forks)
		return (print_error("Memory allocation fail\n"));
	get_struct()->eat = mutex_init(*get_struct());
	if (!get_struct()->eat)
	{
		all_free(get_struct()->forks, NULL, NULL);
		return (print_error("Memory allocation fail\n"));
	}
	pthread_mutex_init(&(get_struct()->print), NULL);
	philo = philo_init(*get_struct(), get_struct()->forks);
	if (!philo)
	{
		all_free(get_struct()->forks, get_struct()->eat, NULL);
		return (print_error("Memory allocation fail\n"));
	}
	threads_init(philo);
	check_status(philo, 0, 0);
	all_free(get_struct()->forks, get_struct()->eat, philo);
	return (0);
}
