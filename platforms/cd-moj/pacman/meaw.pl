% João V. Farias - BeyondMagic

main :-
    % -----------------------------------
    read_line_to_string(user_input, Line1), split_string(Line1, " ", " ", [S1]),
    atom_number(S1, N),
    % -----------------------------------
    read_grid_size(N, G),
    solve(N, G, X),
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

% read_grid_size_/4
% read_grid_size/2
% N: size
% j: row
% acc: grid
% G: answer
read_grid_size_(N, N, Acc, Acc).

read_grid_size_(N, Row, Acc, G) :-
    read_line_to_string(user_input, Input) ,
    atom_chars(Input, LC) ,
    maplist(atom_string, LC, LS) ,
    NewRow is Row + 1 ,
    NewAcc = [LS|Acc] ,
    read_grid_size_(N, NewRow, NewAcc, G)
    .

read_grid_size(N, G) :-
    read_grid_size_(N, 0, [], GR) ,
    reverse(GR, G).

% --------------------------------------

list_item_k_([], K, K, _) :-
    fail.

list_item_k_([H|T], K, Ith, X) :-
    Ith =:= K -> (
        X = H
    ) ; (
        NewIth is Ith + 1 ,
        list_item_k_(T, K, NewIth, X)
    ).

list_item_k(L, K, X) :-
    list_item_k_(L, K, 1, X).

% --------------------------------------

max_list_([], X, X).

max_list_([H|T], Max, X) :-
    H > Max -> (
        NewMax is H ,
        max_list_(T, NewMax, X)
    ) ; (
        max_list_(T, Max, X)
    ).

max_list([H|T], X) :-
    max_list_(T, H, X).

% -------------------------------

% N : size x size of grid
% G : grid
% I : iterator of row
% J : iterator of column
% Acc : list
% Dir : direction of value
% X : answer of pacman

pacman(N, G, N, N, Max, _, Acc, X) :-
    list_item_k(G, N, Row) ,
    list_item_k(Row, N, Char) ,
    ((Char = "o") -> (
        NewMax is Max + 1 ,
        X = [NewMax | Acc]
    ) ; (
        X = [Max | Acc]
    )).

pacman(N, G, I, J, Max, Dir, Acc, X) :-
    %writeln(" 1----- ") ,
    list_item_k(G, I, Row) ,
    %writeln(" 2----- ") ,
    list_item_k(Row, J, Char) ,
    %writeln(" 3----- ") ,
    %write("I = ") , write(I) , write(" | J = ") , write(J) , writeln('') ,
    % fim da linha
    ((
        % direita e chegou no final
        (J =:= N , Dir =:= 1) ;
        % esquerda e chegou no inicio
        (J =:= 1 , Dir =:= -1)
    ) -> (
        NewI is I + 1 ,
        NewJ is J,
        NewDir is -1 * Dir ,
        % ghost
        ((Char = "A") -> (
            NewMax is 0 ,
            %write("NewMax = ") , write(NewMax) , write(" | Char = ") , write(Char) , writeln('') ,
            NewAcc = [Max | Acc] ,
            %write("NewAcc = ") , write(NewAcc) , write(" | NewDir = ") , write(NewDir) , writeln('') ,
            pacman(N, G, NewI, NewJ, NewMax, NewDir, NewAcc, X)
        ) ; (
            % point
            (Char = "o") -> (
                NewMax is Max + 1 ,
                % write("NewMax = ") , write(NewMax) , write(" | Char = ") , write(Char) , writeln('') ,
                pacman(N, G, NewI, NewJ, NewMax, NewDir, Acc, X)
            ) ; (
                % dot
                %write("NewI = ") , write(NewI) , write(" | NewJ = ") , write(NewJ) , writeln('') ,
                pacman(N, G, NewI, NewJ, Max, NewDir, Acc, X)
            )
        ))
    % lugar aleatorio da linha
    ) ; (
        NewJ is J + 1 * Dir ,
        NewI is I ,
        % ghost
        ((Char = "A") -> (
            NewMax is 0 ,
            NewAcc = [Max | Acc] ,
            % write("NewMax = ") , write(NewMax) , write(" | Char = ") , write(Char) , writeln('') ,
            pacman(N, G, NewI, NewJ, NewMax, Dir, NewAcc, X)
        ) ; (
            % point
            (Char = "o") -> (
                NewMax is Max + 1 ,
                % write("NewMax = ") , write(NewMax) , write(" | Char = ") , write(Char) , writeln('') ,
                pacman(N, G, NewI, NewJ, NewMax, Dir, Acc, X)
            ) ; (
                % dot
                % write("NewI = ") , write(NewI) , write(" | NewJ = ") , write(NewJ) , writeln('') ,
                pacman(N, G, NewI, NewJ, Max, Dir, Acc, X)
            )
        ))
    )).

% ----------------------------

solve(N, G, X) :-
    pacman(N, G, 1, 1, 0, 1, [], L) ,
    writeln(L),
    max_list(L, X).
