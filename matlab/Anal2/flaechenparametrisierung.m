% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Parameter:
R=3;
u_0=0; u_E=pi; v_0=0; v_E=2*pi; N_u=45; N_v=90; fig=1;

% Funktion:
P=@(u,v){R*sin(u).*cos(v);R*sin(u).*sin(v);R*cos(u)};

% Daten:
u_data=linspace(u_0,u_E,N_u);
v_data=linspace(v_0,v_E,N_v);

[u_grid,v_grid]=meshgrid(u_data,v_data);
P_grid=P(u_grid,v_grid);

% Surface_Plot:
figure(fig);
surf(P_grid{1},P_grid{2},P_grid{3});
xlabel('x');ylabel('y');zlabel('z');
grid on; axis('image')
