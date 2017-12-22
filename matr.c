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
for(i=0;i<m;i++) /* Create an array */
{
    for(j=0;j<n;j++)
    {
        mas[i][j]=-50 + rand() %100;
        printf("%d ",mas[i][j]);
    }
    printf("\n");
}
printf("\n\n\n");
/*-----------------------------------------*/
/* 2 exercise */
int k;
for(j=0;j<n;j++) /* Swap the first and last lines and deploy them */
{
    k=mas[0][j];
    mas[0][j]=mas[m-1][n-j-1];
    mas[m-1][n-j-1]=k;
}
for(i=0;i<m;i++) /* The output of the resulting array */
{
    for(j=0;j<n;j++)
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
for(i=0;i<m;i++) /* Finding the minimal element */
{
    for(j=0;j<n;j++)
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
i=0;
j=0;
x=0;
y=0;
while(i<m) /* Delete the string and column at the intersection of which is the smallest element of the array */
{
    if(i!=min_str)
    {
       while(j<n)
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
    j=0;
    y=0;
}
m--;
n--;
printf("\n\n\n");
/*--------------------------------------------*/
/* 4 exercise */
int new_mas[9][10];
char a;
int b;
b=0;
i=0;
j=0;
while((a=getchar()) !='.') /* Create an array manually */
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
        j=0;
    }
}
printf("\n\n\n");
/*-------------------------------------------*/
/* 5 exercise*/
if(n!=i+1) /* Checking the number of columns of one matrix with the number of rows of another matrix */
{
    printf("The number of columns should equal the number of strings of the old matrix!");
    return 1;
}
int z,q;
z=j;
int mas_mas[m][z];
for(i=0;i<m;i++) /* Multiplication of matrices */
{
    for(j=0;j<z;j++)
    {
        mas_mas[i][j]=0;
       for(q=0;q<n;q++)
       {
           mas_mas[i][j]=mas_mas[i][j]+mas2[i][q]*new_mas[q][j];
       }
       printf("%d ",mas_mas[i][j]);
    }
    printf("\n");
}
}
