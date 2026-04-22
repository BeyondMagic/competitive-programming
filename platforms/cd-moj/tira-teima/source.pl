% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line),
    split_string(Line, " ", " ", [S1, S2]),
    % Atom to number
    atom_number(S1, X),
    atom_number(S2, Y),
    % -----------------------------------
    solve(X, Y, Ans),
    writeln(Ans),
    halt.

:- initialization(main).

solve(X, Y, Ans) :-
    (
        X >= 0 , X =< 432 ,
        Y >= 0 , Y =< 468
    ) -> (
        Ans = 'dentro'
    ) ; (
        Ans = 'fora'
    ).

