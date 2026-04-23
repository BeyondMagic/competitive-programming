% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line), split_string(Line, " ", " ", Ls) ,
    maplist(atom_number, Ls, L) ,
    % -----------------------------------
    solve(L, X) ,
    writeln(X) ,
    halt.

:- initialization(main).

sum_([], X, X).

sum_([H|T], Acc, X) :-
    NewAcc is Acc + H,
    sum_(T, NewAcc, X).

sum(L, X) :-
    sum_(L, 0, X).

solve(L, X) :-
    sum(L, S) ,
    X is S - 3.
