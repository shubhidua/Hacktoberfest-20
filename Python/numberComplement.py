def findComplement(n: int) -> int:
  c = ""
  b = bin(n).replace("0b","")
  b = str(b)
  for i in range(0,len(b)):
      if b[i] == '0':
          c = c + "1"
      else:
          c = c + "0"
  print(" b ", b, "\n c ", c)
  return int(c,2)

n = 5
print("The complement of ", n, " is : ", findComplement(n))
