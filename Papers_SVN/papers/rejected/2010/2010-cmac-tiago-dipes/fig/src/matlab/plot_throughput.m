function plot_throughput(YMatrix1)
%CREATEFIGURE(YMATRIX1)
%  YMATRIX1:  matrix of y data

%  Auto-generated by MATLAB on 11-Feb-2010 19:08:06

% Create figure
figure1 = figure('XVisual',...
    '0x27 (TrueColor, depth 24, RGB mask 0xff0000 0xff00 0x00ff)');

% Create axes
axes1 = axes('Parent',figure1,'YScale','log','YMinorTick','on',...
    'XTickLabel',{'2','3','4','5'},...
    'XTick',[1 2 3 4],...
    'FontSize',11);
box('on');
hold('all');

% Create multiple lines using matrix input to semilogy
semilogy1 = semilogy(YMatrix1,'Parent',axes1,'MarkerSize',10,'LineWidth',2);
set(semilogy1(1),'Marker','o','DisplayName','No CSMA-CA / ACK');
set(semilogy1(2),'Marker','square','DisplayName','No ACK');
set(semilogy1(3),'Marker','x','DisplayName','No CSMA-CA');
set(semilogy1(4),'Marker','.','DisplayName','Full');
set(semilogy1(5),'Marker','+','DisplayName','Full/Beacon-enabled');

% Create xlabel
xlabel('Number of nodes','FontWeight','demi','FontSize',12);

% Create ylabel
ylabel('Throughput (bits/s)','FontWeight','demi','FontSize',12);

% Create legend
legend1 = legend(axes1,'show');
set(legend1,'Location','West');

