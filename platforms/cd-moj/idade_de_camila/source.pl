% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [A]),
    read_line_to_string(user_input, Line2), split_string(Line2, " ", " ", [B]),
    read_line_to_string(user_input, Line3), split_string(Line3, " ", " ", [C]),
    maplist(atom_number, [A, B, C], L),
    % -----------------------------------
    solve(L, X),
    writeln(X),
    halt.

:- initialization(main).

my_nth1(K, [H|_], K, H) :- !.

my_nth1(K, [_|T], I, X) :-
    NewI is I + 1 ,
    my_nth1(K, T, NewI, X).

my_nth1(K, L, X) :-
    my_nth1(K, L, 1, X).

solve(L, X) :-
    msort(L, S) ,
    my_nth1(2, S, X).
