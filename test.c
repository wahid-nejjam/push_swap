
#include <libc.h>
void	ft_bite(void)
{
	char frr[200];

	bzero(frr, 200);
}

void	ft_bite2(void)
{
	char 	*frr;

	frr = malloc(sizeof (char) * 200);
	bzero(frr, 200);
}

int	main()
{
	size_t i;

	i = 0;
	while (i++ < 100000000)
		ft_bite2();
}