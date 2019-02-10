#include <libc.h>

#define SEC 1000000

int	main(void)
{
	int i = 0;

	while (1)
	{
		write(1, "\7", 1);
		usleep(SEC);
		i = 4;
		while (i-- > 0)
		{
			write(1, "\7", 1);
			usleep(SEC / 8);
		}
		usleep(SEC / 6);
		write(1, "\7", 1);
		usleep(SEC / 3);
		write(1, "\7", 1);
		usleep(SEC * 5);
	}
}
