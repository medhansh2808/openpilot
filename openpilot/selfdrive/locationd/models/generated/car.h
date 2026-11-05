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
void car_err_fun(double *nom_x, double *delta_x, double *out_8382710361721861983);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3522357315394120509);
void car_H_mod_fun(double *state, double *out_4867832477974190008);
void car_f_fun(double *state, double dt, double *out_5941657116251809244);
void car_F_fun(double *state, double dt, double *out_8954669121513829153);
void car_h_25(double *state, double *unused, double *out_1577926933363951538);
void car_H_25(double *state, double *unused, double *out_4325355747938047229);
void car_h_24(double *state, double *unused, double *out_3460282440634355045);
void car_H_24(double *state, double *unused, double *out_6498005346943546795);
void car_h_30(double *state, double *unused, double *out_5215376461617973888);
void car_H_30(double *state, double *unused, double *out_1807022789430798602);
void car_h_26(double *state, double *unused, double *out_5796224177662876915);
void car_H_26(double *state, double *unused, double *out_8066859066812103453);
void car_h_27(double *state, double *unused, double *out_5678216783729500171);
void car_H_27(double *state, double *unused, double *out_3981786101231223513);
void car_h_29(double *state, double *unused, double *out_8373625966157711161);
void car_H_29(double *state, double *unused, double *out_1296791445116406418);
void car_h_28(double *state, double *unused, double *out_1392267225623107913);
void car_H_28(double *state, double *unused, double *out_6379190462185936992);
void car_h_31(double *state, double *unused, double *out_6246882170235372088);
void car_H_31(double *state, double *unused, double *out_8693067169045454929);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}