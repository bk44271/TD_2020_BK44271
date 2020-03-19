clc
close
clear

[t] = 0:0.01:1;
A = 1;
f = 7;
C = 2*pi;
fun = @(t,A,f,C) A*sin(2*pi*f*t + C);
plot(t, fun(t,A,f,C));
hold on
for i=0:1./60:1
    plot(i, fun(i,A,f,C), 'r*', 'MarkerSize', 5);
end