#include <stdio.h>

typedef struct 
{
    int Coef;
    unsigned int Exponent;
} TMonom;
typedef TMonom TPolinom[50];
void citire_polinom(int *n,float a[])
   {
      int i;
      printf("\nIntroduceti gradul polinomului  ");
      scanf("%d",n);
      for(i=0;i<=*n;i++)
        {
             printf("\na[%d]=",i);
             scanf("%f",&a[i]);
        };
      printf("\n");
   }
 
 
   float val_polinom(float x,int n,float a[])
   {
     int i;
     float v;
     v=0.0;
     for(i=n;i>=0;i--)
       v=v*x+a[i];
     return v;
   }
   void afis_polinom(int n,float a[],char c)
   {
     int i;
     printf("\n%c[x]=%g",c,a[0]);
     for(i=1;i<=n;i++)
       printf("+%g*x^%d",a[i],i);
     printf("\n");
   }
int citire() ;
int adunare();
int inmultire(int n,float a[], int m,float b[],
                   int *p,float c[])
{   int i,j;
     *p=n+m;
      for(i=0;i<=n+m;i++) c[i]=0.0;
      for(i=0;i<=n;i++)
       for(j=0;j<=m;j++)
             c[i+j]+=a[i]*b[j];
   
}
int scadere();
