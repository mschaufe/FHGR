% MATLAB initialisieren:
clear all; clc; format compact; format rat; 

% Gleichungssystem Lösen
    % Parameter für (x,y,z)
     A=[2,-5,0; 3,1,-2]; 
    % Loesungen
    b=[11;0];
    res=rref([A b])
    
    
    % Parameter für (x,y,z)
     A1=[7,-6,2;0,5,-4]; 
    % Loesungen
    b1=[9;3];
    res=rref([A1 b1])