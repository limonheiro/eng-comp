  clear all
  clc
  qtde=10;
  dados = [];
  saida = serial("COM3", 9600);
  while qtde > 0
    num = char(srl_read(saida,8));
    num
    qtde=qtde-1;
    end