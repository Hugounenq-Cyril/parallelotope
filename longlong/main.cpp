#include "main.hpp"

using namespace std;

int secret_vector[N] = {
    20, 2, 0, 2, 0, 2, 0, 1, 1, 2, 0, 2, 2, 1, 2, 2, 2, 2, 1, 2
};
long long secret_vector_inv[N] = 
    {
        58815172414720499,
 -5192774098259369,
 2827366444733629,
 -4942902230130329,
 3435735210471119,
 -5367469937079749,
 3935332910174769,
 -2303977703098129,
 1368798786121479,
 -5184747834799869,
 4362951573960249,
 -4887168250376869,
 -1799568248053721,
 -1684244241172529,
 -2215521144466131,
 -4723162182074549,
 -2715118844169781,
 -4323168768204729,
 -341000589441571,
 -4895194513836369
    };

long long DET = 1111789582730830300;

// size of long long in this implem: 
//              9223372036854775807

int secret_norm = norm(secret_vector);
int diameter; // = (sum_i secret[i])^2 * N
int ** V; 
long long ** Binv = rotation_matrix(secret_vector_inv); 

int * dir = new int[N];

int * vertex = new int[N];

vector<int *> ALREADY_VISITED;

int calls = 0;

int main(int argc, char** argv){

    cout << "*****************\n";
    cout << "Max value: " << numeric_limits<long long>::max() << endl;
    cout << "*****************\n\n";

    cout << "Secret vector, inverse, and determinant" << endl;
    print_point(secret_vector);
    print_point(secret_vector_inv);
    cout << "Determinant = ||sv|| = " << DET << endl << endl << "Secret matrix:\n\n";

    print_matrix(Binv);  

    diameter = 0;
    for(int i = 0; i < N; i++){
        diameter += secret_vector[i];
    }

    for(int i = 0; i < N; i++){
        vertex[i] = secret_vector[i]-diameter/2;
    }
    
    dir[0] = 1;
    
    for(int i = 1; i < N; i++){
        dir[i] = -1;
    }
    
    cout << "\n Target vertices: Rows of the following matrix \n";
    V = rotation_matrix(vertex);
    print_matrix(V);

    for(int i = 0; i < N; i++)
    {
        if(!is_in(V[i])) {
            cout << "not in!" << endl;
            char c;
            cin >> c;
        } 
    }
    
    int * point = new int[N]; //fall(point);
    fall(point);
    return 0;
}


bool victory(int * p){
    for (int i = 0; i < N; i++){
        if(equals(p, V[i])) return true;
    }
    return false;
}

int * fall_orth(int * point){

    cout << "Falling:" << endl;
    print_point(point);

    int * first_bounce = push(point, dir, false);

    int * bounce = new int[N];

    for(int i = 0; i < N; i++){
        bounce[i] = first_bounce[i];
    }    
    int * orth_dir = new int[N];
    orth_dir[0] = 1;

    int bounces = 0;
    for(int i = 1; i < N; i++){
        orth_dir[i] = 1;
        bounce = push(bounce, orth_dir, true);
        orth_dir[i] = 0;
        bounces ++ ;
    }
    cout << "Bounces: " << bounces << endl;

    // Reuse first_bounce to compute medium point

    for(int i = 0; i < N; i++){
        first_bounce[i] =  (first_bounce[i] + bounce[i])/2;
    }

    print_point(bounce);
    //print_point(first_bounce);
    print_point(V[0]);
    if(is_in(first_bounce)) return first_bounce;

    cout << "giving last bounce" << endl;

    return bounce;


}

void fall(int * point){


    if(is_already_visited(point)) return;
    ALREADY_VISITED.push_back(point);
    if(is_far(point)) return;
    
    //char c;
    //cin >> c;
    
    if(victory(point)){
        cout << "VICTORY AFTER " << calls << " CALLS" << endl; 
        print_point(point);
        char c;
        cin >> c;
        return;
    }

    // First push in the direction dir
    int * new_point = new int[N];
    
    for(int i = 0; i < N; i++){
        new_point[i] = point[i] + dir[i];
    }

    if(is_in(new_point)){
        fall(new_point);     
    } 
    
    int * neg_new_point = new int[N];
    int * can_dir = new int[N];

    // Canonic norm-growing directions 
    for(int j = 0; j < N; j++){
        
        can_dir[j] = 1;
    
        new_point = add(point, can_dir);
        neg_new_point = add(point, neg(can_dir));
        if(is_in(new_point) && norm(new_point) > norm(point)){
            fall(new_point);
        } 
        else if(is_in(neg_new_point) && norm(neg_new_point) > norm(point))
        {
            fall(neg_new_point);
        }
        can_dir[j] = 0;
    }    

    // Orthogonal directions (they are of the form e_0+e_j)
    int * orth_dir = new int[N];
    orth_dir[0] = 1;
    for(int j = 1; j < N; j++){
        
        orth_dir[j] = 1;
    
        new_point = add(point, orth_dir);
        neg_new_point = add(point, neg(orth_dir));
        if(is_in(new_point)){
            fall(new_point);
        } 
        else if(is_in(neg_new_point))
        {
            fall(neg_new_point);
        }
        orth_dir[j] = 0;
    }

    //cout << "change" << endl;
}

