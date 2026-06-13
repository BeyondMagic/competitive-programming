import Text.Printf


form x
    | x >= 5 = 1
    | x >= 3 = 2
    | x >= 1 = 3
    | otherwise = -1

solve :: String -> Int
solve = form . length . filter (=="V") . lines

main :: IO ()
main = do
    c <- getContents

    let r = solve c

    print r
    --printf "%.3f km/l\n" (x / y)
