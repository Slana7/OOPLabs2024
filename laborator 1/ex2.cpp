#include <iostream>
#include <string>
using namespace std;

bool verifvocale(char a)
{
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        return true;
    return false;
}

int lungime(char s[])
{
    int i, cnt = 0;
    for (i = 0; s[i]; i++)
        cnt++;
    return cnt;
}

char listacuv[100][100];

void sortare(int cnt)
{
    int n = cnt, i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (lungime(listacuv[i]) < lungime(listacuv[j]))
                swap(listacuv[i], listacuv[j]);
}

int main()
{
    char sir[100];
    int i = 0, cnt, j=0, n;
    while (scanf("%c", &sir[i]) && sir[i] != '\n')
        i++;
    sir[i] = '\0', n = i, i = 0, cnt = 0;
    // fac lista de cuvinte
    while (sir[i])
    {
        if (verifvocale(sir[i]))
        {
            listacuv[cnt][j] = sir[i];
            i++;
            j++;
        }
        else
        {
            listacuv[cnt][j] = NULL;
            cnt++;
            i++;
            j = 0;
        }
    }
    listacuv[cnt][j] = NULL;
    sortare(cnt);
    char aux[100];
    for (int i = 0; i <= cnt; i++) {

        printf("%s\n", listacuv[i]);
    }
    return 0;
}