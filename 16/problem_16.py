"""
Ended up writing this in Python becase I didn't like the
convertinf of doubles back to long to ints in C. This is a
faster and cleaner solution
"""

if __name__ == '__main__':
	sum = 0
	for i in str(pow(2,1000)):
		sum += int(i)
	print sum
