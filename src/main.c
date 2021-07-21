#include "../includes/philo.h"

t_arg *get_struct(void)
{
	static t_arg arg;
	return (&arg);
}

void print_status(char status, int id, int fork)
{
	pthread_mutex_lock(&(get_struct()->print));
	///проверить правильность вывода времени
	if (status == 'l')
		printf("%llu %d has taken fork #%d\n", get_time() - get_struct()
				->t_start, id + 1, fork);
	if (status == 'r')
		printf("%llu %d has taken fork #%d\n", get_time() - get_struct()
				->t_start, id + 1, fork);
	if (status == 'e')
		printf("%llu %d is eating\n", get_time() - get_struct()->t_start,
			   id + 1);
	if (status == 's')
		printf("%llu %d is sleeping\n", get_time() - get_struct()->t_start,
			   id + 1);
	if (status == 't')
		printf("%llu %d is thinking\n", get_time() - get_struct()->t_start,
			   id + 1);
	if (status == 'd')
		printf("%llu %d died\n", get_time() - get_struct()->t_start,
			   id + 1);
	if (status == 'u')
		printf("%llu %d has dropped a fork\n", get_time() - get_struct()->t_start, id);
	if (status == 'A')
		printf("ALL EAT %d TIMES", get_struct()->nb_eat);
	if (status != 'd' && status != 'A')
		pthread_mutex_unlock(&(get_struct()->print));
}

void *philosophers(void *strct)
{
	t_philo *philo;

	philo = (t_philo*)strct;
	philo->t_eat = get_time();
	while (1)
	{
		pthread_mutex_lock(&(get_struct()->forks[philo->right]));
		print_status('r', philo->id, philo->right);

		pthread_mutex_lock(&(get_struct()->forks[philo->left]));
		print_status('l', philo->id, philo->left);


		philo->t_eat = get_time();
		print_status('e', philo->id, 0);
		accurate_usleep(get_struct()->t_eat);
//		usleep(get_struct()->t_eat * 1000);
		philo->is_eating++;



		pthread_mutex_unlock(&(get_struct()->forks[philo->left]));
		pthread_mutex_unlock(&(get_struct()->forks[philo->right]));


		print_status('s', philo->id, 0);
		accurate_usleep(get_struct()->t_sleep);
//		usleep(get_struct()->t_sleep * 1000);
		print_status('t', philo->id, 0);

	}
	return (NULL);
}


int main(int argc, char **argv)
{

	int i;
	t_philo *philo;
	pthread_t tr_eat;
	int total;

	if (parsing(get_struct(), argv, argc) == 1)
		return (-1);
	get_struct()->forks = forks_init(*get_struct());
	if (!get_struct()->forks)
	{
		write(1, "Memory allocation fail\n", 23);
		return (-1);
	}
	pthread_mutex_init(&(get_struct()->print), NULL);
	pthread_mutex_init(&(get_struct()->eat), NULL);
	philo = philo_init(*get_struct(), get_struct()->forks);
	if (!philo)
	{
		write(1, "Memory allocation fail\n", 23);
		return (-1);
	}

	i = 0;
	get_struct()->t_start = get_time();

	while (i < get_struct()->nb)
	{
		pthread_create(&(philo[0].tr), NULL, philosophers,(void *) (&philo[i]));
		i++;
//		usleep(1000);
		accurate_usleep(100);
	}

	while (1)
	{
		i = 0;
		total = 0;
		while (i <= get_struct()->nb - 1)
		{
			if (get_struct()->t_die < get_time() - philo[i].t_eat)
			{
				print_status('d', philo[i].id, 0);
				return (0);
			}
			if (get_struct()->nb_eat > 0
				&& philo[i].is_eating >= get_struct()->nb_eat)
				total++;
			i++;
		}
		if (get_struct()->nb_eat > 0 && total == get_struct()->nb - 1)
		{
			print_status('A', philo[i].id, 0);
			return (0);
		}
		usleep(100);
	}
	i = 0;
	while (i < get_struct()->nb)
	{
		pthread_join(philo[i].tr, 0);
		i++;
	}
	return 0;
}
