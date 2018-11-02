% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g;

% Parameter :
x_0=0; x_E=4; N=200; lw=3; fs=12; fig=1;

% Funktionen :
f=@(x)3./(1+x);
g=@(x)x./2;
h=@(x)x.^2/4;

% Daten : 
x_data=linspace(x_0, x_E, N);
f_data=f(x_data);
g_data=g(x_data);
h_data=h(x_data);

% Plot :
figure(fig);
plot(x_data, f_data, 'linewidth', lw);
hold on;

plot(x_data, g_data, '--', 'linewidth',lw);
hold on;

plot(x_data, h_data, 'linewidth', lw);
hold off;

xlabel('x','fontsize',fs);
ylabel('y', 'fontsize',fs);
legend(' f', ' g', ' h');
axis('image'); grid on;
