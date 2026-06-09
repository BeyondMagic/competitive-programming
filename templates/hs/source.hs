import Text.Printf

toInt ns = map (\n -> read n :: Int) ns
toDouble ns = map (\n -> read n :: Double) ns

f (a:b:_) = a * b
solve xs = f (toDouble xs)


main :: IO ()
main = do
    line1 <- getLine
    line2 <- getLine
    line3 <- getLine
    line4 <- getLine

    let linesList = [line1, line2, line3, line4]
    print linesList

    -- printf "|%-10s|\n" "Left"     -- Prints: |Left      |
    -- printf "|%10s|\n"  "Right"    -- Prints: |     Right|
    -- printf "%05d\n"    (42::Int)  -- Prints: 00042
    -- printf "%.3f\n"    (1.23456)  -- Prints: 1.235 (Rounds automatically)
