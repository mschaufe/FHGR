% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g; syms x;

%  Parameter :
temp_start_element1=20;
temp_start_element2=20;

% WeitereParameter :
x_0=-400; x_E=2000; N=20000; lw=3; fs=12; fig=1;


a_element1=1.1*10^-5;
a_element2=1.9*10^-5;
l_element1=29.97;
l_element2=30;

% Funktionen :
f=@(x)((x+temp_start_element1)*a_element1*l_element1)+l_element1;
g=@(x)((x+temp_start_element2)*a_element2*l_element2)+l_element2;

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
ylabel('Länge', 'fontsize',fs);
legend(' Element 1', ' Element 2');
grid on;

temp_x=solve(f(x)==g(x))

