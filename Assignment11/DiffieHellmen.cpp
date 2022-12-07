/* This program calculates the Key for two persons
using the Diffie-Hellman Key exchange algorithm using C++ */
#include <cmath>
#include <iostream>
using namespace std;

// Power function to return value of a ^ b mod P
long long int power(long long int a, long long int b,
					long long int P)
{
	if (b == 1)
		return a;

	else
		return (((long long int)pow(a, b)) % P);
}
int prime(long int pr)
{
	if (pr <= 1)  return 0;
    int i;
    int j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

// Driver program
int main()
{
	long long int P, G, x, a, y, b, ka, kb;

	// Both the persons will be agreed upon the
	// public keys G and P
	P = 23; // A prime number P is taken
	while (1)
	{
		cout<<"Enter the Prime Number: ";
		cin>>P;
		int t = prime(P);
		if(t == 0)
			cout<<"P is not Prime";
		else
			break;
	}
	

	G = 9; // A primitive root for P, G is taken'
	cout<<"Enter the Primitive Root: ";
	cin>>G;
	
	// Alice will choose the private key a
	a = 4; // a is the chosen private key
	cout<<"Enter Alice Private Key: ";
	cin>>a;
	
	// Bob will choose the private key b
	b = 3; // b is the chosen private key
	cout<<"Enter Bob Private Key: ";
	cin>>b;
	
	cout<<"\n\tDiffie-Hellmen Key Exchnage Algorithm\t\n";
	
	cout << "The value of P : " << P << endl;
	
	cout << "The value of G : " << G << endl;

	cout << "The private key a for Alice : " << a << endl;

	x = power(G, a, P); // gets the generated key

	cout << "The private key b for Bob : " << b << endl;

	y = power(G, b, P); // gets the generated key

	// Generating the secret key after the exchange
	// of keys
	ka = power(y, a, P); // Secret key for Alice
	kb = power(x, b, P); // Secret key for Bob
	cout << "Secret key for the Alice is : " << ka << endl;

	cout << "Secret key for the Alice is : " << kb << endl;

	return 0;
}