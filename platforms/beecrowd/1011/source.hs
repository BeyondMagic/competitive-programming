import Text.Printf

solve r = (4.0 / 3.0) * (3.14159) * (r ** 3)

main :: IO ()
main = do
    l1 <- getLine
    let r = read l1 :: Double
    printf "VOLUME = %.3f\n" (solve r)
