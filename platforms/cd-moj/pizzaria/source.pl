% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [S2]),
    atom_number(S1, G),
    atom_number(S2, P),
    % -----------------------------------
    solve(G, P, X),
    writeln(X),
    halt.

:- initialization(main).

solve(G, P, X) :-
    X is G * 8 + P * 4 - 2.
