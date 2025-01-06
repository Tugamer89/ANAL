% ES 3
clear
clc
disp("ES 3")

A = [ 1  -1  2;
     -2   0  5;
      6  -3  6];

    % PARTE 1
function v = powerMethod(A, v0, maxIter)
    v = v0 / norm(v0);
    
    startColor = [0, 0, 1]; % Blu
    endColor = [1, 0, 0];   % Rosso
    
    % Prepara la finestra grafica
    figure;
    hold on;
    grid on;
    xlabel('x'); ylabel('y'); zlabel('z');
    
    for k = 1:maxIter
        v_new = A * v;
        v = v_new / norm(v_new);
        
        t = (k - 1) / (maxIter - 1); % Valore tra 0 e 1
        currentColor = (1 - t) * startColor + t * endColor;
        
        plot3([0, v(1)], [0, v(2)], [0, v(3)], 'Color', currentColor, 'LineWidth', 1);
    end
    
    hold off; % Chiudi la modalità di sovrapposizione
end

v1 = [1; 1; 1];
v2 = [3; 10; 4];
maxIter = 100;

V1 = powerMethod(A, v1, maxIter);
V2 = powerMethod(A, v2, maxIter);

disp("Autovettore di v1 = ");
disp(V1);

disp("Autovettore di v2 = ");
disp(V2);
