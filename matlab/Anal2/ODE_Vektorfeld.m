% MATLAB/Octave
% AUEM
% 2019-05-21
% Begin
% ------------------------------------------------------------------------
% MATLAB/Octave initialisieren:
clear all; clc; format compact; format short g;
%
disp('--------------------------------------------------------------------------------------');
disp(mfilename);
disp('--------------------------------------------------------------------------------------');
% Parameter:
g=9.81
H=7.00
R=2.00
r=5.00e-2
lw=3; fig=0; scal_t=1/60;
%
disp('--------------------------------------------------------------------------------------');
disp('b)');
% Parameter:
t_a=0; t_b=32*60; h_a=0; h_b=7; N_t=33; N_h=29; scale=0.5; fig=fig+1; 
% Funktion:
f=@(t,h)(-r^2/R^2*sqrt(2*g*h));
v_t=@(t,h)1./sqrt(1+f(t,h).^2);
v_h=@(t,h)f(t,h)./sqrt(1+f(t,h).^2);
% Daten:
t_data=linspace(t_a,t_b,N_t)
h_data=linspace(h_a,h_b,N_h)
[t_grid,h_grid]=meshgrid(t_data,h_data)
v_t_grid=v_t(t_grid,h_grid);
v_h_grid=v_h(t_grid,h_grid);
% Plot:
figure(fig);
quiver(t_grid*scal_t,h_grid,v_t_grid*scal_t,v_h_grid,scale,'ShowArrowHead','off');
xlabel('t[min]'); ylabel('h[m]');
grid on;
axis('tight');
%
disp('--------------------------------------------------------------------------------------');
disp('c)');
% Parameter:
t_0=0; t_E=R^2/r^2*sqrt(2*H/g); h_0=H; N=200; fig=fig+1; lw=3;
% Funktion:
h=@(t)(sqrt(H)-r^2/R^2*sqrt(g/2)*t).^2;
% Daten:
h_E=h(t_E);
t_h=linspace(t_0,t_E,N);
y_h=h(t_h);
% Plot:
figure(fig);
plot(t_h*scal_t,y_h,'linewidth',lw);
xlabel('t[min]'); ylabel('h[m]');
grid on;
axis('tight');
%
disp('--------------------------------------------------------------------------------------');
disp('d)');
%
Dt=t_E-t_0
Dt=Dt/60
%
disp('--------------------------------------------------------------------------------------');
%
% ----------------------------------------------------------------------------------
% End