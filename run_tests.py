import subprocess
import os

def run_prog(exe_path, input_str):
    p = subprocess.Popen(
        [exe_path],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = p.communicate(input=input_str)
    return stdout

os.makedirs(r"d:\tugas\TM5\output", exist_ok=True)

# Test 1: Soal 1
input_s1 = """1
15
1
28
1
42
1
99
1
10
3
2
2
3
1
55
1
77
1
88
1
95
1
100
3
4
3
5
"""
out1 = run_prog(r"d:\tugas\TM5\src\soal1.exe", input_s1)
with open(r"d:\tugas\TM5\output\output_soal1.txt", "w", encoding="utf-8") as f:
    f.write(out1)
print("Soal 1 test executed successfully.")

# Test 2: Soal 2
input_s2 = """1
45
1
12
1
88
1
34
1
91
1
23
1
70
3
4
5
6
2
3
4
7
4
8
"""
out2 = run_prog(r"d:\tugas\TM5\src\soal2.exe", input_s2)
with open(r"d:\tugas\TM5\output\output_soal2.txt", "w", encoding="utf-8") as f:
    f.write(out2)
print("Soal 2 test executed successfully.")

# Test 3: Soal 3A Circular Queue
input_s3a = """1
10
1
20
1
30
1
40
1
50
1
60
1
70
3
4
1
999
2
2
2
3
1
80
1
90
3
4
5
6
"""
out3a = run_prog(r"d:\tugas\TM5\src\soal3_circular.exe", input_s3a)
with open(r"d:\tugas\TM5\output\output_soal3_circular.txt", "w", encoding="utf-8") as f:
    f.write(out3a)
print("Soal 3A test executed successfully.")

# Test 4: Soal 3B Linked List Queue
input_s3b = """1
100
1
200
1
300
1
400
4
3
2
2
4
1
500
1
600
4
5
4
6
"""
out3b = run_prog(r"d:\tugas\TM5\src\soal3_linked_list.exe", input_s3b)
with open(r"d:\tugas\TM5\output\output_soal3_linked_list.txt", "w", encoding="utf-8") as f:
    f.write(out3b)
print("Soal 3B test executed successfully.")
