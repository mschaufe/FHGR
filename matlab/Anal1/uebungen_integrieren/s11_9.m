% MATLAB initialisieren:
clear all; clc; format compact; format long;

% Paramter:
    x_0=2; % <--  erster X Wert
    x_E=3; % <--  letzter X Wert
    n=9; % anzahl durchläufe
    N=5; % anzahl Werte, die generiert werden
    fig=1; % Figur 1
    lw=4; % Liniendicke
    
% Funktionen:
f=@(x)log(10)./log(x); % <-- (Punkt nicht Vergessen!)

% Daten:
for k=1:n;
    x_data=linspace(x_0,x_E,N);
    y_data=f(x_data);
    I=trapz(x_data,y_data)
    N=2*N;
end

% Plot:
figure(fig);
plot(x_data,y_data,'-','linewidth',lw);
xlabel('x'); ylabel('y');
grid on;
% axis('image');
