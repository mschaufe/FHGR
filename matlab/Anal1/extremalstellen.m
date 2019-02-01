% MALAB/OCTAVE initialisieren
clear all; clc; format compact;

% Definitionen
syms x real;

% Werte Aufgaben
disp('Wir betrachten die Funktion:')
f=@(x)x.^4-2*x^2+2

poldeg = polynomialDegree(f(x));

disp('Für die erste und zweite Ableitung erhalten wir:')

erste_ableitung=diff(f(x))  %erste Ableitung
zweite_ableitung=diff(f(x),2)
g=@(x)12*x^2 - 4

%g=@(x)zweite_ableitung
    
disp(sprintf('Da die erste Ableitung ein Polynom ''%d'' Grades ist, kann f hoechstens ''%d'' Kritische Stellen haben  ',poldeg,poldeg));
disp('Erste Ableitung = 0 und nach x aufloesen:')
kritische_stellen=solve(0==erste_ableitung,x)
anzahl_kritische_stellen=numel(kritische_stellen);

for c = 1:anzahl_kritische_stellen
    y_grund_funktion(c)=f(kritische_stellen(c))
    y_zweite_ableitung(c)=g(kritische_stellen(c))
    
end

