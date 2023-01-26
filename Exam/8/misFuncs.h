/*
 * Veronica Bola~nos
 * Materia: Programaci'on I
 *
 */

#ifndef _MIS_FUNCS_H_
#define _MIS_FUNCS_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef double (*f_RenR)(double);
typedef void (*DibujaSegmentos)(double, double, double, double);

double seno(double);
double coseno(double);
double parabola(double);

void grafica(f_RenR f, double, double);
extern DibujaSegmentos dibujaSegmento;


#ifdef __cplusplus
}
#endif

#endif