int norm(int * p){
    int res = 0;
    for(int i = 0; i < N; i++){
        res += (p[i])*(p[i]);
    }
    return res;
}


bool is_far(int * p){
    
    int * a = new int[N];
    a[0] = p[0] - diameter/2;
    for(int i = 1; i < N; i++){
        a[i] = p[i] + diameter/2;
    }

    if(norm(a) > N*diameter*diameter/4){return true;}
    return false;
}


int * push (int * point, int * dir, bool bidirectional){
    int * res = new int[N];
    for(int i = 0; i < N; i++){
        res[i] = point[i];
    }

    while(is_in(res)){
        res = add(res, dir);
    }
    res = add(res, neg(dir));
    
    
    if(!equals(res, point) || !bidirectional) return res;
    
    // Now proceed in the other direction
    while(is_in(res)){
        res = add(res, neg(dir));
    }
    res = add(res, dir);
    return res;
}

bool is_in(int * p){
    
    calls ++;
    cout << calls << endl;
    long long * res = matrix_vector(Binv, p);    

    // if res/DET < -1/2 or > 1/2

    for(int i = 0; i < N; i++){
        if((2*res[i]<-DET)||(2*res[i]>DET)) return false;
    }
    return true;
}


bool equals(int * a, int * b){

    for(int i = 0; i < N; i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}


long long ** rotation_matrix(long long * v){

    long long ** res = new long long *[N];

    for(int i = 0; i < N; i++){
        res[i] = new long long [N];
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


// ATTENTION, this is different (ij -> ji), do NOT use for algebra
int ** rotation_matrix(int * v){

    int ** res = new int *[N];

    for(int i = 0; i < N; i++){
        res[i] = new int [N];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i >= j){
                res[j][i] = v[i - j];
            }
            else{
                res[j][i] = v[i - j + N];
            }
        }
    }
    return res;
}


long long * matrix_vector(long long ** A, int* v){

    long long * res = new long long [N];

    for(int i = 0; i < N; i++){
        res[i] = 0;
        for(int j = 0; j < N; j++){
            res[i] += A[i][j] * v[j];
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

    cout << norm(p) << " | ";
    cout << "(";
    for(int i = 0; i < N-1; i++){

        cout << setw(4);
        cout <<  p[i] << ",";
    }    
    cout << setw(4);
    cout <<  p[N-1] << ")";
    cout << endl;
}


void print_point(long long * p){
    cout << "(";
    int length = (int)log10(DET)+2;
    for(int i = 0; i < N-1; i++){

        cout << setw(length);
        cout <<  p[i] << ",";
    }    
    cout << setw(length);
    cout <<  p[N-1] << ")";
    cout << endl;
}



void print_matrix(int** p){
    
    cout << "**** BEGIN MATRIX ****" << endl;
    int length = 4;
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N-1; i++){
            cout << setw(length);
            cout << p[k][i] << ",";
        }  
        cout << setw(length);
        cout << p[k][N-1] << endl;
    }
    cout << "****  END MATRIX  ****" << endl;

}


void print_matrix(long long ** p){

    cout << "**** BEGIN MATRIX ****" << endl;
    int length = (int)log10(DET)+2;
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N-1; i++){
            cout << setw(length);
            cout << p[k][i] << ",";
        }  
        cout << setw(length);
        cout << p[k][N-1] << endl;
    }
    cout << "****  END MATRIX  ****" << endl;

}


int * add(int * a, int * b){
    
    int * res = new int[N];

    for(int i = 0; i < N; i++){
        res[i] = a[i] + b[i];
    }
    return res;
}

int * neg(int * a){

    int * res = new int[N];

    for(int i = 0; i < N; i++){
        res[i] = -a[i];
    }
    return res;
}

void print_visited(){
    
    cout << "/// ALREADY_VISITED" << endl;
    for (unsigned i=0; i<ALREADY_VISITED.size(); i++)
    print_point(ALREADY_VISITED.at(i));
    cout << "/// END ALREADY_VISITED" << endl;
}

bool is_already_visited(int * p){
    
    
    for (unsigned i=0; i<ALREADY_VISITED.size(); i++)
        if(equals(ALREADY_VISITED.at(i), p)) return true;
    return false;
    
}