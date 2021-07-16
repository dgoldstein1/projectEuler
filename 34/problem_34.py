
import math

def getDigits(n):
	digits = []
	while n != 0:
		digits.insert(0,n%10)
		n = n / 10
	return digits

if __name__ == "__main__":
	s = 0
	for i in range(3,1000000):
		sumDigits = 0
		digits = getDigits(i)
		for n in range(0, len(digits)):
			sumDigits = sumDigits + math.factorial(digits[n])
			if sumDigits > i: break
			if n == len(digits) - 1 and sumDigits == i:
				print(i)
				s = s + i

	print(s)
		


