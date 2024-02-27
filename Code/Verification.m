% Load requirement test

clc
clear
close all

addpath('Test\')
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

fs = 5e3;          %% Switchign frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;

fsamp = 50e3;
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
Kp = 0.03
Ki = 0.003
Kanti = 0.95
% Ki = 0
% Kanti = 0
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
%%
figure(1)
plot(only_16gen.time,only_16gen.Io,'k');grid on;
title('i_2')

figure(2)
plot(only_16gen.time,only_16gen.Va)