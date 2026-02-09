% Program 1: Max and Min
find_max(X, Y, X) :- X >= Y, !.
find_max(X, Y, Y) :- X < Y.

find_min(X, Y, X) :- X =< Y, !.
find_min(X, Y, Y) :- X > Y.


% Program 2: Resistance of Circuits
series(R1, R2, Re) :-
    Re is R1 + R2.

parallel(R1, R2, Re) :-
    Re is (R1 * R2) / (R1 + R2).

% Program 3: Line Segment Classification
vertical(seg(point(X, _), point(X, _))).
horizontal(seg(point(_, Y), point(_, Y))).
oblique(seg(point(X1, Y1), point(X2, Y2))) :-
    X1 \== X2,
    Y1 \== Y2.
