t = 0:0.01:5;
G1 = zpk([],[-2, -3, -7],41);
T1 = feedback(G1,1);
step(T1,t);
hold on

G2 = zpk([-0.04098],[-0.01 -2 -3 -7],41);
T2 = feedback(G2,1);
step(T2,t);
hold on

legend("sem compensação", "compensado");