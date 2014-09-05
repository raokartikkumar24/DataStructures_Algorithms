#include<iostream>
using namespace std;

char str[MAXSIZE];//pre-processed array
int p[MAXSIZE]; //auxiliary array
char s[MAXSIZE];//original input
int n;

void populatep()
{
    int i;
    int mx = 0;
    int id;
    for(i=1; i<n; i++)
    {
        if( mx > i )
            p[i] = MIN( p[2*id-i], p[id]+id-i );
        else
            p[i] = 1;
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)
            ;
        if( p[i] + i > mx )
        {
            mx = p[i] + i;
            id = i;
        }
    }
}

void preprocess()
{
    int i,j,k;
    n = strlen(s);
    str[0] = '$';
    str[1] = '#';
    for(i=0;i<n;i++)
    {
        str[i*2 + 2] = s[i];
        str[i*2 + 3] = '#';
    }
    n = n*2 + 2;
    str[n] = 0;
    cout <<str<<" : "<<strlen(str)<<endl;
}

void getlength()
{
    int i;
    int ans = 0;
    for(i=0;i<n;i++)
        getmax(ans, p[i]);
    printf("%d\n", ans-1);
}
//test
int main()
{
    while( scanf("%s", s) )
    {
        preprocess();
        populatep();
        getlength();
    }
    return 0;
}