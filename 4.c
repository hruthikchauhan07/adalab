#include<stdio.h>
#include<math.h>
#include<process.h>
#include<stdlib.h>
int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
 main()
{
int m,n,p[10],w[10],i,j,k[10],v[20][20];


printf("enter the no. of objects");
scanf("%d",&n);

printf("enter the weight");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);

printf("enter the profit");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);

printf("enter capacity");
scanf("%d",&m);

for(i=0;i<=n;i++)
  {
for(j=0;j<=m;j++)
    {
if(i==0||j==0)
	v[i][j]=0;
else
	if(j<w[i])
	v[i][j]=v[i-1][j];
	else
	     v[i][j]=max(v[i-1][j],p[i]+v[i-1][j-w[i]]);
     }
    }

printf("knapsack filling\n");
for(i=0;i<=n;i++)
  {
for(j=0;j<=m;j++)
     {
printf("%d ",v[i][j]);
     }
printf("\n");
  }
for(i=0;i<=n;i++)
k[i]=0;
i=n;
j=m;
while(i!=0 && j!=0)
{
if(v[i][j]!=v[i-1][j])
	 {
	k[i]=1;
    j=j-w[i];
	 }
i--;
}


printf("\n the optimal solution is %d\n ",v[n][m]);


printf("solution vector is\n");
for(i=1;i<=n;i++)
printf("%d ",k[i]);
return 0;
}
