% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g; syms x;

%  Parameter :
t_start_element1:0
t_start_element2:100

% WeitereParameter :
x_0=-400; x_E=2000; N=20000; lw=3; fs=12; fig=1;


a_element1=1.2*10^-5
a_element2=2.38*10^-5
l_element1=25.4
l_aussen_stahl=25.451

% Funktionen :
f=@(x)((x-t_start_element1)*a_element1*l_element1)+l_element1;
g=@(x)((t_start_element2-x)*a_element2*l_element2)+l_element2;

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
ylabel('L�nge mm', 'fontsize',fs);
legend(' Stahl', ' Messing');
grid on;

temp_x=solve(f(x)==g(x))
