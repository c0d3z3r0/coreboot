#!/usr/bin/env python3

def c(a,b):
    a=bin(a)[2:]
    b=bin(b)[2:]
    l=max(len(a), len(b))
    a=a.zfill(l)
    b=b.zfill(l)
    for i in range(0, l):
        if a[i] != b[i]:
          print(f'{l-i-1}: {int(a[i])}->{int(b[i])}')

while True:
  try:
    v = input()
    v = v.split(' ')
    c(int(v[0], 16), int(v[1],16))
  except:
    pass
  print()

