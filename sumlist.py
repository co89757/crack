def sumList(base, basesum, li):
	 
	for e in li:
		if isinstance(e, int):
			basesum += base*e 
		else:
			basesum = sumList(base+1, basesum, e)
	return basesum


if __name__ == '__main__':
	li = [1,1,3, [1,1]] 
	print sumList(1, 0, li) 