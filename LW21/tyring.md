# Laboratory Work Report No. 5
---

## Course: "Fundamental Informatics"
---

Student of Group M8O-108B-23 Nurgaliev Daniil Ildarovich

Work was done

Instructor: Sevastyanov Viktor Sergeevich, Department 806

1. **Topic**: Turing Machine
2. **Objective**: To study the Turing machine and complete the assignment
3. **Assignment**:
- Implement the logical multiplication of binary numbers in a Turing machine
4. **Idea, method, algorithm for solving the task**:
- Download a Turing machine emulator
- Try out the "commands" of the Turing machine
- Execute the logical multiplication of binary numbers in a Turing machine
5. **Scenario for completing work**: execute commands, check tests
Test
Input Data
Result

:------:
:----------------:
:---------:

Test 1
111 1
1

Test 2
101 110
100

Test 3
000 001
0
6. **Protocol**:
00, ,<,copy

copy,1,<,copy
copy,0,<,copy
copy, ,<,chislo1

chislo1,1,<,chislo1
chislo1,0,<,chislo1
chislo1, ,>,arr
chislo1,*,>,arr
chislo1,^,>,arr
chislo1,+,>,arr2
chislo1,%,>,arr2

arr,1,*,ed
arr,0,^,nul
arr, ,>,arr2

ed,*,>,ed
ed,^,>,ed
ed,1,>,ed
ed,0,>,ed
ed, ,>,ed1

ed1,1,>,ed1
ed1,0,>,ed1
ed1, ,>,input1

input1,0,>,input1
input1,1,>,input1
input1, ,1,nachalo

input0,0,>,input0
input0,1,>,input0
input0, ,0,nachalo

nachalo,1,<,nachalo
nachalo,0,<,nachalo
nachalo, ,=,00

nul,*,>,nul
nul,^,>,nul
nul,1,>,nul
nul,0,>,nul
nul, ,>,nul1

nul1,0,>,nul1
nul1,1,>,nul1
nul1, ,>,input0

arr2,1,+,ed20
arr2,0,%,nul20
arr2, ,<,wow

ed20,1,>,ed20
ed20,0,>,ed20
ed20,+>,
(ed20…)

7. **Conclusion**: I learned to work with a Turing machine; change symbols; copy numbers; execute their logical multiplication.