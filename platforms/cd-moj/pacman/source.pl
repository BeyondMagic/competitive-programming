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

% --------------------------------------

% reverse_/3
% reverse/2

reverse_([], Acc, Acc).

reverse_([H|T], Acc, X) :-
    reverse_(T, [H|Acc], X).

reverse(L, X) :-
    reverse_(L, [], X).

% --------------------------------------

% my_max/2
my_max(A, B, X) :-
    A > B -> (X = A) ; (X = B).

% --------------------------------------

% readline/1

readline(R) :-
    read_line_to_string(user_input, Input) ,
    atom_chars(Input, L) ,
    maplist(atom_string, L, R).

% --------------------------------------

% pacman/5

pacman([], 0, P, M, _, X) :-
    P > M ->
        (X = P) ;
        (X = M).

pacman([], L, P, M, r, X) :-
    readline(R) ,
    NewL is L - 1 ,
    pacman(R, NewL, P, M, l, X).

pacman([], L, P, M, l, X) :-
    readline(R1) ,
    reverse(R1, R2) ,
    NewL is L - 1 ,
    pacman(R2, NewL, P, M, r, X).

pacman(["A"|T], L, _, M, D, X) :-
    pacman(T, L, 0, M, D, X).

pacman(["o"|T], L, P, M, D, X) :-
    NewP is P + 1 ,
    my_max(NewP, M, NewMax) ,
    pacman(T, L, NewP, NewMax, D, X).

pacman(["."|T], L, P, M, D, X) :-
    pacman(T, L, P, M, D, X).

% --------------------------------------

solve(N, X) :-
    pacman([], N, 0, 0, r, X).
