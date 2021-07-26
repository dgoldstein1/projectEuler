import math
def isPrime(n):
	if n <= 1: return False
	sq = int(math.sqrt(n)) + 1
	for i in range(2,sq):
		if n % i == 0: return False
	return True

def rotateAndCheckPrime(n, left=True):
	if left:
		n /= 10
	else:
		digit = int(math.log(n, 10))
		n = n - (n / pow(10, digit)) * pow(10, digit)
	if n == 0: return True
	return isPrime(n) and rotateAndCheckPrime(n, left)

if __name__ == "__main__":
	numFound = 0
	s = 0
	for n in range(23, 1000000):
		# if numFound == 11: break
		if isPrime(n) and rotateAndCheckPrime(n, False) and rotateAndCheckPrime(n, True):
			print(n)
			numFound += 1
			s += n
	print("numFound: {}, sum : {}".format(numFound, s))