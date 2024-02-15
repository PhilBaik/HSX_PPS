%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%% Author: Hyeongmeen Baik
%%%%%%%%%%%% Date: 02/13/2024
%%%%%%%%%%%% Title: HSX Simulation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc
clear
close all
%%
Vf = 4;
Ra = 0.0096;
La = 0.002;
Rf = 0.0054;
Lf = 0.0125;
Laf = 0.00847;
J = 137;
w_initial = 163.55;
n_initial = w_initial/2/pi*60;



tau_field = Lf/Rf;
RHSX = 0.09;
LHSX = 0.02;

Cs_fet = inf        %% snubber capacitance of ideal switch 
Rs_fet = 1e8  %% snubber resistance of ideal switch
Vf = 0.6            %% Body diode drop 

fss = 5e3;          %% Switchign frequency
Tss = 1/fss;
Tdead = Tss/100;

%%
% Open Circuit Test (Back EMF)

OCout = sim('OC_test.slx')

%%
tt = OCout.ArmatureVoltage.Time';
OC_E = OCout.ArmatureVoltage.Data';
OC_w = OCout.simout.Speed_wm__rad_s_.Data';
OC_If = OCout.simout.Field_current_if__A_.Data';

max(OC_If)
OC_If_max_theory = 4/Rf;
OC_If_ss_start = OC_If_max_theory*0.95;
OC_index_0_9 = find(OC_If>OC_If_ss_start,1);

tt_ss = tt(find(OC_If>OC_If_ss_start));
OC_E_ss = OC_E(find(OC_If>OC_If_ss_start));
OC_w_ss = OC_w(find(OC_If>OC_If_ss_start));
OC_If_ss = OC_If(find(OC_If>OC_If_ss_start));
OC_K1 = OC_E_ss./OC_w_ss;

K1 = OC_K1(1,end);
If_ss = OC_If_ss(1,end);


%%
E_initial = w_initial*K1
I_target = 13750
Vdiff = I_target*(Ra+Rf)
Vref1 = E_initial+Vdiff;
Iref1 = 8600;
%% Plot
close all
i=1;

figure(i);
ax=gcf;
ax.Position = [10+20*i 10+20*i 800 300];
plot(tt_ss,OC_E_ss,'DisplayName','E','LineWidth',2);
hold on;legend;grid on;
title('Open Circuit')
plot(tt_ss,OC_w_ss,'DisplayName','w','LineWidth',2);
plot(tt_ss,OC_If_ss,'DisplayName','I_f','LineWidth',2);
i = i+1;

figure(2);
ax=gcf;
ax.Position = [10+20*i 10+20*i 800 300];
plot(tt_ss,OC_K2,'DisplayName','K_2','LineWidth',2);
hold on;legend;grid on;
title('BackEMF Constant')
i = i+1;
