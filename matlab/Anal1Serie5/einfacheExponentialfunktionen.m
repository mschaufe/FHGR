% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format rat;

% Parameter :
x_0=-3; x_E=3; N=200; lw=3; fs=12; fig=1;
a=[2, 3, 1/2, 1/3];
stellen=[-3, -2, -1, 0, 1, 2, 3]
res=zeros(7,4)

% Funktionswerte :
i=1;
while i<8 
clc
    f=@(x)a.^stellen(i);
    res(i,:)=f(a)
i=1+i;
end


% Daten
x_data=linspace(x_0, x_E, N);
figure(fig);
% Graph :
i=1;
while i<5
    f=@(x)a(i).^x;
    f_data=f(x_data);
    % Plot :
    plot(x_data, f_data, 'linewidth', lw);hold on;
i=1+i;
end
grid on;

