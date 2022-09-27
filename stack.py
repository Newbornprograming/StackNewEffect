class Stack:
  def __init__(self):
    self.items = []
    
  def isEmpty(self):
    return self.items == []
    
  def push(self, item):
    self.items.append(item)
    
  def pop(self):
    return self.items.pop()
    
  def peek(self):
    return self.items[len(self.items) - 1]
    
  def size(self):
    return len(self.items)


# application1 using stack: revese string
def reverseString(inputString):
  tempStack = Stack()
  newString = ""
  for i in range(len(inputString)):
    tempStack.push(inputString[i])
    
  for i in range(len(inputString)):
    newString += tempStack.pop()
    
  return newString
  
  
# application2 using stack: general balanced symbols
def matches(openSymbol,closeSymbol):
  opens = "([{"
  closers = ")]}"
  return opens.index(openSymbol) == closers.index(closeSymbol)

def parChecker(symbolString):
  s = Stack()
  balanced = True
  index = 0
  while index < len(symbolString) and balanced:
    symbol = symbolString[index]
    if symbol in "([{":
      s.push(symbol)
    else:
      if s.isEmpty():
        balanced = False
      else:
        top = s.pop()
        if not matches(top,symbol):
          balanced = False
    index += 1
  return balanced and s.isEmpty()
    
    
# application3 using stack: decimal numbers coverting into numbers in any other base
def baseConverter(decNumber, base):
  digits = "0123456789ABCDEF"
  
  remstack = Stack()
  
  while decNumber > 0:
    rem = decNumber % base
    remstack.push(rem)
    decNumber = decNumber // base
    
  newString = ""
  while not remstack.isEmpty():
    newString += digits[remstack.pop()]
    
  return newString
    
    
# application4 using stack: infix to postfix notation
def infixToPostfix(infixexpr):
  prec = {}
  prec["**"] = 4
  prec["*"] = 3
  prec["/"] = 3
  prec["+"] = 2
  prec["-"] = 2
  prec["("] = 1
  
  opStack = Stack()
  postfixList = []
  tokenList = infixexpr.split()
  
  for token in tokenList:
    if token in "ABCDEFGHIJKLMNOPQRSTUVWXYZ" or token in "0123456789":
      postfixList.append(token)
    elif token == '(':
      opStack.push(token)
    elif token == ')':
      topToken = opStack.pop()
      while topToken != '(':
        postfixList.append(topToken)
        topToken = opStack.pop()
    else:
      while (not opStack.isEmpty()) and (prec[opStack.peek()] >= prec[token]):
        postfixList.append(opStack.pop())
      opStack.push(token)
      
  while not opStack.isEmpty():
    postfixList.append(opStack.pop())
  
  return " ".join(postfixList)


# application5 using stack: postfix evaluation
def postfixEval(postfixExpr):
  operandStack = Stack()
  tokenList = postfixExpr.split()
  
  for token in tokenList:
    if token in "0123456789":
      operandStack.push(int(token))
    else:
      operand2 = operandStack.pop()
      operand1 = operandStack.pop()
      result = doMath(token, operand1, operand2)
      operandStack.push(result)
  return operandStack.pop()
    
def doMath(op, op1, op2):
  if op == "*":
    return op1 * op2
  elif op == "/":
    return op1 / op2
  elif op == "+":
    return op1 + op2
  elif op == "**":
    return op1 ** op2
  else:
    return op1 - op2
    
def main():
  myStack = Stack()
  print(myStack.isEmpty())
  myStack.push(1)
  print(myStack.isEmpty())
  print(myStack.peek())
  myStack.pop()
  
  print(reverseString("abc"))
  
  print(parChecker("{{([][])}()}"))
  
  print(baseConverter(25, 2))
  print(baseConverter(25, 16))  
  print(baseConverter(25, 8))  
  print(baseConverter(256, 16))
  print(baseConverter(26, 26))
  
  print(infixToPostfix("A * B + C * D"))
  print(infixToPostfix("( A + B ) * C - ( D - E ) * ( F + G )"))  
  print(infixToPostfix("1 0 + 3 * 5 / ( 1 6 - 4 )"))
  print(infixToPostfix("5 * 3 ** ( 4 - 2 )"))
  
  print(postfixEval('7 8 + 3 2 + /'))
  print(postfixEval(infixToPostfix("5 * 3 ** ( 4 - 2 )")))
main()