#include<math.h>
#include<stdio.h>

int gcd(int a,int b)
{
    int temp;
    while(1)
    {
        temp=a%b;
        if(temp==0)
        return b;
        a=b;
        b=temp;
    }
}
void modinverse(int e,int phi)
{
    e=e%phi;
    for(int x=1;x<phi;x++)
    {
        if((x*e)%phi==1)
        return x;
        
    }
    return -1;
    
}
long long exponential(int base,int expo,int mod)
{
    int res=1;
    base%=mod;
    while(expo>0)
    {
        if(expo%2==1)
        {
            res=(res*base)%mod;
        }
        base=(base*base)%mod;
        expo/=2;
    }
    return res;
    
}
