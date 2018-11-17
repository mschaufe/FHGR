%MATLAB initialisieren

clear all; clc; format compact; format short g;

% Parameter

mk=0.1;
ck=385;


mkk=0.15;

tm=38;

mw= 0.2;
cw=4182;
tw=16;

twd=100
mwd=0.0012;
lwd=2.257*10^6;

%Ergebnisse
syms tk
Qk= ck*mk*(tk-tm)
Qkk=ck*mkk*(tm-tw)
Qwz=cw*(mw-mwd)*(tm-tw)
Qwv=cw*mwd*(twd-tm)
Qwd=lwd*mwd

%Ausgabe

solve(0 ==-Qk+Qkk+Qwz+Qwv+Qwd)
