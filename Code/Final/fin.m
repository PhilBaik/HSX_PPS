
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

Lc = 100e-6;
n = 2;
RPM = 1700;
w_initial = RPM/60*2*pi;
Ltot = 10*LHSX+La+Lc/n;
Rtot = Ra+10*RHSX;
Limit = 0.999 %% smaller than 0.999
%%
fs = 10e3;          %% Switching frequency
Ts = 1/fs;
Tdead = Ts/100;
fdead = 1/Tdead;
fsamp = 50e3;
% fsamp = 200e3;
Tsamp = 1/fsamp;

T_trigger = 15
T_end = 20
T_hold = 1.5
%% Series 1
VDC = 40;
Vf = 3.1
n = 4;
Lc1 = Lc/n;
Ltot = 10*LHSX+La+Lc1;
Rtot = Ra+10*RHSX;
K = 30;
Kp = K*Ltot;
Ki = K*Rtot;
% Kp = 1
% Ki = 1
Kanti = 0;
% Ki = 0
% Kanti = 0
Limit1 = 0.9992;
%%


out1=sim('HSX_single_fin.slx');

%% Multi 1
VDC = 40;
Lc = 100e-6;
Vf = 3.1;
n=2;
Ltot = 10*LHSX+La+Lc/n;
Rtot = Ra+10*RHSX;
K = 50;
Kp = K*Ltot;
Ki = K*Rtot;
K2 = 10;
Kpp = K2*(2*LHSX+2*La+Lc);
Kii = K2*2*Rtot;

Kpp = 0.001;
Kii = 0.001;

Kaa = 0;
% Kp = 1
% Ki = 1
Kanti = 0.95;
% Ki = 0
% Kanti = 0
multi_enable = 1;

out2=sim('HSX_double_fin2.slx');


%% Multi 1 Lc Check
T_end = 1
Lc_arr = [50e-6 100e-6 150e-6]
for i = 1:1:length(LC_arr)

VDC = 40;
% Lc = 100e-6;
Lc = Lc_arr(1,i);
Vf = 3.1;
n=2;
Ltot = 10*LHSX+La+Lc/n;
Rtot = Ra+10*RHSX;
K = 50;
Kp = K*Ltot;
Ki = K*Rtot;
K2 = 10;
Kpp = K2*(2*LHSX+2*La+Lc);
Kii = K2*2*Rtot;

Kpp = 0.001;
Kii = 0.001;

Kaa = 0;
% Kp = 1
% Ki = 1
Kanti = 0.95;
% Ki = 0
% Kanti = 0
multi_enable = 1;

outLC(i)=sim('HSX_double_fin2.slx');

end
%%
LC = {}
LC(1).data = outLC(1,1).IL.Data(:,1);
LC(1).time = outLC(1,1).IL.Time;
LC(2).data = outLC(1,2).IL.Data(:,1);
LC(2).time = outLC(1,2).IL.Time;
LC(3).data = outLC(1,3).IL.Data(:,1);
LC(3).time = outLC(1,3).IL.Time;

%%
figure(1)
plot(LC(1).time,LC(1).data);hold on;
plot(LC(2).time,LC(2).data);
plot(LC(3).time,LC(3).data);
%% Quatro 1
VDC = 40;
Lc = 100e-6;
Vf = 3.1;
n=4;
Ltot = 10*LHSX+La+Lc/n;
Rtot = Ra+10*RHSX;
K = 50;
Kp = K*Ltot;
Ki = K*Rtot;
K2 = 10;
Kpp = K2*(2*LHSX+2*La+Lc);
Kii = K2*2*Rtot;


Kaa = 0;
% Kp = 1
% Ki = 1
Kanti = 0.95;
% Ki = 0
% Kanti = 0
multi_enable = 1;
temp_index = 1;

Kpp = 0.01;
Kii = 0.001;
%%
out4=sim('HSX_quatro_fin.slx');
out4_IL = out4.IL.Data(:,1);
out4_t = out4.IL.Time(:,1);
% Lc = 100e-6;
% Kpp = 0.001;
% Kii = 0.001;
% out=sim('HSX_quatro_fin.slx');
% out_temp2 = out.IL.Data(:,1);
% out_t2 = out.IL.Time(:,1);
% Lc = 10e-6;
% Kpp = 0.01;
% Kii = 0.001;
% out=sim('HSX_quatro_fin.slx');
% out_temp3 = out.IL.Data(:,1);
% out_t3 = out.IL.Time(:,1);
%%
t1 = out1.Io.Time(:,1);
Io1 = out1.Io.Data(:,1);
Iorg1 = out1.Io_org.Data(:,1);


t2 = out2.Io.Time(:,1);
Io2 = out2.Io.Data(:,1);
t4 = out4.Io.Time(:,1);
Io4 = out4.Io.Data(:,1);
Io4_limit = Limit*max(Io4)*ones(size(Io4));

%%
IL41 = out4.IL.Data(:,1);
IL42 = out4.IL.Data(:,2);
IL43 = out4.IL.Data(:,3);
IL44 = out4.IL.Data(:,4);



