def toBinary(n):
	b = ""
	while n > 0:
		r = 1 if n % 2 != 0 else 0
		b = str(r) + b
		n /= 2
	return b

def isPalindrome(n):
	length = len(n)
	for i in range(len(n) / 2):
		if n[i] != n[length  - 1 - i]: return False
	return True


if __name__ == "__main__":
	s = 0
	for i in range(1000000):
		if isPalindrome(str(i)) and isPalindrome(toBinary(i)):
			s += i
	print(s)