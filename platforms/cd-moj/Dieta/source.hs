import Text.Printf

grams (a:b:c:_) = a * 4 + b * 9 + c * 4

solve (k, l) = k - (sum $ map grams l)

format (h:t) = (k, refeicoes) where
    k = read (last $ words h) :: Int
    toInt c = read c :: Int
    refeicoes = map (\w -> map toInt (words w)) t

main :: IO ()
main = do
    -- l1 <- getLine
    content <- getContents
    -- let t = read l1 :: Int
    let i = format (lines content)
    let r = solve i
    printf "%d\n" (r)
