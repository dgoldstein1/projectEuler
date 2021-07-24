import math

def isPrime(n):
	mx = int(math.sqrt(n)) + 1
	for i in range(2, mx):
		if n % i == 0: return False
	return True

def rotate(i, nDigits):
	return (i / 10) + ((i % 10) * pow(10, nDigits-1))


if __name__ == '__main__':
	nCircularPrimes = 0
	for i in range(2, 1000000):
		nDigits = int(math.log(i,10)) + 1
		n = i
		allRotationsPrime = True
		for j in range(nDigits):
			if (isPrime(n) is False):
				allRotationsPrime = False
				break
			n = rotate(n, nDigits)
		if allRotationsPrime:
			nCircularPrimes += 1

	print(nCircularPrimes)

