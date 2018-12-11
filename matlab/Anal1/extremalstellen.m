% MALAB/OCTAVE initialisieren
clear all; clc; format compact;

% Definitionen
syms x real;

% Werte Aufgaben
disp('Wir betrachten die Funktion:')
f = x^4-2*x^2+2

poldeg = polynomialDegree(f)

disp('Für die erste und zweite Ableitung erhalten wir:')

erste_ableitung=diff(f)  %erste Ableitung
zweite_ableitung=diff(erste_ableitung)
    
disp(sprintf('Da die erste Ableitung ein Polynom ''%d'' Grades ist, kann f hoechstens ''%d'' Kritische Stellen haben  ',poldeg,poldeg));

kritische_stellen=solve(0==erste_ableitung,x)

kritische_stellen(1)