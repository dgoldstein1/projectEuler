import math;

#checked and works

#inputs prime 'place' and returns actual number (i.e. place 6th prime number = 13)
def primeNumber(prime):
    current = 1;
    iterations = 0;
    while(iterations != prime):
        current = current+1;
        if(isPrime(current)):
            iterations = iterations + 1;        
    return current;
        
#TODO: make more efficient
def isPrime(number): 
    if number == 0: return False;
    if number == 1: return False;
    if number == 2: return True;
    n = 1;
    while(n < math.sqrt(number)):
        n = n+1;
        if(number % n == 0): 
            return False;
    return True;
	
def getLCF(n):
	i = 2
	while(i < math.sqrt(n)):
		if(n % i == 0):
			return i;
		i=i+1;
	return i;

if __name__ == "__main__":
	print(getLCF(209))
	print(getLCF(637))
	print(getLCF(1007))
	print(getLCF(4141))
	print(getLCF(1050703))