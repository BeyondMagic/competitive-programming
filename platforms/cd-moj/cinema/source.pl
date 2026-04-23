% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    atom_number(S1, A),
    atom_number(S2, B),
    % -----------------------------------
    solve(A, B, X),
    writeln(X),
    halt.

:- initialization(main).

:- use_module(library(arithmetic)).
:- arithmetic_function(ingresso/1).
:- op(700, 'xfx', ingresso).

ingresso(A, X) :-
    A =< 17 -> (X = 15) ; (
        A =< 59 -> (X = 30) ; (
            X = 20
        )
    ).

solve(A, B, X) :-
    X is ingresso(A) + ingresso(B).

