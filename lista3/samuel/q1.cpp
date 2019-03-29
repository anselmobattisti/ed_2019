#include <stdio.h>

void shift_troca_string(char *str)
{
	if(str[0])
	{
		if(str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] -= 32;
			str[0]--;
			if(str[0] == 64)
				str[0]+=26;
			//printf("%d\n", str)
		}
		else if(str[0] >= 'A' && str[0] <= 'Z')
		{
			str[0] += 32;
			str[0]--;
			if(str[0] == 96)
				str[0]+=26;
		}
		else
			str[0] = '!';
		shift_troca_string(&str[1]);
	}
}

int main()
{
	char s[100];

	scanf("%s",s);

	shift_troca_string(s);

	printf("\n\nModificada = %s\n",s);
}