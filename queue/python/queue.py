# Menu driven programm for stacks
import os

class Queue():
    def __init__(self):
        self.queue = []
        self.front = None
        self.rear = None
        
    def isempty(self):
        if self.queue == []:
            return True
        else:
            return False
        
    def enqueue(self, x):
        self.queue.append(x)
        self.front = 0
        self.rear = len(self.queue) - 1
        
    def dequeue(self):
        if self.isempty():
            print("Underflow")
        else:
            self.item = self.queue.pop(0)
            if self.isempty():
                self.front = None
                self.rear = None
            else:
                self.rear = len(self.queue) - 1
            return(self.item)
    
    def peep(self):
        if self.isempty():
            return None
        else:
            return self.queue[self.front]
    
    def display(self):
        if self.isempty():
            print("List Empty")
        else:
            print("Queue:")
            for i in range(0, len(self.queue)):
                print(self.queue[i])

def clear():
    os.system("cls")

def pausenclear():
    input("Press enter to continue:")
    os.system("cls")

q1 = Queue()
while True:
    print("Your choices are: 1. Enqueue 2. Dequeue 3. Peep 4. Display 5. Exit")
    ch = int(input("Enter your choice(1/2/3/4/5):"))
    if ch == 1:
        clear()
        a = int(input("Enter element to enqueue:"))
        q1.enqueue(a)
        print(a, "Enqueued successfully")
        pausenclear()

    elif ch == 2:
        clear()
        itm = q1.dequeue()
        print("Successfully dequeued:", itm)
        pausenclear()
    
    elif ch == 3:
        clear()
        itm = q1.peep()
        print ("Element at front =", itm)
        pausenclear()
        
    elif ch == 4:
        clear()
        q1.display()
        pausenclear()
        
    elif ch == 5:
        break