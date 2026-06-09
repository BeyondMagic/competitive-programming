import Text.Printf

solve = foldl (\a b -> div ( a + b + (abs (a - b)) ) 2) 0 . map (\c -> read c :: Int) . words

main :: IO ()
main = do
    l1 <- getLine
    printf "%d eh o maior\n" (solve l1)
