


number = int(input("Enter a number: "))
original_number = number
binary_representation = ""
total_one=0

while number > 0:
    remainder = number % 2
    number=number // 2
    if remainder == 1:
        total_one +=1
        
print(total_one)
