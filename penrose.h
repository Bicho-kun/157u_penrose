#include<stdio.h>
#include<png.h>
#include<malloc.h>
#include"./bi/stdbi.h"
#define phi1 0.6180339887498948482045868343656381177203091798057628621354486227052604628189L
#define phi2 0.3819660112501051517954131656343618822796908201942371378645513772947395371811L

typedef struct{
  unsigned char c[3];
} Color;
// Esta estructura representa un color. Permite caracterizarlo de manera abstracta con una estructura.


typedef struct{
  unsigned int ori:1; // Orientación, para efecto del producto cruz: ori=0
  int niv;  // Nivel de conmplejidad niv=0,1,...
  Color col;// Color padre
  double*a;
  double*b;
  double*c;
  double*x;
} triang_param;
// Esta estructura permite a las funciones p_lu y p_ma definir el color de la posición x usando sus parámetros.

Color p_lu(triang_param);
Color p_ma(triang_param);

int cruzo(double*a, double*b, double*o){
  return ((a[0]-o[0])*(b[1]-o[1])-(a[1]-o[1])*(b[0]-o[0]))>0;
}
Color p_lu(triang_param p){
  if(p.niv<1){
    // Aquí va la modificación inicial de color.
    if(p.ori){
      p.col.c[0]=30;
      p.col.c[1]=80;
      p.col.c[2]=250;
    } else {
      p.col.c[0]=30;
      p.col.c[1]=50;
      p.col.c[2]=250;
    }
    return p.col;
  }
  double t[2];
  double d[2];
  int i;
  p.niv--;
  fo(i,2){ // Estableciendo los vectores t[] y d[] definidos en el cuaderno.
    d[i]=phi1*p.c[i]+phi2*p.a[i];
    t[i]=phi1*p.a[i]+phi2*p.b[i];
  }
  if( p.ori^cruzo(d,p.x,t) ){ //si x es rosita...
    p.ori^=1;
    p.b=d;
    p.c=t;
    p.col=p_ma(p);
    //Aquí va modificación local de color.
    return p.col;
  }
  else { //Si x es alguno de los lu...
    p.a=p.b; // En el peor caso p.a <- p.b <- p.c <- d.
    if( p.ori^cruzo(d,p.x,p.b) ){ //si x es verde...
      p.ori^=1;
      p.b=t;
    }
    else {
      p.b=p.c;
    }
    p.c=d;
    p.col=p_lu(p);
    //Aquí va modificación local de color.
    return p.col;
  }
}

Color p_ma(triang_param p){
  if(p.niv<1){
    // Aquí va la modificación inicial de color.
    if(p.ori){
      p.col.c[0]=150;
      p.col.c[1]=80;
      p.col.c[2]=250;
    } else {
      p.col.c[0]=150;
      p.col.c[1]=50;
      p.col.c[2]=250;
    }
    return p.col;
  }
  double t[2];
  int i;
  p.niv--;
  fo(i,2){ // Estableciendo los vectores t[] y d[] definidos en el cuaderno.
    t[i]=phi1*p.b[i]+phi2*p.a[i];
  }
  if( p.ori^cruzo(p.c,p.x,t) ){ //si x es azul...
    p.b=t;
    p.col=p_lu(p);
    //Aquí va modificación local de color.
    return p.col;
  }
  else { //Si x es morado
    p.a=p.b; // En el peor caso p.a <- p.b <- p.c <- d.
    p.b=p.c;
    p.c=t;
    p.col=p_ma(p);
    //Aquí va modificación local de color.
    return p.col;
  }
}





