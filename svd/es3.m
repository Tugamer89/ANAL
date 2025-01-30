% ES 3
clear
clc
disp("ES 3");
format long;

d0 = 3;
d1 = 2;
m = 10*(d0+1) + d1;

x = (1:m)' / m;
A = [ones(m, 1), x, x.^2];
y = sin(x);

disp("Norma due al quadrato di Ac - y")

%% PARTE 1
[U, S, V] = svd(A);
c1 = V * pinv(S) * U' * y;
disp("SVD = ");
disp(norm(A * c1 - y) ^ 2);

%% PARTE 2
[Q, R] = qr(A);
c2 = R \ (Q' * y);
disp("QR = ");
disp(norm(A * c2 - y) ^ 2);

%% PARTE 3
c3 = (A' * A) \ (A' * y);
disp("eq. norm. = ");
disp(norm(A * c3 - y) ^ 2);

%% PARTE 4
c4 = A \ y;
disp("diretta = ");
disp(norm(A * c4 - y) ^ 2);

format default;
