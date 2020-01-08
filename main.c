#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf(" %d\n",ft_printf("'a%*.3sa'", -15, "ABCDD"));
	printf(" %d\n", printf("'a%*.3sa'", -15, "ABCDD"));
}
