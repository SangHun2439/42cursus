#include "ft_printf.h"
#include <locale.h>
int	main()
{
//	int test = 193;
//	ft_putwchar_fd(test, 1);
	wchar_t	*str;
	wchar_t *str2;
	int		test;

	str = 0;
	str2 = L"english한글";
	setlocale(LC_ALL, "");
	ft_printf("number : %d\n", ft_printf("arg1--%0#15.1x\n arg2--%010.2s", 1234, "hello"));
	printf("number : %d\n", printf("arg1--%0#15.1x\n arg2--%010.2s", 1234, "hello"));
//	ft_printf("%d", ft_printf("abcde%-#+20.3nabcde", &test));
	//ft_printf("\n%d", test);
}
