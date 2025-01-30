% ES 3
clear
clc
disp("ES 3");

A = [ 1  -1  2;
     -2   0  5;
      6  -3  6];

maxIter = 2000;

    % PARTE 1
function lambda = powerMethod(A, v0, maxIter)
    v = v0 / norm(v0);
    
    for k = 1:maxIter
        v_new = A * v;
        v = v_new / norm(v_new);
        lambda = v' * A * v;
    end
end

v1 = [1; 1; 1];
v2 = [3; 10; 4];

lambda1 = powerMethod(A, v1, maxIter);
lambda2 = powerMethod(A, v2, maxIter);

fprintf("\nAutovalore stimato (v1): %.6E\n", lambda1);
fprintf("Autovalore stimato (v2): %.6E\n", lambda2);

    % PARTE 2
function lambda = inversePowerMethod(A, p, v0, maxIter)
    B = inv(A - p*eye(size(A)));
    mi = powerMethod(B, v0, maxIter);
    lambda = 1/mi + p;
end


eig_vals = eig(A);
p = 100;

lambda_inv1 = inversePowerMethod(A, p, v1, maxIter);
lambda_inv2 = inversePowerMethod(A, p, v2, maxIter);


fprintf("\nAutovalore stimato con metodo inverso (v1): %.6E\n", lambda_inv1);
fprintf("Autovalore stimato con metodo inverso (v2): %.6E\n", lambda_inv2);

fprintf("\nAutovalori reali della matrice:\n");
fprintf("[%.6E, %.6E, %.6E]\n", eig_vals);


fprintf("\nDifferenza metodo potenze (v1): |%.6E - %.6E| = %.6E\n", max(abs(eig_vals)), lambda1, abs(max(abs(eig_vals)) - lambda1));
fprintf("Differenza metodo potenze (v2): |%.6E - %.6E| = %.6E\n", max(abs(eig_vals)), lambda2, abs(max(abs(eig_vals)) - lambda2));
fprintf("Differenza metodo potenze inverse (v1): |%.6E - %.6E| = %.6E\n", max(abs(eig_vals)), lambda_inv1, abs(max(abs(eig_vals)) - lambda_inv1));
fprintf("Differenza metodo potenze inverse (v2): |%.6E - %.6E| = %.6E\n", max(abs(eig_vals)), lambda_inv2, abs(max(abs(eig_vals)) - lambda_inv2));

fprintf("\nVelocità di convergenza metodo delle potenze = %.6E\n", abs(min(lambda1, lambda2)/max(lambda1, lambda2))^maxIter)
fprintf("Velocità di convergenza metodo delle potenze inverse = %.6E\n", abs(max(lambda_inv1-p, lambda_inv2-p)/min(lambda_inv1-p, lambda_inv2-p))^maxIter)
