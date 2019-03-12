% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
x_0=0; x_E=2; y_0=0; y_E=1; N_x=201; N_y=101;

% Funktion:
f=@(x,y)x.*y;

% Daten:
x_data=linspace(x_0,x_E,N_x);
y_data=linspace(y_0,y_E,N_y);
[x_grid,y_grid]=meshgrid(x_data,y_data);
f_grid=f(x_grid,y_grid);

% Integral:
I = trapz(x_data,trapz(y_data,f_grid))
