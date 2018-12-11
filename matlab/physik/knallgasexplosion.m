% MALAB/OCTAVE initialisieren
clear all; clc; format compact; format short g; syms x;

% Konstanten laden
konstanten;

% --------------------------------------------------------
k=273.15;

Cpwasserstoff = 28.9
Cpsauerstoff = 29.3
dT=k+20

Q=Cpwasserstoff*2.00*dT+Cpsauerstoff*1*dT

Q2=(5/2)*3*R_G*dT

T=(2*(561000+18300))/(12*2*R_G)

(2*T)/(3*dT)