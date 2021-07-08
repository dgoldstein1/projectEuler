"""
based on https://www.xarg.org/puzzle/project-euler/problem-31/
"""

if __name__ == '__main__':
	coins = [1,2,5,10,20,50,100,200]
	target = 200
	table = [0] * target
	table[0] = 1

	# loop through table and generate combinations dynamically
	for coin in coins:
		for i in range(coin, target):
			table[i] += table[i - coin]

	print(table[target-1])
