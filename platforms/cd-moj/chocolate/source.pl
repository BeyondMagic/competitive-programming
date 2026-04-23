% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    atom_number(S1, L),
    % -----------------------------------
    solve(L, X),
    writeln(X),
    halt.

:- initialization(main).

log2(A, X) :-
    Y is log(A) / log(2),
    X is floor(Y).

solve(L, X) :-
    log2(L, P) ,
    X is 4 ** P.
