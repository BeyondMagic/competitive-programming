% João V. Farias - BeyondMagic

main :-
    read_line_to_string(user_input, Line1),
    split_string(Line1, " ", " ", [S1]),
    read_line_to_string(user_input, Line2),
    split_string(Line2, " ", " ", [S2]),
    read_line_to_string(user_input, Line3),
    split_string(Line3, " ", " ", [S3]),
    atom_number(S1, N),
    atom_number(S2, M),
    atom_number(S3, S),
    solve(N, M, S, X),
    writeln(X),
    halt.

:- initialization(main).

% S := 6
% ___
% 100 -> 1
% 100 => 0 + 0 + 1 = 1
% 99 => 9 + 9 => 18
% ...
% 60 => 6 + 0 => 6

% -------------
%
% sum_digits/2 of number and put into X

sum_digits_(0, Acc, X) :-
    X = Acc ,
    !.

sum_digits_(N, Acc, X) :-
    Digit is N mod 10 ,
    NewAcc is Digit + Acc ,
    NewN is N // 10 ,
    sum_digits_(NewN, NewAcc, X).

sum_digits(N, X) :-
    sum_digits_(N, 0, X).

% ------------

solve(N, Ith, S, X) :-
    Ith < N -> ( X = -1) ;
    (
        sum_digits(Ith, Sum) ,
        Sum is S -> (
            X = Ith
        ) ;
        (
            NewIth is Ith - 1 ,
            solve(N, NewIth, S, X)
        )
    ).
