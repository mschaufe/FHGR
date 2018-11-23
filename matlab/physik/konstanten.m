% MATLAB/Octave
% 2018-09-02
% Begin
% --------------------------------------------------------------------------
% Mathematische Konstanten
eu=exp(1);
% --------------------------------------------------------------------------
% Fundamentale
c=299792458;						% Lichtgeschwindikgit
h_D=1.054572e-34;					% Dirac-Konstante
h_P=2*pi*h_D;						% Planck-Konstante
% --------------------------------------------------------------------------
% Mechanik
G_N=6.674e-11;                      % Newton-Gravitationskonstante
g=9.81;								% Fallbeschleunigung (Mitteleuropa)
g_n=9.80665;						% Fallbeschleunigung (Normwert)
% --------------------------------------------------------------------------
% Elektrik
y_B=1e-7;							% Ampere-Konstante
y_E=c^2*y_B;						% Coulomb-Konstante
mu_0=4*pi*y_B;						% Magnetische Feldkonstante
ep_0=1/(4*pi*y_E);					% Elektrische Feldkonstante
el=1.602177e-19;					% Elemenarladung
alpha_EM=el^2/(4*pi*ep_0*h_D*c);	% Feinstruktur-Konstante
% --------------------------------------------------------------------------
% Kalorik
N_A=6.022141e23;					% Avogadro-Konstante
Q_A=N_A*el;							% Farady-Konstante
k_B=1.380649e-23;					% Boltzmann-Konstante
R_G=k_B*N_A;						% Universelle Gaskonstante
sigma_SB=2/15*pi^5*k_B^4/h_P^3/c^2;	% Stefan-Boltzmann-Konstante
% --------------------------------------------------------------------------
% Mikroskopisch
m_u=1e-3/N_A;						% Atomare Masseneinheit
K_J=2*el/h_P;						% Josephson-Konstante
R_K=h_P/el^2;						% Klitzing-Konstante
% --------------------------------------------------------------------------
% Elementarteilchen
% Elektron
m_e=9.109384e-31; Z_e=-1; s_e=0.5; g_e=-2.002319304;
q_e=Z_e*el; mu_e=0.5*h_D*g_e*q_e*s_e/m_e;
r_e=q_e^2/(4*pi*ep_0*m_e*c^2); lambda_e=h_P/c/m_e;
% Myon
m_mu=1.883531e-28; Z_mu=-1; s_mu=0.5; g_mu=-2.002332; LT_mu=2.197e-6;
q_mu=Z_mu*el; mu_mu=0.5*h_D*g_mu*q_mu*s_mu/m_mu;
r_mu=q_mu^2/(4*pi*ep_0*m_mu*c^2); lambda_mu=h_P/c/m_mu;
% Tauon
m_tau=3.167e-27; Z_tau=-1; s_tau=0.5; LT_tau=2.9e-13;
q_tau=Z_tau*el;
r_tau=q_tau^2/(4*pi*ep_0*m_tau*c^2); lambda_tau=h_P/c/m_tau;
% Proton
m_p=1.672622e-27; Z_p=1;
q_p=Z_p*el;
r_p=q_p^2/(4*pi*ep_0*m_p*c^2); lambda_p=h_P/c/m_p;
% Neutron
m_n=1.674927e-27; Z_n=0;
q_n=Z_n*el;
r_n=q_n^2/(4*pi*ep_0*m_n*c^2); lambda_n=h_P/c/m_n;
% W-Boson
m_w=1.43e-25; Z_w=1;
q_w=Z_w*el;
r_w=q_w^2/(4*pi*ep_0*m_w*c^2); lambda_w=h_P/c/m_w;
% Z-Boson
m_z=1.626e-25; Z_z=0;
q_z=Z_z*el;
r_z=q_z^2/(4*pi*ep_0*m_z*c^2); lambda_z=h_P/c/m_z;
% --------------------------------------------------------------------------
% Chemische Elemente
Z_H=1; m_H=1.00794; rho_H=0.084;
Z_He=2; m_He=4.0026; rho_He=0.17;
Z_Li=3; m_Li=6.941; rho_Li=0.53e3;
Z_Be=4; m_Be=9.012182; rho_Be=1.85e3;
Z_B=5; m_B=10.811; rho_B=2.35e3;
Z_C=6; m_C=12.0107; rho_C=3.51e3;
Z_N=7; m_N=14.0067; rho_N=1.17;
Z_O=8; m_O=15.9994; rho_O=1.33;
Z_F=9; m_F=18.9984; rho_F=1.58;
Z_Ne=10; m_Ne=20.1797; rho_Ne=0.84;
Z_Na=11; m_Na=22.98977; rho_Na=0.97e3;
Z_Mg=12; m_Mg=24.3050; rho_Mg=1.74e3;
Z_Al=13; m_Al=26.9815; rho_Al=2.70e3;
Z_Si=14; m_Si=28.0855; rho_Si=2.33e3;
Z_P=15; m_P=30.9737; rho_P=1.82e3;
Z_S=16; m_S=32.065; rho_S=2.07e3;
Z_Cl=17; m_Cl=35.453; rho_Cl=2.95;
Z_Ar=18; m_Ar=39.948; rho_Ar=1.66;
Z_K=19; m_K=39.0983; rho_K=0.86e3;
Z_Ca=20; m_Ca=40.078; rho_Ca=1.54e3;
Z_Sc=21; m_Sc=44.9559; rho_Sc=2.99e3;
Z_Ti=22; m_Ti=47.867; rho_Ti=4.51e3;
Z_V=23; m_V=50.941; rho_V=6.09e3;
Z_Cr=24; m_Cr=51.996; rho_Cr=7.14e3;
Z_Mn=25; m_Mn=54.938; rho_Mn=7.44e3;
Z_Fe=26; m_Fe=55.845; rho_Fe=7.87e3;
Z_Co=27; m_Co=58.9332; rho_Co=8.89e3;
Z_Ni=28; m_Ni=58.693; rho_Ni=8.91e3;
Z_Cu=29; m_Cu=63.546; rho_Cu=8.92e3;
Z_Zn=30; m_Zn=65.409; rho_Zn=7.14e3;
Z_Ga=31; m_Ga=69.723; rho_Ga=5.91e3;
Z_Ge=32; m_Ge=72.64; rho_Ge=5.32e3;
Z_As=33; m_As=74.9216; rho_As=5.72e3;
Z_Se=34; m_Se=78.96; rho_Se=4.19e3;
Z_Br=35; m_Br=79.904; rho_Br=3.14e3;
Z_Kr=36; m_Kr=83.798; rho_Kr=3.48;
Z_Rb=37; m_Rb=85.4678; rho_Rb=1.53e3;
Z_Sr=38; m_Sr=87.62; rho_Sr=2.63e3;
Z_Y=39; m_Y=88.90585; rho_Y=4.47e3;
Z_Zr=40; m_Zr=91.224; rho_Zr=6.51e3;
Z_Nb=41; m_Nb=92.906; rho_Nb=8.58e3;
Z_Mo=42; m_Mo=95.94; rho_Mo=10.28e3;
Z_Tc=43; m_Tc=98.9063; rho_Tc=11.49e3;
Z_Ru=44; m_Ru=101.07; rho_Ru=12.45e3;
Z_Rh=45; m_Rh=102.905; rho_Rh=12.41e3;
Z_Pd=46; m_Pd=106.42; rho_Pd=12.02e3;
Z_Ag=47; m_Ag=107.868; rho_Ag=10.49e3;
Z_Cd=48; m_Cd=112.411; rho_Cd=8.64e3;
Z_In=49; m_In=114.818; rho_In=7.31e3;
Z_Sn=50; m_Sn=118.710; rho_Sn=7.29e3;
Z_Sb=51; m_Sb=121.760; rho_Sb=6.69e3;
Z_Te=52; m_Te=127.60; rho_Te=6.25e3;
Z_I=53; m_I=126.904; rho_I=4.94e3;
Z_Xe=54; m_Xe=131.293; rho_Xe=5.49;
Z_Cs=55; m_Cs=132.905; rho_Cs=1.90e3;
Z_Ba=56; m_Ba=137.327; rho_Ba=3.65e3;
Z_La=57; m_La=138.906; rho_La=6.16e3;
Z_Ce=58; m_Ce=140.116; rho_Ce=6.77e3;
Z_Pr=59; m_Pr=140.908; rho_Pr=6.48e3;
Z_Nd=60; m_Nd=144.24; rho_Nd=7.00e3;
Z_Pm=61; m_Pm=146.915; rho_Pm=7.22e3;
Z_Sm=62; m_Sm=150.36; rho_Sm=7.54e3;
Z_Eu=63; m_Eu=151.964; rho_Eu=5.25e3;
Z_Gd=64; m_Gd=157.25; rho_Gd=7.89e3;
Z_Tb=65; m_Tb=158.925; rho_Tb=6.16e3;
Z_Dy=66; m_Dy=162.500; rho_Dy=6.77e3;
Z_Ho=67; m_Ho=164.930; rho_Ho=6.48e3;
Z_Er=68; m_Er=167.259; rho_Er=7.00e3;
Z_Tm=69; m_Tm=168.259; rho_Tm=7.22e3;
Z_Yb=70; m_Yb=173.04; rho_Yb=7.54e3;
Z_Lu=71; m_Lu=174.967; rho_Lu=5.25e3;
Z_Hf=72; m_Hf=178.49; rho_Hf=13.31e3;
Z_Ta=73; m_Ta=180.9479; rho_Ta=16.68e3;
Z_W=74; m_W=183.84; rho_W=19.26e3;
Z_Re=75; m_Re=186.207; rho_Re=21.03e3;
Z_Os=76; m_Os=190.23; rho_Os=22.61e3;
Z_Ir=77; m_Ir=192.217; rho_Ir=22.65e3;
Z_Pt=78; m_Pt=195.078; rho_Pt=21.42e3;
Z_Au=79; m_Au=196.9665; rho_Au=19.32e3;
Z_Hg=80; m_Hg=200.59; rho_Hg=13.55e3;
Z_Tl=81; m_Tl=204.383; rho_Tl=11.85e3;
Z_Pb=82; m_Pb=207.2; rho_Pb=11.34e3;
Z_Bi=83; m_Bi=208.980; rho_Bi=9.80e3;
Z_Po=84; m_Po=208.9824; rho_Po=9.20e3;
Z_At=85; m_At=209.9871; % rho_At=e3;
Z_Rn=86; m_Rn=222.0176; rho_Rn=9.23;
Z_Fr=87; m_Fr=223.0197; % rho_Fr=e3;
Z_Ra=88; m_Ra=226.0254; rho_Ra=5.50e3;
Z_Ac=89; m_Ac=227.028; rho_Ac=10.07e3;
Z_Th=90; m_Th=232.038; rho_Th=11.72e3;
Z_Pa=91; m_Pa=231.036; rho_Pa=15.37e3;
Z_U=92; m_U=238.029; rho_U=18.97e3;
Z_Np=93; m_Np=237.048; rho_Np=20.48e3;
Z_Pu=94; m_Pu=244.064; rho_Pu=19.74e3;
Z_Am=95; m_Am=243.061; rho_Am=13.67e3;
Z_Cm=96; m_Cm=247.070; rho_Cm=13.51e3;
Z_Bk=97; m_Bk=247.0703; rho_Bk=10.07e3;
Z_Cf=98; m_Cf=251.0796; rho_Cf=11.72e3;
Z_Es=99; m_Es=252.083; rho_Es=15.37e3;
Z_Fm=100; m_Fm=257.095; rho_Fm=18.97e3;
Z_Md=101; m_Md=258.098; rho_Md=20.48e3;
Z_No=102; m_No=259.101; rho_No=19.74e3;
Z_Lr=103; m_Lr=262.1097; rho_Lr=13.67e3;
Z_Rf=104; m_Rf=261.1088; % rho_Rf=;
Z_Db=105; m_Db=262.1141; % rho_Db=;
Z_Sg=106; m_Sg=263; % rho_Sg=;
Z_Bh=107; m_Bh=262; % rho_Bh=;
Z_Hs=108; m_Hs=265; % rho_Hs=;
Z_Mt=109; m_Mt=266; % rho_Mt=;
Z_Ds=110; m_Ds=268; % rho_Ds=;
Z_Rg=111; m_Rg=270; % rho_Rg=;
% --------------------------------------------------------------------------
% Einheitenkonversion
kg2u=1/m_u; u2kg=m_u;
kg2MeV=1e-6*c^2/el; MeV2kg=1/kg2MeV;
PS2kW=75*g_n; kW2PS=1/PS2kW;
% --------------------------------------------------------------------------
% End