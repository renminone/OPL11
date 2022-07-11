#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define MAXL 1000
#define YES 1
#define NO 0

int main()
{
	setlocale(LC_ALL, "Rus");
	HANDLE hStdout;
	FILE* fpin;
	int i = 0, l = 1, vs = 0, ms = 0, sc = 0, c = YES, m, v;
	char line[MAXL];
	char s[MAXL];
	char* sp;
	sp = &s[i];
	char cl[18] = { '#', 'i', 'n', 'c', 'l', 'u', 'd', 'e', ' ', '<', 's', 't', 'd', 'i', 'o', '.', 'h', '>' };
	char mf[10] = { 'i', 'n', 't', ' ', 'm', 'a', 'i', 'n', '(', ')',  };
	char vf[4] = { 'v', 'o', 'i', 'd' };
	char* ptr, *cp, *mp, *vp;
	ptr = &line[i]; //Указатель на символ файла
	cp = &cl[i]; //Указатель на триггер cl
	mp = &mf[i]; //Указатель на триггер mf
	vp = &vf[i]; //Указатель на триггер vf

	WORD ftc, et; //Цвет текста заголовков и текста вывода ошибки.
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	ftc = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE; //Цвет текста функции
	et = FOREGROUND_INTENSITY | FOREGROUND_RED; //Цвет текста ошибки

	fopen_s(&fpin, "test.txt", "rt");
	if (fpin == NULL)
		return;

	while ((ptr = fgets(line, MAXL, fpin)) != NULL) 
	{
		if (l == 1)
			while (*ptr++ == *cp++)
				sc++;
		if ((l == 1) && (sc < 18))
		{
			SetConsoleTextAttribute(hStdout, et);
			printf("Программа не на языке С!");
			c = NO;
		}
		else
			l++;
		break;
	}
	fclose(fpin);
	
	if (c == YES)
	{
		fopen_s(&fpin, "test.txt", "rt");
		if (fpin == NULL)
			return;

		while ((ptr = fgets(line, MAXL, fpin)) != NULL)
		{
				for (i = 0; i < 10; i++)//Метка для int main()
				{      
					if (*ptr == *mp)
					{
						SetConsoleTextAttribute(hStdout, ftc);
						vs = YES;
					}
					else
					{
						SetConsoleTextAttribute(hStdout, 7);
						break;
					}
				}
			if (vs != YES)    //Метка для void...
				for (i = 0; i < 4; i++)
				{
					if (*ptr == *vp)
					{
						ms = YES;
						SetConsoleTextAttribute(hStdout, ftc);
					}
					else
					{
						SetConsoleTextAttribute(hStdout, 7);
						break;
					}
				}
			ms = NO;
			vs = NO;
			printf("%s", ptr);
		}
	}
	printf("\n");
	SetConsoleTextAttribute(hStdout, 7);
	return 0;
}
