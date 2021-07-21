#include<math.h>
#include"penrose.h"
#define bipng_an 640
#define bipng_al 360
void gen_vertices(double**);
void pinta_color(Color,int,int,png_byte**);
int triango(double*x,double*a,double*b,double*c)
{ return(
  cruzo(a,b,x) &&
  cruzo(b,c,x) &&
  cruzo(c,a,x)
  );
  
}

int main(int narg,char**a){
  biey(narg<2,"%s <salida.png>\n",a[0]);
  #include"./bi/bipng_variables.h"
  #define bipng_escribir_nom a[1]
  double v[3][2];
  double x[2];
  int i,j,k;
  triang_param p;
  bpf("Con\n");
  //gen_vertices((double**)v);
  
  v[0][0]=-640;
  v[0][1]=-bipng_al;
  v[1][0]=860;
  v[1][1]=-bipng_al;
  v[2][0]=1500*cos(M_PI/5)-640;
  v[2][1]=1500*sin(M_PI/5)-bipng_al;
  bpf("Hola\n");
  //return 0;
  p.ori=0;
  p.a=v[0];
  p.b=v[1];
  p.c=v[2];
  p.x=x;
  p.niv=9;
  fo(i,bipng_al){
    x[1]=-i;
    fo(j,bipng_an){
      x[0]=j;
      if(i==29&&j==45)printf("%lf,%lf\n",p.c[0],p.c[1]);
      if(triango(x,p.a,p.b,p.c))
        pinta_color(p_lu(p),i,j,bipng_buf);
      else fo(k,3)bipng_buf[i][3*j+k]=0;
        
    }
  }
  
  #include"./bi/bipng_escribir.h"
  free(bipng_buf[0]);
  free(bipng_buf);
  return 0;
}

void gen_vertices(double**v){
  v[0][0]=0;v[2][1]=0;
  v[0][1]=v[1][1]=-bipng_al;
  v[1][0]=v[2][0]=bipng_an;
}


inline void pinta_color(Color col,int i,int j,png_byte**buf){
  int k;
  fo(k,3)buf[i][3*j+k]=col.c[k];
}
