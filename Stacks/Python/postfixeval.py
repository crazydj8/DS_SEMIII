from stack import Stack

s1 = Stack()
exp = input("Enter Expression: ")

for i in exp:
    if i.isdigit():
        s1.push(int(i))   
    else:
        op1 = s1.spop()
        op2 = s1.spop()
        if i == "+": 
            x = op2 + op1
        elif i == "-":
            x = op2 - op1
        elif i == "*":
            x = op2 * op1
        elif i == "/":
            x = op2 / op1
            if (int(x) - x == 0):
                x = int(x)
        elif i == "^":
            x = op2 ** op1
        s1.push(x)   
    s1.display()
print("Answer =", s1.spop())