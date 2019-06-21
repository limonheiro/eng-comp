clc
clear all
s=tf('s');
G=100/(s*((1/6400)*(s^2) + s/50 + 1)); %fun��o transferencia da planta
FT = feedback(G,1); % fun��o tranferencia de malha fechada
[y,t]=step(FT); % responta ao degrau unitario
S=stepinfo(y,t);
PO=S.Overshoot;
subplot(3,1,1);
plot(t,y);
grid
title("Resposta ao Degrau unitario da fun��o G(s)");
fprintf('Overshoot inicial: %.4f\n',PO);
p=0;
size=[];
poo=[];
while( PO > 0.0 )
    %((s+z)/(s+p))
    p = p+rand(1); % polo
    %propor��o encontrada com a equa��o de erro
    z = p/5; % zero
    Gc=((s+z)/(s+p)); %compensador
    Fl=Gc*G;
    FTL = feedback(Fl,1);% fun��o tranferencia de malha fechada
    [y,t]=step(FTL); % responta ao degrau unitario
    Sl=stepinfo(y,t);
    PO=Sl.Overshoot;
    if(PO<10)
        size=[size,p];
        poo=[poo,PO];
    end
end
p = size(1); % polo
%propor��o encontrada com a equa��o de erro
z = p/5; % zero
Gc=((s+z)/(s+p)); %compensador
Fl=Gc*G;
FTL = feedback(Fl,1);% fun��o tranferencia de malha fechada
[y,t]=step(FTL); % responta ao degrau unitario
Sl=stepinfo(y,t);
PO=Sl.Overshoot;

subplot(3,1,2);
plot(t,y);
grid
title("Resposta ao Degrau unitario da fun��o Gc(s)G(s)");
fprintf('Overshoot final: %.4f\n',PO);
fprintf('Compensador Gc(s)');
Gc
fprintf('fun��o transferencia Gc(s)G(s)\n');
GcG=FTL
subplot(3,1,3);
plot(size,poo);
grid
title("Percentual de sobressinal X Valor do polo da Gc(s)");