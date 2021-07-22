#include "../includes/philo.h"

static char	*count_sp_signs(const char *str, int *sign, int *count)
{
	if (str == NULL)
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\r'
		   || *str == '\v' || *str == '\n' || *str == '\f'
		   || *str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			(*sign)++;
			if (!(*(str + 1) >= '0' && *(str + 1) <= '9'))
				return (NULL);
		}
		if (*str == '+')
		{
			(*count)++;
		}
		str++;
	}
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	long long int		res;
	int					sign;
	int					count;
	int					cdigits;

	res = 0;
	sign = 0;
	count = 0;
	cdigits = -1;
	str = count_sp_signs(str, &sign, &count);
	if (str == NULL)
		return (0);
	if (count + sign > 1)
		return (0);
	while ((*str >= '0' && *str <= '9') && (++cdigits >= 0))
		res = res * 10 + (*str++ - '0');
	if (cdigits > 19 && sign == 0)
		return (-1);
	if (cdigits > 19 && sign == 1)
		return (0);
	if (sign == 1)
		return (-res);
	return (res);
}

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

t_arg	*get_struct(void)
{
	static t_arg	arg;

	return (&arg);
}

void	accurate_usleep(uint64_t time)
{
	uint64_t	res;

	res = get_time() + (uint64_t)time;
	while (res > get_time())
		usleep(1);
}
