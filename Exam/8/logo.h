/*
 * Veronica Bola~nos
 * Materia: Programaci'on I
 *
 */

#ifndef _MI_LOGO_H_
#define _MI_LOGO_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#define ARRIBA 0
#define ABAJO !(ARRIBA)

#ifndef G2R
#  define G2R (M_PI/180.0)
#endif

typedef int (*misFractales)(void);

typedef struct _logo_{
  double x, y;
  char pluma;
  int grados;
  void (*dibujaSegmento)(double, double, double, double);
}LOGO;

int asignaModoDibujarSegmento(void (*dibujaSegmento)(double, double, double, double), LOGO* tortuga);
int inicia(double x, double y, int grados, char pluma, LOGO* tortuga);
int der(int g, LOGO* tortuga);
int izq(int g, LOGO* tortuga);
int avanza(double l, LOGO* tortuga);
int retrocede(double l, LOGO* tortuga);



#ifdef __cplusplus
}
#endif

#endif
