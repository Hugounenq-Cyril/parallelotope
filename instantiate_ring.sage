from sage.stats.distributions.discrete_gaussian_integer import DiscreteGaussianDistributionIntegerSampler
sigma = 0.6
D = DiscreteGaussianDistributionIntegerSampler(sigma=sigma)


N = 334


R.<y> = QQ[]
phi = y^N-1

S.<x> = R.quotient(phi)

f = 0

f += randint(N,2*N)

for i in range(1,N,1):
    f += abs(D()) * x^i

r = 0
for i in range(0,N,1):
    r += f[i]

r_str = "Trace: " + str(r)
print(r_str)

g = 1/f

