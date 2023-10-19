import random
import os 
import time 


def bozo_sort(unordered_list):
    starting_time = time.time()
    ordered_list = sorted(unordered_list)
    counter = 0

    while unordered_list != ordered_list:
        i = random.randint(0, len(unordered_list)-1)
        j = random.randint(0, len(unordered_list)-1)
    
        unordered_list[i], unordered_list[j] = unordered_list[j], unordered_list[i]
        counter += 1
        print(unordered_list)    
        
    ending_time = time.time()
    total_time = round(ending_time - starting_time, 5)
    print(f"Amount of interations: {counter}")
    print(f"Amount of time: {total_time} seconds")


if __name__ == "__main__":
    os.system("clear")
    unordered_list = [2,3,4,1,6,5,11,12,20]
    bozo_sort(unordered_list)