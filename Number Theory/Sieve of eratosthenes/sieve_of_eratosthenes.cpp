ll Prime[1000000];
bool status[1000000]={false};
void sieve(ll number)
{
    status[2]=true;
    for(int i=3 ;i<=number;i+=2) status[i]=true;
    ll rootNumber=sqrt(number+1);

    for(int i=3;i<=rootNumber;i+=2)
    {
        if(status[i]==false)
        {
            continue;
        }
        else
        {
            for(int k=i*i;k<=number;k+=i+i)
                status[k]=false;
        }
    }

}
