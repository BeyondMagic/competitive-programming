% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1) ,
    atom_number(Line1, N) ,
    read_line_to_string(user_input, Line2) ,
    split_string(Line2, " ", " ", LString) ,
    maplist(atom_number, LString, LNum) ,
    solve(N, LNum),
    halt.

:- initialization(main).

% my_max returns the largest number of a list
my_max_([], B, X) :-
    X = B.

my_max_([H|T], B, X) :-
    H > B -> (
        NewB is H,
        my_max_(T, NewB, X)
    ) ; (
        my_max_(T, B, X)
    ).

my_max([H|T], X) :-
    my_max_(T, H, X).

% ------------

% item_k/3 : returns the number at that position

item_k_([H|T], K, Ith, X) :-
    Ith is K -> (
        X = H
    ) ; (
        NewIth is Ith + 1,
        item_k_(T, K, NewIth, X)
    )
    .

item_k(L, K, X) :-
    item_k_(L, K, 0, X).

% ------------

print_line(_, _, MaxHeight, MaxHeight, _) :- !.

print_line(N, Ith, MaxHeight, Line, List) :-
    item_k(List, Ith, Column) ,
    % Se for possível
    (MaxHeight - Line =< Column -> (
        write('1')
    ) ; (
        write('0')
    )) ,
    (Ith is N - 1 -> (
        NewLine is Line + 1 ,
        writeln('') ,
        print_line(N, 0, MaxHeight, NewLine, List)
    ) ; (
        NewIth is Ith + 1 ,
        write(' ') ,
        print_line(N, NewIth, MaxHeight, Line, List)
    ))
    .

% --------

solve(N, L) :-
    my_max(L, MaxHeight) , % H is how many times we want to repeat each line
    print_line(N, 0, MaxHeight, 0, L).

