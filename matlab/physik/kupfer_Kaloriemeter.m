m_wasser = 0.5;
c_wasser = 4182;
temp_wasser = 20;
syms tmisch;

m_eis = 0.2;
temp_eis = 0;
Schmelzwaerme_Wasser = 3.338*10^5;

delta_T_wasser = (tmisch - temp_wasser);
delta_T_eis = (tmisch - temp_eis);
delta_T_eiswasser = (Schmelzwaerme_Wasser * m_eis);

solve(0==c_wasser*m_wasser*delta_T_wasser + c_wasser*m_eis*delta_T_eis+delta_T_eiswasser)