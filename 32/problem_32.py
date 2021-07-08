import math

"""
brute force
"""

def nDigits(n):
	l = 0
	while n != 0:
		n = n / 10
		l+=1
	return l

def is9Pandigital(multipler, multiplicand, product):
	targetLen = 9
	digitLen = nDigits(multipler) + nDigits(multiplicand) + nDigits(product)
	if (digitLen != targetLen):
		return False, ""
	asString = "{}{}{}".format(multipler,multiplicand,product)
	if "0" in asString:
		return False, ""
	return len(set(asString)) == targetLen, asString

if __name__ == '__main__':
	limit = int(math.floor(math.sqrt(123456789)))
	halfLimit = 5000
	answers = {}
	sumOfPandigitals = 0

	for multipler in range(0, halfLimit):
		for multiplicand in range(0, halfLimit):
			product = multipler * multiplicand
			isPan, digits = is9Pandigital(multipler, multiplicand, product)
			if (isPan and product not in answers):
				answers[product] = True
				sumOfPandigitals += product
				print(digits)

	print(sumOfPandigitals)