#include "main.hpp"

double ** ORTH;
bool FIRST_TIME = true;

using namespace std;

int main(int argc, char** argv){

	srand(time(NULL));

  // CENTER
  double center[N] = {};

  // ORTHONORMAL DIRECTIONS
  double * initial_dir  = new double [N];
  double * initial_dir2 = new double [N];

  /*
  for(int i = 0; i < N; i++){
    initial_dir[i] = rand() % 1100 - 500;
  }
  */

  char a;

  for(int i=0; i < N; i++){
    if(i==0){initial_dir[i]=RADIO/2;}
    else{initial_dir[i]=RADIO;}
    initial_dir2[i]+=initial_dir[i]+((double)(rand()%7-3));
  }
  
  double * v1 = fallnew(center,initial_dir);
  cin >> a;
  
  double * v2 = fallnew(center,initial_dir2);
  cin >> a;

  double *new_dir = half(v1,v2);

  cout << "new dir:"<<endl;
  print_point(new_dir);

  cout << "vertex:"<<endl;
  print_point(fallnew(center,new_dir));

  return 0;

}


double * fallnew(double *start, double *dir)
{

  FIRST_TIME= true;
  ORTH = gram_schmidt_orth(dir);
  char a;

  cout << "START"<<endl;
  print_point(start);
  print_point(dir);

  double ** gs = gram_schmidt_orth(dir);
  cout << endl<<endl<< "DIRECTIONS:"<< endl<<endl;
  print_matrix(gs);
  cout <<endl<< "ORTHONORMAL: "<< is_orthonormal(gs)<<endl<<endl;
  cin >> a;
  double * prev_point = start;
  double * next = next_point(prev_point);
  print_point(next);
  cout << "norm: " << norm(next)<<endl; 

  while(diff(prev_point,next)){

    prev_point = next;
    next = next_point(prev_point);
    print_point(next);
    cout << "norm: " << norm(next)<<endl; 

    //cin >> a;

  }
  
  double * v1 = next;
  cout << "final point:"<<endl;
  print_point(v1);
  return v1;
}

double * fall(double *start, double *dir){

  double * current_point = binary_move(start,dir);
  double * previous_point = start;
  print_point(previous_point);
  print_point(current_point);
  

  

  while(diff(current_point,previous_point)){

    previous_point = current_point;
    current_point = next_point(current_point);
    print_point(current_point);
  }

  double * vertex = new double[N];
  for(int i = 0;i < N; i++){
    vertex[i]=current_point[i];
  }  
  return vertex;
}

double * fallOld(double *dir){

  double * current_dir = dir;
  double * prev_dir = new double [N];

  int cont = 0;

  while(diff(current_dir,prev_dir)){
    cout << "FALL #" << cont <<endl;
    cont++;
    prev_dir = current_dir;
    current_dir = next_dir(current_dir);
    print_point(current_dir);
  }

  double * vertex = new double[N];
  for(int i = 0;i < N; i++){
    vertex[i]=current_dir[i];
  }  
  return vertex;
}


bool is_orthonormal(double **m)
{
  for(int i = 0;i < N;i++)
  {
    for(int j = i+1;j < N; j++)
    {
      if(abs(inner_prod(m[i],m[j]))>0.000001){

        cout << "ERROR NORMA NO ORTOGONALES "<<i << " "<<j<<endl;
        return false;
      } 
    }
  }
  for(int i = 0; i < N; i++)
  {
    if(abs(norm(m[i])-1)>0.000001)
    {
      cout << "ERROR NORMA NO UNO"<<endl;
      return false;
    } 
  }
  return true;
}




double * next_point_static(double * start){


  double * x[N];
  double ** gs;
  gs = ORTH;
  if(FIRST_TIME){
    x[0] = binary_move(start, ORTH[0]);
    FIRST_TIME = false;
  }
  else{
    x[0] = binary_move(start, start);

  }
  int i;
  double * opposite = new double [N];
  cout << "MATRIX (static):"<<endl;
  print_matrix(gs);
  cout <<endl;
  cout << "0: "; print_point(x[0]);
  for(i=1;i<N;i++){

    if(test_neighbour(x[i-1],gs[i])==1){

      x[i] = binary_move(x[i-1],gs[i]); 
    }
    else{
      //opposite = gs[i];
      for(int j = 0; j < N; j++){
        opposite[j]= - gs[i][j];
      }
      x[i] = binary_move(x[i-1],opposite);
    }
    cout << i << ": "; print_point(x[i]);
  }
  double *y = new double [N];
  for(i=0;i<N;i++)
  {
    y[i]=(x[N-1][i]+x[0][i])/2;
  }
  return y;
} 

double * next_point(double * start){


  double * x[N];
  double ** gs;
  if(FIRST_TIME){
    x[0] = binary_move(start, ORTH[0]);
    gs = ORTH;
    FIRST_TIME = false;
  }
  else{
    x[0] = binary_move(start, start);
    gs = gram_schmidt_orth(start);
  }
  int i;
  double * opposite = new double [N];
  cout << "MATRIX:"<<endl;
  print_matrix(gs);
  cout <<endl;
  cout << "0: "; print_point(x[0]);
  for(i=1;i<N;i++){

    if(test_neighbour(x[i-1],gs[i])==1){

      x[i] = binary_move(x[i-1],gs[i]); 
    }
    else{
      //opposite = gs[i];
      for(int j = 0; j < N; j++){
        opposite[j]= - gs[i][j];
      }
      x[i] = binary_move(x[i-1],opposite);
    }
    cout << i << ": "; print_point(x[i]);
  }
  double *y = new double [N];
  for(i=0;i<N;i++)
  {
    y[i]=(x[N-1][i]+x[0][i])/2;
  }
  return y;
} 


