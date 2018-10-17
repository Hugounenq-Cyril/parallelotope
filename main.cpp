#include "main.hpp"
#include "keys.hpp"

using namespace std;


int secret_norm = norm(secret_vector);
int diameter; // = (sum_i secret[i])^2 * N


int * dir = new int[N];

int * vertex = new int[N];
int norm_vertex;

vector<int *> ALREADY_VISITED;

int calls = 0;

int main(int argc_mpz, char** argv){

    
    diameter = 0;
    for(int i = 0; i < N; i++){
        diameter += secret_vector[i];
    }

    cout << "Secret vector, inverse, and determinant" << endl;
    print_point(secret_vector);
    print_point(secret_vector_inv);
    cout << "Determinant = ||sv|| = " << DET << endl << endl;
    cout << "Trace: " << diameter << endl;

    char a;
    cin >> a;

    for(int i = 0; i < N; i++){
        vertex[i] = secret_vector[i]-diameter/2;
    }
    norm_vertex = norm(vertex);

    dir[0] = 1;
    
    for(int i = 1; i < N; i++){
        dir[i] = -1;
    }


    int * point = new int[N];
    for(int i = 0; i < N; i++){
        point[i] = 0;
    }
    
    fall(point);
    return 0;
}


bool victory(int * p){

    return equals(p, vertex);

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
    
    if(is_in(first_bounce)) return first_bounce;

    cout << "giving last bounce" << endl;

    return bounce;


}

void fall(int * point){

    
    if(is_already_visited(point)) return;
    ALREADY_VISITED.push_back(point);
    //if(is_far(point)) return;
    
    if(victory(point)){
        cout << "VICTORY AFTER " << calls << " CALLS" << endl; 
        print_point(point);
        char c;
        cin >> c;
        return;
    }

    // Auxiliar arrays

    int * new_point = new int[N];
    int * neg_new_point = new int[N];
    int * dir_point = new int[N];
    int * orth_dir = new int[N];
    int * can_dir = new int[N];
   
   // 1. Push in the direction dir = (1,-1,-1, etc)
    
    dir_point = add(point, dir);
    for(int i = 0; i < N; i++){
        dir_point[i] = point[i] + dir[i];
    }

    if(is_in(dir_point)){
        fall(dir_point);     
    } 

    // Canonic norm-growing directions 
    
    int * final_point = new int[N];

    set(final_point, point);

    for(int j = 0; j < N; j++){
        
        can_dir[j] = 1;
    
        new_point = add(final_point, can_dir);
        neg_new_point = add(final_point, neg(can_dir));
        if(is_in(neg_new_point) && norm(neg_new_point) > norm(final_point))
        {
            //fall(neg_new_point);
            set(final_point, neg_new_point);
        }
        else if(is_in(new_point) && norm(new_point) > norm(final_point)){
            //fall(new_point);
            final_point = add(final_point, new_point);
            set(final_point, new_point);
        }
        can_dir[j] = 0;
    }    
    fall(final_point);

    // Orthogonal directions (they are of the form e_0+e_j)
    
    orth_dir[0] = 1;
    for(int j = 1; j < N; j++){
        
        orth_dir[j] = 1;
    
        new_point = add(point, orth_dir);
        neg_new_point = add(point, neg(orth_dir));
        if(is_in(neg_new_point))
        {
            fall(neg_new_point);
        }
        else if(is_in(new_point)){
            fall(new_point);
        } 
        orth_dir[j] = 0;
    }

    delete[] new_point;
    delete[] neg_new_point;
    delete[] can_dir;
    delete[] orth_dir;
    delete[] dir_point;
    
 
    cout << "dead end" << endl;
    print_point(point);
    cout << "vertex:" << endl;
    print_point(vertex);
    //char b;
    //cin >> b;
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

    //if(norm(a) > N*diameter*diameter/4){return true;}
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


void set(int * a, int * b){
    for(int i = 0; i < N; i++){
        a[i] = b[i];
    }
}
bool is_in(int * p){
    
    calls ++;
    double percent_d = (double) norm(p) / norm_vertex;
    percent_d = sqrt(percent_d); 
    int percent = (int)100*percent_d;
    cout << calls << " , " << ALREADY_VISITED.size() << " , " << percent << " %" << endl;
    
    mpz_class * res = poly_mult(secret_vector_inv, p);
    
    // if res/DET < -1/2 or > 1/2

    for(int i = 0; i < N; i++){
        if(cmp( 2 * res[i], - DET) < 0 || cmp( 2 * res[i], DET) > 0)
            return false;
    }
    return true;
}


bool equals(int * a, int * b){

    for(int i = 0; i < N; i++){
        if(a[i]!=b[i]) return false;
    }
    return true;
}


mpz_class ** rotation_matrix(mpz_class * v){

    mpz_class ** res = new mpz_class *[N];

    for(int i = 0; i < N; i++){
        res[i] = new mpz_class[N];
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
int ** vertex_matrix(int * v){

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

// Unefficient
mpz_class * matrix_vector(mpz_class ** A, int* v){

    mpz_class * res = new mpz_class [N];

    for(int i = 0; i < N; i++){
        res[i] = 0;
        for(int j = 0; j < N; j++){
            res[i] += A[i][j] * v[j];
        }
    }
    return res;    
}


mpz_class * poly_mult(mpz_class * x, int* y){

    mpz_class * res = new mpz_class [N];

    for(int i = 0; i < N; i++){
        res[i] = 0;
    }


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res[(i + j) % N] += x[i] * y[j];
        }
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


void print_point(mpz_class * p){
    cout << "(";
    for(int i = 0; i < N-1; i++){

        cout << setw(LENGTH);
        cout <<  p[i] << ",";
    }    
    cout << setw(LENGTH);
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


void print_matrix(mpz_class ** p){

    cout << "**** BEGIN MATRIX ****" << endl;
    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N-1; i++){
            cout << setw(LENGTH);
            cout << p[k][i] << ",";
        }  
        cout << setw(LENGTH);
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