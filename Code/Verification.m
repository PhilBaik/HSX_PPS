% Load requirement test

clc
clear
close all

addpath('Test\')
%%
Vf = 4.5;
Ra = 0.0096;
La = 0.002;
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

fs = 5e3;          %% Switching frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 500e3;
Tsamp = 1/fsamp;

flat_del_t = 1;
%% simulink 
only_16gen_sim = sim('Test\HSX_16_model.slx');
%%
only_16gen.time = only_16gen_sim.tout';
only_16gen.Io = only_16gen_sim.Io.data';
only_16gen.Va = only_16gen_sim.Vo.data';
[only_16gen.maxIo only_16gen.maxIndex] = max(only_16gen.Io)
%%
max_current_t = only_16gen.time(1,only_16gen.maxIndex)
target_t = flat_del_t + max_current_t;
only_16gen.max_needed_current = only_16gen.maxIo-only_16gen.Io(1,find(only_16gen.time>target_t,1));

%% Parallel
Kp = 0.001
Kp = 0.1
Ki = 10
Kanti = 0.98
Ilimit = 2000

%% Series 1
Kp = 50
Ki = 100
Kanti = 0.8
Ki = 0
Kanti = 0
Ilimit = 2000

T_trigger = 20
T_end = 40
fs = 5e3;          %% Switchign frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 50e3;
Tsamp = 1/fsamp;

flat_del_t = 1;
%% Series 1
Vf = 3.1
Kp = 0.5
Ki = 0.006
% Kp = 1
% Ki = 1
Kanti = 0.98
% Ki = 0
% Kanti = 0
Ilimit = 2000

T_trigger = 4
T_end = 5.5
fs = 1e3;          %% Switching frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 500e3;
Tsamp = 1/fsamp;

n_module = 2;
Phase_shift = Ts/n_module;
z_phase_shift = round(Phase_shift/Tdead);
flat_del_t = 1;

%%
figure(1)
plot(only_16gen.time,only_16gen.Io,'k');grid on;
title('i_2')

figure(2)
plot(only_16gen.time,only_16gen.Va)