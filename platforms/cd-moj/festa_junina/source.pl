% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    read_line_to_string(user_input, Line3), split_string(Line3, " ", " ", [S3]),
    atom_number(S1, E),
    atom_number(S2, S),
    atom_number(S3, L),
    % -----------------------------------
    solve(E, S, L, X),
    writeln(X),
    halt.

:- initialization(main).

:- use_module(library(arithmetic)).
:- arithmetic_function(my_abs/1).
:- op(500, xfx, my_abs).

% ----------------

my_abs(A, X) :-
    A < 0 -> (X is A * -1) ; (X = A).

% -------------------

%  abs(E - S) + abs(L - S) + abs(L - E)
solve(E, S, L, X) :-
    D1 is E - S ,
    D2 is L - S ,
    D3 is L - E ,
    X is my_abs(D1) + my_abs(D2) + my_abs(D3).

