#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
int lg, i, x, suma = 0;
int main()
{
    FILE* pFile;
    pFile = fopen("in.txt", "r");
    if (pFile == 0)
    {
        printf("Couldn't open the file!!");
        return 0;
    }

    char numar[20];
    char c;
    while (fgets(numar, 20, pFile))
    {
        lg = 0;
        i = 0;
        x = 0;
        while(numar[i]!='\0')
        {
            lg++;
            i++;
        }

        for (i = 0; i < lg; i++)
            if (numar[i] >= '0' && numar[i] <= '9')
                x = x * 10 + (numar[i] - '0');
        suma = suma + x;
    }
    cout << suma;
    fclose(pFile);
    return 0;
}