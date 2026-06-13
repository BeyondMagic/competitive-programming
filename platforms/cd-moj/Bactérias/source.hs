import Text.Printf

solve :: Int -> Int -> Int
solve a b = truncate $ log (fromIntegral a) / log (fromIntegral b)

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let x = read l1 :: Int
    let y = read l2 :: Int

    printf "%d\n" (solve x y)
