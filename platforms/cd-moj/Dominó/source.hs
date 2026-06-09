import Text.Printf

solve n = div ((n + 1) * (n + 2)) 2

main :: IO ()
main = do
    l1 <- getLine
    let n = read l1 :: Int
    printf "%d\n" (solve n)
