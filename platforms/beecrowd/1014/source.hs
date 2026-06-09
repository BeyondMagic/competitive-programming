import Text.Printf

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine

    let x = read l1 :: Double
    let y = read l2 :: Double

    printf "%.3f km/l\n" (x / y)
