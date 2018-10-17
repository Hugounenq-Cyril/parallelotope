N = 64
phi = x^N-1

R.<x> = QQ[]
S.<x> = R.quotient(phi)

f = 0

f += randint(N,2*N)

for i in range(1,N,1):
    r = randint(0,5)   
    if r == 0:
        f += x ^ i
    if r == 1:
        f += 2*x ^ i

r = 0
for i in range(0,N,1):
    r += f[i]

print(r)

g = 1/f

