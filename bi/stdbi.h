#ifndef STDBI_H
  #define STDBI_H
  #include<stdio.h>
  #include<stdlib.h>
  #include<stdarg.h>
  #include<unistd.h>
  #include<time.h>

  #ifndef birrrtam
    #define birrrtam 500
  #endif
  char RrR[birrrtam];
  int bpf(const char*tx,...)
  { va_list args;
    va_start(args,tx);
    int y=vsprintf(RrR,tx,args);
    va_end(args);
    write(1,RrR,y);
    return y;
  }
  #define bpc(d) {RrR[0]=(d);write(1,RrR,1);}

  #define fo(a,b) for(a=0;a<b;a++)
  #define of(a,b) for(a=b;a--;)

  int bieret=1;
  #define biex(a,s); {if(a){bpf("%s",s); return bieret;}}
  void biey(int si,const char* __restrict__ tx,...)
  { if(!si)return;//Salir con un formato especial.
    va_list args;
    va_start(args,tx);
    int y=vsprintf(RrR,tx,args);
    va_end(args);
    write(2,RrR,y);
    exit(bieret);
  }

  typedef unsigned int   unt;
  typedef unsigned short ush;
  typedef unsigned char  uch;
  #define rin register int
  #define rch register char

  #define may(a,b,c);   {a=(b*)malloc((c)*sizeof(b));biex(!a,"Err May");}
  #define mayy(a,b,c);  b*a=(b*)malloc((c)*sizeof(b));biex(!a,"Err May");

  #define alea() srand(time(NULL))

#endif
