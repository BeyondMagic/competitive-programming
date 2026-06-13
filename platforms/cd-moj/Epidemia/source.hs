import Text.Printf

solve :: Int -> Int -> Int -> Int -> Int
solve n r p k
    | n >= p    = 0
    | otherwise = 1 + solve (n + k * r) r p (k * r)

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let x = read l1 :: Int
    let y = read l2 :: Int
    let z = read l3 :: Int

    printf "%d\n" (solve x y z x)
