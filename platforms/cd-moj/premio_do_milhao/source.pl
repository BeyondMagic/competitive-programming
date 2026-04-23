% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    atom_number(S1, N),
    % -----------------------------------
    solve(N, X),
    writeln(X),
    halt.

:- initialization(main).

% ---------------------

solve(N, _, N, N).

solve(N, S, D, X) :-
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]) ,
    atom_number(S1, K) ,
    NewS is S + K ,
    (NewS >= 1000000 -> (
        X = D
    ) ; (
        NewD is D + 1 ,
        solve(N, NewS, NewD, X)
    )).


solve(N, X) :-
    solve(N, 0, 1, X).

