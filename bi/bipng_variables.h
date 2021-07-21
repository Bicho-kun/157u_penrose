#ifndef bipng_fpng
  FILE*bipng_fpng;
#endif
#ifndef bipng_eses
  png_structp bipng_eses;
#endif
#ifndef bipng_esif
  png_infop bipng_esif;
#endif
#ifndef bipng_indx
  register int bipng_indx; //índice, p.ej. buf[i]
#endif
#ifndef bipng_al
  png_uint_32 bipng_al=360;
#endif
#ifndef bipng_an
  png_uint_32 bipng_an=640;
#endif
#ifndef bipng_profbt
  int bipng_profbt=8;
#endif
#ifndef bipng_reng
  png_uint_32 bipng_reng=(bipng_an*3);
#endif
#ifndef bipng_gamma
  double bipng_gamma=45/99.;
#endif
#ifndef bipng_tipoco
  int bipng_tipoco=PNG_COLOR_TYPE_RGB;
#endif
#ifndef bipng_no_apartar
  #include<bi/bipng_apartar.h>
#endif
#ifndef bipng_leer_cabez
  png_byte bipng_leer_cabez[8];
#endif
