import Text.Printf

toInt ns = map (\n -> read n :: Int) ns
toDouble ns = map (\n -> read n :: Double) ns

f (a:b:_) = a * b
solve xs = f (toDouble xs)

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let r = [l2, l3]
    printf "NUMBER = %s\n" (l1)
    printf "SALARY = U$ %.2f\n" (solve r)

