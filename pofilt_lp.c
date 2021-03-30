/*
 ============================================================================
 Name        : pofilt_lp.c
 Author      : Dharmesh Patel
 Version     : V0.a 15.01.2020
 Copyright   : (c) 2020 Univ. Bremerhaven , Kai Mueller
 Description : 2nd order Low pass filter - 6Hz  (discrete)
 ============================================================================
 */

#include "pofilt_lp.h"

#define BL_0 0.00134871194835634
#define BL_1 0.00269742389671268
#define BL_2 0.00134871194835634
#define AL_1 -1.89346414636183
#define AL_2 0.898858994155252

typedef struct {
	double b0, b1, b2, a1, a2;
	double u_k1, u_k2, y_k1, y_k2;
}Filterobj;

static Filterobj LP_f;

//Filter for poxi data (Low pass 6 Hz)
double pofilt_lp(int reset, double u)
{
	double y_out;
	if (reset>0) {
			LP_f.b0 = BL_0;
			LP_f.b1 = BL_1;
			LP_f.b2 = BL_2;
			LP_f.a1 = AL_1;
			LP_f.a2 = AL_2;
			LP_f.u_k1 = 0.0;
			LP_f.u_k2 = 0.0;
			LP_f.y_k1 = 0.0;
			LP_f.y_k2 = 0.0;
			y_out = 0.0;
		} else {
			y_out = LP_f.b0*u + LP_f.b1*LP_f.u_k1 + LP_f.b2*LP_f.u_k2
			        - LP_f.a1*LP_f.y_k1 - LP_f.a2* LP_f.y_k2;
			LP_f.u_k2 = LP_f.u_k1;
			LP_f.u_k1 = u;
			LP_f.y_k2 = LP_f.y_k1;
			LP_f.y_k1 = y_out;
		}
   return y_out;
}
