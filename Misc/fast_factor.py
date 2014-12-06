def arrayF(n):
	F = [0] * (n+1)
	i = 2
	while (i*i <= n ):
		if(F[i] == 0 ):
			k = i*i
			while( k <= n):
				if( F[k] == 0):
					F[k] = i
				k += i
		i += 1
	return F



def factorization(x,F):
	primefactors = []
	while(F[x] > 0):
		primefactors += [F[x]]
		x = x // F[x]
	primefactors += [x]
	return  primefactors




if __name__ == "__main__":
	factors = arrayF(100)
	print(factorization(4,factors))