import Text.Printf

listToInt = map (\x -> read x :: Int) . words

sumFilter x = length . filter (==x)


formatAns :: (Int, Int) -> Char
formatAns (a, b)
    | a < 0 || b < 0 = 'N'
    | otherwise      = 'S'

solve n t p m = formatAns
    (
        p - sumFilter 1 t,
        m - sumFilter 2 t
    )

main :: IO ()
main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine
    l4 <- getLine

    let n = read l1 :: Int
    let t = listToInt l2
    let p = read l3 :: Int
    let m = read l4 :: Int

    printf "%c\n" (solve n t p m)
