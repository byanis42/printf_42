#include "../include/ft_printf.h"

int		main()
{
	// printf("test numero 1 : %*s\n", 2, "caca\n");
	int number=5;
	//char jonysins[] = "plombier";


    //printf("---%5d----\n", number);
	//ft_printf("---%5d----\n", number); 
	

	//printf("expected :%-.014d\n", 1242);
	ft_printf("\n%u", 42424242);
	printf("\n%u\n\n\n", 42424242);

	system("leaks a.out");
	//printf("expected :%d", 2222);
//	printf("%s\n", "c'est le s encule");

	return (0);
}

/* ----------------------------------------------------------------



			A l'aide germain
					SOS


                                          (help)
-------------------------------------------------------------------
	Cas speciaux : 
	printf("%.014i\n", 15);  .0 pose problem
*/