%%
t44 = out4.Control.Time;
control4 = out4.Control.Data(:,1);
T_start4 = t44(find(control4==1,1))
temp_t4 = t44(find(control4==1,1):end,1);
temp_control4 = control4(find(control4==1,1):end,1);
T_end4 = temp_t4(find(temp_control4==0,1))
T_peak4 = T_end4-T_start4
%%
IH4 = out4.IH.Data(:,1);
ILow4 = IL41-IH4;
max(IH4)
Ppeak4=VDC*max(IH4)
Prms4 = VDC*sqrt(sum(IH4.^2)*Tsamp/T_peak4)
Igh_ave4 = sum(IH4)*Tsamp/T_peak4
Igl_ave4 = sum(ILow4)*Tsamp/(T_end-T_trigger)
%%
figure
plot(t4,IL41);hold on;
plot(t4,IL42);
plot(t4,IL43);
plot(t4,IL44);
%%
save("text.mat")
%%
ex_en = 1;

close all
fig_num = 10;
ax=figure(fig_num);
ax.Position = [fig_num fig_num*10 600 200]
plot(t1,Iorg1,'k','LineWidth',1.5,'DisplayName','w/o compensator');hold on;
plot(t1,Io1,'Color',	"#EDB120",'LineWidth',1.7,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','single');
a=plot(t2,Io2,'Color',[0.3010 0.7450 0.9330],'LineWidth',1.6,'DisplayName','two-phase');hold on;
a.MarkerEdgeColor = "#80B3FF"
plot(t4,Io4,'-.','Color',	[0.6350 0.0780 0.1840],'LineWidth',1.5,'DisplayName','four-phase');
grid on;legend('Location','northeast','Box','off');
set(gca,'fontname','times')
ylim([0 900])
xlim([14 T_end])
ylabel('Output Current (A)')
xlabel('Time (s)')
if ex_en == 1;
    exportgraphics(ax,'io1.pdf','ContentType','vector')
end
ex_en = 0;
fig_num = fig_num+1;

%%

ax=figure(fig_num);
ax.Position = [fig_num fig_num*10 600 200]
plot(t1,Iorg1,'k','LineWidth',1.5,'DisplayName','w/o compensator');hold on;
plot(t1,Io1,'Color',	"#EDB120",'LineWidth',1.7,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','single');
a=plot(t2,Io2,'Color',[0.3010 0.7450 0.9330],'LineWidth',1.6,'DisplayName','two-phase');hold on;
a.MarkerEdgeColor = "#80B3FF"
plot(t4,Io4,'-.','Color',	[0.6350 0.0780 0.1840],'LineWidth',1.5,'DisplayName','four-phase');
plot(t4,Io4_limit,'--k','LineWidth',1,'DisplayName','99.9 Limit');
grid on;legend('Location','northeast','Box','off');
set(gca,'fontname','times')
ylim([840 860])
xlim([15.6 16.2])
ylabel('Output Current (A)')
xlabel('Time (s)')
if ex_en == 1;
    exportgraphics(ax,'io2.pdf','ContentType','vector')
end
ex_en = 0;
fig_num = fig_num+1;
%%
ex_en = 0
ax=figure(fig_num);
ax.Position = [fig_num fig_num*10 600 200]
yyaxis left
ylim([856.86 856.87])
a=plot(t1,Io1,'Color',"#EDB120",'LineWidth',1.7,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','single');hold on;
yyaxis right
% a=plot(t2,Io2,'Color',[0.5 0.25 0.90],'LineWidth',1.6,'DisplayName','two-phase');hold on;
plot(t4,Io4,'-.','Color',[0.6350 0.0780 0.1840],'LineWidth',1.5,'DisplayName','four-phase');
grid on;legend('Location','northeast','Box','off');
set(gca,'fontname','times')

xlim([15.8725 15.8735])
ylabel('Output Current (A)')
xlabel('Time (s)')
set(gca,'fontname','times')
legend('boxoff')
ax = gca;
ax.YAxis(1).Color = "#EDB120";
ax.YAxis(2).Color = [0.6350 0.0780 0.1840];

if ex_en == 1;
    exportgraphics(ax,'io3.pdf','ContentType','vector')
end
ex_en = 0;
fig_num = fig_num+1;

%%
ax=figure(fig_num);
ax.Position = [fig_num fig_num*10 600 200]

a=plot(t4,IL41,'LineWidth',1.5,'DisplayName','I_{L1}');hold on;
ylabel('Inductor Current [A]')
xlabel('Time (s)')
plot(t4,IL42,'-','LineWidth',1.5,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','I_{L2}');
plot(t4,IL43,'-','LineWidth',1.5,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','I_{L3}');
plot(t4,IL44,'-','LineWidth',1.5,'MarkerIndices',1:2000:length(t4),'MarkerSize',5,'DisplayName','I_{L4}');
grid on;legend('Location','northwest');
set(gca,'fontname','times')
legend('boxon')
ax = gca;
fig_num = fig_num+1;
exportgraphics(ax,'iL1.pdf','ContentType','vector')

%%
% figure
% plot(out_t,out_temp,'k');hold on;
% plot(out_t2,out_temp2,'r');
% plot(out_t3,out_temp3,'--g')
% %%
% close all
% fig_num = 10;
% 
% ax=figure(fig_num);
% ax.Position = [fig_num fig_num*10 600 200]
% plot(t3,check3,'k','LineWidth',1.5,'DisplayName','w/o compensator');hold on;
% a=plot(t2,check2,'Color',[0.1 0.65 0.25],'LineWidth',2,'DisplayName','double');hold on;
% a.MarkerEdgeColor = "#80B3FF"
% plot(t,check1,'-.','Color',[0.5 0.25 0.90],'LineWidth',1.5,'MarkerIndices',1:2000:length(t),'MarkerSize',5,'DisplayName','single');
% grid on;legend('Location','northeast');
% set(gca,'fontname','times')
% legend('boxoff')
% 
% ylabel('Output Current [A]')
% xlabel('Time [s]')
% xlim([14 20])
% ax = gca;
% exportgraphics(ax,'io1.pdf','ContentType','vector')
% fig_num = fig_num+1;
% 
% 
% ax=figure(fig_num);
% ax.Position = [fig_num fig_num*10 600 200]
% plot(t3,check3,'k','LineWidth',1.5,'DisplayName','w/o compensator');hold on;
% a=plot(t2,check2,'Color',[0.1 0.65 0.25],'LineWidth',2,'DisplayName','double');hold on;
% a.MarkerEdgeColor = "#80B3FF"
% plot(t,check1,'-.','Color',[0.5 0.25 0.90],'LineWidth',1.5,'MarkerIndices',1:2000:length(t),'MarkerSize',5,'DisplayName','single');
% plot(t3,limit,'--r','DisplayName','99.9% Limit')
% grid on;legend('Location','southeast');
% set(gca,'fontname','times')
% legend('boxoff')
% 
% ylabel('Output Current [A]')
% xlabel('Time [s]')
% xlim([15.6 16.2])
% ylim([850 858])
% ax = gca;
% fig_num = fig_num+1;
% exportgraphics(ax,'io2.pdf','ContentType','vector')
% 
% ax=figure(fig_num);
% ax.Position = [fig_num fig_num*10 600 200]
% 
% yyaxis left
% a=plot(t2,check2,'Color',[0.1 0.65 0.25],'LineWidth',2,'DisplayName','double');hold on;
% a.MarkerEdgeColor = "#80B3FF"
% ylabel('Output Current [A]')
% yyaxis right
% plot(t,check1,'-.','Color',[0.5 0.25 0.90],'LineWidth',1.5,'MarkerIndices',1:2000:length(t),'MarkerSize',5,'DisplayName','single');
% 
% grid on;legend('Location','northeast');
% set(gca,'fontname','times')
% legend('boxoff')
% ax = gca;
% ax.YAxis(1).Color = [0.1 0.65 0.25];
% ax.YAxis(2).Color = [0.5 0.25 0.90];
% 
% xlabel('Time [s]')
% xlim([16.0456 16.0461])
% ax = gca;
% fig_num = fig_num+1;
% exportgraphics(ax,'io3.pdf','ContentType','vector')
% 
% 
% ax=figure(fig_num);
% ax.Position = [fig_num fig_num*10 600 200]
% 
% a=plot(t2,IL1,'Color','#A2142F','LineWidth',2,'DisplayName','I_{L1}');hold on;
% a.MarkerEdgeColor = "#80B3FF"
% ylabel('Inductor Current [A]')
% plot(t2,IL2,'--','Color','#EDB120','LineWidth',1.5,'MarkerIndices',1:2000:length(t),'MarkerSize',5,'DisplayName','I_{L2}');
% 
% grid on;legend('Location','northwest');
% set(gca,'fontname','times')
% legend('boxoff')
% ax = gca;
% xlabel('Time [s]')
% fig_num = fig_num+1;
% exportgraphics(ax,'iL1.pdf','ContentType','vector')
% 
% ax=figure(fig_num);
% ax.Position = [fig_num fig_num*10 600 200]
% 
% a=plot(t2,IL1,'Color','#A2142F','LineWidth',2,'DisplayName','I_{L1}');hold on;
% a.MarkerEdgeColor = "#80B3FF"
% ylabel('Inductor Current [A]')
% plot(t2,IL2,'--','Color','#EDB120','LineWidth',1.5,'MarkerIndices',1:2000:length(t),'MarkerSize',5,'DisplayName','I_{L2}');
% 
% grid on;legend('Location','northwest');
% set(gca,'fontname','times')
% legend('boxoff')
% ax = gca;
% xlabel('Time [s]')
% fig_num = fig_num+1;
% xlim([15.9289 15.9294])
% ylim([420 440])
% exportgraphics(ax,'iL2.pdf','ContentType','vector')