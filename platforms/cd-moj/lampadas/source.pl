% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [N]) ,
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", LS) ,
    maplist(atom_number, LS, L) ,
    % -----------------------------------
    solve(N, L, X),
    [A, B] = X,
    writeln(A),
    writeln(B),
    halt.

:- initialization(main).

solve([], A, B, X) :-
    X = [A, B].

solve([1|T], A, B, X) :-
    NewA is A xor 1,
    solve(T, NewA, B, X).

solve([2|T], A, B, X) :-
    NewA is A xor 1,
    NewB is B xor 1,
    solve(T, NewA, NewB, X).

solve(_, L, X) :-
    solve(L, 0, 0, X).