double * next_dir(double * dir){

	double ** gs = gram_schmidt_orth(dir);

 cout << "sanity "<< is_orthonormal(gs)<< endl;

 double center[N] = {};
 double * x[N];

 x[0] = binary_move(center, gs[0]);

  //print_point(x[0]);

 double * opposite = new double [N];
 int i;
 int cont_indep = 0;



 for(i=1;i<N;i++){

  opposite = gs[i];
  if(test_neighbour(x[i-1],gs[i])==1){
    x[i] = binary_move(x[i-1],gs[i]); 
  }
  else if (test_neighbour(x[i-1],gs[i])==-1){
    for(int j = 0; j < N; j++){
      opposite[j]*=-1;
    }
    x[i] = binary_move(x[i-1],opposite);
  }
  else {
    x[i] = x[i-1];
    cout << "atascado:"<<endl;
    print_point(x[i-1]);
    cout << "en direccion:"<<endl;
    print_point(gs[i]);
  }

  if(diff(x[i],x[i-1]))
  {
    cont_indep++;	
  } 
}

double *y = new double [N];
for(i=0;i<N;i++)
{
  y[i]=(x[N-1][i]+x[0][i])/2;
}
cout << "independence :"<< cont_indep <<endl;
return y;
} 

int test_neighbour(double * point, double * dir)
{
	double * unitary = normalized(dir);
	double * neighbour1 = new double [N];
	double * neighbour2 = new double [N];
	
	for(int i=0;i<N;i++)
	{
		neighbour1[i] = (point[i] + unitary[i]/100);
		neighbour2[i] = (point[i] - unitary[i]/100);
	}

	if(is_in(neighbour1)) {return 1;}
	/*cout << "OUT 1:";
	print_point(neighbour1);
*/
	if(is_in(neighbour2)) {return -1;}
	/*cout << "OUT 2:";
	print_point(neighbour2);
	*/
	return 0;
}


bool is_in(double* p){
	for(int i = 0; i < N; i++){
		if(abs(p[i]) > RADIO) return false;
	}
	return true;
}


double* half(double* p1, double* p2){
	double* p3 = new double[N];
	for(int i = 0; i < N; i++){
		p3[i] = (p1[i] + p2[i]) / 2;
	}
	return p3;
}

bool diff(double* p1, double* p2){
  for(int i=0; i < N; i++){
    if(abs(p1[i] - p2[i])>0.01) return true;
  }
  return false;
}


bool diffR(double* p1, double* p2){
  for(int i=0; i < N; i++){
    if(abs(p1[i] - p2[i])>0) return true;
  }
  return false;
}

double* binary_move(double* p, double* dir){

	double* pin = p;
	double* pout = new double[N];

  for(int i = 0; i < N; i ++){
    pout[i] = p[i] + dir[i] * D;
  }

  double* phalf = new double[N];
  phalf = half(pin, pout);
  while(diffR(pin, phalf)){
		//cout << phalf[0] << " ";
    if(is_in(phalf)){
			//coutneigh << "in" << endl;
     pin = phalf;
   }
   else{
     pout = phalf;
			//cout << "out" << endl;
   }
   phalf = half(pin, pout);
 }
 return phalf;
}


double* normalized(double* p){
	double suma = 0;
	for(int i = 0; i < N; i++){
		suma += p[i] * p[i];
	}
	double norma = sqrt(suma);
	double* d = new double[N];
	for(int i = 0; i < N; i++){
		d[i] = p[i] / norma; 
	}
	return d;
}

void print_point(double* p){
	for(int i = 0; i < N; i++){
		cout <<  p[i] << ",";
	}
	cout << endl;
}


void print_matrix(double** p){
  for(int k = 0; k < N; k++)
  {
    for(int i = 0; i < N; i++){
      cout << p[k][i] << ",";
    }  
    cout << endl;
  }
}

double** gram_schmidt(double* dir){
	
	double** u = new double*[N];
	double** v = new double*[N];
	
	v[0] = dir;
	
	//double norma_init = norm(dir);

	for(int i = 1; i < N; i++)
	{
		v[i] = new double[N];
		for(int l = 0;l < N; l++)
		{
			v[i][l]=rand()%(2*D);
		}
	}

	u[0]= new double[N];
	for(int i = 0; i < N; i++)
	{
		u[0][i]=v[0][i];
	}

	for(int k = 1; k < N; k++)
	{
		u[k]= new double[N];
		for(int i = 0; i < N; i++)
		{
			u[k][i]=v[k][i];

		}
		//print_point(u[k]);

		for(int j = 0; j < k; j++)
		{

			double num = inner_prod(u[j],v[k]);
			double den = norm(u[j])*norm(u[j]);
			for(int i = 0; i < N; i++)
			{
				u[k][i] -= (u[j][i] * num) / den; 
			}			
		}
	}
	return u;
}


double** gram_schmidt_orth(double* dir){
	
	double** matrix = gram_schmidt(dir);

	for(int l = 0; l < N; l++)
	{
		matrix[l]=normalized(matrix[l]);
	}
	return matrix;
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

