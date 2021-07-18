#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	int					i;

	sign = 0;
	res = 0;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
					  str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	sign = str[i] == '-' ? -1 : 1;
	i = str[i] == '+' ? i + 1 : i;
	i = sign == -1 ? i + 1 : i;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - 48;
	if (res > 9223372036854775807)
		return (sign == 1 ? -1 : 0);
	return (res * sign);
}

int		ft_sizeint(int n)
{
	int size;

	if (n < 0)
	{
		size = 1;
		n = n * (-1);
	}
	else
		size = 0;
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size + 1);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char*)dst;
	ptr2 = (unsigned char*)src;
	if (!n || dst == src)
		return (dst);
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		a;
	char	*s2;

	a = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * a + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, (a + 1));
	return (s2);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	else
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_sizeint(n) + 1))))
			return (NULL);
		i = ft_sizeint(n) - 1;
		str[ft_sizeint(n)] = '\0';
		if (n < 0)
		{
			str[0] = '-';
			n = n * (-1);
		}
		while (n > 9)
		{
			str[i] = n % 10 + 48;
			n = n / 10;
			i--;
		}
		str[i] = n + 48;
		return (str);
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}