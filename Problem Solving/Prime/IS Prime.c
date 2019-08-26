/*
def isprime(n):
   """Returns True if n is prime"""
   if n == 2: return True
   if n == 3: return True
   if n % 2 == 0: return False
   if n % 3 == 0: return False

   i = 5
   w = 2
   while i * i <= n:
      if n % i == 0:
         return False

      i += w
      w = 6 - w

   return True
*/
   #include<stdio.h>
int isprime(int n)
{
	if(n==2||n==3)
		return 1;
	if(n%2==0||n%3==0)
		return 0;
	int i=5;
	int w=2;
	while(i*i <= n)
	{
		if(n%i==0)
			return 0;

	    i+=w;
	    w=6-w;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
    if(isprime(n)==1)
    {
    	printf("prime");
    }
    else
    	printf("not prime");
	return 0;
}