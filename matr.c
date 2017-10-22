#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
/* 1 exercise */
int i,j,m,n;
srand(time(NULL));
m=rand() %5 +3;
n=rand() %5 +4;
printf("Strings:%d, Columns:%d\n\n",m,n);
int mas[m][n];
for(i=1;i<m+1;i++)
{
    for(j=1;j<n+1;j++)
    {
        mas[i][j]=-500 + rand() %1000;
        printf("%d ",mas[i][j]);
    }
    printf("\n");
}
printf("\n\n\n");
/*-----------------------------------------*/
/* 2 exercise */
int k;
for(j=1;j<n+1;j++)
{
    k=mas[1][j];
    mas[1][j]=mas[m][n-j];
    mas[m][n-j]=k;
}
for(i=1;i<m+1;i++)
{
    for(j=1;j<n+1;j++)
    {
        printf("%d ",mas[i][j]);
    }
    printf("\n");
}
printf("\n\n\n");
/*-----------------------------------------*/
/* 3 exercise */
int mas2[m-1][n-1];
int min, min_str, min_col,x,y;
min=501;
for(i=1;i<m+1;i++)
{
    for(j=1;j<n+1;j++)
       {

          if(mas[i][j]<min)
          {
              min=mas[i][j];
              min_str=i;
              min_col=j;
          }
       }
}
printf("Min. element = %d, String = %d, Column = %d\n\n", min, min_str, min_col);
i=1;
j=1;
x=1;
y=1;
while(i<m+1)
{
    if(i!=min_str)
    {
       while(j<n+1)
       {
           if(j!=min_col)
           {
               mas2[x][y]=mas[i][j];
               printf("%d ",mas2[x][y]);
           }
           else
           {
               y--;
           }
           j++;
           y++;
       }
       printf("\n");
    }
    else
    {
        x--;
    }
    x++;
    i++;
    j=1;
}
m--;
n--;
printf("\n\n\n");
/*--------------------------------------------*/
/* 4 exercise */
int new_mas[8][9];
char a;
int b;
b=0;
i=1;
j=1;
while((a=getchar()) !='.')
{
    if(a>='0' && a<='9')
        b=b*10+a - '0';
    if(a==' ')
    {
        new_mas[i][j]=b;
        printf("%d ",new_mas[i][j]);
        b=0;
        j++;
    }
    if(a==',')
    {
        new_mas[i][j]=b;
        printf("%d\n",new_mas[i][j]);
        b=0;
        i++;
        j=1;
    }
}
printf("\n\n\n");
/*-------------------------------------------*/
/* 5 exercise*/
if(n!=i)
{
    printf("The number of columns should equal the number of rows of the old matrix!");
    return 1;
}
int z,q;
z=j++;
int mas_mas[m][z];
for(i=1;i<m+1;i++)
{
    for(j=1;j<z+1;j++)
    {
        mas_mas[i][j]=0;
       for(q=1;q<n+1;q++)
       {
           mas_mas[i][j]=mas_mas[i][j]+mas2[i][q]*new_mas[q][j];
       }
       printf("%d ",mas_mas[i][j]);
    }
    printf("\n");
}
}
