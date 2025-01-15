def fact(num):
    if(num < 1):
        return 1
    else:
        return num*fact(num-1)
    


odd = 1
even = 14
sum = 0
for i in range(8):
    x = fact(odd)
    y = fact(even)
    sum += 1 / (x* y)
    print(f'{odd}! = ', x,f', {even}! = ', y,'\n1/x! * y!',sum)
    odd += 2
    even -= 2
    
    