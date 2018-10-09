#include "main.hpp"

using namespace std;

int secret_vector[N] = {6,0,1,0,1,0,0};
int secret_vector_inv[N] = {
        270125,17351,-50419,10547,-35236,-8290,21842,-45397};

int _DEN = 1624707;
int ** B    = rotation_matrix(secret_vector); 
int ** Binv = rotation_matrix(secret_vector_inv); 
    

int main(int argc, char** argv){

    print_point(secret_vector);
    print_point(secret_vector_inv);

    print_matrix(B);  
    print_matrix(Binv);  
    
    int p[N] = {0,0,0,0,0,0,0,0};
    cout << is_in(p) << endl;

    while(is_in(p)){
            int i = 7;
            p[i]++;

    }
    print_point(p);
    return 0;
}


bool is_in(int* p){
    
    double * res = matrix_vector_den(Binv, p, _DEN);
    
    for(int i = 0; i < N; i++){
        if((res[i] < -0.5)||(res[i]>=0.5)) return false;
    }
    return true;
}


int** rotation_matrix(int* v){

    int ** res = new int*[N];

    for(int i = 0; i < N; i++){
        res[i] = new int[N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i >= j){
                res[i][j] = v[i - j];
            }
            else{
                res[i][j] = v[i - j + N];
            }
        }
    }
    return res;
}


double* matrix_vector_den(int ** A, int* v, int den){

    double * res = new double[N];

    for(int i = 0; i < N; i++){
        res[i] = 0;
        for(int j = 0; j < N; j++){
            res[i] += A[i][j] * v[j];
        }
        res[i] /= den;
    }
    return res;
    
}

void print_point(int* p){
    for(int i = 0; i < N-1; i++){
        cout <<  p[i] << ",";
    }
    cout <<  p[N-1];
    cout << endl;
}

void print_point(double* p){
    for(int i = 0; i < N-1; i++){
        cout <<  p[i] << ",";
    }
    cout <<  p[N-1];
    cout << endl;
}


void print_matrix(int** p){

    cout << "**** BEGIN MATRIX ****" << endl;
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N-1; i++){
            cout << p[k][i] << ",";
        }  
        cout << p[k][N-1] << endl;
    }
    cout << "**** END MATRIX ****" << endl;

}

double inner_prod(double* u, double* v){
    double result = 0;
    for(int i = 0; i < N; i++){
        result += u[i] * v[i];
    }
    return result;
}

double norm(double* u){
    return(sqrt(inner_prod(u, u)));
}

