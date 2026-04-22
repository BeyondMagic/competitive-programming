% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line),
    % split_string(+String, +SepChars, +PadChars, -SubStrings).
    split_string(Line, " ", " ", [S1, S2, S3]),
    % Atom to number
    atom_number(S1, N1),
    atom_number(S2, N2),
    atom_number(S3, N3),
    % -----------------------------------
    solve(N1, N2, N3, X),
    writeln(X),
    halt.

:- initialization(main).
:- use_module(library(arithmetic)).
:- arithmetic_function(my_min/2).
:- op(800, yfx, my_min).

X = A my_min B :- ((A =< B) -> (X = A) ; (X = B)), !.
A my_min B = X :- ((A =< B) -> (X = A) ; (X = B)), !.

my_min(A, B, X) :-
	A =< B -> (X = A) ; (X = B).

solve(A, B, C, X) :-
	X = min(A // 2, min(B // 3, C // 5)).

