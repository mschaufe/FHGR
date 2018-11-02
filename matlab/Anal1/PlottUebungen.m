% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g;

% Parameter :
N=200; lw=3; fs=12; fig=1;

% Funktionen :
fa=@(x)x/2-3;
fb=@(x)2*sin(x);
fc=@(x)x.^2;
fd=@(x)exp(1).^x;
fe=@(x)log(x)/log(10);
ff=@(x)1./(x+2);

% Daten : 
yfa_data=linspace(-2, 2, N); fa_data=fa(yfa_data);
yfb_data=linspace(0, 2*pi, N); fb_data=fb(yfb_data);
yfc_data=linspace(-1, 2, N); fc_data=fc(yfc_data);
yfd_data=linspace(-6, 2, N); fd_data=fd(yfd_data);
yfe_data=linspace(0.01, 10, N); fe_data=fe(yfe_data);
yff_data=linspace(-1, 4, N); ff_data=ff(yff_data);


% Plot :
figure(fig);
subplot(2,3,1);
    plot(yfa_data, fa_data, 'linewidth', lw);

        xlabel('x');
        ylabel('y');
        legend('a');
        axis('image'); grid on;
    
subplot(2,3,2);
    plot(yfb_data, fb_data, 'linewidth', lw);

        xlabel('x');
        ylabel('y');
        legend('b');
        axis('image'); grid on;

subplot(2,3,3);
    plot(yfc_data, fc_data, 'linewidth', lw);
        
        xlabel('x');
        ylabel('y');
        legend('c');
        axis('image'); grid on;

subplot(2,3,4);
    plot(yfd_data, fd_data, 'linewidth', lw);
        
        xlabel('x');
        ylabel('y');
        legend('d');
        axis('image'); grid on;
        
subplot(2,3,5);
    plot(yfe_data, fe_data, 'linewidth', lw);
        
        xlabel('x');
        ylabel('y');
        legend('e');
        axis('image'); grid on;
        
 subplot(2,3,6);
    plot(yff_data, ff_data, 'linewidth', lw);
        
        xlabel('x');
        ylabel('y');
        legend('f');
        axis('image'); grid on;