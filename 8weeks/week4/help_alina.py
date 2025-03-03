# Link to the problem statement : https://www.hackerrank.com/contests/acm-8-weeks-of-code-week-04/challenges/decode-and-multiply
def extract_number(s):
    num_str = ""
    for ch in s:
        if '0' <= ch <= '9':
            num_str += ch
    return num_str

def solve():
    s1 = input().strip()
    s2 = input().strip()

    num1 = int(extract_number(s1))
    num2 = int(extract_number(s2))

    print(num1 * num2)

if __name__ == "__main__":
    solve()
