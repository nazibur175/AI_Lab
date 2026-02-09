% 1. Area of a rectangle
area_rectangle(Length, Breadth, Area) :-
    Area is Length * Breadth.

% 2. Celsius to Fahrenheit
celsius_to_fahrenheit(C, F) :-
    F is C * 9 / 5 + 32.

% 3. Factorial
factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, SubResult),
    Result is N * SubResult.

