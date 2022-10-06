# Menu driven programm for stacks
import os

class Stack():
    def __init__(self):
        self.stk = []
        self.top = None
        
    def isempty(self):
        if self.stk == []:
            return True
        else:
            return False
        
    def push(self, x):
        self.stk.append(x)
        self.top = len(self.stk) - 1
        
    def spop(self):
        if self.isempty():
            print("Underflow")
        else:
            self.item = self.stk.pop()
            if self.isempty():
                self.top = None
            else:
                self.top = len(self.stk) - 1
            return(self.item)
    
    def peep(self):
        if self.isempty():
            return None
        else:
            self.top = len(self.stk) - 1
            return self.stk[self.top]
    
    def display(self):
        if self.isempty():
            print("List Empty")
        else:
            self.top = len(self.stk) - 1
            print("Stack:")
            for i in range(self.top, -1, -1):
                print(self.stk[i])

def clear():
    os.system("cls")

def pausenclear():
    input("Press enter to continue:")
    os.system("cls")
               
s1 = Stack()
'''while True:
    print("Your choices are: 1. Push 2. Pop 3. Peep 4. Display 5. Exit")
    ch = int(input("Enter your choice(1/2/3/4/5):"))
    if ch == 1:
        clear()
        a = int(input("Enter element to push:"))
        s1.push(a)
        print(a, "Pushed successfully")
        pausenclear()

    elif ch == 2:
        clear()
        itm = s1.spop()
        print("Successfully deleted:", itm)
        pausenclear()
    
    elif ch == 3:
        clear()
        itm = s1.peep()
        print ("Element on Top =", itm)
        pausenclear()
        
    elif ch == 4:
        clear()
        s1.display()
        pausenclear()
        
    elif ch == 5:
        break'''