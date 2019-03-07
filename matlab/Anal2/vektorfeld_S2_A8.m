% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
x_0=-6; x_E=6; y_0=-4; y_E=4; N_x=13; N_y=9; fig=1; scale=0.5;

% Funktion:
f=@(x,y){2./(1+x.^2+y.^2).*x;2./(1+x.^2+y.^2).*y};

% Daten:
x_data=linspace(x_0,x_E,N_x);
y_data=linspace(y_0,y_E,N_y);
[x_grid,y_grid]=meshgrid(x_data,y_data);
v_grid=f(x_grid,y_grid);

% Surface_Plot:
figure(fig);
quiver(x_grid,y_grid,v_grid{1},v_grid{2},scale);
xlabel('x');ylabel('y');
grid on; axis('image');
