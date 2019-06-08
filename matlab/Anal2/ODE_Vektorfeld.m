
% MATLAB initialisieren:
clear all; clc; format compact; format short g;

% Paramter:
    x_0=0; % erster X Wert
    x_E=6; % letzter X Wert
    y_0=-2; % erster Y Wert
    y_E=2; % letzter Y Wert
    N_x=25; % anzahl Werte, die generiert werden in X
    N_y=25; % anzahl Werte, die generiert werden in Y
    fig=1; % Figur 1
    scale=0.5; % Skalierung
    
% Funktionen:
f=@(x,y)1.-y.^2; % hier die Funktion aendern
v=@(x,y){1./sqrt(1+f(x,y).^2);f(x,y)./sqrt(1+f(x,y).^2)};

% Daten:
x_data=linspace(x_0,x_E,N_x);
y_data=linspace(y_0,y_E,N_y);
[x_grid,y_grid]=meshgrid(x_data,y_data);
v_grid=v(x_grid,y_grid);

% Plot:
figure(fig);
quiver(x_grid,y_grid,v_grid{1},v_grid{2},scale);
xlabel('x'); ylabel('y');
grid on;
axis('image');
                  