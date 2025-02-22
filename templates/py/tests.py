tests = [
    (
        """

        """,
        """

        """
    ),
    (
        """

        """,
        """

        """
    ),
    (
        """

        """,
        """

        """
    )
]

import subprocess

# Strips the \n and spaces from the start and end of the tuple (str, str).
tests = [(t[0].strip(), t[1].strip()) for t in tests]

def test(i: int) -> bool:
    inp, expected = tests[i - 1]
    
    out = subprocess.run(
        ['python', 'main.py'],
        input=inp,
        text=True,
        capture_output=True
    ).stdout.strip()
    
    if out != expected:
        print(f'Test {i} FAILED:\n  {inp=}\n  {out=}\n  {expected=}')
        
    return out != expected

# If first program argument is a number, then read that test instead.
import sys
if len(sys.argv) > 1:
    i = int(sys.argv[1])
    exit(int(test(i)))

good = True

for i in range(len(tests)):
    if test(i + 1):
        good = False

print()  
print("All tests pass" if good else "Some tests fail.")