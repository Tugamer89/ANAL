% ES 2
clear
clc
disp("ES 2");
format longE;

minN = 2;
maxN = 10;

numIter = maxN - minN + 1;
maxS_values = zeros(1, numIter);
minS_values = zeros(1, numIter);
condB_values = zeros(1, numIter);

for n = minN:maxN
    disp("n = " + n);

    B = zeros(n, n);
    for i = 1:n
        for j = 1:n
            if i < j
                B(i, j) = -1;
            elseif i == j
                B(i, j) = 1;
            end
        end
    end

    disp("B = ");
    disp(B);
    
        % PARTE 1
    [U, S, V] = svd(B);
    sValues = diag(S);
    disp("S = ");
    disp(sValues);
    
        % PARTE 2
    maxS = max(sValues);
    minS = min(sValues);
    condB = maxS / minS;
    
    disp("Valore singolare massimo = " + maxS);
    disp("Valore singolare minimo = " + minS);
    disp("Condizionamento in norma 2 = " + condB);
    disp('');
    
    index = n - minN + 1;
    maxS_values(index) = maxS;
    minS_values(index) = minS;
    condB_values(index) = condB;

        % PARTE 3
    B(n, 1) = B(n, 1) + -2^(2 - n);
    aVal = eig(B);
    disp("Autovalori = ");
    disp(aVal);

        % PARTE 4
    r = rank(B);
    disp("Rango = " + r);

    fprintf("\n\n");
end


figure;

% Valori singolari massimi e minimi
subplot(2,1,1);
plot(minN:maxN, maxS_values, 'r-', 'LineWidth', 2);
hold on;
plot(minN:maxN, minS_values, 'b-', 'LineWidth', 2);
xlabel('n');
ylabel('Valori singolari');
title('Andamento dei valori singolari massimi e minimi');
legend('Max singolare', 'Min singolare');
grid on;

% Condizionamento
subplot(2,1,2);
plot(minN:maxN, condB_values, 'g-', 'LineWidth', 2);
xlabel('n');
ylabel('Condizionamento');
title('Andamento del condizionamento');
grid on;

format default;
