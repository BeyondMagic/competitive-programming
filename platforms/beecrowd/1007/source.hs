import Text.Printf

toInt ns = map (\n -> read n :: Int) ns
f (a:b:c:d:_) = a * b - c * d
solve xs = f (toInt xs)

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine
    l4 <- getLine

    let r = [l1, l2, l3, l4]
    printf "DIFERENCA = %d\n" (solve r)

    -- printf "|%-10s|\n" "Left"     -- Prints: |Left      |
    -- printf "|%10s|\n"  "Right"    -- Prints: |     Right|
    -- printf "%05d\n"    (42::Int)  -- Prints: 00042
    -- printf "%.3f\n"    (1.23456)  -- Prints: 1.235 (Rounds automatically
