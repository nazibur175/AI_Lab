hanoi(0, _, _, _) :- !.

hanoi(N, Source, Target, Auxiliary) :-
    N > 0,
    M is N - 1,
    hanoi(M, Source, Auxiliary, Target),
    write('Move disk '),
    write(N),
    write(' from '),
    write(Source),
    write(' to '),
    write(Target),
    nl,
    hanoi(M, Auxiliary, Target, Source).

% Sample queries:
% ?- hanoi(1, left, right, middle).
% Move disk 1 from left to right
% true.
%
% ?- hanoi(3, left, right, middle).
% Move disk 1 from left to middle
% Move disk 2 from left to right
% Move disk 1 from middle to right
% Move disk 3 from left to middle
% Move disk 1 from right to left
% Move disk 2 from right to middle
% Move disk 1 from left to middle
% true.
