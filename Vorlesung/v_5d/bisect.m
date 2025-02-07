% 

a = -1;
b = 2;
x = linspace(a,b,1000);
y = sin(x)-x/2;
plot(x,y,[a,b],[0,0])
title('sin(x)-x/2');