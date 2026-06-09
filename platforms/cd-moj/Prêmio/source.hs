import Text.Printf

prize s
    | s >= 150  = 'B'
    | (s >= 120) && (s < 150) = 'D'
    | (s >= 100) && (s < 120) = 'P'
    | otherwise = 'N'

solve p d b = prize (p + (d * 2) + (b * 3))

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine

    let p = read l1 :: Int -- 1 ponto
    let d = read l2 :: Int -- 2 pontos
    let b = read l3 :: Int -- 3 pontos

    printf "%c\n" (solve p d b)
