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
void err_fun(double *nom_x, double *delta_x, double *out_8382710361721861983) {
   out_8382710361721861983[0] = delta_x[0] + nom_x[0];
   out_8382710361721861983[1] = delta_x[1] + nom_x[1];
   out_8382710361721861983[2] = delta_x[2] + nom_x[2];
   out_8382710361721861983[3] = delta_x[3] + nom_x[3];
   out_8382710361721861983[4] = delta_x[4] + nom_x[4];
   out_8382710361721861983[5] = delta_x[5] + nom_x[5];
   out_8382710361721861983[6] = delta_x[6] + nom_x[6];
   out_8382710361721861983[7] = delta_x[7] + nom_x[7];
   out_8382710361721861983[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3522357315394120509) {
   out_3522357315394120509[0] = -nom_x[0] + true_x[0];
   out_3522357315394120509[1] = -nom_x[1] + true_x[1];
   out_3522357315394120509[2] = -nom_x[2] + true_x[2];
   out_3522357315394120509[3] = -nom_x[3] + true_x[3];
   out_3522357315394120509[4] = -nom_x[4] + true_x[4];
   out_3522357315394120509[5] = -nom_x[5] + true_x[5];
   out_3522357315394120509[6] = -nom_x[6] + true_x[6];
   out_3522357315394120509[7] = -nom_x[7] + true_x[7];
   out_3522357315394120509[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4867832477974190008) {
   out_4867832477974190008[0] = 1.0;
   out_4867832477974190008[1] = 0.0;
   out_4867832477974190008[2] = 0.0;
   out_4867832477974190008[3] = 0.0;
   out_4867832477974190008[4] = 0.0;
   out_4867832477974190008[5] = 0.0;
   out_4867832477974190008[6] = 0.0;
   out_4867832477974190008[7] = 0.0;
   out_4867832477974190008[8] = 0.0;
   out_4867832477974190008[9] = 0.0;
   out_4867832477974190008[10] = 1.0;
   out_4867832477974190008[11] = 0.0;
   out_4867832477974190008[12] = 0.0;
   out_4867832477974190008[13] = 0.0;
   out_4867832477974190008[14] = 0.0;
   out_4867832477974190008[15] = 0.0;
   out_4867832477974190008[16] = 0.0;
   out_4867832477974190008[17] = 0.0;
   out_4867832477974190008[18] = 0.0;
   out_4867832477974190008[19] = 0.0;
   out_4867832477974190008[20] = 1.0;
   out_4867832477974190008[21] = 0.0;
   out_4867832477974190008[22] = 0.0;
   out_4867832477974190008[23] = 0.0;
   out_4867832477974190008[24] = 0.0;
   out_4867832477974190008[25] = 0.0;
   out_4867832477974190008[26] = 0.0;
   out_4867832477974190008[27] = 0.0;
   out_4867832477974190008[28] = 0.0;
   out_4867832477974190008[29] = 0.0;
   out_4867832477974190008[30] = 1.0;
   out_4867832477974190008[31] = 0.0;
   out_4867832477974190008[32] = 0.0;
   out_4867832477974190008[33] = 0.0;
   out_4867832477974190008[34] = 0.0;
   out_4867832477974190008[35] = 0.0;
   out_4867832477974190008[36] = 0.0;
   out_4867832477974190008[37] = 0.0;
   out_4867832477974190008[38] = 0.0;
   out_4867832477974190008[39] = 0.0;
   out_4867832477974190008[40] = 1.0;
   out_4867832477974190008[41] = 0.0;
   out_4867832477974190008[42] = 0.0;
   out_4867832477974190008[43] = 0.0;
   out_4867832477974190008[44] = 0.0;
   out_4867832477974190008[45] = 0.0;
   out_4867832477974190008[46] = 0.0;
   out_4867832477974190008[47] = 0.0;
   out_4867832477974190008[48] = 0.0;
   out_4867832477974190008[49] = 0.0;
   out_4867832477974190008[50] = 1.0;
   out_4867832477974190008[51] = 0.0;
   out_4867832477974190008[52] = 0.0;
   out_4867832477974190008[53] = 0.0;
   out_4867832477974190008[54] = 0.0;
   out_4867832477974190008[55] = 0.0;
   out_4867832477974190008[56] = 0.0;
   out_4867832477974190008[57] = 0.0;
   out_4867832477974190008[58] = 0.0;
   out_4867832477974190008[59] = 0.0;
   out_4867832477974190008[60] = 1.0;
   out_4867832477974190008[61] = 0.0;
   out_4867832477974190008[62] = 0.0;
   out_4867832477974190008[63] = 0.0;
   out_4867832477974190008[64] = 0.0;
   out_4867832477974190008[65] = 0.0;
   out_4867832477974190008[66] = 0.0;
   out_4867832477974190008[67] = 0.0;
   out_4867832477974190008[68] = 0.0;
   out_4867832477974190008[69] = 0.0;
   out_4867832477974190008[70] = 1.0;
   out_4867832477974190008[71] = 0.0;
   out_4867832477974190008[72] = 0.0;
   out_4867832477974190008[73] = 0.0;
   out_4867832477974190008[74] = 0.0;
   out_4867832477974190008[75] = 0.0;
   out_4867832477974190008[76] = 0.0;
   out_4867832477974190008[77] = 0.0;
   out_4867832477974190008[78] = 0.0;
   out_4867832477974190008[79] = 0.0;
   out_4867832477974190008[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5941657116251809244) {
   out_5941657116251809244[0] = state[0];
   out_5941657116251809244[1] = state[1];
   out_5941657116251809244[2] = state[2];
   out_5941657116251809244[3] = state[3];
   out_5941657116251809244[4] = state[4];
   out_5941657116251809244[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_5941657116251809244[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5941657116251809244[7] = state[7];
   out_5941657116251809244[8] = state[8];
}
void F_fun(double *state, double dt, double *out_8954669121513829153) {
   out_8954669121513829153[0] = 1;
   out_8954669121513829153[1] = 0;
   out_8954669121513829153[2] = 0;
   out_8954669121513829153[3] = 0;
   out_8954669121513829153[4] = 0;
   out_8954669121513829153[5] = 0;
   out_8954669121513829153[6] = 0;
   out_8954669121513829153[7] = 0;
   out_8954669121513829153[8] = 0;
   out_8954669121513829153[9] = 0;
   out_8954669121513829153[10] = 1;
   out_8954669121513829153[11] = 0;
   out_8954669121513829153[12] = 0;
   out_8954669121513829153[13] = 0;
   out_8954669121513829153[14] = 0;
   out_8954669121513829153[15] = 0;
   out_8954669121513829153[16] = 0;
   out_8954669121513829153[17] = 0;
   out_8954669121513829153[18] = 0;
   out_8954669121513829153[19] = 0;
   out_8954669121513829153[20] = 1;
   out_8954669121513829153[21] = 0;
   out_8954669121513829153[22] = 0;
   out_8954669121513829153[23] = 0;
   out_8954669121513829153[24] = 0;
   out_8954669121513829153[25] = 0;
   out_8954669121513829153[26] = 0;
   out_8954669121513829153[27] = 0;
   out_8954669121513829153[28] = 0;
   out_8954669121513829153[29] = 0;
   out_8954669121513829153[30] = 1;
   out_8954669121513829153[31] = 0;
   out_8954669121513829153[32] = 0;
   out_8954669121513829153[33] = 0;
   out_8954669121513829153[34] = 0;
   out_8954669121513829153[35] = 0;
   out_8954669121513829153[36] = 0;
   out_8954669121513829153[37] = 0;
   out_8954669121513829153[38] = 0;
   out_8954669121513829153[39] = 0;
   out_8954669121513829153[40] = 1;
   out_8954669121513829153[41] = 0;
   out_8954669121513829153[42] = 0;
   out_8954669121513829153[43] = 0;
   out_8954669121513829153[44] = 0;
   out_8954669121513829153[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_8954669121513829153[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_8954669121513829153[47] = -dt*stiffness_front*state[0]/state[1];
   out_8954669121513829153[48] = -dt*stiffness_front*state[0]/state[1];
   out_8954669121513829153[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_8954669121513829153[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_8954669121513829153[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_8954669121513829153[52] = dt*stiffness_front*state[0]/state[1];
   out_8954669121513829153[53] = -9.8100000000000005*dt;
   out_8954669121513829153[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_8954669121513829153[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_8954669121513829153[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8954669121513829153[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8954669121513829153[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_8954669121513829153[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_8954669121513829153[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_8954669121513829153[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_8954669121513829153[62] = 0;
   out_8954669121513829153[63] = 0;
   out_8954669121513829153[64] = 0;
   out_8954669121513829153[65] = 0;
   out_8954669121513829153[66] = 0;
   out_8954669121513829153[67] = 0;
   out_8954669121513829153[68] = 0;
   out_8954669121513829153[69] = 0;
   out_8954669121513829153[70] = 1;
   out_8954669121513829153[71] = 0;
   out_8954669121513829153[72] = 0;
   out_8954669121513829153[73] = 0;
   out_8954669121513829153[74] = 0;
   out_8954669121513829153[75] = 0;
   out_8954669121513829153[76] = 0;
   out_8954669121513829153[77] = 0;
   out_8954669121513829153[78] = 0;
   out_8954669121513829153[79] = 0;
   out_8954669121513829153[80] = 1;
}
void h_25(double *state, double *unused, double *out_1577926933363951538) {
   out_1577926933363951538[0] = state[6];
}
void H_25(double *state, double *unused, double *out_4325355747938047229) {
   out_4325355747938047229[0] = 0;
   out_4325355747938047229[1] = 0;
   out_4325355747938047229[2] = 0;
   out_4325355747938047229[3] = 0;
   out_4325355747938047229[4] = 0;
   out_4325355747938047229[5] = 0;
   out_4325355747938047229[6] = 1;
   out_4325355747938047229[7] = 0;
   out_4325355747938047229[8] = 0;
}
void h_24(double *state, double *unused, double *out_3460282440634355045) {
   out_3460282440634355045[0] = state[4];
   out_3460282440634355045[1] = state[5];
}
void H_24(double *state, double *unused, double *out_6498005346943546795) {
   out_6498005346943546795[0] = 0;
   out_6498005346943546795[1] = 0;
   out_6498005346943546795[2] = 0;
   out_6498005346943546795[3] = 0;
   out_6498005346943546795[4] = 1;
   out_6498005346943546795[5] = 0;
   out_6498005346943546795[6] = 0;
   out_6498005346943546795[7] = 0;
   out_6498005346943546795[8] = 0;
   out_6498005346943546795[9] = 0;
   out_6498005346943546795[10] = 0;
   out_6498005346943546795[11] = 0;
   out_6498005346943546795[12] = 0;
   out_6498005346943546795[13] = 0;
   out_6498005346943546795[14] = 1;
   out_6498005346943546795[15] = 0;
   out_6498005346943546795[16] = 0;
   out_6498005346943546795[17] = 0;
}
void h_30(double *state, double *unused, double *out_5215376461617973888) {
   out_5215376461617973888[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1807022789430798602) {
   out_1807022789430798602[0] = 0;
   out_1807022789430798602[1] = 0;
   out_1807022789430798602[2] = 0;
   out_1807022789430798602[3] = 0;
   out_1807022789430798602[4] = 1;
   out_1807022789430798602[5] = 0;
   out_1807022789430798602[6] = 0;
   out_1807022789430798602[7] = 0;
   out_1807022789430798602[8] = 0;
}
void h_26(double *state, double *unused, double *out_5796224177662876915) {
   out_5796224177662876915[0] = state[7];
}
void H_26(double *state, double *unused, double *out_8066859066812103453) {
   out_8066859066812103453[0] = 0;
   out_8066859066812103453[1] = 0;
   out_8066859066812103453[2] = 0;
   out_8066859066812103453[3] = 0;
   out_8066859066812103453[4] = 0;
   out_8066859066812103453[5] = 0;
   out_8066859066812103453[6] = 0;
   out_8066859066812103453[7] = 1;
   out_8066859066812103453[8] = 0;
}
void h_27(double *state, double *unused, double *out_5678216783729500171) {
   out_5678216783729500171[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3981786101231223513) {
   out_3981786101231223513[0] = 0;
   out_3981786101231223513[1] = 0;
   out_3981786101231223513[2] = 0;
   out_3981786101231223513[3] = 1;
   out_3981786101231223513[4] = 0;
   out_3981786101231223513[5] = 0;
   out_3981786101231223513[6] = 0;
   out_3981786101231223513[7] = 0;
   out_3981786101231223513[8] = 0;
}
void h_29(double *state, double *unused, double *out_8373625966157711161) {
   out_8373625966157711161[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1296791445116406418) {
   out_1296791445116406418[0] = 0;
   out_1296791445116406418[1] = 1;
   out_1296791445116406418[2] = 0;
   out_1296791445116406418[3] = 0;
   out_1296791445116406418[4] = 0;
   out_1296791445116406418[5] = 0;
   out_1296791445116406418[6] = 0;
   out_1296791445116406418[7] = 0;
   out_1296791445116406418[8] = 0;
}
void h_28(double *state, double *unused, double *out_1392267225623107913) {
   out_1392267225623107913[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6379190462185936992) {
   out_6379190462185936992[0] = 1;
   out_6379190462185936992[1] = 0;
   out_6379190462185936992[2] = 0;
   out_6379190462185936992[3] = 0;
   out_6379190462185936992[4] = 0;
   out_6379190462185936992[5] = 0;
   out_6379190462185936992[6] = 0;
   out_6379190462185936992[7] = 0;
   out_6379190462185936992[8] = 0;
}
void h_31(double *state, double *unused, double *out_6246882170235372088) {
   out_6246882170235372088[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8693067169045454929) {
   out_8693067169045454929[0] = 0;
   out_8693067169045454929[1] = 0;
   out_8693067169045454929[2] = 0;
   out_8693067169045454929[3] = 0;
   out_8693067169045454929[4] = 0;
   out_8693067169045454929[5] = 0;
   out_8693067169045454929[6] = 0;
   out_8693067169045454929[7] = 0;
   out_8693067169045454929[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8382710361721861983) {
  err_fun(nom_x, delta_x, out_8382710361721861983);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3522357315394120509) {
  inv_err_fun(nom_x, true_x, out_3522357315394120509);
}
void car_H_mod_fun(double *state, double *out_4867832477974190008) {
  H_mod_fun(state, out_4867832477974190008);
}
void car_f_fun(double *state, double dt, double *out_5941657116251809244) {
  f_fun(state,  dt, out_5941657116251809244);
}
void car_F_fun(double *state, double dt, double *out_8954669121513829153) {
  F_fun(state,  dt, out_8954669121513829153);
}
void car_h_25(double *state, double *unused, double *out_1577926933363951538) {
  h_25(state, unused, out_1577926933363951538);
}
void car_H_25(double *state, double *unused, double *out_4325355747938047229) {
  H_25(state, unused, out_4325355747938047229);
}
void car_h_24(double *state, double *unused, double *out_3460282440634355045) {
  h_24(state, unused, out_3460282440634355045);
}
void car_H_24(double *state, double *unused, double *out_6498005346943546795) {
  H_24(state, unused, out_6498005346943546795);
}
void car_h_30(double *state, double *unused, double *out_5215376461617973888) {
  h_30(state, unused, out_5215376461617973888);
}
void car_H_30(double *state, double *unused, double *out_1807022789430798602) {
  H_30(state, unused, out_1807022789430798602);
}
void car_h_26(double *state, double *unused, double *out_5796224177662876915) {
  h_26(state, unused, out_5796224177662876915);
}
void car_H_26(double *state, double *unused, double *out_8066859066812103453) {
  H_26(state, unused, out_8066859066812103453);
}
void car_h_27(double *state, double *unused, double *out_5678216783729500171) {
  h_27(state, unused, out_5678216783729500171);
}
void car_H_27(double *state, double *unused, double *out_3981786101231223513) {
  H_27(state, unused, out_3981786101231223513);
}
void car_h_29(double *state, double *unused, double *out_8373625966157711161) {
  h_29(state, unused, out_8373625966157711161);
}
void car_H_29(double *state, double *unused, double *out_1296791445116406418) {
  H_29(state, unused, out_1296791445116406418);
}
void car_h_28(double *state, double *unused, double *out_1392267225623107913) {
  h_28(state, unused, out_1392267225623107913);
}
void car_H_28(double *state, double *unused, double *out_6379190462185936992) {
  H_28(state, unused, out_6379190462185936992);
}
void car_h_31(double *state, double *unused, double *out_6246882170235372088) {
  h_31(state, unused, out_6246882170235372088);
}
void car_H_31(double *state, double *unused, double *out_8693067169045454929) {
  H_31(state, unused, out_8693067169045454929);
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
