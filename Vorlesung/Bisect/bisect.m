%%
clear, clc, clf

%% define function
syms x
 f = sin(x) - 0.5 * x;
%f = (1.234567-x)*(x+0.987654);


%% define interval
a = -2;
b = 2;

%% graphics
fplot(f,[a,b]);            %% old: ezplot
hold on
plot([a,b],[0,0],'-r')

