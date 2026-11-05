#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_893436089228109690);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8379058142980748080);
void pose_H_mod_fun(double *state, double *out_1655046560292470994);
void pose_f_fun(double *state, double dt, double *out_5788694501928425556);
void pose_F_fun(double *state, double dt, double *out_7768357802212593422);
void pose_h_4(double *state, double *unused, double *out_7817161189331034850);
void pose_H_4(double *state, double *unused, double *out_457099078409572890);
void pose_h_10(double *state, double *unused, double *out_1069920605421722541);
void pose_H_10(double *state, double *unused, double *out_4123669723156225352);
void pose_h_13(double *state, double *unused, double *out_7366557747156282930);
void pose_H_13(double *state, double *unused, double *out_2755174746922759911);
void pose_h_14(double *state, double *unused, double *out_6888234972875149128);
void pose_H_14(double *state, double *unused, double *out_3539887510704945186);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}