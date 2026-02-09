% 1. Area of a rectangle
area_rectangle(Length, Breadth, Area) :-
    Area is Length * Breadth.

% Sample queries:
% ?- area_rectangle(5, 8, Area).
% Area = 40.
%
% ?- area_rectangle(10, 2.5, Area).
% Area = 25.0.


% 2. Celsius to Fahrenheit
celsius_to_fahrenheit(C, F) :-
    F is C * 9 / 5 + 32.

% Sample queries:
% ?- celsius_to_fahrenheit(0, F).
% F = 32.0.
%
% ?- celsius_to_fahrenheit(25, F).
% F = 77.0.


% 3. Factorial
factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, SubResult),
    Result is N * SubResult.

% Sample queries:
% ?- factorial(5, F).
% F = 120.
%
% ?- factorial(0, F).
% F = 1.
