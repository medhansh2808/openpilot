#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_5195967926175737340) {
   out_5195967926175737340[0] = delta_x[0] + nom_x[0];
   out_5195967926175737340[1] = delta_x[1] + nom_x[1];
   out_5195967926175737340[2] = delta_x[2] + nom_x[2];
   out_5195967926175737340[3] = delta_x[3] + nom_x[3];
   out_5195967926175737340[4] = delta_x[4] + nom_x[4];
   out_5195967926175737340[5] = delta_x[5] + nom_x[5];
   out_5195967926175737340[6] = delta_x[6] + nom_x[6];
   out_5195967926175737340[7] = delta_x[7] + nom_x[7];
   out_5195967926175737340[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_5038352358272318907) {
   out_5038352358272318907[0] = -nom_x[0] + true_x[0];
   out_5038352358272318907[1] = -nom_x[1] + true_x[1];
   out_5038352358272318907[2] = -nom_x[2] + true_x[2];
   out_5038352358272318907[3] = -nom_x[3] + true_x[3];
   out_5038352358272318907[4] = -nom_x[4] + true_x[4];
   out_5038352358272318907[5] = -nom_x[5] + true_x[5];
   out_5038352358272318907[6] = -nom_x[6] + true_x[6];
   out_5038352358272318907[7] = -nom_x[7] + true_x[7];
   out_5038352358272318907[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4148079720927220714) {
   out_4148079720927220714[0] = 1.0;
   out_4148079720927220714[1] = 0.0;
   out_4148079720927220714[2] = 0.0;
   out_4148079720927220714[3] = 0.0;
   out_4148079720927220714[4] = 0.0;
   out_4148079720927220714[5] = 0.0;
   out_4148079720927220714[6] = 0.0;
   out_4148079720927220714[7] = 0.0;
   out_4148079720927220714[8] = 0.0;
   out_4148079720927220714[9] = 0.0;
   out_4148079720927220714[10] = 1.0;
   out_4148079720927220714[11] = 0.0;
   out_4148079720927220714[12] = 0.0;
   out_4148079720927220714[13] = 0.0;
   out_4148079720927220714[14] = 0.0;
   out_4148079720927220714[15] = 0.0;
   out_4148079720927220714[16] = 0.0;
   out_4148079720927220714[17] = 0.0;
   out_4148079720927220714[18] = 0.0;
   out_4148079720927220714[19] = 0.0;
   out_4148079720927220714[20] = 1.0;
   out_4148079720927220714[21] = 0.0;
   out_4148079720927220714[22] = 0.0;
   out_4148079720927220714[23] = 0.0;
   out_4148079720927220714[24] = 0.0;
   out_4148079720927220714[25] = 0.0;
   out_4148079720927220714[26] = 0.0;
   out_4148079720927220714[27] = 0.0;
   out_4148079720927220714[28] = 0.0;
   out_4148079720927220714[29] = 0.0;
   out_4148079720927220714[30] = 1.0;
   out_4148079720927220714[31] = 0.0;
   out_4148079720927220714[32] = 0.0;
   out_4148079720927220714[33] = 0.0;
   out_4148079720927220714[34] = 0.0;
   out_4148079720927220714[35] = 0.0;
   out_4148079720927220714[36] = 0.0;
   out_4148079720927220714[37] = 0.0;
   out_4148079720927220714[38] = 0.0;
   out_4148079720927220714[39] = 0.0;
   out_4148079720927220714[40] = 1.0;
   out_4148079720927220714[41] = 0.0;
   out_4148079720927220714[42] = 0.0;
   out_4148079720927220714[43] = 0.0;
   out_4148079720927220714[44] = 0.0;
   out_4148079720927220714[45] = 0.0;
   out_4148079720927220714[46] = 0.0;
   out_4148079720927220714[47] = 0.0;
   out_4148079720927220714[48] = 0.0;
   out_4148079720927220714[49] = 0.0;
   out_4148079720927220714[50] = 1.0;
   out_4148079720927220714[51] = 0.0;
   out_4148079720927220714[52] = 0.0;
   out_4148079720927220714[53] = 0.0;
   out_4148079720927220714[54] = 0.0;
   out_4148079720927220714[55] = 0.0;
   out_4148079720927220714[56] = 0.0;
   out_4148079720927220714[57] = 0.0;
   out_4148079720927220714[58] = 0.0;
   out_4148079720927220714[59] = 0.0;
   out_4148079720927220714[60] = 1.0;
   out_4148079720927220714[61] = 0.0;
   out_4148079720927220714[62] = 0.0;
   out_4148079720927220714[63] = 0.0;
   out_4148079720927220714[64] = 0.0;
   out_4148079720927220714[65] = 0.0;
   out_4148079720927220714[66] = 0.0;
   out_4148079720927220714[67] = 0.0;
   out_4148079720927220714[68] = 0.0;
   out_4148079720927220714[69] = 0.0;
   out_4148079720927220714[70] = 1.0;
   out_4148079720927220714[71] = 0.0;
   out_4148079720927220714[72] = 0.0;
   out_4148079720927220714[73] = 0.0;
   out_4148079720927220714[74] = 0.0;
   out_4148079720927220714[75] = 0.0;
   out_4148079720927220714[76] = 0.0;
   out_4148079720927220714[77] = 0.0;
   out_4148079720927220714[78] = 0.0;
   out_4148079720927220714[79] = 0.0;
   out_4148079720927220714[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_2457004505259509534) {
   out_2457004505259509534[0] = state[0];
   out_2457004505259509534[1] = state[1];
   out_2457004505259509534[2] = state[2];
   out_2457004505259509534[3] = state[3];
   out_2457004505259509534[4] = state[4];
   out_2457004505259509534[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_2457004505259509534[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_2457004505259509534[7] = state[7];
   out_2457004505259509534[8] = state[8];
}
void F_fun(double *state, double dt, double *out_6660883876973656350) {
   out_6660883876973656350[0] = 1;
   out_6660883876973656350[1] = 0;
   out_6660883876973656350[2] = 0;
   out_6660883876973656350[3] = 0;
   out_6660883876973656350[4] = 0;
   out_6660883876973656350[5] = 0;
   out_6660883876973656350[6] = 0;
   out_6660883876973656350[7] = 0;
   out_6660883876973656350[8] = 0;
   out_6660883876973656350[9] = 0;
   out_6660883876973656350[10] = 1;
   out_6660883876973656350[11] = 0;
   out_6660883876973656350[12] = 0;
   out_6660883876973656350[13] = 0;
   out_6660883876973656350[14] = 0;
   out_6660883876973656350[15] = 0;
   out_6660883876973656350[16] = 0;
   out_6660883876973656350[17] = 0;
   out_6660883876973656350[18] = 0;
   out_6660883876973656350[19] = 0;
   out_6660883876973656350[20] = 1;
   out_6660883876973656350[21] = 0;
   out_6660883876973656350[22] = 0;
   out_6660883876973656350[23] = 0;
   out_6660883876973656350[24] = 0;
   out_6660883876973656350[25] = 0;
   out_6660883876973656350[26] = 0;
   out_6660883876973656350[27] = 0;
   out_6660883876973656350[28] = 0;
   out_6660883876973656350[29] = 0;
   out_6660883876973656350[30] = 1;
   out_6660883876973656350[31] = 0;
   out_6660883876973656350[32] = 0;
   out_6660883876973656350[33] = 0;
   out_6660883876973656350[34] = 0;
   out_6660883876973656350[35] = 0;
   out_6660883876973656350[36] = 0;
   out_6660883876973656350[37] = 0;
   out_6660883876973656350[38] = 0;
   out_6660883876973656350[39] = 0;
   out_6660883876973656350[40] = 1;
   out_6660883876973656350[41] = 0;
   out_6660883876973656350[42] = 0;
   out_6660883876973656350[43] = 0;
   out_6660883876973656350[44] = 0;
   out_6660883876973656350[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_6660883876973656350[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_6660883876973656350[47] = -dt*stiffness_front*state[0]/state[1];
   out_6660883876973656350[48] = -dt*stiffness_front*state[0]/state[1];
   out_6660883876973656350[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_6660883876973656350[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_6660883876973656350[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_6660883876973656350[52] = dt*stiffness_front*state[0]/state[1];
   out_6660883876973656350[53] = -9.8100000000000005*dt;
   out_6660883876973656350[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_6660883876973656350[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_6660883876973656350[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6660883876973656350[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6660883876973656350[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_6660883876973656350[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_6660883876973656350[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_6660883876973656350[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_6660883876973656350[62] = 0;
   out_6660883876973656350[63] = 0;
   out_6660883876973656350[64] = 0;
   out_6660883876973656350[65] = 0;
   out_6660883876973656350[66] = 0;
   out_6660883876973656350[67] = 0;
   out_6660883876973656350[68] = 0;
   out_6660883876973656350[69] = 0;
   out_6660883876973656350[70] = 1;
   out_6660883876973656350[71] = 0;
   out_6660883876973656350[72] = 0;
   out_6660883876973656350[73] = 0;
   out_6660883876973656350[74] = 0;
   out_6660883876973656350[75] = 0;
   out_6660883876973656350[76] = 0;
   out_6660883876973656350[77] = 0;
   out_6660883876973656350[78] = 0;
   out_6660883876973656350[79] = 0;
   out_6660883876973656350[80] = 1;
}
void h_25(double *state, double *unused, double *out_8846235545148926018) {
   out_8846235545148926018[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5045108504985016523) {
   out_5045108504985016523[0] = 0;
   out_5045108504985016523[1] = 0;
   out_5045108504985016523[2] = 0;
   out_5045108504985016523[3] = 0;
   out_5045108504985016523[4] = 0;
   out_5045108504985016523[5] = 0;
   out_5045108504985016523[6] = 1;
   out_5045108504985016523[7] = 0;
   out_5045108504985016523[8] = 0;
}
void h_24(double *state, double *unused, double *out_2908177826929237879) {
   out_2908177826929237879[0] = state[4];
   out_2908177826929237879[1] = state[5];
}
void H_24(double *state, double *unused, double *out_2819400721006147961) {
   out_2819400721006147961[0] = 0;
   out_2819400721006147961[1] = 0;
   out_2819400721006147961[2] = 0;
   out_2819400721006147961[3] = 0;
   out_2819400721006147961[4] = 1;
   out_2819400721006147961[5] = 0;
   out_2819400721006147961[6] = 0;
   out_2819400721006147961[7] = 0;
   out_2819400721006147961[8] = 0;
   out_2819400721006147961[9] = 0;
   out_2819400721006147961[10] = 0;
   out_2819400721006147961[11] = 0;
   out_2819400721006147961[12] = 0;
   out_2819400721006147961[13] = 0;
   out_2819400721006147961[14] = 1;
   out_2819400721006147961[15] = 0;
   out_2819400721006147961[16] = 0;
   out_2819400721006147961[17] = 0;
}
void h_30(double *state, double *unused, double *out_2781006367731848463) {
   out_2781006367731848463[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1871581836506600232) {
   out_1871581836506600232[0] = 0;
   out_1871581836506600232[1] = 0;
   out_1871581836506600232[2] = 0;
   out_1871581836506600232[3] = 0;
   out_1871581836506600232[4] = 1;
   out_1871581836506600232[5] = 0;
   out_1871581836506600232[6] = 0;
   out_1871581836506600232[7] = 0;
   out_1871581836506600232[8] = 0;
}
void h_26(double *state, double *unused, double *out_2861723503349108372) {
   out_2861723503349108372[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8786611823859072747) {
   out_8786611823859072747[0] = 0;
   out_8786611823859072747[1] = 0;
   out_8786611823859072747[2] = 0;
   out_8786611823859072747[3] = 0;
   out_8786611823859072747[4] = 0;
   out_8786611823859072747[5] = 0;
   out_8786611823859072747[6] = 0;
   out_8786611823859072747[7] = 1;
   out_8786611823859072747[8] = 0;
}
void h_27(double *state, double *unused, double *out_1194851708916398945) {
   out_1194851708916398945[0] = state[3];
}
void H_27(double *state, double *unused, double *out_303181475293824679) {
   out_303181475293824679[0] = 0;
   out_303181475293824679[1] = 0;
   out_303181475293824679[2] = 0;
   out_303181475293824679[3] = 1;
   out_303181475293824679[4] = 0;
   out_303181475293824679[5] = 0;
   out_303181475293824679[6] = 0;
   out_303181475293824679[7] = 0;
   out_303181475293824679[8] = 0;
}
void h_29(double *state, double *unused, double *out_5295193670116963540) {
   out_5295193670116963540[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2381813180820992416) {
   out_2381813180820992416[0] = 0;
   out_2381813180820992416[1] = 1;
   out_2381813180820992416[2] = 0;
   out_2381813180820992416[3] = 0;
   out_2381813180820992416[4] = 0;
   out_2381813180820992416[5] = 0;
   out_2381813180820992416[6] = 0;
   out_2381813180820992416[7] = 0;
   out_2381813180820992416[8] = 0;
}
void h_28(double *state, double *unused, double *out_5620212624214630478) {
   out_5620212624214630478[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7098943219232906286) {
   out_7098943219232906286[0] = 1;
   out_7098943219232906286[1] = 0;
   out_7098943219232906286[2] = 0;
   out_7098943219232906286[3] = 0;
   out_7098943219232906286[4] = 0;
   out_7098943219232906286[5] = 0;
   out_7098943219232906286[6] = 0;
   out_7098943219232906286[7] = 0;
   out_7098943219232906286[8] = 0;
}
void h_31(double *state, double *unused, double *out_7444271086998469050) {
   out_7444271086998469050[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5014462543108056095) {
   out_5014462543108056095[0] = 0;
   out_5014462543108056095[1] = 0;
   out_5014462543108056095[2] = 0;
   out_5014462543108056095[3] = 0;
   out_5014462543108056095[4] = 0;
   out_5014462543108056095[5] = 0;
   out_5014462543108056095[6] = 0;
   out_5014462543108056095[7] = 0;
   out_5014462543108056095[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_5195967926175737340) {
  err_fun(nom_x, delta_x, out_5195967926175737340);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5038352358272318907) {
  inv_err_fun(nom_x, true_x, out_5038352358272318907);
}
void car_H_mod_fun(double *state, double *out_4148079720927220714) {
  H_mod_fun(state, out_4148079720927220714);
}
void car_f_fun(double *state, double dt, double *out_2457004505259509534) {
  f_fun(state,  dt, out_2457004505259509534);
}
void car_F_fun(double *state, double dt, double *out_6660883876973656350) {
  F_fun(state,  dt, out_6660883876973656350);
}
void car_h_25(double *state, double *unused, double *out_8846235545148926018) {
  h_25(state, unused, out_8846235545148926018);
}
void car_H_25(double *state, double *unused, double *out_5045108504985016523) {
  H_25(state, unused, out_5045108504985016523);
}
void car_h_24(double *state, double *unused, double *out_2908177826929237879) {
  h_24(state, unused, out_2908177826929237879);
}
void car_H_24(double *state, double *unused, double *out_2819400721006147961) {
  H_24(state, unused, out_2819400721006147961);
}
void car_h_30(double *state, double *unused, double *out_2781006367731848463) {
  h_30(state, unused, out_2781006367731848463);
}
void car_H_30(double *state, double *unused, double *out_1871581836506600232) {
  H_30(state, unused, out_1871581836506600232);
}
void car_h_26(double *state, double *unused, double *out_2861723503349108372) {
  h_26(state, unused, out_2861723503349108372);
}
void car_H_26(double *state, double *unused, double *out_8786611823859072747) {
  H_26(state, unused, out_8786611823859072747);
}
void car_h_27(double *state, double *unused, double *out_1194851708916398945) {
  h_27(state, unused, out_1194851708916398945);
}
void car_H_27(double *state, double *unused, double *out_303181475293824679) {
  H_27(state, unused, out_303181475293824679);
}
void car_h_29(double *state, double *unused, double *out_5295193670116963540) {
  h_29(state, unused, out_5295193670116963540);
}
void car_H_29(double *state, double *unused, double *out_2381813180820992416) {
  H_29(state, unused, out_2381813180820992416);
}
void car_h_28(double *state, double *unused, double *out_5620212624214630478) {
  h_28(state, unused, out_5620212624214630478);
}
void car_H_28(double *state, double *unused, double *out_7098943219232906286) {
  H_28(state, unused, out_7098943219232906286);
}
void car_h_31(double *state, double *unused, double *out_7444271086998469050) {
  h_31(state, unused, out_7444271086998469050);
}
void car_H_31(double *state, double *unused, double *out_5014462543108056095) {
  H_31(state, unused, out_5014462543108056095);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
