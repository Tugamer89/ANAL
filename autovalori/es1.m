% ES 1
clear
clc
disp("ES 1");

d0 = 6;
d1 = 1;
n = 10*(d1+1) + d0;

%% PARTE 1
A = diag(ones(1, n-1), 1) + eye(n);
E = zeros(n);
E(n, 1) = 2^(-n);
B = A + E;

VA = eig(A);
VB = eig(B);
diff = VB-VA;

nN1 = norm(B - A) / norm(A);
nV1 = norm(VB - VA) / norm(VA);

disp("norm(B-A)   = " + nN1);
disp("norm(VB-VA) = " + nV1);
disp("VB - VA = ");
disp(diff);

%% PARTE 2
A2 = A' * A;
B2 = B' * B;

VA2 = eig(A2);
VB2 = eig(B2);
diff2 = VB2-VA2;

nN2 = norm(B2 - A2) / norm(A2);
nV2 = norm(VB2 - VA2) / norm(VA2);

disp("norm(B2-A2)   = " + nN2);
disp("norm(VB2-VA2) = " + nV2);
disp("VB2 - VA2 = ");
disp(diff2);
