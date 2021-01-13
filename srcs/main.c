#include "../include/ft_printf.h"

int		main()
{
	// printf("test numero 1 : %*s\n", 2, "caca\n");
	int number=5;

    //printf("---%5d----\n", number);
	//ft_printf("---%5d----\n", number); 
	

	ft_printf("%-010c\n", 'l');
//	printf("%s\n", "c'est le s encule");

	return (0);
}

/*
	Cas speciaux : 
	printf("%.014i\n", 15);  .0 pose problem
*/

