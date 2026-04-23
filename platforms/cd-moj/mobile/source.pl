% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    read_line_to_string(user_input, Line3), split_string(Line3, " ", " ", [S3]),
    read_line_to_string(user_input, Line4), split_string(Line4, " ", " ", [S4]),
    atom_number(S1, A),
    atom_number(S2, B),
    atom_number(S3, C),
    atom_number(S4, D),
    % -----------------------------------
    solve(A, B, C, D, X),
    writeln(X),
    halt.

:- initialization(main).

solve(A, B, C, D, X) :-
    (
        A =:= B + C + D ,
        D =:= B + C ,
        B =:= C
    ) -> (
        X = 'S'
    ) ; (
        X = 'N'
    ).
