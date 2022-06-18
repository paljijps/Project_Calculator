#ifndef satyam

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 1000
void input();                             //function declartaion
void discrete(float d[],int f[],int *n,int *r)              //function to take input of discrete data
{
    *r=0;
    int i,j,count;
    printf("\nEnter the number of elements: ");
    scanf("%d",n);
    printf("\nEnter elements: ");
    for(i=0; i< *n; i++)
    {
	    scanf("%f", &d[i]);
	    f[i] = -1;
    }
    for(i=0; i < *n; i++)
    {
	    count = 1;
	    for(j=i+1; j< *n; j++)
	    {
	        if(d[i]==d[j])
	        {
		    count++;                        // If duplicate element is found increment count
		    f[j] = 0;                    //To stop count frequency of same element again
	        }
	    }
	    if(f[i] != 0)
	        f[i] = count;                    //if element is not repeated count will be same
        }
        //Display output of array
        printf("\nFrequency of all elements : \n");
        for(i=0; i < *n; i++)
        {
	        if(f[i] != 0)
            {
	            printf("%-12.4f\t %3d \n", d[i], f[i]); 
                *r=*r+1;
            }
    }
}
void ungrouped(float d[],int f[],int *r)            //function to take input of ungrouped frequency data
{
    printf("\nEnter the number of rows: ");
	scanf("%d",r);
	printf("\nEnter data points: ");
	for(int i=0; i < *r; i++)
	    scanf("%f",&d[i]);
	printf("\nEnter corresponding frequencies: ");
	for(int i=0; i < *r; i++)
	    scanf("%d",&f[i]);
}
void grouped(float d[],int f[],int *r,float ll[],float ul[])        //function to take input of grouped frequency data
{
    int i;
    printf("\nEnter the number of rows: ");
	scanf("%d",r);
	printf("\nEnter lower limits: ");
	for(i=0; i < *r; i++)
	     scanf("%f",&ll[i]);
	printf("\nEnter upper limits: ");
	for(i=0; i < *r; i++)
	     scanf("%f",&ul[i]);
	printf("\nEnter corresponding frequencies: ");
	for(i=0; i < *r; i++)
	    scanf("%d",&f[i]);
}
float meanf(float d1[],int f1[],float ll1[],float ul1[],int *r1)        //Calculation of mean
{
    float m,sum=0,sumf=0; int i;
    if(ll1[0]==0 && ul1[0]==0)              //If the data is ungrouped
    {
	for(i=0;i<*r1;i++) 
    {
	  sum=sum+(d1[i]*f1[i]);
	  sumf=sumf+f1[i];
    }  
	m=sum/sumf;
    }
    else                                   //If the data is grouped
    {
    for(i=0;i<*r1;i++)
	{    
        sum=sum+((ll1[i]+ul1[i])/2.0)*f1[i];
        sumf=sumf+f1[i];
    }
	m=sum/sumf;
    }
	return(m);
}
float medianf(float d1[],int f1[],float ll1[],float ul1[],int *r1)      //Calculation of median
{
	float m,h,a; int i,j,cf[SIZE];
    if(ll1[0]==0 && ul1[0]==0)          //If the data is ungrouped
    {
	cf[0]=f1[0];
    for(i=0;i<*r1;i++)
        for(j=i+1;j<*r1;j++)
            if(d1[j]<d1[i])
            {
                a=d1[i];
                d1[i]=d1[j];
                d1[j]=a;
            }
	for(i=1;i< *r1;i++)
	    cf[i]=cf[i-1]+f1[i];            //Calculation of cumulative frequency
	for(i=0;i< *r1;i++)
	{
        if(cf[i]>(cf[*r1-1]/2))         //calculation of median
	        {
                if(*r1%2==0)
                    m=(d1[i]+d1[i-1])/2;
                else
		            m=d1[i];
		        break;
	        }
	}
    }
    else                                //If the data is grouped
    {
	cf[0]=f1[0];
	for(i=1;i< *r1;i++)
	    cf[i]=cf[i-1]+f1[i];           //Calculation of cumulative frequency
	for(i=0;i< *r1;i++)
	{
	    h=ul1[i]-ll1[i];                                    //class width
	    if(cf[i]>(cf[*r1-1]/2))                             //median class
	    {
		m=ll1[i]+((h/f1[i])*(cf[*r1-1]/2.0-cf[i-1]));         //expression to calculate median
		break;
	    }
	}
     }
	return(m);
}
float modef(float d1[],int f1[],float ll1[],float ul1[],int *r1)        //calculation of mode
{
	float m,h; int i,j,f0,f11,f2;
    if(ll1[0]==0 && ul1[0]==0)                  //for ungrouped data
    {
        for(i=0;i< *r1;i++)
            for(j=i+1;j< *r1;j++)
            {
                m=d1[i];
                if(f1[j]>f1[i])
                    m=d1[j];
                if(f1[j]==f1[i])
                    m=d1[j];
            }        
    }
    else
    {
	for(i=0;i< *r1-1;i++)
    {
        for(j=i+1;j< *r1;j++)
        {
            if(f1[j]>f1[i])
            {
                f0=f1[j-1];                 //calculation of f0,f1,f2
                f11=f1[j];
                f2=f1[j+1];
                break;
            }
        } 
    }
    
    for(i=0;i< *r1;i++)
    {
        h=ul1[i]-ll1[i];                   //class width
        if(f1[i]==f11)                     //modal class
            m=ll1[i]+((h*(f11-f0))/(2*f11-f0-f2));          //expression to calculate mode    
    }
    }
	return(m);	
}
void correg()
{
    float x[SIZE],y[SIZE],cor,cov,xy[SIZE],xbar,ybar,sumx,sumy,sumx2,sumy2,sumxy,varx,vary,byx,bxy,t;
    int i,j,n; 
    sumx=0;sumy=0;sumxy=0;sumx2=0;sumy2=0;
    printf("\nEnter the number of units: ");
    scanf("%d",&n);
    printf("\nEnter the data for variable X: ");
    for(i=0;i<n;i++)
        scanf("%f",&x[i]);
    printf("\nEnter the data for variable Y: ");    
    for(i=0;i<n;i++)
        scanf("%f",&y[i]);
    for(i=0;i<n;i++)
    {
        sumx=sumx+x[i];                         //summation x
        sumx2=sumx2+(x[i]*x[i]);                //summation x^2
        sumy=sumy+y[i];                         //summation y
        sumy2=sumy2+(y[i]*y[i]);                //summation y^2
        sumxy=sumxy+(x[i]*y[i]);                //summation xy
    }
    xbar=sumx/n;                                //mean of x
    ybar=sumy/n;                                //mean of y
    cov=sumxy*(1.0/ n)-(xbar*ybar);             //cov(x,y)
    varx=(1.0/n)*sumx2-(xbar*xbar);             //variance of x
    vary=(1.0/n)*sumy2-(ybar*ybar);             //variance of y
    cor=cov/(sqrt(varx)*sqrt(vary));            //cor(x,y)  
    byx=(cor*sqrt(vary))/sqrt(varx);            //regression coefficient of y on x
    bxy=(cor*sqrt(varx))/sqrt(vary);            //regression coefficient of x on y
    t=atan(((1-cor*cor)/fabs(cor))*((sqrt(varx)*sqrt(vary))/(varx+vary)));      //angle b/w regression lines
    printf("\nCovariance= %f",cov);
    printf("\nKarl Peasron's Coefficient of Correlation= %f",cor);
    printf("\nRegression Line Y on X :\n");
    printf("Y - %f = %f(X - %f)",ybar,byx,xbar);
    printf("\nRegression Line X on Y :\n");
    printf("X - %f = %f(Y - %f)",xbar,bxy,ybar);
    printf("\nAngle between two lines of Regression= %f radian",t);
    printf("\nsd of x= %f",sqrt(varx));
    printf("\nsd of y= %f",sqrt(vary));
}
void cal(float d[],int f[],float ll[],float ul[],int *r,int *n)
{
    float mean,median,mode;
    int c;
    do
    {
    printf("\nEnter your choice:\n");
    printf("\n1 Mean\n2 Median\n3 Mode\n0 Previous\n");
    fflush(stdin);
    scanf("%d",&c);
    switch(c)
    {
	case 1:
	mean=meanf(d,f,ll,ul,r);
	printf("\nMean=%f",mean);
	break;
	case 2:
	median=medianf(d,f,ll,ul,r);
	printf("\nMedian=%f",median);
	break;
    case 3:
    mode=modef(d,f,ll,ul,r);
    printf("\nMode=%f",mode);
    printf("\nWarning: Results maybe unexpected if mode does not exits!!!");
	break;
    default:
    system("cls");
	printf("\nYou have entered the wrong choice.");
    }
    if(c!=0)
    {
        printf("\nPress 0 for Main Menu \n1 for calculating again\n2 Statistical Calculation main menu.\n ");
        scanf("%d",&c);
    }
    if(c==0)
        input();
    }while(c==1);

}
void input()
{

    int c;
    float data[SIZE],LL[SIZE],UL[SIZE],mean,median,mode; int freq[SIZE],num,row;
    LL[0]=0; UL[0]=0;
    int l;
do
{   
    l=0;
    printf("\nEnter your choice:\n");
    printf("\n1 Discrete data\n2 Ungrouped Frequency\n3 Grouped Fequency\n");
    printf("4 Data to calculate correlation and regression\n");
    fflush(stdin);
    scanf("%d",&c);
    switch(c)
    {
    case 1:
    discrete(data,freq,&num,&row);
    break;
    case 2:
    ungrouped(data,freq,&row);
    break;
    case 3:
    grouped(data,freq,&row,LL,UL);
    break;
    case 4:
    correg();
    break;
    default:
	printf("\nYou have entered the wrong choice.");
	l=1;
    }
}while(l==1);
if(c!=4)
    cal(data,freq,LL,UL,&row,&num);

}

#define satyam
#endif