import Text.Printf

main :: IO ()
main = do
    l1 <- getLine
    let t = read l1 :: Int

    printf "%d\n" (t * 4)
