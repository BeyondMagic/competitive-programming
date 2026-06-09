import Text.Printf

solve d a n
    | n <= 14   = (32 - n) * (d + (n - 1) * a)
    | otherwise = (32 - n) * (d + 14 * a)

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let d = read l1 :: Int
    let a = read l2 :: Int
    let n = read l3 :: Int

    printf "%d\n" (solve d a n)
