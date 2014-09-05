int RES[100][100];

int subsetSumDyn(int* A, int len, int sum)
{
    int i,j;

    for(j=0; j<=sum; j++)
        RES[0][j] = 0;
    
    for(i=0; i<=len; i++)
        RES[i][0] = 1;

    for(i=1; i<=len; i++)
    {
        for(j=1; j<=sum; j++)
        {
            int index = j - A[i-1];
            if(index >=0)
                RES[i][j] = RES[i-1][j] | RES[i-1][index];
            else
                RES[i][j] = RES[i-1][j];
        }
    }

    return RES[len][sum];
}

int main()
{
    int A[] = {13, 21, 11, 14, 4, 5};
    int len = sizeof(A)/sizeof(int);

    printf("Subset sub: %d\n", subsetSumDyn(A, len, 32));
    return 0;
}
