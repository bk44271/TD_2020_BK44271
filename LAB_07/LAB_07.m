clc
close
clear

x = fscanf(fopen('x.txt', 'r'), '%f');
y = fscanf(fopen('y.txt', 'r'), '%f');
nrzix = fscanf(fopen('nrzix.txt', 'r'), '%f');
nrziy = fscanf(fopen('nrziy.txt', 'r'), '%f');
manx = fscanf(fopen('manx.txt', 'r'), '%f');
many = fscanf(fopen('many.txt', 'r'), '%f');


for i=0:0.01:1
    figure(1)
    plot(x,y)
    figure(2)
    plot(nrzix, nrziy)
    figure(3)
    plot(manx, many)
    
end