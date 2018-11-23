% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g; syms x;

% Konstanten laden
konstanten;

% --------------------------------------------------------
k=273.15
T1=k+20
T2=k+100

P1=100000

P2=(P1*T2)/(T1)
a=0.5^2
F=P2