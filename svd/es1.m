% ES 1
clear
clc
disp("ES 1");

d0 = 3;
d1 = 2;
m = 10*(d0+1) + d1;

x = (1:m)' / m;
A = [ones(m, 1), x, x.^2];
disp("A = ");
disp(A);

    % PARTE 1
[UA, sA, VA] = svd(A);
AT = A';
[UAT, sAT, VAT] = svd(AT);

disp("ΣA - ΣAT = ");
disp(diag(sA) - diag(sAT));

    % PARTE 2
aValAAT = eig(A*AT);
aValATA = eig(AT*A);

disp("ΣA - ΛAAT = ");
disp(sA - aValAAT);
disp("ΣA - ΛATA = ");
disp(diag(sA) - aValATA);

    % PRTE 3
ortA = orth(A);
ortAT = orth(AT);

disp("Im(A) - UA = ");
disp(ortA - UA(:, 1:3));
disp("Im(AT) - UAT = ");
disp(ortAT - UAT);

    % PARTE 4
nullA = null(A);
nullAT = null(AT);

disp("nullA - VA = ");
disp(nullA' * VA);
disp("nullAT - VAT = ");
disp(nullAT' * VAT);
