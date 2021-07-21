#ifndef bipng_escribir_buf
  #define bipng_escribir_buf bipng_buf
#endif
#ifndef bipng_escribir_fpng
  #define bipng_escribir_fpng bipng_fpng
#endif
#ifndef bipng_escribir_al
  #define bipng_escribir_al bipng_al
#endif
#ifndef bipng_escribir_an
  #define bipng_escribir_an bipng_an
#endif
#ifndef bipng_escribir_tipoco
  #define bipng_escribir_tipoco bipng_tipoco
#endif
#ifndef bipng_escribir_profbt
  #define bipng_escribir_profbt bipng_profbt
#endif
#ifndef bipng_escribir_eses
  #define bipng_escribir_eses bipng_eses
#endif
#ifndef bipng_escribir_esif
  #define bipng_escribir_esif bipng_esif
#endif
#ifndef bipng_escribir_gamma
  #define bipng_escribir_gamma bipng_gamma
#endif

bipng_escribir_fpng=fopen(bipng_escribir_nom,"wb");
biex(!bipng_escribir_fpng,"Er:!bipng_escribir_fpng\n");
bipng_escribir_eses = png_create_write_struct(PNG_LIBPNG_VER_STRING,0,0,0);
biex(!bipng_escribir_eses,"Er:!bipng_escribir_eses\n");
bipng_escribir_esif = png_create_info_struct(bipng_escribir_eses);
biex(!bipng_escribir_eses,"Er:!bipng_escribir_esif\n");
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:init_io\n");
png_init_io(bipng_escribir_eses, bipng_escribir_fpng);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:set_IHDR\n");
png_set_IHDR
( bipng_escribir_eses,
  bipng_escribir_esif,
  bipng_escribir_an,
  bipng_escribir_al,
  bipng_escribir_profbt,
  bipng_escribir_tipoco,
  0,0,0
);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:set_gAMA\n");
png_set_gAMA(bipng_escribir_eses, bipng_escribir_esif,bipng_escribir_gamma);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:write_info\n");
png_write_info(bipng_escribir_eses, bipng_escribir_esif);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:write_image\n");
png_write_image(bipng_escribir_eses, bipng_escribir_buf);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:write_end\n");
png_write_end(bipng_escribir_eses,0);
fclose(bipng_escribir_fpng);
biex(setjmp(png_jmpbuf(bipng_escribir_eses)),"Er:destroy_write_struct\n");
png_destroy_write_struct(&bipng_escribir_eses,&bipng_escribir_esif);
