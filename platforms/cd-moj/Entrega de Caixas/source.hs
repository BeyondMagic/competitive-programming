import Text.Printf

solve :: Int -> Int -> Int -> Int
solve x y z
    | (x < y) && (y < z)            = 1
    | (x + y) < z                   = 1
    | (x < y) || (x < z) || (y < z) = 2
    | otherwise                     = 3

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let x = read l1 :: Int
    let y = read l2 :: Int
    let z = read l3 :: Int

    printf "%d\n" (solve x y z)
