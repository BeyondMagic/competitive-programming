% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", L1),
    atom_number(S1, N),
    maplist(atom_number, L1, L),
    % -----------------------------------
    solve(N, L, X),
    writeln(X),
    halt.

:- initialization(main).

% X = Acc
reverse_([], Acc, Acc).

reverse_([H|T], Acc, X) :-
    reverse_(T, [H|Acc], X).

reverse(L, X) :-
    reverse_(L, [], X).

solve_([], _, X, X).

solve_([H|T], Max, Acc, X) :-
    Max >= H -> (
        NewAcc is Acc + 1 ,
        solve_(T, Max, NewAcc, X)
    ) ; (
        NewMax is H,
        solve_(T, NewMax, Acc, X)
    ).

solve(_, L, X) :-
    reverse(L, [Max|T]) ,
    solve_(T, Max, 0, X).

