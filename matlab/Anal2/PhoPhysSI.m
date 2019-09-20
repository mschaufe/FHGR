% MATLAB/Octave
% AUEM
% 2019-02-18
% Begin
% --------------------------------------------------------------------------
% Mathematische Konstanten
eu=exp(1);
% --------------------------------------------------------------------------
% Fundamentale
c=299792458;						% Lichtgeschwindikgit
h_P=6.62607015e-34;					% Planck-Konstante
h_D=h_P/(2*pi);						% Dirac-Konstante
% --------------------------------------------------------------------------
% Mechanik
G_N=6.674e-11;                      % Newton-Gravitationskonstante
g=9.81;								% Fallbeschleunigung (Mitteleuropa)
g_n=9.80665;						% Fallbeschleunigung (Normwert)
% --------------------------------------------------------------------------
% Elektrik
el=1.602176634e-19;					% Elemenarladung
y_B=1e-7;							% Ampere-Konstante
y_E=c^2*y_B;						% Coulomb-Konstante
mu_0=4*pi*y_B;						% Magnetische Feldkonstante
ep_0=1/(4*pi*y_E);					% Elektrische Feldkonstante
alpha_EM=el^2/(4*pi*ep_0*h_D*c);	% Feinstruktur-Konstante
% --------------------------------------------------------------------------
% Kalorik
N_A=6.02214076e23;					% Avogadro-Konstante
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
Z_H=1; M_H=1.00794e-3; rho_H=0.084;
Z_He=2; M_He=4.0026e-3; rho_He=0.17;
Z_Li=3; M_Li=6.941e-3; rho_Li=0.53e3;
Z_Be=4; M_Be=9.012182e-3; rho_Be=1.85e3;
Z_B=5; M_B=10.811e-3; rho_B=2.35e3;
Z_C=6; M_C=12.0107e-3; rho_C=3.51e3;
Z_N=7; M_N=14.0067e-3; rho_N=1.17;
Z_O=8; M_O=15.9994e-3; rho_O=1.33;
Z_F=9; M_F=18.9984e-3; rho_F=1.58;
Z_Ne=10; M_Ne=20.1797e-3; rho_Ne=0.84;
Z_Na=11; M_Na=22.98977e-3; rho_Na=0.97e3;
Z_Mg=12; M_Mg=24.3050e-3; rho_Mg=1.74e3;
Z_Al=13; M_Al=26.9815e-3; rho_Al=2.70e3;
Z_Si=14; M_Si=28.0855e-3; rho_Si=2.33e3;
Z_P=15; M_P=30.9737e-3; rho_P=1.82e3;
Z_S=16; M_S=32.065e-3; rho_S=2.07e3;
Z_Cl=17; M_Cl=35.453e-3; rho_Cl=2.95;
Z_Ar=18; M_Ar=39.948e-3; rho_Ar=1.66;
Z_K=19; M_K=39.0983e-3; rho_K=0.86e3;
Z_Ca=20; M_Ca=40.078e-3; rho_Ca=1.54e3;
Z_Sc=21; M_Sc=44.9559e-3; rho_Sc=2.99e3;
Z_Ti=22; M_Ti=47.867e-3; rho_Ti=4.51e3;
Z_V=23; M_V=50.941e-3; rho_V=6.09e3;
Z_Cr=24; M_Cr=51.996e-3; rho_Cr=7.14e3;
Z_Mn=25; M_Mn=54.938e-3; rho_Mn=7.44e3;
Z_Fe=26; M_Fe=55.845e-3; rho_Fe=7.87e3;
Z_Co=27; M_Co=58.9332e-3; rho_Co=8.89e3;
Z_Ni=28; M_Ni=58.693e-3; rho_Ni=8.91e3;
Z_Cu=29; M_Cu=63.546e-3; rho_Cu=8.92e3;
Z_Zn=30; M_Zn=65.409e-3; rho_Zn=7.14e3;
Z_Ga=31; M_Ga=69.723e-3; rho_Ga=5.91e3;
Z_Ge=32; M_Ge=72.64e-3; rho_Ge=5.32e3;
Z_As=33; M_As=74.9216e-3; rho_As=5.72e3;
Z_Se=34; M_Se=78.96e-3; rho_Se=4.19e3;
Z_Br=35; M_Br=79.904e-3; rho_Br=3.14e3;
Z_Kr=36; M_Kr=83.798e-3; rho_Kr=3.48;
Z_Rb=37; M_Rb=85.4678e-3; rho_Rb=1.53e3;
Z_Sr=38; M_Sr=87.62e-3; rho_Sr=2.63e3;
Z_Y=39; M_Y=88.90585e-3; rho_Y=4.47e3;
Z_Zr=40; M_Zr=91.224e-3; rho_Zr=6.51e3;
Z_Nb=41; M_Nb=92.906e-3; rho_Nb=8.58e3;
Z_Mo=42; M_Mo=95.94e-3; rho_Mo=10.28e3;
Z_Tc=43; M_Tc=98.9063e-3; rho_Tc=11.49e3;
Z_Ru=44; M_Ru=101.07e-3; rho_Ru=12.45e3;
Z_Rh=45; M_Rh=102.905e-3; rho_Rh=12.41e3;
Z_Pd=46; M_Pd=106.42e-3; rho_Pd=12.02e3;
Z_Ag=47; M_Ag=107.868e-3; rho_Ag=10.49e3;
Z_Cd=48; M_Cd=112.411e-3; rho_Cd=8.64e3;
Z_In=49; M_In=114.818e-3; rho_In=7.31e3;
Z_Sn=50; M_Sn=118.710e-3; rho_Sn=7.29e3;
Z_Sb=51; M_Sb=121.760e-3; rho_Sb=6.69e3;
Z_Te=52; M_Te=127.60e-3; rho_Te=6.25e3;
Z_I=53; M_I=126.904e-3; rho_I=4.94e3;
Z_Xe=54; M_Xe=131.293e-3; rho_Xe=5.49;
Z_Cs=55; M_Cs=132.905e-3; rho_Cs=1.90e3;
Z_Ba=56; M_Ba=137.327e-3; rho_Ba=3.65e3;
Z_La=57; M_La=138.906e-3; rho_La=6.16e3;
Z_Ce=58; M_Ce=140.116e-3; rho_Ce=6.77e3;
Z_Pr=59; M_Pr=140.908e-3; rho_Pr=6.48e3;
Z_Nd=60; M_Nd=144.24e-3; rho_Nd=7.00e3;
Z_Pm=61; M_Pm=146.915e-3; rho_Pm=7.22e3;
Z_Sm=62; M_Sm=150.36e-3; rho_Sm=7.54e3;
Z_Eu=63; M_Eu=151.964e-3; rho_Eu=5.25e3;
Z_Gd=64; M_Gd=157.25e-3; rho_Gd=7.89e3;
Z_Tb=65; M_Tb=158.925e-3; rho_Tb=6.16e3;
Z_Dy=66; M_Dy=162.500e-3; rho_Dy=6.77e3;
Z_Ho=67; M_Ho=164.930e-3; rho_Ho=6.48e3;
Z_Er=68; M_Er=167.259e-3; rho_Er=7.00e3;
Z_Tm=69; M_Tm=168.259e-3; rho_Tm=7.22e3;
Z_Yb=70; M_Yb=173.04e-3; rho_Yb=7.54e3;
Z_Lu=71; M_Lu=174.967e-3; rho_Lu=5.25e3;
Z_Hf=72; M_Hf=178.49e-3; rho_Hf=13.31e3;
Z_Ta=73; M_Ta=180.9479e-3; rho_Ta=16.68e3;
Z_W=74; M_W=183.84e-3; rho_W=19.26e3;
Z_Re=75; M_Re=186.207e-3; rho_Re=21.03e3;
Z_Os=76; M_Os=190.23e-3; rho_Os=22.61e3;
Z_Ir=77; M_Ir=192.217e-3; rho_Ir=22.65e3;
Z_Pt=78; M_Pt=195.078e-3; rho_Pt=21.42e3;
Z_Au=79; M_Au=196.9665e-3; rho_Au=19.32e3;
Z_Hg=80; M_Hg=200.59e-3; rho_Hg=13.55e3;
Z_Tl=81; M_Tl=204.383e-3; rho_Tl=11.85e3;
Z_Pb=82; M_Pb=207.2e-3; rho_Pb=11.34e3;
Z_Bi=83; M_Bi=208.980e-3; rho_Bi=9.80e3;
Z_Po=84; M_Po=208.9824e-3; rho_Po=9.20e3;
Z_At=85; M_At=209.9871; % rho_At=e3;
Z_Rn=86; M_Rn=222.0176e-3; rho_Rn=9.23;
Z_Fr=87; M_Fr=223.0197; % rho_Fr=e3;
Z_Ra=88; M_Ra=226.0254e-3; rho_Ra=5.50e3;
Z_Ac=89; M_Ac=227.028e-3; rho_Ac=10.07e3;
Z_Th=90; M_Th=232.038e-3; rho_Th=11.72e3;
Z_Pa=91; M_Pa=231.036e-3; rho_Pa=15.37e3;
Z_U=92; M_U=238.029e-3; rho_U=18.97e3;
Z_Np=93; M_Np=237.048e-3; rho_Np=20.48e3;
Z_Pu=94; M_Pu=244.064e-3; rho_Pu=19.74e3;
Z_Am=95; M_Am=243.061e-3; rho_Am=13.67e3;
Z_Cm=96; M_Cm=247.070e-3; rho_Cm=13.51e3;
Z_Bk=97; M_Bk=247.0703e-3; rho_Bk=10.07e3;
Z_Cf=98; M_Cf=251.0796e-3; rho_Cf=11.72e3;
Z_Es=99; M_Es=252.083e-3; rho_Es=15.37e3;
Z_Fm=100; M_Fm=257.095e-3; rho_Fm=18.97e3;
Z_Md=101; M_Md=258.098e-3; rho_Md=20.48e3;
Z_No=102; M_No=259.101e-3; rho_No=19.74e3;
Z_Lr=103; M_Lr=262.1097e-3; rho_Lr=13.67e3;
Z_Rf=104; M_Rf=261.1088e-3; % rho_Rf=;
Z_Db=105; M_Db=262.1141e-3; % rho_Db=;
Z_Sg=106; M_Sg=263e-3; % rho_Sg=;
Z_Bh=107; M_Bh=262e-3; % rho_Bh=;
Z_Hs=108; M_Hs=265e-3; % rho_Hs=;
Z_Mt=109; M_Mt=266e-3; % rho_Mt=;
Z_Ds=110; M_Ds=268e-3; % rho_Ds=;
Z_Rg=111; M_Rg=270e-3; % rho_Rg=;
% --------------------------------------------------------------------------
% Einheitenkonversion
kg2u=1/m_u; u2kg=m_u;
kg2MeV=1e-6*c^2/el; MeV2kg=1/kg2MeV;
PS2kW=0.075*g_n; kW2PS=1/PS2kW;
% --------------------------------------------------------------------------
% End
