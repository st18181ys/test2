def mul(base=2,exp=8):
    result=1
    for i in range(exp):
        result*=base
    return result

print(mul())
print(mul(4,2))
print(mul(base=5,exp=3))