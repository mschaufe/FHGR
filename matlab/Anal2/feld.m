% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
x_0=-3; x_E=3; y_0=-2; y_E=2; N_x=13; N_y=9; scale=0.5; lw=2; fig=1;

% Funktion:
v=@(x,y){-y,x};

% Daten:
x_data=linspace(x_0,x_E,N_x);
y_data=linspace(y_0,y_E,N_y);
[x_grid,y_grid]=meshgrid(x_data,y_data);
v_grid=v(x_grid,y_grid);

% Plot:
figure(fig);
quiver(x_grid,y_grid,v_grid{1},v_grid{2},scale);
xlabel('x');ylabel('y');
grid on; axis('image')
