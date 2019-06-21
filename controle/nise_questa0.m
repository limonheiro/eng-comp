
G=zpk([],[-2 -3 -7],1);
figure
rlocus(G);
sgrid(0.59,0);

G2=zpk([-0.04098],[-0.01 -2 -3 -7],1);
figure
rlocus(G2);
sgrid(0.59,0);
%axis([-10 0 -4.4])