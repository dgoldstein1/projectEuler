import math

def numFactors(n):
	i = 2
	factors = [1]
	while(i < math.sqrt(n)):
		if(n % i == 0):
			factors.append(i)
		i += 1
	factors.append(n)
	return len(factors) * 2;
	
if __name__ == "__main__":
	index = 1
	x = 1
	while True:
		print (index, x)
		if(numFactors(x) > 500):
			print x
			break
		index += 1
		x += index
	
	