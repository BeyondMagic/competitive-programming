import Text.Printf

solve :: Int -> Int -> Int -> Int
solve a b c
    | (b - a) < (c - b) = 1
    | (b - a) > (c - b) = -1
    | otherwise         = 0

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let a = read l1 :: Int
    let b = read l2 :: Int
    let c = read l3 :: Int

    printf "%d\n" (solve a b c)
