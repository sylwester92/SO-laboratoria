#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <memory.h>


int licz_w_linii(char *linia, const char character)
	{
		int licznik;
		for (licznik = 0; linia[licznik]; linia[licznik] == character ? licznik++ : *linia++);
		return licznik;
	}

void licz_wszystko(char *plik, const char character, void (*licznikFunction)(char *, const char))
{
	FILE *stream;
	char *linia = NULL;
	size_t len = 0;
    

stream = fopen(plik, "r");
if (stream == NULL)
	{
        	perror(plik);
        	exit(EXIT_FAILURE);
        }

printf("[PID rodzica: %d] Zliczam ilosc spacji w pliku", getpid());
while (getline(&linia, &len, stream) != -1)
	{
		linia[strlen(linia) - 1] = '\0';

		if (fork() == 0)
		{
                	printf("[PID rodzica, %d, PID dziecka: %d] ", getppid(), getpid());
                	(*licznikFunction)(linia, character);
                	break;
        	}
	}

    free(linia);
    fclose(stream);
    exit(EXIT_SUCCESS);
}

void countCharacter(char *linia, const char character)
	{
		int charlicznik = licz_w_linii(linia, character);
        	printf("Ilosc spacji wynosi %d dla linii: '%s' \n", charlicznik, linia);
	}

int main()
	{
        	licz_wszystko("input.txt", ' ', countCharacter);
	}
