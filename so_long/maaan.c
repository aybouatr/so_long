#include <stdio.h>


size_t	ft_strlen(const char *str)
{
	size_t	e;

	e = 0;
	while (str[e])
		e++;
	return (e);
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while ((i < len) && (s1[i]) && (s1[i] == s2[i]))
		i++;
	if (i == len)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int main()
{
    char *map = "g545454545454g.be";

    printf("%d\n",ft_strncmp(&map[ft_strlen(map) - 4],".ber",4));
}