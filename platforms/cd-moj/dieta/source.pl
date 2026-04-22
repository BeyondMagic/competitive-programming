% ----

main :-
    read_line_to_string(user_input, Line),
    split_string(Line, " ", " ", [S1, S2]),
    atom_number(S1, N),
    atom_number(S2, M),
    solve(N, M, X),
    writeln(X),
    halt.

:- initialization(main).

% 3 2000
% 65 15 20 = 475
% 40 20 25 = 440
% 50 10 35 = 430
% 2000 - (475 + 440 + 430) = 655

% N : refeições
% M : limite de calorias
% P : 4 calorias
% G : 9 calorias
% C : 4 calorias
% X : Quantidade máxima de calorais ele pode comer sem exceder M
solve_case(N, M, Ith, Acc, X) :-
    Ith =:= N -> (X is M - Acc) ;
    (
        read_line_to_string(user_input, Line),
        split_string(Line, " ", " ", [S1, S2, S3]) ,
        atom_number(S1, P) ,
        atom_number(S2, G) ,
        atom_number(S3, C) ,
        NewIth is Ith + 1 ,
        Sum is P * 4 + G * 9 + C * 4 ,
        (
            Sum + Acc =< M -> (
                NewAcc is Sum + Acc ,
                solve_case(N, M, NewIth, NewAcc, X)
            ) ; (
                solve_case(N, M, NewIth, Acc, X)
            )
        )
    ).

solve(N, M, X) :-
    solve_case(N, M, 0, 0, X).
