det = g[0].denominator()

det_str = "mpz_class DET = "

det_str += str(det)

det_str += "_mpz;"

g *= det 


secret_vector_str = "int secret_vector[N] = {"
secret_vector_str += str(f[0]) + ","
for i in range(1,N-1,1):
    secret_vector_str += str(f[i]) + ","
secret_vector_str += str(f[N-1]) + "};"

secret_vector_inv_str = "mpz_class secret_vector_inv[N] = {"
secret_vector_inv_str += str(g[0]) + "_mpz,"
for i in range(1,N-1,1):
    secret_vector_inv_str += str(g[i]) + "_mpz,"
secret_vector_inv_str += str(g[N-1]) + "_mpz};"

with open("keys.hpp", 'w') as file:
    print >> file, det_str 
    print >> file, secret_vector_str
    print >> file, secret_vector_inv_str



