#ifndef siddhant

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "satyam.h"
#define SIZE 1000
void input2();


float geomean(float d1[], int f1[], float ll1[], float ul1[], int *r1)  //Function to calculate Geometric mean
{
    float gm, sum = 0, sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)                  //If data is ungrouped
    {
        for (int i = 0; i < *r1; i++)
        {
            sum = sum + (log(d1[i])) * f1[i];
            sumf = sumf + f1[i];
        }
        gm = exp(sum / sumf);
    }
    else
    {
        for (i = 0; i < *r1; i++)                    //if data is grouped   
        {
            sum = sum + log(((ll1[i] + ul1[i]) / 2.0)) * f1[i];
            sumf = sumf + f1[i];
        }
        gm = exp(sum / sumf);                         //calculation of geometric Mean
    }
    return (gm);
}

float harmean(float d1[], int f1[], float ll1[], float ul1[], int *r1)  //Function to calculate Harmonic mean
{
    float hm, sum = 0, sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)                //if data is ungrouped 
    {
        for (int i = 0; i < *r1; i++)
        {
            sum = sum + ((1.0 / d1[i]) * f1[i]);
            sumf = sumf + f1[i];
        }
        hm = sumf / sum;
    }
    else
    {
        for (i = 0; i < *r1; i++)                     //if data is grouped 
        {
            sum = sum + (1 / ((ll1[i] + ul1[i]) / 2.0)) * f1[i];
            sumf = sumf + f1[i];
        }
        hm = sumf / sum;
    }
    return (hm);
}
float q1(float d1[],int f1[],float ll1[],float ul1[],int *r1)      //Calculation of quartile1
{
	float q,h,a; int i,j,cf[SIZE];
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
        if(cf[i]>(cf[*r1-1]/4.0))         //calculation of q1
	        {
                if(*r1%2==0)
                    q=(d1[i]+d1[i-1])/4;
                else
		            q=d1[i];
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
	    if(cf[i]>(cf[*r1-1]/4))                             //q1 class
	    {
		q=ll1[i]+((h/f1[i])*(cf[*r1-1]/4.0-cf[i-1]));         //expression to calculate Quartile1
		break;
	    }
	}
     }
	return(q);
}
float q3(float d1[],int f1[],float ll1[],float ul1[],int *r1)      //Calculation of quartile3
{
	float q,h,a; int i,j,cf[SIZE];
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
        if(cf[i]>(3*(cf[*r1-1])/4.0))         //calculation of q3
	        {
                if(*r1%2==0)
                    q=(3*(d1[i]+d1[i-1]))/4.0;
                else
		            q=d1[i];
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
	    if(cf[i]>(3*(cf[*r1-1]))/4)                             //q3 class
	    {
		q=ll1[i]+((h/f1[i])*(3*(cf[*r1-1])/4.0-cf[i-1]));         //expression to calculate Quartile3
		break;
	    }
	}
     }
	return(q);
}


float var(float d1[], int f1[], float ll1[], float ul1[], int *r1) //Formula for Variance
{
    float v, m1, sum, sumf;
    sum = 0;
    sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)                         //for ungrouped data
    {
        m1 = meanf(d1, f1, ll1, ul1, r1);
        for (i = 0; i < *r1; i++)
        {
            
            sum = sum + (pow((d1[i] - m1), 2) * f1[i]);
            sumf = sumf + f1[i];
        }
        v = sum / sumf;
    }
    else
    {
        m1 = meanf(d1, f1, ll1, ul1, r1);
        for (i = 0; i < *r1; i++)                               //for grouped data
        {
            sum = sum + (pow((((ll1[i] + ul1[i]) / 2.0) - m1), 2) * f1[i]);
            sumf = sumf + f1[i];
        }
        v = sum / sumf;                                     //calculation of variance
    }
    return (v);
}
float rangef(float d1[], int f1[], float ll1[], float ul1[], int *r1) //formula for range
{
    float ran, min, max;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)                 //for ungrouped data
    {
        for (i = 0; i < *r1; i++)
        {
            min = d1[i];
            max = d1[i];
        }
        for (i = 0; i < *r1; i++)
        {
            if (min > d1[i])
                min = d1[i];
            if (max, d1[i])
                max = d1[i];
        }
        ran = max - min;
    }
    else                                           //for grouped data
    {
        ran = ul1[*r1 - 1] - ll1[0];
    }
    return (ran);
}
float md(float d1[], int f1[], float ll1[], float ul1[], int *r1) //formula for mean deviation
{
    float m, sum = 0, sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)                   //for ungrouped case
    {
        for (i = 0; i < *r1; i++)
        {
            sum = sum + fabs((d1[i] - meanf(d1, f1, ll1, ul1, r1))) * f1[i];
            sumf = sumf + f1[i];
        }
        m = sum / sumf;
    }
    else
    {
        for (i = 0; i < *r1; i++)                   //for grouped case
        {
            sum = sum + fabs(((ll1[i] + ul1[i]) / 2.0) - meanf(d1, f1, ll1, ul1, r1)) * f1[i];
            sumf = sumf + f1[i];
        }
        m = sum / sumf;
    }
    return (m);
}
float mom3(float d1[], int f1[], float ll1[], float ul1[], int *r1) //formula for 3rd central moment
{
    float M3, sd, sum = 0, sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)           //for ungrouped data
    {
        for (int i = 0; i < *r1; i++)
        {
            sum = sum + pow((d1[i] - meanf(d1, f1, ll1, ul1, r1)), 3) * f1[i];
            sumf = sumf + f1[i];
        }
        M3 = sum / sumf;
    }
    else
    {
        for (i = 0; i < *r1; i++)               //for grouped data
        {
            sum = sum + pow(((ll1[i] + ul1[i]) / 2.0) - meanf(d1, f1, ll1, ul1, r1), 2) * f1[i];
            sumf = sumf + f1[i];
        }
        M3 = sum / sumf;
    }
    return (M3);
}

