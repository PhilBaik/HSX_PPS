VDC = 50;
%%
Vf = 4.5;
Ra = 0.0096;
La = 0.02;
Rf = 0.0054;
Lf = 0.0125;
Laf = 0.00847;
J = 137;

% Vf = 4.5;
% Ra = 0.0096;
% La = 0.002;
% Rf = 0.0054;
% Lf = 0.0125;
% Laf = 0.00847;
% J = 137;

n_initial = 1700;
w_initial = n_initial/60*2*pi;

tau_field = Lf/Rf;
RHSX = 0.09;
LHSX = 0.02;

%% Series 1
Vf = 3.1

% Kp = 1
% Ki = 1
Kanti = 0
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

Lc = 1e-4;

Ltot = Lc+ La +LHSX
Rtot = RHSX+Ra
k = 50
Kp = k*Ltot
Ki = -k*Rtot

