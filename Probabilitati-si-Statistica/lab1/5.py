import math

def count_ways(num_people, num_chairs):
    between_chairs = num_people - 1
    rest = num_chairs - between_chairs 
    
    return math.perm(rest, num_people)

people = 5
chairs = 12

print(count_ways(people, chairs))