
clc
clear
close all

%%
Ra = 0.0096;
La = 0.002;
Rf = 0.0054;
Lf = 0.0125;
Laf = 0.00847;
J = 137;
RHSX = 0.09;
LHSX = 0.02;
Lc = 1e-3;
n = 2;

Ltot = LHSX+La+Lc/n;
Rtot = Ra+RHSX;
%% Series 1
VDC = 50;
Vf = 3.1
n = 1;
Ltot = LHSX+La+Lc/n;
K = 30;
Kp = K*Ltot;
Ki = -K*Rtot;
% Kp = 1
% Ki = 1
Kanti = 0
% Ki = 0
% Kanti = 0
Ilimit = 2000

T_trigger = 15
T_end = 20
fs = 1e3;          %% Switching frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 50e3;
Tsamp = 1/fsamp;

n_module = 1;
Phase_shift = Ts/n_module;
z_phase_shift = round(Phase_shift/Tdead);
flat_del_t = 1;

%% Multi 1
VDC = 50;
Vf = 3.1
K = 100
Kp = K*Ltot;
Ki = -K*Rtot;
% Kp = 1
% Ki = 1
Kanti = 0.95
% Ki = 0
% Kanti = 0
Ilimit = 2000

T_trigger = 4
T_end = 5.5
fs = 1e3;          %% Switching frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 50e3;
Tsamp = 1/fsamp;

n_module = 2;
Phase_shift = Ts/n_module;
z_phase_shift = round(Phase_shift/Tdead);
flat_del_t = 1;