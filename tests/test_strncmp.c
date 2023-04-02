int	ft_isascii(int ascii)
{
	if (ascii >= 0 && ascii <= 127)
	{
		return (1);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (!ft_isascii(s1[i]) || !ft_isascii(s2[i]))
			i++;
		if ((s1[i] > s2[i]) || !s2[i])
			return (1);
		if ((s1[i] < s2[i]) || !s1[i])
			return (-1);
		i++;
	}
	return (0);
}
#include <stdio.h>
int main(void)
{
    int i = 4;

    printf("%d\n", ft_strncmp("PATH=/Users/rhamza/.brew/bin:/usr/", "PATH", i));
    return (0);
}