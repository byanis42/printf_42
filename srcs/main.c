#include "../include/ft_printf.h"
# define YEAR 2021

int		main()
{
	// printf("test numero 1 : %*s\n", 2, "caca\n");
	int number=5;
	int ret;
	ret = 99999;
	//char jonysins[] = "plombier";


    //printf("---%5d----\n", number);
	//ft_printf("---%5d----\n", number); 
	

	//printf("expected :%-.014d\n", 1242);
	//ft_printf("\n%12u", 42424242);
	ret = ft_printf("%2.p\n", NULL);
	printf("%.03s\n", "");
	printf("ft_printf ret : %d\n", ret);
//	printf("%d\n", printf("%-5.i\n", 42));
	//printf("\n%u\n\n\n", 42424242);

	//system("leaks a.out");
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