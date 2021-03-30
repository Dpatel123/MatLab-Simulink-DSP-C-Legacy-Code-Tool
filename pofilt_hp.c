/*
 ============================================================================
 Name        : pofilt_hp.c
 Author      : Dharmesh Patel
 Version     : V0.a 15.01.2020
 Copyright   : (c) 2020 Univ. Bremerhaven , Kai Mueller
 Description : 2nd order High pass filter - 0.3Hz  (discrete)
 ============================================================================
 */

#include "pofilt_hp.h"

#define BH_0 0.997337820133346
#define BH_1 -1.99467564026669
#define BH_2 0.997337820133346
#define AH_1 -1.99466855305249
#define AH_2 0.994682727480893

typedef struct {
	double b0, b1, b2, a1, a2;
	double u_k1, u_k2, y_k1, y_k2;
}Filterobj;

static Filterobj HP_f;

//Filter for poxi data (High pass 0.3 Hz)
double pofilt_hp(int reset, double u)
{
	double y_out;
	if (reset>0) {
			HP_f.b0 = BH_0;
			HP_f.b1 = BH_1;
			HP_f.b2 = BH_2;
			HP_f.a1 = AH_1;
			HP_f.a2 = AH_2;
			HP_f.u_k1 = 0.0;
			HP_f.u_k2 = 0.0;
			HP_f.y_k1 = 0.0;
			HP_f.y_k2 = 0.0;
			y_out = 0;
		} else {
			y_out = HP_f.b0*u + HP_f.b1*HP_f.u_k1 + HP_f.b2*HP_f.u_k2
			        - HP_f.a1*HP_f.y_k1 - HP_f.a2* HP_f.y_k2;
			HP_f.u_k2 = HP_f.u_k1;
			HP_f.u_k1 = u;
			HP_f.y_k2 = HP_f.y_k1;
			HP_f.y_k1 = y_out;
		}
   return y_out;
}
