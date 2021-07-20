#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	check_argumets(char **argv, int argc)
{
	int	i;
	int	m;

	i = 1;
	while (i < argc)
	{
		m = 0;
		while (argv[i][m] != '\0')
		{
			if (ft_isdigit(argv[i][m]) == 0)
			{
				write (1, "Invalid argument\n", 17);
				return (1);
			}
			m++;
		}
		i++;
	}
	return (0);
}

int	parsing(t_arg *arg, char **argv, int argc)
{
	if (argc != 5 && argc != 6)
	{
		write (1, "Wrong number of arguments\n", 26);
		return (1);
	}
	if (check_argumets(argv, argc) == 1)
		return (1);
	arg->nb = ft_atoi(argv[1]);
	arg->t_die = ft_atoi(argv[2]);
	arg->t_eat = ft_atoi(argv[3]);
	arg->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		arg->nb_eat = ft_atoi(argv[5]);
	else
		arg->nb_eat = -1;
	return (0);
}
