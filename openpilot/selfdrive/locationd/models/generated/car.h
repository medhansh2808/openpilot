#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_5195967926175737340);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_5038352358272318907);
void car_H_mod_fun(double *state, double *out_4148079720927220714);
void car_f_fun(double *state, double dt, double *out_2457004505259509534);
void car_F_fun(double *state, double dt, double *out_6660883876973656350);
void car_h_25(double *state, double *unused, double *out_8846235545148926018);
void car_H_25(double *state, double *unused, double *out_5045108504985016523);
void car_h_24(double *state, double *unused, double *out_2908177826929237879);
void car_H_24(double *state, double *unused, double *out_2819400721006147961);
void car_h_30(double *state, double *unused, double *out_2781006367731848463);
void car_H_30(double *state, double *unused, double *out_1871581836506600232);
void car_h_26(double *state, double *unused, double *out_2861723503349108372);
void car_H_26(double *state, double *unused, double *out_8786611823859072747);
void car_h_27(double *state, double *unused, double *out_1194851708916398945);
void car_H_27(double *state, double *unused, double *out_303181475293824679);
void car_h_29(double *state, double *unused, double *out_5295193670116963540);
void car_H_29(double *state, double *unused, double *out_2381813180820992416);
void car_h_28(double *state, double *unused, double *out_5620212624214630478);
void car_H_28(double *state, double *unused, double *out_7098943219232906286);
void car_h_31(double *state, double *unused, double *out_7444271086998469050);
void car_H_31(double *state, double *unused, double *out_5014462543108056095);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}