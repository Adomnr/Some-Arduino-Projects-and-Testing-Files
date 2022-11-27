 epsilon_D = ones(size(lambda)) - ((f(1)*omegap^2) *...
        (omegalight.^2 + i*Gamma(1)*omegalight).^(-1));




twopic = 1.883651567308853e+09; % twopic=2*pi*c where c is speed of light
omegalight = twopic*(lambda.^(-1)); % angular frequency of light (rad/s)
invsqrt2 = 0.707106781186547;  % 1/sqrt(2)
ehbar = 1.51926751447914e+015; % e/hbar where hbar=h/(2*pi) and e=1.6e-19



omegap = 9.03*ehbar;
            f =     [0.760 0.024 0.010 0.071 0.601 4.384];
            Gamma = [0.053 0.241 0.345 0.870 2.494 2.214]*ehbar;
            omega = [0.000 0.415 0.830 2.969 4.304 13.32]*ehbar;
 order = length(omega); 
