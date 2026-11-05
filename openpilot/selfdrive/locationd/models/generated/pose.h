#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8670698209167984406);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_9015049238036164588);
void pose_H_mod_fun(double *state, double *out_2928489040978298353);
void pose_f_fun(double *state, double dt, double *out_2323113914602961191);
void pose_F_fun(double *state, double dt, double *out_6901050174259076486);
void pose_h_4(double *state, double *unused, double *out_2996611270475893358);
void pose_H_4(double *state, double *unused, double *out_4621784882735821210);
void pose_h_10(double *state, double *unused, double *out_961907255194536489);
void pose_H_10(double *state, double *unused, double *out_6481820587514982003);
void pose_h_13(double *state, double *unused, double *out_5073206363808515425);
void pose_H_13(double *state, double *unused, double *out_2988846325580879719);
void pose_h_14(double *state, double *unused, double *out_5922811292220657062);
void pose_H_14(double *state, double *unused, double *out_7704573315031193506);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}