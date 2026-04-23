% João V. Farias - BeyondMagic

main :-
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    atom_number(S1, N),
    atom_number(S2, M),
    % -----------------------------------
    solve(N, M, X),
    writeln(X),
    halt.

:- initialization(main).

solve(N, M, X) :-
    X is M + (M - N).
