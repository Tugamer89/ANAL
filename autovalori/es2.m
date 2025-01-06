% ES 2
clear
clc
disp("ES 2");
    
    % PARTE 1
A = [0 1 1 1 1 1 1 0 0 0 0;
     1 0 0 0 0 0 0 0 0 0 0;
     1 0 0 0 0 0 0 0 0 1 0;
     1 0 0 0 1 0 0 0 0 1 0;
     1 0 0 1 0 1 0 1 0 0 0;
     1 0 0 0 1 0 0 1 0 0 0;
     1 0 0 0 0 0 0 0 0 0 0;
     0 0 0 0 1 1 0 0 1 0 0;
     0 0 0 0 0 0 0 1 0 0 0;
     0 0 1 1 0 0 0 0 0 0 1;
     0 0 0 0 0 0 0 0 0 1 0];

    % PARTE 2
D = diag(A*ones(11, 1));
G = D \ A;

[aVect, aVal] = eig(G);
aVal = diag(aVal);
x = aVect(:, 1);

disp("Autovettori di G: ");
disp(aVect);
disp("Autovalori di G: ");
disp(aVal);
disp("Vettore x: ")
disp(x)
