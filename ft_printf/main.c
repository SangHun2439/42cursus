#include "ft_printf.h"
#include <locale.h>
int	main()
{
	int test = 193;
	ft_putwchar_fd(test, 1);
//	setlocale(LC_ALL, "");
//	printf("%d\n", ft_printf("%.2sft_printf test", "HELLO WORLD"));
//	printf("%d\n", printf("%.3lsprintf test", L"HELLO WORLD"));	
}
