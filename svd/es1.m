% ES 1
clear
clc
disp("ES 1");

d0 = 3;
d1 = 2;
m = 10*(d0+1) + d1;

x = (1:m)' / m;
A = [ones(m, 1), x, x.^2];

    % PARTE 1
[UA, sA, VA] = svd(A);
AT = A';
[UAT, sAT, VAT] = svd(AT);

disp("ΣA - ΣAT = ");
disp(diag(sA) - diag(sAT));
disp("UA - VAT = ");
disp(UA - VAT);
disp("VA - UAT = ");
disp(VA - UAT);

    % PARTE 2
aValAAT = sort(eig(A*AT), "descend");
aValATA = sort(eig(AT*A), "descend");

disp("ΣA - ΛAAT = ");
disp([diag(sA.^2); zeros(m-width(sA), 1)] - aValAAT);
disp("ΣA - ΛATA = ");
disp(diag(sA.^2) - aValATA);

    % PARTE 3
ortA = orth(A);
ortAT = orth(AT);

disp("Im(A) - UA = ");
disp(ortA - UA(:, 1:3));
disp("Im(AT) - UAT = ");
disp(ortAT - UAT);

    % PARTE 4
ker_nullA = null(A);
ker_nullAT = null(AT);

tol = max(size(A)) * eps(max(diag(sA)));
rank = sum(diag(sA) > tol);
kernel_svdA = VA(:, rank+1:end);
kernel_svdAT = VAT(:, rank+1:end);

disp("ker_nullA - kernel_svdA = ");
disp(ker_nullA - kernel_svdA);
disp("ker_nullAT - kernel_svdAT = ");
disp(ker_nullAT - kernel_svdAT);
