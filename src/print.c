#include "../includes/philo.h"

void	print_status(char status, int id, int fork)
{
	pthread_mutex_lock(&(get_struct()->print));
	if (status == 'l')
		printf("%llu %d has taken fork #%d\n", get_time()
			- get_struct()->t_start, id, fork + 1);
	if (status == 'r')
		printf("%llu %d has taken fork #%d\n", get_time()
			- get_struct()->t_start, id, fork + 1);
	if (status == 'e')
		printf("%llu %d is eating\n", get_time() - get_struct()->t_start, id);
	if (status == 's')
		printf("%llu %d is sleeping\n", get_time() - get_struct()->t_start, id);
	if (status == 't')
		printf("%llu %d is thinking\n", get_time() - get_struct()->t_start, id);
	if (status == 'd')
		printf("%llu %d died\n", get_time() - get_struct()->t_start, id);
	if (status == 'A')
		printf("ALL EAT %d TIMES", get_struct()->nb_eat);
	if (status != 'd' && status != 'A')
		pthread_mutex_unlock(&(get_struct()->print));
}

int	print_error(char *str)
{
	printf("%s", str);
	return (-1);
}
