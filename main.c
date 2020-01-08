#include <stdio.h>
#include "ft_printf.h"

int main()
{
	// printf(" %d\n",ft_printf("'%00015x'", 0x99));
	// printf(" %d\n",printf("'%00015x'", 0x99));
	printf(" %d\n",ft_printf("'%-15.8u'", 0));
	printf(" %d\n",printf("'%-15.8u'", 0));
}
