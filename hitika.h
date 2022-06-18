#ifndef hitika

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

float determinant(int s,float a[10][10])
{
  float det,b[10][10];
  int m=0,n=0,cf;
  if(s==2)
  {
   det=a[0][0]*a[1][1]-a[1][0]*a[0][1];
   return(det);
  } 
  for(int i=0;i<s;i++)
  {
    m=0;
    for(int j=1;j<s;j++)
    {
      n=0;
      for(int k=0;k<s;k++)
      {
        if(k!=i)
        {
          b[m][n]=a[j][k];
          n++;
        }
      }
      m++; 
    }
    if(i%2==0)
    cf=1;
    else
    cf=-1;
    det=det+cf*a[0][i]*determinant(m,b);
  }
 
}
void matrix()
{
  int n;
  float det,a[10][10];
  printf("\nEnter the size of matrix (max 10) :");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("\nElement [%d][%d] :",i,j);
      scanf("%f",&a[i][j]);
    }
  }
  det=determinant(n,a);
  printf("\nDeterminant = %f ",det);
  getch();
}
void max_no(float a[150],int n,float *max)
{
  *max=a[0];
  for(int i=0;i<n;i++)
  {
    if(*max<a[i])
    *max=a[i];
  }
}
void min_no(float a[150],int n,float *min)
{
  *min=a[0];
  for(int i=0;i<n;i++)
  {
    if(*min>a[i])
    *min=a[i];
  }
}
void sort_dec(float a[150],int n)
{
  float t;
  int i;
   for(i=0;i<(n-1);i++)
   {
     for(int j=i+1;j<n;j++)
     { 
      if(a[i]<a[j])
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
     } 
   }
}
void sort_inc(float a[150],int n)
{
  float t;
  int i;
   for(i=0;i<(n-1);i++)
   {
     for(int j=i+1;j<n;j++)
     {
      if(a[i]>a[j])
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
      }
     } 
   }
}
void input_kb(int m)
{
  int j=1,i=0,n;
  float a[150];
  printf("\nEnter the no. of elements you want to enter :");
  scanf("%d",&n);
  while(i<n)
  scanf("%f",&a[i++]);
  if(m==0)
  {
  sort_dec(a,n);
  printf("\nIn descending order\n");
  for(i=0;i<n;i++)
  printf("%f\t",a[i]);
  }
  if(m==1)
  {
  sort_inc(a,n);
  printf("\nIn ascending order\n");
  for(i=0;i<n;i++)
  printf("%f\t",a[i]);
  }
  float max,min;
  if(m==2)
  {
    max_no(a,i,&max);
    printf("\nMaximum = %f",max);
  }
  if(m==3)
  {
    min_no(a,i,&min);
    printf("\nMinimum = %f",min);
  }
  getch();
}
void input_file(int m)
{
  int j,i=0,n;
  float a[150];
  char f1[50],f2[50];
  FILE *fp1, *fp2;
  printf("\nEnter the name of the file (with path) in which data is stored :");
  scanf("%s",f1);
  printf("\nEnter the name of file (with path) in which you want to save the output :");
  scanf("%s",f2);
  fp1=fopen(f1,"r");
  fp2=fopen(f2,"w");
  if(fp1==NULL)
  {
    puts("\nCannot open the file1");
    exit(0);
  }
  if(fp2==NULL)
  {
    puts("\nCannot open the file2");
    exit(0);
  }
  printf("\nYour entered data is\n");
  while(fscanf(fp1,"%f",&a[i])!=EOF)
  {
  printf("%f\n",a[i]);
  i++;
  }
  if(m==1)
  {
  sort_inc(a,i);
  printf("\nAfter sorting in ascending order\n");
  for(j=0;j<i;j++)
  {
   fprintf(fp2,"%f\n",a[j]);
   printf("%f\n",a[j]);
  } 
  }
  if(m==0)
  {
  sort_dec(a,i);
  printf("\nIn descending order\n");
  for(j=0;j<i;j++)
  {
   fprintf(fp2,"%f\n",a[j]);
   printf("%f\n",a[j]);
  } 
  }
  float max,min;
  if(m==2)
  {
    max_no(a,i,&max);
    printf("\nMaximum = %f",max);
    fprintf(fp2,"\nMaximum = %f",max);
  }
  if(m==3)
  {
    min_no(a,i,&min);
    printf("\nMinimum = %f",min);
    fprintf(fp2,"\nMinimum = %f",min);
  }
  fclose(fp1);
  fclose(fp2);
  getch();
}
void seq(int m)
{
  int j=0,mode;
  while(j==0)
  {
   printf("\nYou want to enter data yourself or through file ?\nPress 1 for file and 0 otherwise :");
   scanf("%d",&mode);
   switch(mode)
   {
    case 1:input_file(m); j=1; break;
    case 0: input_kb(m); j=1; break;
    default: printf("\nYou entered wrong input.. please re-enter..."); j=0;
   }
  }
}
void lcm()
{
   int arr[10],n,max,j=0,i;
   printf("\nYou want to find lcm of how many no.s (max 10)? ");
   scanf("%d",&n);
   printf("\nEnter the no.s whose lcm is to be found :");
   for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   max=arr[0];
   for(i=0;i<n;i++)
   max=(arr[i]>max)?arr[i]:max;
   while(1)
   {
     j=0;
     for(i=0;i<n;i++)
     {
       if(max%arr[i]==0)
       j++;
     }
     if(j==n)
     {
       printf("\nlcm is %d",max);
       break;
     }
     else
     max++;
   }
   getch();
}   
void gcd()
{
   int arr[10],n,min,j=0,i,g=0;
   printf("\nYou want to find gcd of how many no.s (max 10)? ");
   scanf("%d",&n);
   printf("\nEnter the no.s whose gcd is to be found :");
   for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   min=arr[0];
   for(i=0;i<n;i++)
   min=(min<arr[i])?min:arr[i];
   for(int k=1;k<=min;k++)
   {
      j=0;
      for(i=0;i<n;i++)
      {
       if(arr[i]%k==0)
       j++;
      }
      if(j==n)
      g=k;
   }
   printf("\ngcd is %d",g);
   getch();
}
void search()
{
  int mode, i = 0, n,j=0;
  float a[150], no;
  char f1[50];
  FILE *fp;
  printf("\nEnter the name of the file (with path) in which data is stored :");
  scanf("%s", f1);
  fp = fopen(f1, "r");
  if (fp == NULL)
  {
    puts("\nCannot open the file1");
    exit(0);
  }
  while (fscanf(fp, "%f", &a[i]) != EOF)
  {
    i++;
  }
  n = i;
  printf("\nEnter the no. you want to search in this data in file :");
  scanf("%f", &no);
  for (i = 0; i < n; i++)
  {
    if (a[i] == no)
    {
      printf("\nThe no. is present in file at position %d", i + 1);
      j=1;
    }
  }
  if (j==0)
    printf("\nThe no. you are searching for is not in this file.");
  getch();
}

#define hitika
#endif