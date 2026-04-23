% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    atom_number(S1, E),
    atom_number(S2, D),
    % -----------------------------------
    solve(E, D, X),
    writeln(X),
    halt.

:- initialization(main).

solve(E, D, X) :-
    E > D -> (
        X is E + D
    ) ; (
        X is 2 * (D - E)
    ).
