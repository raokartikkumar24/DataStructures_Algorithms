import timeit
def sieve(n):
	sieve = [True] * (n+1)
	sieve[0] = sieve[1] = False
	i = 2
	primenumber = []
	while (i*i <= n):
		if (sieve[i]):
			k = i*i
			while (k <= n):
				sieve[k] = False
				k+=i #factors of the number
		i+=1

	for j in range(2,n+1):
		if sieve[j]:
			primenumber.append(j)
			
	return primenumber


if __name__ =="__main__":
	start = timeit.default_timer()
	print(sieve(10000000))
	stop = timeit.default_timer()
	print(stop-start)