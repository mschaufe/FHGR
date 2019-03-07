% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
x_0=-3; x_E=3; y_0=-2; y_E=2; N_x=13; N_y=9; fig=1;

% Funktion:
f=@(x,y)x.*y;

% Daten:
x_data=linspace(x_0,x_E,N_x);
y_data=linspace(y_0,y_E,N_y);

[x_grid,y_grid]=meshgrid(x_data,y_data);
f_grid=f(x_grid,y_grid);
% Surface_Plot:
surf(x_grid,y_grid,f_grid);
xlabel('x');ylabel('y');zlabel('z');
grid on; axis('image')
