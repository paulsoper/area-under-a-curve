<p>Numerical methods - at the moment all in c - for measuring the area under a curve.</p>
<p>Usage is, for example, simpson -a 0 -b 10 -n 100, to use Simpson's rule to integrate f(x) from 0 to 10 using 100 segments</p>
<p>Each method integrates the curve f(x) = sqrt(x) + x^(3/2)</p>
<p>When Mathematica integrates this function, the definite integral from 0 to 10 is 21.65696300259461, and the definite integral from 0 to 100 is 667.411</p>
<p>The eight methods represented here are the eight Newton-Cotes formulae - four open and four closed.</p>
<p>The trapezoid rule is the first degree closed Newton-Cotes formula.</p>
<p>Simpson's rule is the second degree closed Newton-Cotes formula.</p>
<p>Simpson's 3/8 rule is the third degree closed Newton-Cotes formula.</p>
<p>Boole's rule is the fourth degree closed Newton-Cotes formula.</p>
<p>The rectangle rule is the first degree open Newton-Cotes formula.</p>
<p>The trapezoid method is the second degree open Newton-Cotes formula.</p>
<p>Milne's rule is the third degree open Newton-Cotes formula.</p>
<p>The fourth degree open Newton-Cotes formula has no name, and is in the program noname.c</p>