float mom4(float d1[], int f1[], float ll1[], float ul1[], int *r1) //formula for 4th central moment
{
    float M4, sd, sum = 0, sumf = 0;
    int i;
    if (ll1[0] == 0 && ul1[0] == 0)
    {
        for (int i = 0; i < *r1; i++)
        {
            sum = sum + pow((d1[i] - meanf(d1, f1, ll1, ul1, r1)), 4) * f1[i];
            sumf = sumf + f1[i];
        }
        M4 = sum / sumf;
    }
    else
    {
        for (i = 0; i < *r1; i++)
        {
            sum = sum + pow(((ll1[i] + ul1[i]) / 2.0) - meanf(d1, f1, ll1, ul1, r1), 2) * f1[i];
            sumf = sumf + f1[i];
        }
        M4 = sum / sumf;
    }
    return (M4);
}

void cal2(float d[],  int f[],  float ll[], float ul[], int *r, int *n)
{
    float Mean, GM, HM, Q1, Q3, Range, MD, VAR, COV, m2, m3, m4, Sk, kurt;
    int c;
    do
    {
        printf("\nChoose the option from following:\n");
        printf("\n1 Geometric Mean\n2 Harmonic Mean\n3 Quartiles\n4 Range\n5 Quartile Deviation\n6 Mean Deviation\n7 Variance & Standard Deviation\n8 Coefficient of Variation\n9 Central Moments\n10 Skewness\n11 Kurtosis \n0 Previous\n");
        fflush(stdin);
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            GM = geomean(d, f, ll, ul, r);
            printf("\nGeometric Mean=%f", GM);
            break;
        case 2:
            HM = harmean(d, f, ll, ul, r);
            printf("\nHarmonic Mean=%f", HM);
            break;
        case 3:
            Q1 = q1(d, f, ll, ul, r);
            Q3 = q3(d, f, ll, ul, r);
            printf("\nQuartile1=%f\nQuartile3=%f\nInter Quartile Range=%f", Q1, Q3, (Q3 - Q1));
            break;
        case 4:
            Range = rangef(d, f, ll, ul, r);
            printf("\nRange=%f", Range);
            break;
        case 5:
            Q1 = q1(d, f, ll, ul, r);
            Q3 = q3(d, f, ll, ul, r);
            printf("\nQuartile Deviation=%f", (Q3 - Q1) / 2.0);
            break;
        case 6:
            MD = md(d, f, ll, ul, r);
            printf("\nMean Deviation=%f", MD);
            break;
        case 7:
            VAR = var(d, f, ll, ul, r);
            printf("\n Variance = %f\nStandard Deviation = %f", VAR, sqrt(VAR));
            break;
        case 8:
            Mean = meanf(d, f, ll, ul, r);
            VAR = var(d, f, ll, ul, r);
            COV = (sqrt(VAR) / Mean) * 100.0;
            printf("\nCoefficient of Variation=%f", COV);
            break;
        case 9:
            m2 = var(d, f, ll, ul, r);
            m3 = mom3(d, f, ll, ul, r);
            m4 = mom4(d, f, ll, ul, r);
            printf("\n m1 = 0\nm2 = %f\nm3 = %f\nm4 = %f", m2, m3, m4);
            break;
        case 10:
    
            m2 = var(d, f, ll, ul, r);
            m3 = mom3(d, f, ll, ul, r);
            Sk = m3 / (pow(m2, 1.5));
            if (Sk > 0)
            printf("\nMoment coefficeint of Skewness=%f,therefore, the given distribution is postively skewed", Sk);
            else if (Sk == 0)
                 printf("\nMoment coefficeint of Skewness=%f,therefore, the given distribution is symmetric", Sk);
            else
                 printf("\nMoment coefficeint of Skewness=%f,therefore, the given distribution is negatively skewed", Sk);
            break;
        case 11:
            m2 = var(d, f, ll, ul, r);
            m4 = mom4(d, f, ll, ul, r);
            kurt = m4 / (pow(m2, 2));
            if (kurt == 3)
                printf("\nMoment coefficeint of Kurtosis=%f,therefore the given distribution is Mesokurtic", kurt);
            else if (kurt > 3)
                printf("\nMoment coefficeint of Kurtosis=%f,therefore the given distribution is Leptokurtic", kurt);
            else
                printf("\nMoment coefficeint of Kurtosis=%f,therefore the given distribution is Platykurtic", kurt);
            break;

        default:
            system("cls");
            printf("\nYou have entered the wrong choice.");
        }
        if (c != 0)
        {
            printf("\nPress 0 for Main Menu and 1 for calculating again. ");
            scanf("%d", &c);
        }
        if (c == 0)
            input2();
    } while (c == 1);
}
void input2()
{
    int c;
    float data[SIZE], X[SIZE], Y[SIZE], LL[SIZE], UL[SIZE], mean, median, mode;
    int freq[SIZE], fX[SIZE], fY[SIZE], num, row;
    LL[0] = 0;
    UL[0] = 0;
    int l;
    do
    {
        l = 0;
        printf("\n1 Discrete data\n2 Ungrouped Frequency\n3 Grouped Fequency\n");
        fflush(stdin);
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            discrete(data, freq, &num, &row);
            break;
        case 2:
            ungrouped(data, freq, &row);
            break;
        case 3:
            grouped(data, freq, &row, LL, UL);
            break;
        default:
            printf("\nYou have entered the wrong choice.");
            l = 1;
        }
    } while (l == 1);
    cal2(data, freq, LL, UL, &row, &num);
}

#define siddhant
#endif
