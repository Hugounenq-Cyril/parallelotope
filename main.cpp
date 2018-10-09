#include "main.hpp"

using namespace std;

int secret_vector[N] = {6,0,1,0,1,0,0};
int secret_vector_inv[N] = {
        270125,17351,-50419,10547,-35236,-8290,21842,-45397};

int DET= 1624707;
int diameter; // = sum (secret[i])
int ** B    = rotation_matrix(secret_vector); 
int ** Binv = rotation_matrix(secret_vector_inv); 

int calls = 0;

int main(int argc, char** argv){

    cout << "Secret vector, inverse, and determinant" << endl;
    print_point(secret_vector);
    print_point(secret_vector_inv);
    cout << DET << endl;

    print_matrix(B);  
    print_matrix(Binv);  


    // First find vertex along <(1,1,...,1)>
    diameter = 0;
    for(int i = 0; i < N; i++){
        diameter += secret_vector[i];
    }

    int starting_point[N];
    for(int i = 0; i < N; i++){
        starting_point[i] = -diameter/2 + 1;
    }
    
    int * point = starting_point;

   
    move(point);
   

    return 0;
}


int * move(int* p){

    int * next_point = new int [N];

    for(int i = 0; i < N; i++){
        next_point[i] = p[i];
    }

    while(is_in(next_point)){
        next_point[0]++;
    }
    next_point[0]--;


    for(int j = 1; j < N; j ++)
    {
        next_point[j] ++ ;
        if(is_in(next_point)) move(next_point);
        else{next_point[j] -- ;}
    }
    
    char c;
    cin >> c ;
    
    int * candidate_vertex = new int[N];
    for(int i = 0; i < N; i++){
        candidate_vertex[i] = p[i] + diameter/2;
    }

    // We are maybe on a vertex, or on a side.
    cout << "Calls so far :" << calls << endl;
    cout << "Vertex? :";
    print_point(candidate_vertex);

    
    return p;

}

int * old_move(int* p){
    // Add all coordinates but the first.
    int * next_point = new int [N];
    next_point[0] = p[0];
    for(int i = 1; i < N; i++){
        next_point[i] = p[i] + 1;
    }
    
    // Return closest point to <e_1,...,e_[N-1]>
    for(int j = 1; j < N; j++)
    {
        if(is_in(next_point)) return next_point;
        next_point[j] -- ;
    }
    
    // We are maybe on a vertex
    cout << "vertex? : ";
    print_point(next_point);

    // No more coordinates can be added, now add the first
    next_point[0] ++;

    if(!is_in(next_point)) return p;
    return next_point;

}

bool is_in(int* p){
    
    calls ++;

    double * res = matrix_vector_den(Binv, p, DET);
    
    for(int i = 0; i < N; i++){
        if((res[i] < -0.5)||(res[i]>0.5)) return false;
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

// Computes (1/det)* A * v  
double* matrix_vector_den(int ** A, int* v, int det){

    double * res = new double[N];

    for(int i = 0; i < N; i++){
        res[i] = 0;
        for(int j = 0; j < N; j++){
            res[i] += A[i][j] * v[j];
        }
        res[i] /= det;
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
    cout << "****  END MATRIX  ****" << endl;

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

