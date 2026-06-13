import Text.Printf

listStrToInt = map (\x -> read x :: Int). words

solve x n m = (x * (n + 1)) - sum m

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    m <- getContents

    let x = read l1 :: Int
    let n = read l2 :: Int
    let mp = listStrToInt m

    print (solve x n mp)
    --printf "%s\n" (m)
