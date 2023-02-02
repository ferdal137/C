#ifndef _NEWRAPL_
#define _NEWRAPL_

#ifdef __cplusplus
extern "C" {
#endif

Inter obtenerIntervalos(FILE *f);
double RapNew(double a, double b, Rx f);
Inter obtenerRaices(Inter J, Rx f);
void escribirRaices(FILE *f, Inter J);

#ifdef __cplusplus
}
#endif

#endif