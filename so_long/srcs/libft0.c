#include "../includes/so_long.h"


char	*ft_strdup(const char *s1)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	e;

	e = 0;
	while (str[e])
		e++;
	return (e);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}