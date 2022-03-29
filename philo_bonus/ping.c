#include <stdio.h>

int main()
{
	int	i = 0;
	int	p;

	while (i < 8)
	{
		p = (i + 1) % 8; 
		printf("___%d___\n", p);
		i++;
	}
	
	return (0);
}