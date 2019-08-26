using System;
public class prime
{

public static void Main()
{
  int max=100;
  bool[] is_prime = new bool[max + 1];
    for (int i = 2; i <= max; i++) is_prime[i] = true;

    // Cross out multiples.
    for (int i = 2; i <= max; i++)
    {
        // See if i is prime.
        if (is_prime[i])
        {
            // Knock out multiples of i.
            for (int j = i + i; j <= max; j +=(2*i))
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < max; i++)
	{
        if (is_prime[i])
		Console.WriteLine(i);
		}
}
}