#include <stdio.h>
#include <stdlib.h>

long int P, a;

long int mod_exp(long int b, long int e, long int m) {
	long int r = 1;
	while (e > 0) {
		if (e % 2 == 1) {
			r = (r * b) % m;
		}
		b = (b * b) % m;
		e /= 2;
	}
	return r;
}

void dh_key_exchange(long int priv, long int *pub, long int a, long int P) {
	*pub = mod_exp(a, priv, P);
}

int main() {
	printf("\nEnter a prime number:");
	scanf("%ld", &P);
	
	printf("\nEnter the primitive root of the prime number:");
	scanf("%ld", &a);	
	
	long int priv_c, priv_s, pub_c, pub_s, shared_c, shared_s;
	
	printf("\nEnter the private key of client:");
	scanf("%ld", &priv_c);
	
	printf("\nEnter the private key of server:");
	scanf("%ld", &priv_s);
	
	dh_key_exchange(priv_c, &pub_c, a, P);
	printf("\nClient public key: %ld\n", pub_c);
	
	dh_key_exchange(priv_s, &pub_s, a, P);
	printf("\nServer public key: %ld\n", pub_s);
	
	shared_c = mod_exp(pub_s, priv_c, P);
	shared_s = mod_exp(pub_c, priv_s, P);
	
	printf("\nClient shared secret: %ld\n", shared_c);
	printf("Server shared secret: %ld\n", shared_s);
	
	return 0;
}
