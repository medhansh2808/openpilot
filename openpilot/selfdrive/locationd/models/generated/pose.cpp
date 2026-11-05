#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8670698209167984406) {
   out_8670698209167984406[0] = delta_x[0] + nom_x[0];
   out_8670698209167984406[1] = delta_x[1] + nom_x[1];
   out_8670698209167984406[2] = delta_x[2] + nom_x[2];
   out_8670698209167984406[3] = delta_x[3] + nom_x[3];
   out_8670698209167984406[4] = delta_x[4] + nom_x[4];
   out_8670698209167984406[5] = delta_x[5] + nom_x[5];
   out_8670698209167984406[6] = delta_x[6] + nom_x[6];
   out_8670698209167984406[7] = delta_x[7] + nom_x[7];
   out_8670698209167984406[8] = delta_x[8] + nom_x[8];
   out_8670698209167984406[9] = delta_x[9] + nom_x[9];
   out_8670698209167984406[10] = delta_x[10] + nom_x[10];
   out_8670698209167984406[11] = delta_x[11] + nom_x[11];
   out_8670698209167984406[12] = delta_x[12] + nom_x[12];
   out_8670698209167984406[13] = delta_x[13] + nom_x[13];
   out_8670698209167984406[14] = delta_x[14] + nom_x[14];
   out_8670698209167984406[15] = delta_x[15] + nom_x[15];
   out_8670698209167984406[16] = delta_x[16] + nom_x[16];
   out_8670698209167984406[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_9015049238036164588) {
   out_9015049238036164588[0] = -nom_x[0] + true_x[0];
   out_9015049238036164588[1] = -nom_x[1] + true_x[1];
   out_9015049238036164588[2] = -nom_x[2] + true_x[2];
   out_9015049238036164588[3] = -nom_x[3] + true_x[3];
   out_9015049238036164588[4] = -nom_x[4] + true_x[4];
   out_9015049238036164588[5] = -nom_x[5] + true_x[5];
   out_9015049238036164588[6] = -nom_x[6] + true_x[6];
   out_9015049238036164588[7] = -nom_x[7] + true_x[7];
   out_9015049238036164588[8] = -nom_x[8] + true_x[8];
   out_9015049238036164588[9] = -nom_x[9] + true_x[9];
   out_9015049238036164588[10] = -nom_x[10] + true_x[10];
   out_9015049238036164588[11] = -nom_x[11] + true_x[11];
   out_9015049238036164588[12] = -nom_x[12] + true_x[12];
   out_9015049238036164588[13] = -nom_x[13] + true_x[13];
   out_9015049238036164588[14] = -nom_x[14] + true_x[14];
   out_9015049238036164588[15] = -nom_x[15] + true_x[15];
   out_9015049238036164588[16] = -nom_x[16] + true_x[16];
   out_9015049238036164588[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_2928489040978298353) {
   out_2928489040978298353[0] = 1.0;
   out_2928489040978298353[1] = 0.0;
   out_2928489040978298353[2] = 0.0;
   out_2928489040978298353[3] = 0.0;
   out_2928489040978298353[4] = 0.0;
   out_2928489040978298353[5] = 0.0;
   out_2928489040978298353[6] = 0.0;
   out_2928489040978298353[7] = 0.0;
   out_2928489040978298353[8] = 0.0;
   out_2928489040978298353[9] = 0.0;
   out_2928489040978298353[10] = 0.0;
   out_2928489040978298353[11] = 0.0;
   out_2928489040978298353[12] = 0.0;
   out_2928489040978298353[13] = 0.0;
   out_2928489040978298353[14] = 0.0;
   out_2928489040978298353[15] = 0.0;
   out_2928489040978298353[16] = 0.0;
   out_2928489040978298353[17] = 0.0;
   out_2928489040978298353[18] = 0.0;
   out_2928489040978298353[19] = 1.0;
   out_2928489040978298353[20] = 0.0;
   out_2928489040978298353[21] = 0.0;
   out_2928489040978298353[22] = 0.0;
   out_2928489040978298353[23] = 0.0;
   out_2928489040978298353[24] = 0.0;
   out_2928489040978298353[25] = 0.0;
   out_2928489040978298353[26] = 0.0;
   out_2928489040978298353[27] = 0.0;
   out_2928489040978298353[28] = 0.0;
   out_2928489040978298353[29] = 0.0;
   out_2928489040978298353[30] = 0.0;
   out_2928489040978298353[31] = 0.0;
   out_2928489040978298353[32] = 0.0;
   out_2928489040978298353[33] = 0.0;
   out_2928489040978298353[34] = 0.0;
   out_2928489040978298353[35] = 0.0;
   out_2928489040978298353[36] = 0.0;
   out_2928489040978298353[37] = 0.0;
   out_2928489040978298353[38] = 1.0;
   out_2928489040978298353[39] = 0.0;
   out_2928489040978298353[40] = 0.0;
   out_2928489040978298353[41] = 0.0;
   out_2928489040978298353[42] = 0.0;
   out_2928489040978298353[43] = 0.0;
   out_2928489040978298353[44] = 0.0;
   out_2928489040978298353[45] = 0.0;
   out_2928489040978298353[46] = 0.0;
   out_2928489040978298353[47] = 0.0;
   out_2928489040978298353[48] = 0.0;
   out_2928489040978298353[49] = 0.0;
   out_2928489040978298353[50] = 0.0;
   out_2928489040978298353[51] = 0.0;
   out_2928489040978298353[52] = 0.0;
   out_2928489040978298353[53] = 0.0;
   out_2928489040978298353[54] = 0.0;
   out_2928489040978298353[55] = 0.0;
   out_2928489040978298353[56] = 0.0;
   out_2928489040978298353[57] = 1.0;
   out_2928489040978298353[58] = 0.0;
   out_2928489040978298353[59] = 0.0;
   out_2928489040978298353[60] = 0.0;
   out_2928489040978298353[61] = 0.0;
   out_2928489040978298353[62] = 0.0;
   out_2928489040978298353[63] = 0.0;
   out_2928489040978298353[64] = 0.0;
   out_2928489040978298353[65] = 0.0;
   out_2928489040978298353[66] = 0.0;
   out_2928489040978298353[67] = 0.0;
   out_2928489040978298353[68] = 0.0;
   out_2928489040978298353[69] = 0.0;
   out_2928489040978298353[70] = 0.0;
   out_2928489040978298353[71] = 0.0;
   out_2928489040978298353[72] = 0.0;
   out_2928489040978298353[73] = 0.0;
   out_2928489040978298353[74] = 0.0;
   out_2928489040978298353[75] = 0.0;
   out_2928489040978298353[76] = 1.0;
   out_2928489040978298353[77] = 0.0;
   out_2928489040978298353[78] = 0.0;
   out_2928489040978298353[79] = 0.0;
   out_2928489040978298353[80] = 0.0;
   out_2928489040978298353[81] = 0.0;
   out_2928489040978298353[82] = 0.0;
   out_2928489040978298353[83] = 0.0;
   out_2928489040978298353[84] = 0.0;
   out_2928489040978298353[85] = 0.0;
   out_2928489040978298353[86] = 0.0;
   out_2928489040978298353[87] = 0.0;
   out_2928489040978298353[88] = 0.0;
   out_2928489040978298353[89] = 0.0;
   out_2928489040978298353[90] = 0.0;
   out_2928489040978298353[91] = 0.0;
   out_2928489040978298353[92] = 0.0;
   out_2928489040978298353[93] = 0.0;
   out_2928489040978298353[94] = 0.0;
   out_2928489040978298353[95] = 1.0;
   out_2928489040978298353[96] = 0.0;
   out_2928489040978298353[97] = 0.0;
   out_2928489040978298353[98] = 0.0;
   out_2928489040978298353[99] = 0.0;
   out_2928489040978298353[100] = 0.0;
   out_2928489040978298353[101] = 0.0;
   out_2928489040978298353[102] = 0.0;
   out_2928489040978298353[103] = 0.0;
   out_2928489040978298353[104] = 0.0;
   out_2928489040978298353[105] = 0.0;
   out_2928489040978298353[106] = 0.0;
   out_2928489040978298353[107] = 0.0;
   out_2928489040978298353[108] = 0.0;
   out_2928489040978298353[109] = 0.0;
   out_2928489040978298353[110] = 0.0;
   out_2928489040978298353[111] = 0.0;
   out_2928489040978298353[112] = 0.0;
   out_2928489040978298353[113] = 0.0;
   out_2928489040978298353[114] = 1.0;
   out_2928489040978298353[115] = 0.0;
   out_2928489040978298353[116] = 0.0;
   out_2928489040978298353[117] = 0.0;
   out_2928489040978298353[118] = 0.0;
   out_2928489040978298353[119] = 0.0;
   out_2928489040978298353[120] = 0.0;
   out_2928489040978298353[121] = 0.0;
   out_2928489040978298353[122] = 0.0;
   out_2928489040978298353[123] = 0.0;
   out_2928489040978298353[124] = 0.0;
   out_2928489040978298353[125] = 0.0;
   out_2928489040978298353[126] = 0.0;
   out_2928489040978298353[127] = 0.0;
   out_2928489040978298353[128] = 0.0;
   out_2928489040978298353[129] = 0.0;
   out_2928489040978298353[130] = 0.0;
   out_2928489040978298353[131] = 0.0;
   out_2928489040978298353[132] = 0.0;
   out_2928489040978298353[133] = 1.0;
   out_2928489040978298353[134] = 0.0;
   out_2928489040978298353[135] = 0.0;
   out_2928489040978298353[136] = 0.0;
   out_2928489040978298353[137] = 0.0;
   out_2928489040978298353[138] = 0.0;
   out_2928489040978298353[139] = 0.0;
   out_2928489040978298353[140] = 0.0;
   out_2928489040978298353[141] = 0.0;
   out_2928489040978298353[142] = 0.0;
   out_2928489040978298353[143] = 0.0;
   out_2928489040978298353[144] = 0.0;
   out_2928489040978298353[145] = 0.0;
   out_2928489040978298353[146] = 0.0;
   out_2928489040978298353[147] = 0.0;
   out_2928489040978298353[148] = 0.0;
   out_2928489040978298353[149] = 0.0;
   out_2928489040978298353[150] = 0.0;
   out_2928489040978298353[151] = 0.0;
   out_2928489040978298353[152] = 1.0;
   out_2928489040978298353[153] = 0.0;
   out_2928489040978298353[154] = 0.0;
   out_2928489040978298353[155] = 0.0;
   out_2928489040978298353[156] = 0.0;
   out_2928489040978298353[157] = 0.0;
   out_2928489040978298353[158] = 0.0;
   out_2928489040978298353[159] = 0.0;
   out_2928489040978298353[160] = 0.0;
   out_2928489040978298353[161] = 0.0;
   out_2928489040978298353[162] = 0.0;
   out_2928489040978298353[163] = 0.0;
   out_2928489040978298353[164] = 0.0;
   out_2928489040978298353[165] = 0.0;
   out_2928489040978298353[166] = 0.0;
   out_2928489040978298353[167] = 0.0;
   out_2928489040978298353[168] = 0.0;
   out_2928489040978298353[169] = 0.0;
   out_2928489040978298353[170] = 0.0;
   out_2928489040978298353[171] = 1.0;
   out_2928489040978298353[172] = 0.0;
   out_2928489040978298353[173] = 0.0;
   out_2928489040978298353[174] = 0.0;
   out_2928489040978298353[175] = 0.0;
   out_2928489040978298353[176] = 0.0;
   out_2928489040978298353[177] = 0.0;
   out_2928489040978298353[178] = 0.0;
   out_2928489040978298353[179] = 0.0;
   out_2928489040978298353[180] = 0.0;
   out_2928489040978298353[181] = 0.0;
   out_2928489040978298353[182] = 0.0;
   out_2928489040978298353[183] = 0.0;
   out_2928489040978298353[184] = 0.0;
   out_2928489040978298353[185] = 0.0;
   out_2928489040978298353[186] = 0.0;
   out_2928489040978298353[187] = 0.0;
   out_2928489040978298353[188] = 0.0;
   out_2928489040978298353[189] = 0.0;
   out_2928489040978298353[190] = 1.0;
   out_2928489040978298353[191] = 0.0;
   out_2928489040978298353[192] = 0.0;
   out_2928489040978298353[193] = 0.0;
   out_2928489040978298353[194] = 0.0;
   out_2928489040978298353[195] = 0.0;
   out_2928489040978298353[196] = 0.0;
   out_2928489040978298353[197] = 0.0;
   out_2928489040978298353[198] = 0.0;
   out_2928489040978298353[199] = 0.0;
   out_2928489040978298353[200] = 0.0;
   out_2928489040978298353[201] = 0.0;
   out_2928489040978298353[202] = 0.0;
   out_2928489040978298353[203] = 0.0;
   out_2928489040978298353[204] = 0.0;
   out_2928489040978298353[205] = 0.0;
   out_2928489040978298353[206] = 0.0;
   out_2928489040978298353[207] = 0.0;
   out_2928489040978298353[208] = 0.0;
   out_2928489040978298353[209] = 1.0;
   out_2928489040978298353[210] = 0.0;
   out_2928489040978298353[211] = 0.0;
   out_2928489040978298353[212] = 0.0;
   out_2928489040978298353[213] = 0.0;
   out_2928489040978298353[214] = 0.0;
   out_2928489040978298353[215] = 0.0;
   out_2928489040978298353[216] = 0.0;
   out_2928489040978298353[217] = 0.0;
   out_2928489040978298353[218] = 0.0;
   out_2928489040978298353[219] = 0.0;
   out_2928489040978298353[220] = 0.0;
   out_2928489040978298353[221] = 0.0;
   out_2928489040978298353[222] = 0.0;
   out_2928489040978298353[223] = 0.0;
   out_2928489040978298353[224] = 0.0;
   out_2928489040978298353[225] = 0.0;
   out_2928489040978298353[226] = 0.0;
   out_2928489040978298353[227] = 0.0;
   out_2928489040978298353[228] = 1.0;
   out_2928489040978298353[229] = 0.0;
   out_2928489040978298353[230] = 0.0;
   out_2928489040978298353[231] = 0.0;
   out_2928489040978298353[232] = 0.0;
   out_2928489040978298353[233] = 0.0;
   out_2928489040978298353[234] = 0.0;
   out_2928489040978298353[235] = 0.0;
   out_2928489040978298353[236] = 0.0;
   out_2928489040978298353[237] = 0.0;
   out_2928489040978298353[238] = 0.0;
   out_2928489040978298353[239] = 0.0;
   out_2928489040978298353[240] = 0.0;
   out_2928489040978298353[241] = 0.0;
   out_2928489040978298353[242] = 0.0;
   out_2928489040978298353[243] = 0.0;
   out_2928489040978298353[244] = 0.0;
   out_2928489040978298353[245] = 0.0;
   out_2928489040978298353[246] = 0.0;
   out_2928489040978298353[247] = 1.0;
   out_2928489040978298353[248] = 0.0;
   out_2928489040978298353[249] = 0.0;
   out_2928489040978298353[250] = 0.0;
   out_2928489040978298353[251] = 0.0;
   out_2928489040978298353[252] = 0.0;
   out_2928489040978298353[253] = 0.0;
   out_2928489040978298353[254] = 0.0;
   out_2928489040978298353[255] = 0.0;
   out_2928489040978298353[256] = 0.0;
   out_2928489040978298353[257] = 0.0;
   out_2928489040978298353[258] = 0.0;
   out_2928489040978298353[259] = 0.0;
   out_2928489040978298353[260] = 0.0;
   out_2928489040978298353[261] = 0.0;
   out_2928489040978298353[262] = 0.0;
   out_2928489040978298353[263] = 0.0;
   out_2928489040978298353[264] = 0.0;
   out_2928489040978298353[265] = 0.0;
   out_2928489040978298353[266] = 1.0;
   out_2928489040978298353[267] = 0.0;
   out_2928489040978298353[268] = 0.0;
   out_2928489040978298353[269] = 0.0;
   out_2928489040978298353[270] = 0.0;
   out_2928489040978298353[271] = 0.0;
   out_2928489040978298353[272] = 0.0;
   out_2928489040978298353[273] = 0.0;
   out_2928489040978298353[274] = 0.0;
   out_2928489040978298353[275] = 0.0;
   out_2928489040978298353[276] = 0.0;
   out_2928489040978298353[277] = 0.0;
   out_2928489040978298353[278] = 0.0;
   out_2928489040978298353[279] = 0.0;
   out_2928489040978298353[280] = 0.0;
   out_2928489040978298353[281] = 0.0;
   out_2928489040978298353[282] = 0.0;
   out_2928489040978298353[283] = 0.0;
   out_2928489040978298353[284] = 0.0;
   out_2928489040978298353[285] = 1.0;
   out_2928489040978298353[286] = 0.0;
   out_2928489040978298353[287] = 0.0;
   out_2928489040978298353[288] = 0.0;
   out_2928489040978298353[289] = 0.0;
   out_2928489040978298353[290] = 0.0;
   out_2928489040978298353[291] = 0.0;
   out_2928489040978298353[292] = 0.0;
   out_2928489040978298353[293] = 0.0;
   out_2928489040978298353[294] = 0.0;
   out_2928489040978298353[295] = 0.0;
   out_2928489040978298353[296] = 0.0;
   out_2928489040978298353[297] = 0.0;
   out_2928489040978298353[298] = 0.0;
   out_2928489040978298353[299] = 0.0;
   out_2928489040978298353[300] = 0.0;
   out_2928489040978298353[301] = 0.0;
   out_2928489040978298353[302] = 0.0;
   out_2928489040978298353[303] = 0.0;
   out_2928489040978298353[304] = 1.0;
   out_2928489040978298353[305] = 0.0;
   out_2928489040978298353[306] = 0.0;
   out_2928489040978298353[307] = 0.0;
   out_2928489040978298353[308] = 0.0;
   out_2928489040978298353[309] = 0.0;
   out_2928489040978298353[310] = 0.0;
   out_2928489040978298353[311] = 0.0;
   out_2928489040978298353[312] = 0.0;
   out_2928489040978298353[313] = 0.0;
   out_2928489040978298353[314] = 0.0;
   out_2928489040978298353[315] = 0.0;
   out_2928489040978298353[316] = 0.0;
   out_2928489040978298353[317] = 0.0;
   out_2928489040978298353[318] = 0.0;
   out_2928489040978298353[319] = 0.0;
   out_2928489040978298353[320] = 0.0;
   out_2928489040978298353[321] = 0.0;
   out_2928489040978298353[322] = 0.0;
   out_2928489040978298353[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_2323113914602961191) {
   out_2323113914602961191[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_2323113914602961191[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_2323113914602961191[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_2323113914602961191[3] = dt*state[12] + state[3];
   out_2323113914602961191[4] = dt*state[13] + state[4];
   out_2323113914602961191[5] = dt*state[14] + state[5];
   out_2323113914602961191[6] = state[6];
   out_2323113914602961191[7] = state[7];
   out_2323113914602961191[8] = state[8];
   out_2323113914602961191[9] = state[9];
   out_2323113914602961191[10] = state[10];
   out_2323113914602961191[11] = state[11];
   out_2323113914602961191[12] = state[12];
   out_2323113914602961191[13] = state[13];
   out_2323113914602961191[14] = state[14];
   out_2323113914602961191[15] = state[15];
   out_2323113914602961191[16] = state[16];
   out_2323113914602961191[17] = state[17];
}
void F_fun(double *state, double dt, double *out_6901050174259076486) {
   out_6901050174259076486[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6901050174259076486[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6901050174259076486[2] = 0;
   out_6901050174259076486[3] = 0;
   out_6901050174259076486[4] = 0;
   out_6901050174259076486[5] = 0;
   out_6901050174259076486[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6901050174259076486[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6901050174259076486[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_6901050174259076486[9] = 0;
   out_6901050174259076486[10] = 0;
   out_6901050174259076486[11] = 0;
   out_6901050174259076486[12] = 0;
   out_6901050174259076486[13] = 0;
   out_6901050174259076486[14] = 0;
   out_6901050174259076486[15] = 0;
   out_6901050174259076486[16] = 0;
   out_6901050174259076486[17] = 0;
   out_6901050174259076486[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6901050174259076486[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6901050174259076486[20] = 0;
   out_6901050174259076486[21] = 0;
   out_6901050174259076486[22] = 0;
   out_6901050174259076486[23] = 0;
   out_6901050174259076486[24] = 0;
   out_6901050174259076486[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6901050174259076486[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_6901050174259076486[27] = 0;
   out_6901050174259076486[28] = 0;
   out_6901050174259076486[29] = 0;
   out_6901050174259076486[30] = 0;
   out_6901050174259076486[31] = 0;
   out_6901050174259076486[32] = 0;
   out_6901050174259076486[33] = 0;
   out_6901050174259076486[34] = 0;
   out_6901050174259076486[35] = 0;
   out_6901050174259076486[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6901050174259076486[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6901050174259076486[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6901050174259076486[39] = 0;
   out_6901050174259076486[40] = 0;
   out_6901050174259076486[41] = 0;
   out_6901050174259076486[42] = 0;
   out_6901050174259076486[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6901050174259076486[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_6901050174259076486[45] = 0;
   out_6901050174259076486[46] = 0;
   out_6901050174259076486[47] = 0;
   out_6901050174259076486[48] = 0;
   out_6901050174259076486[49] = 0;
   out_6901050174259076486[50] = 0;
   out_6901050174259076486[51] = 0;
   out_6901050174259076486[52] = 0;
   out_6901050174259076486[53] = 0;
   out_6901050174259076486[54] = 0;
   out_6901050174259076486[55] = 0;
   out_6901050174259076486[56] = 0;
   out_6901050174259076486[57] = 1;
   out_6901050174259076486[58] = 0;
   out_6901050174259076486[59] = 0;
   out_6901050174259076486[60] = 0;
   out_6901050174259076486[61] = 0;
   out_6901050174259076486[62] = 0;
   out_6901050174259076486[63] = 0;
   out_6901050174259076486[64] = 0;
   out_6901050174259076486[65] = 0;
   out_6901050174259076486[66] = dt;
   out_6901050174259076486[67] = 0;
   out_6901050174259076486[68] = 0;
   out_6901050174259076486[69] = 0;
   out_6901050174259076486[70] = 0;
   out_6901050174259076486[71] = 0;
   out_6901050174259076486[72] = 0;
   out_6901050174259076486[73] = 0;
   out_6901050174259076486[74] = 0;
   out_6901050174259076486[75] = 0;
   out_6901050174259076486[76] = 1;
   out_6901050174259076486[77] = 0;
   out_6901050174259076486[78] = 0;
   out_6901050174259076486[79] = 0;
   out_6901050174259076486[80] = 0;
   out_6901050174259076486[81] = 0;
   out_6901050174259076486[82] = 0;
   out_6901050174259076486[83] = 0;
   out_6901050174259076486[84] = 0;
   out_6901050174259076486[85] = dt;
   out_6901050174259076486[86] = 0;
   out_6901050174259076486[87] = 0;
   out_6901050174259076486[88] = 0;
   out_6901050174259076486[89] = 0;
   out_6901050174259076486[90] = 0;
   out_6901050174259076486[91] = 0;
   out_6901050174259076486[92] = 0;
   out_6901050174259076486[93] = 0;
   out_6901050174259076486[94] = 0;
   out_6901050174259076486[95] = 1;
   out_6901050174259076486[96] = 0;
   out_6901050174259076486[97] = 0;
   out_6901050174259076486[98] = 0;
   out_6901050174259076486[99] = 0;
   out_6901050174259076486[100] = 0;
   out_6901050174259076486[101] = 0;
   out_6901050174259076486[102] = 0;
   out_6901050174259076486[103] = 0;
   out_6901050174259076486[104] = dt;
   out_6901050174259076486[105] = 0;
   out_6901050174259076486[106] = 0;
   out_6901050174259076486[107] = 0;
   out_6901050174259076486[108] = 0;
   out_6901050174259076486[109] = 0;
   out_6901050174259076486[110] = 0;
   out_6901050174259076486[111] = 0;
   out_6901050174259076486[112] = 0;
   out_6901050174259076486[113] = 0;
   out_6901050174259076486[114] = 1;
   out_6901050174259076486[115] = 0;
   out_6901050174259076486[116] = 0;
   out_6901050174259076486[117] = 0;
   out_6901050174259076486[118] = 0;
   out_6901050174259076486[119] = 0;
   out_6901050174259076486[120] = 0;
   out_6901050174259076486[121] = 0;
   out_6901050174259076486[122] = 0;
   out_6901050174259076486[123] = 0;
   out_6901050174259076486[124] = 0;
   out_6901050174259076486[125] = 0;
   out_6901050174259076486[126] = 0;
   out_6901050174259076486[127] = 0;
   out_6901050174259076486[128] = 0;
   out_6901050174259076486[129] = 0;
   out_6901050174259076486[130] = 0;
   out_6901050174259076486[131] = 0;
   out_6901050174259076486[132] = 0;
   out_6901050174259076486[133] = 1;
   out_6901050174259076486[134] = 0;
   out_6901050174259076486[135] = 0;
   out_6901050174259076486[136] = 0;
   out_6901050174259076486[137] = 0;
   out_6901050174259076486[138] = 0;
   out_6901050174259076486[139] = 0;
   out_6901050174259076486[140] = 0;
   out_6901050174259076486[141] = 0;
   out_6901050174259076486[142] = 0;
   out_6901050174259076486[143] = 0;
   out_6901050174259076486[144] = 0;
   out_6901050174259076486[145] = 0;
   out_6901050174259076486[146] = 0;
   out_6901050174259076486[147] = 0;
   out_6901050174259076486[148] = 0;
   out_6901050174259076486[149] = 0;
   out_6901050174259076486[150] = 0;
   out_6901050174259076486[151] = 0;
   out_6901050174259076486[152] = 1;
   out_6901050174259076486[153] = 0;
   out_6901050174259076486[154] = 0;
   out_6901050174259076486[155] = 0;
   out_6901050174259076486[156] = 0;
   out_6901050174259076486[157] = 0;
   out_6901050174259076486[158] = 0;
   out_6901050174259076486[159] = 0;
   out_6901050174259076486[160] = 0;
   out_6901050174259076486[161] = 0;
   out_6901050174259076486[162] = 0;
   out_6901050174259076486[163] = 0;
   out_6901050174259076486[164] = 0;
   out_6901050174259076486[165] = 0;
   out_6901050174259076486[166] = 0;
   out_6901050174259076486[167] = 0;
   out_6901050174259076486[168] = 0;
   out_6901050174259076486[169] = 0;
   out_6901050174259076486[170] = 0;
   out_6901050174259076486[171] = 1;
   out_6901050174259076486[172] = 0;
   out_6901050174259076486[173] = 0;
   out_6901050174259076486[174] = 0;
   out_6901050174259076486[175] = 0;
   out_6901050174259076486[176] = 0;
   out_6901050174259076486[177] = 0;
   out_6901050174259076486[178] = 0;
   out_6901050174259076486[179] = 0;
   out_6901050174259076486[180] = 0;
   out_6901050174259076486[181] = 0;
   out_6901050174259076486[182] = 0;
   out_6901050174259076486[183] = 0;
   out_6901050174259076486[184] = 0;
   out_6901050174259076486[185] = 0;
   out_6901050174259076486[186] = 0;
   out_6901050174259076486[187] = 0;
   out_6901050174259076486[188] = 0;
   out_6901050174259076486[189] = 0;
   out_6901050174259076486[190] = 1;
   out_6901050174259076486[191] = 0;
   out_6901050174259076486[192] = 0;
   out_6901050174259076486[193] = 0;
   out_6901050174259076486[194] = 0;
   out_6901050174259076486[195] = 0;
   out_6901050174259076486[196] = 0;
   out_6901050174259076486[197] = 0;
   out_6901050174259076486[198] = 0;
   out_6901050174259076486[199] = 0;
   out_6901050174259076486[200] = 0;
   out_6901050174259076486[201] = 0;
   out_6901050174259076486[202] = 0;
   out_6901050174259076486[203] = 0;
   out_6901050174259076486[204] = 0;
   out_6901050174259076486[205] = 0;
   out_6901050174259076486[206] = 0;
   out_6901050174259076486[207] = 0;
   out_6901050174259076486[208] = 0;
   out_6901050174259076486[209] = 1;
   out_6901050174259076486[210] = 0;
   out_6901050174259076486[211] = 0;
   out_6901050174259076486[212] = 0;
   out_6901050174259076486[213] = 0;
   out_6901050174259076486[214] = 0;
   out_6901050174259076486[215] = 0;
   out_6901050174259076486[216] = 0;
   out_6901050174259076486[217] = 0;
   out_6901050174259076486[218] = 0;
   out_6901050174259076486[219] = 0;
   out_6901050174259076486[220] = 0;
   out_6901050174259076486[221] = 0;
   out_6901050174259076486[222] = 0;
   out_6901050174259076486[223] = 0;
   out_6901050174259076486[224] = 0;
   out_6901050174259076486[225] = 0;
   out_6901050174259076486[226] = 0;
   out_6901050174259076486[227] = 0;
   out_6901050174259076486[228] = 1;
   out_6901050174259076486[229] = 0;
   out_6901050174259076486[230] = 0;
   out_6901050174259076486[231] = 0;
   out_6901050174259076486[232] = 0;
   out_6901050174259076486[233] = 0;
   out_6901050174259076486[234] = 0;
   out_6901050174259076486[235] = 0;
   out_6901050174259076486[236] = 0;
   out_6901050174259076486[237] = 0;
   out_6901050174259076486[238] = 0;
   out_6901050174259076486[239] = 0;
   out_6901050174259076486[240] = 0;
   out_6901050174259076486[241] = 0;
   out_6901050174259076486[242] = 0;
   out_6901050174259076486[243] = 0;
   out_6901050174259076486[244] = 0;
   out_6901050174259076486[245] = 0;
   out_6901050174259076486[246] = 0;
   out_6901050174259076486[247] = 1;
   out_6901050174259076486[248] = 0;
   out_6901050174259076486[249] = 0;
   out_6901050174259076486[250] = 0;
   out_6901050174259076486[251] = 0;
   out_6901050174259076486[252] = 0;
   out_6901050174259076486[253] = 0;
   out_6901050174259076486[254] = 0;
   out_6901050174259076486[255] = 0;
   out_6901050174259076486[256] = 0;
   out_6901050174259076486[257] = 0;
   out_6901050174259076486[258] = 0;
   out_6901050174259076486[259] = 0;
   out_6901050174259076486[260] = 0;
   out_6901050174259076486[261] = 0;
   out_6901050174259076486[262] = 0;
   out_6901050174259076486[263] = 0;
   out_6901050174259076486[264] = 0;
   out_6901050174259076486[265] = 0;
   out_6901050174259076486[266] = 1;
   out_6901050174259076486[267] = 0;
   out_6901050174259076486[268] = 0;
   out_6901050174259076486[269] = 0;
   out_6901050174259076486[270] = 0;
   out_6901050174259076486[271] = 0;
   out_6901050174259076486[272] = 0;
   out_6901050174259076486[273] = 0;
   out_6901050174259076486[274] = 0;
   out_6901050174259076486[275] = 0;
   out_6901050174259076486[276] = 0;
   out_6901050174259076486[277] = 0;
   out_6901050174259076486[278] = 0;
   out_6901050174259076486[279] = 0;
   out_6901050174259076486[280] = 0;
   out_6901050174259076486[281] = 0;
   out_6901050174259076486[282] = 0;
   out_6901050174259076486[283] = 0;
   out_6901050174259076486[284] = 0;
   out_6901050174259076486[285] = 1;
   out_6901050174259076486[286] = 0;
   out_6901050174259076486[287] = 0;
   out_6901050174259076486[288] = 0;
   out_6901050174259076486[289] = 0;
   out_6901050174259076486[290] = 0;
   out_6901050174259076486[291] = 0;
   out_6901050174259076486[292] = 0;
   out_6901050174259076486[293] = 0;
   out_6901050174259076486[294] = 0;
   out_6901050174259076486[295] = 0;
   out_6901050174259076486[296] = 0;
   out_6901050174259076486[297] = 0;
   out_6901050174259076486[298] = 0;
   out_6901050174259076486[299] = 0;
   out_6901050174259076486[300] = 0;
   out_6901050174259076486[301] = 0;
   out_6901050174259076486[302] = 0;
   out_6901050174259076486[303] = 0;
   out_6901050174259076486[304] = 1;
   out_6901050174259076486[305] = 0;
   out_6901050174259076486[306] = 0;
   out_6901050174259076486[307] = 0;
   out_6901050174259076486[308] = 0;
   out_6901050174259076486[309] = 0;
   out_6901050174259076486[310] = 0;
   out_6901050174259076486[311] = 0;
   out_6901050174259076486[312] = 0;
   out_6901050174259076486[313] = 0;
   out_6901050174259076486[314] = 0;
   out_6901050174259076486[315] = 0;
   out_6901050174259076486[316] = 0;
   out_6901050174259076486[317] = 0;
   out_6901050174259076486[318] = 0;
   out_6901050174259076486[319] = 0;
   out_6901050174259076486[320] = 0;
   out_6901050174259076486[321] = 0;
   out_6901050174259076486[322] = 0;
   out_6901050174259076486[323] = 1;
}
void h_4(double *state, double *unused, double *out_2996611270475893358) {
   out_2996611270475893358[0] = state[6] + state[9];
   out_2996611270475893358[1] = state[7] + state[10];
   out_2996611270475893358[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_4621784882735821210) {
   out_4621784882735821210[0] = 0;
   out_4621784882735821210[1] = 0;
   out_4621784882735821210[2] = 0;
   out_4621784882735821210[3] = 0;
   out_4621784882735821210[4] = 0;
   out_4621784882735821210[5] = 0;
   out_4621784882735821210[6] = 1;
   out_4621784882735821210[7] = 0;
   out_4621784882735821210[8] = 0;
   out_4621784882735821210[9] = 1;
   out_4621784882735821210[10] = 0;
   out_4621784882735821210[11] = 0;
   out_4621784882735821210[12] = 0;
   out_4621784882735821210[13] = 0;
   out_4621784882735821210[14] = 0;
   out_4621784882735821210[15] = 0;
   out_4621784882735821210[16] = 0;
   out_4621784882735821210[17] = 0;
   out_4621784882735821210[18] = 0;
   out_4621784882735821210[19] = 0;
   out_4621784882735821210[20] = 0;
   out_4621784882735821210[21] = 0;
   out_4621784882735821210[22] = 0;
   out_4621784882735821210[23] = 0;
   out_4621784882735821210[24] = 0;
   out_4621784882735821210[25] = 1;
   out_4621784882735821210[26] = 0;
   out_4621784882735821210[27] = 0;
   out_4621784882735821210[28] = 1;
   out_4621784882735821210[29] = 0;
   out_4621784882735821210[30] = 0;
   out_4621784882735821210[31] = 0;
   out_4621784882735821210[32] = 0;
   out_4621784882735821210[33] = 0;
   out_4621784882735821210[34] = 0;
   out_4621784882735821210[35] = 0;
   out_4621784882735821210[36] = 0;
   out_4621784882735821210[37] = 0;
   out_4621784882735821210[38] = 0;
   out_4621784882735821210[39] = 0;
   out_4621784882735821210[40] = 0;
   out_4621784882735821210[41] = 0;
   out_4621784882735821210[42] = 0;
   out_4621784882735821210[43] = 0;
   out_4621784882735821210[44] = 1;
   out_4621784882735821210[45] = 0;
   out_4621784882735821210[46] = 0;
   out_4621784882735821210[47] = 1;
   out_4621784882735821210[48] = 0;
   out_4621784882735821210[49] = 0;
   out_4621784882735821210[50] = 0;
   out_4621784882735821210[51] = 0;
   out_4621784882735821210[52] = 0;
   out_4621784882735821210[53] = 0;
}
void h_10(double *state, double *unused, double *out_961907255194536489) {
   out_961907255194536489[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_961907255194536489[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_961907255194536489[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6481820587514982003) {
   out_6481820587514982003[0] = 0;
   out_6481820587514982003[1] = 9.8100000000000005*cos(state[1]);
   out_6481820587514982003[2] = 0;
   out_6481820587514982003[3] = 0;
   out_6481820587514982003[4] = -state[8];
   out_6481820587514982003[5] = state[7];
   out_6481820587514982003[6] = 0;
   out_6481820587514982003[7] = state[5];
   out_6481820587514982003[8] = -state[4];
   out_6481820587514982003[9] = 0;
   out_6481820587514982003[10] = 0;
   out_6481820587514982003[11] = 0;
   out_6481820587514982003[12] = 1;
   out_6481820587514982003[13] = 0;
   out_6481820587514982003[14] = 0;
   out_6481820587514982003[15] = 1;
   out_6481820587514982003[16] = 0;
   out_6481820587514982003[17] = 0;
   out_6481820587514982003[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6481820587514982003[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6481820587514982003[20] = 0;
   out_6481820587514982003[21] = state[8];
   out_6481820587514982003[22] = 0;
   out_6481820587514982003[23] = -state[6];
   out_6481820587514982003[24] = -state[5];
   out_6481820587514982003[25] = 0;
   out_6481820587514982003[26] = state[3];
   out_6481820587514982003[27] = 0;
   out_6481820587514982003[28] = 0;
   out_6481820587514982003[29] = 0;
   out_6481820587514982003[30] = 0;
   out_6481820587514982003[31] = 1;
   out_6481820587514982003[32] = 0;
   out_6481820587514982003[33] = 0;
   out_6481820587514982003[34] = 1;
   out_6481820587514982003[35] = 0;
   out_6481820587514982003[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6481820587514982003[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6481820587514982003[38] = 0;
   out_6481820587514982003[39] = -state[7];
   out_6481820587514982003[40] = state[6];
   out_6481820587514982003[41] = 0;
   out_6481820587514982003[42] = state[4];
   out_6481820587514982003[43] = -state[3];
   out_6481820587514982003[44] = 0;
   out_6481820587514982003[45] = 0;
   out_6481820587514982003[46] = 0;
   out_6481820587514982003[47] = 0;
   out_6481820587514982003[48] = 0;
   out_6481820587514982003[49] = 0;
   out_6481820587514982003[50] = 1;
   out_6481820587514982003[51] = 0;
   out_6481820587514982003[52] = 0;
   out_6481820587514982003[53] = 1;
}
void h_13(double *state, double *unused, double *out_5073206363808515425) {
   out_5073206363808515425[0] = state[3];
   out_5073206363808515425[1] = state[4];
   out_5073206363808515425[2] = state[5];
}
void H_13(double *state, double *unused, double *out_2988846325580879719) {
   out_2988846325580879719[0] = 0;
   out_2988846325580879719[1] = 0;
   out_2988846325580879719[2] = 0;
   out_2988846325580879719[3] = 1;
   out_2988846325580879719[4] = 0;
   out_2988846325580879719[5] = 0;
   out_2988846325580879719[6] = 0;
   out_2988846325580879719[7] = 0;
   out_2988846325580879719[8] = 0;
   out_2988846325580879719[9] = 0;
   out_2988846325580879719[10] = 0;
   out_2988846325580879719[11] = 0;
   out_2988846325580879719[12] = 0;
   out_2988846325580879719[13] = 0;
   out_2988846325580879719[14] = 0;
   out_2988846325580879719[15] = 0;
   out_2988846325580879719[16] = 0;
   out_2988846325580879719[17] = 0;
   out_2988846325580879719[18] = 0;
   out_2988846325580879719[19] = 0;
   out_2988846325580879719[20] = 0;
   out_2988846325580879719[21] = 0;
   out_2988846325580879719[22] = 1;
   out_2988846325580879719[23] = 0;
   out_2988846325580879719[24] = 0;
   out_2988846325580879719[25] = 0;
   out_2988846325580879719[26] = 0;
   out_2988846325580879719[27] = 0;
   out_2988846325580879719[28] = 0;
   out_2988846325580879719[29] = 0;
   out_2988846325580879719[30] = 0;
   out_2988846325580879719[31] = 0;
   out_2988846325580879719[32] = 0;
   out_2988846325580879719[33] = 0;
   out_2988846325580879719[34] = 0;
   out_2988846325580879719[35] = 0;
   out_2988846325580879719[36] = 0;
   out_2988846325580879719[37] = 0;
   out_2988846325580879719[38] = 0;
   out_2988846325580879719[39] = 0;
   out_2988846325580879719[40] = 0;
   out_2988846325580879719[41] = 1;
   out_2988846325580879719[42] = 0;
   out_2988846325580879719[43] = 0;
   out_2988846325580879719[44] = 0;
   out_2988846325580879719[45] = 0;
   out_2988846325580879719[46] = 0;
   out_2988846325580879719[47] = 0;
   out_2988846325580879719[48] = 0;
   out_2988846325580879719[49] = 0;
   out_2988846325580879719[50] = 0;
   out_2988846325580879719[51] = 0;
   out_2988846325580879719[52] = 0;
   out_2988846325580879719[53] = 0;
}
void h_14(double *state, double *unused, double *out_5922811292220657062) {
   out_5922811292220657062[0] = state[6];
   out_5922811292220657062[1] = state[7];
   out_5922811292220657062[2] = state[8];
}
void H_14(double *state, double *unused, double *out_7704573315031193506) {
   out_7704573315031193506[0] = 0;
   out_7704573315031193506[1] = 0;
   out_7704573315031193506[2] = 0;
   out_7704573315031193506[3] = 0;
   out_7704573315031193506[4] = 0;
   out_7704573315031193506[5] = 0;
   out_7704573315031193506[6] = 1;
   out_7704573315031193506[7] = 0;
   out_7704573315031193506[8] = 0;
   out_7704573315031193506[9] = 0;
   out_7704573315031193506[10] = 0;
   out_7704573315031193506[11] = 0;
   out_7704573315031193506[12] = 0;
   out_7704573315031193506[13] = 0;
   out_7704573315031193506[14] = 0;
   out_7704573315031193506[15] = 0;
   out_7704573315031193506[16] = 0;
   out_7704573315031193506[17] = 0;
   out_7704573315031193506[18] = 0;
   out_7704573315031193506[19] = 0;
   out_7704573315031193506[20] = 0;
   out_7704573315031193506[21] = 0;
   out_7704573315031193506[22] = 0;
   out_7704573315031193506[23] = 0;
   out_7704573315031193506[24] = 0;
   out_7704573315031193506[25] = 1;
   out_7704573315031193506[26] = 0;
   out_7704573315031193506[27] = 0;
   out_7704573315031193506[28] = 0;
   out_7704573315031193506[29] = 0;
   out_7704573315031193506[30] = 0;
   out_7704573315031193506[31] = 0;
   out_7704573315031193506[32] = 0;
   out_7704573315031193506[33] = 0;
   out_7704573315031193506[34] = 0;
   out_7704573315031193506[35] = 0;
   out_7704573315031193506[36] = 0;
   out_7704573315031193506[37] = 0;
   out_7704573315031193506[38] = 0;
   out_7704573315031193506[39] = 0;
   out_7704573315031193506[40] = 0;
   out_7704573315031193506[41] = 0;
   out_7704573315031193506[42] = 0;
   out_7704573315031193506[43] = 0;
   out_7704573315031193506[44] = 1;
   out_7704573315031193506[45] = 0;
   out_7704573315031193506[46] = 0;
   out_7704573315031193506[47] = 0;
   out_7704573315031193506[48] = 0;
   out_7704573315031193506[49] = 0;
   out_7704573315031193506[50] = 0;
   out_7704573315031193506[51] = 0;
   out_7704573315031193506[52] = 0;
   out_7704573315031193506[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_8670698209167984406) {
  err_fun(nom_x, delta_x, out_8670698209167984406);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_9015049238036164588) {
  inv_err_fun(nom_x, true_x, out_9015049238036164588);
}
void pose_H_mod_fun(double *state, double *out_2928489040978298353) {
  H_mod_fun(state, out_2928489040978298353);
}
void pose_f_fun(double *state, double dt, double *out_2323113914602961191) {
  f_fun(state,  dt, out_2323113914602961191);
}
void pose_F_fun(double *state, double dt, double *out_6901050174259076486) {
  F_fun(state,  dt, out_6901050174259076486);
}
void pose_h_4(double *state, double *unused, double *out_2996611270475893358) {
  h_4(state, unused, out_2996611270475893358);
}
void pose_H_4(double *state, double *unused, double *out_4621784882735821210) {
  H_4(state, unused, out_4621784882735821210);
}
void pose_h_10(double *state, double *unused, double *out_961907255194536489) {
  h_10(state, unused, out_961907255194536489);
}
void pose_H_10(double *state, double *unused, double *out_6481820587514982003) {
  H_10(state, unused, out_6481820587514982003);
}
void pose_h_13(double *state, double *unused, double *out_5073206363808515425) {
  h_13(state, unused, out_5073206363808515425);
}
void pose_H_13(double *state, double *unused, double *out_2988846325580879719) {
  H_13(state, unused, out_2988846325580879719);
}
void pose_h_14(double *state, double *unused, double *out_5922811292220657062) {
  h_14(state, unused, out_5922811292220657062);
}
void pose_H_14(double *state, double *unused, double *out_7704573315031193506) {
  H_14(state, unused, out_7704573315031193506);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
