clc
close
clear

[t] = 0:0.01:1;
A = 1;
f = 7;
C = 2*pi;
j=0;
z=0;
fun = @(t,A,f,C) A*sin(2*pi*f*t + C);
plot(t, fun(t,A,f,C));
hold on
for i=0:1./2.^8:1
    plot(i, fun(i,A,f,C), 'r*', 'MarkerSize', 2);
    plot([j j], [z fun(i,A,f,C)]);
    plot([j i], [fun(i,A,f,C) fun(i,A,f,C)]);
    j = i;
    z = fun(i,A,f,C);
end