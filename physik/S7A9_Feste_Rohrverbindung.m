% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g;

% Parameter :
x_0=-40; x_E=2000; N=20000; lw=3; fs=12; fig=1;
syms x;

a_stahl=1.1*10^-5
a_messing=1.9*10^-5
l_innen_messing=29.97
l_aussen_stahl=30.00

% Funktionen :
f=@(x)((x-20)*a_stahl*l_aussen_stahl)+l_aussen_stahl;
g=@(x)((x-20)*a_messing*l_innen_messing)+l_innen_messing;

% Daten : 
x_data=linspace(x_0, x_E, N);
f_data=f(x_data);
g_data=g(x_data);

% Plot :
figure(fig);
plot(x_data, f_data, 'linewidth', lw);
hold on;

plot(x_data, g_data, 'linewidth', lw);
hold off;

xlabel('Temperatur C','fontsize',fs);
ylabel('Länge mm', 'fontsize',fs);
legend(' Stahl', ' Messing');
grid on;

temp=solve(f(x)==g(x))
