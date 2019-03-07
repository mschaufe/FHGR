% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
tau_0=0; tau_E=10; N=700; lw=3; fig=1;

% Funktionen:
s=@(tau){tau.*cos(pi*tau);tau.*sin(pi*tau)}

% Daten:
tau_data=linspace(tau_0,tau_E,N)
s_data=s(tau_data);

% Plot:
figure(fig);
plot(s_data{1},s_data{2},'linewidth', lw);
xlabel('x'); ylabel('y');
grid on; axis('image');

