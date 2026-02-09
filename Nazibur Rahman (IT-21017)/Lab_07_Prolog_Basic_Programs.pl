% Program 1: Max and Min
find_max(X, Y, X) :- X >= Y, !.
find_max(X, Y, Y) :- X < Y.

find_min(X, Y, X) :- X =< Y, !.
find_min(X, Y, Y) :- X > Y.

% Sample queries:
% ?- find_max(5, 8, Max).
% Max = 8.
%
% ?- find_min(5, 8, Min).
% Min = 5.


% Program 2: Resistance of Circuits
series(R1, R2, Re) :-
    Re is R1 + R2.

parallel(R1, R2, Re) :-
    Re is (R1 * R2) / (R1 + R2).

% Sample query:
% ?- parallel(10, 40, R3), series(R3, 12, R4), parallel(R4, 30, R5).
% R3 = 8.0,
% R4 = 20,
% R5 = 12.0.


% Program 3: Line Segment Classification
vertical(seg(point(X, _), point(X, _))).
horizontal(seg(point(_, Y), point(_, Y))).
oblique(seg(point(X1, Y1), point(X2, Y2))) :-
    X1 \== X2,
    Y1 \== Y2.

% Sample queries:
% ?- vertical(seg(point(3, 1), point(3, 10))).
% true.
%
% ?- horizontal(seg(point(1, 5), point(9, 5))).
% true.
%
% ?- oblique(seg(point(1, 2), point(3, 5))).
% true.
