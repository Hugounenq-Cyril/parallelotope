
a = "int secret_vector[N] = {"
a += str(f[0]) + ","
for i in range(1,N-1,1):
    a += str(f[i]) + ","
a += str(f[N-1]) + "};"

b = "mpz_class secret_vector_inv[N] = {"
b += str(g[0]) + "_mpz,"
for i in range(1,N-1,1):
    b += str(g[i]) + "_mpz,"
b += str(g[N-1]) + "_mpz};"

print(a)
print(b)

