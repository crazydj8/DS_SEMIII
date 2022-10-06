# convert infix expression to postfix
from stack import Stack

def checkprec(a, b):
    precedence = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3, "(": 4, "[": 4, "{":4}
    if(precedence[a] > precedence[b]):
        return 1
    elif(precedence[a] < precedence[b]):
        return -1
    else:
        return 0

def infixtopostfix():
    exp = input("Enter Expression:")
    s1 = Stack()
    pexp = ""

    condition = 0
    brace = 1
    for i in range(0, len(exp)):
        #if operand is encountered then it is not pushed into the stack its always sent to the expression
        if (exp[i].isalnum()):
            pexp = pexp + exp[i]
            
        #If operator is encountered then:
        elif (exp[i] in ["+", "-", "*", "/", "^", "(", "[", "{"]):
            #if stack is empty, operator  is always pushed into stack
            if (s1.peep() == None):
                if (exp == "(" or exp == "[" or exp == "{"):
                    brace += 1
                s1.push(exp[i])
                
            #else if precedence of input chr is greater than stack top(or if both operators are power(^)) then its just pushed into stack
            elif(checkprec(exp[i], s1.peep()) > 0 or checkprec(exp[i], s1.peep()) == 0 and (exp[i], s1.peep()) == ("^", "^")):
                if (exp == "(" or exp == "[" or exp == "{"):
                    brace += 1
                s1.push(exp[i])
            
            #else if precedence of input chr is less than stack top(or if both are equal precedence and both are not power(^)) then everything
            #is popped adn sent to expression till either it encounters "(" or the stack becomes Null or current inpur precedence becomes higher than stack top
            #only after that current input is pushed into the stack
            elif(checkprec(exp[i], s1.peep()) < 0 or checkprec(exp[i], s1.peep()) == 0 and (exp[i], s1.peep()) != ("^", "^")):
                while (s1.peep() != None and checkprec(exp[i], s1.peep()) <= 0):
                    if (s1.peep() != "(" and s1.peep() != "[" and s1.peep() != "{"):
                        pexp = pexp + s1.spop()
                    else:
                        break
                s1.push(exp[i])
        
        #when close bracket is encountered, everything is popped till open bracket is encountered and then sent to the expression
        #and then the open bracket is also popped but not sent into the expression
        elif (exp[i] == ")"):
            brace -= 1

            while(s1.peep() != "("):
                if s1.peep() == None:
                    condition = 1
                    break
                pexp = pexp + s1.spop() 
            if (condition != 1):
                s1.spop() 
        
        elif (exp[i] == "]"):
            brace -= 1

            while(s1.peep() != "["):
                if s1.peep() == None:
                    condition = 1
                    break
                pexp = pexp + s1.spop() 
            if (condition != 1):
                s1.spop() 
                
        elif (exp[i] == "{"):
            brace -= 1

            while(s1.peep() != "}"):
                if s1.peep() == None:
                    condition = 1
                    break
                pexp = pexp + s1.spop() 
            if (condition != 1):
                s1.spop() 
        
        #in the end all the left operators are popped from stack and then sent into the expression in order
        if (i == len(exp) - 1):
            while(s1.peep() != None):
                if (s1.peep() != "("):
                    pexp = pexp + s1.spop()
                else:
                    s1.spop()
        
        if (brace != 0):
            condtion = 1

        if condition == 1:
            print("Wrong Input")
            return(None)
        
    return (pexp)
    
print(infixtopostfix())