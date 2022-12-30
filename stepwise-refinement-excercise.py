def get_list_of_digits_from_num(input_num, min_digits=0): #todo: more efficient way
    num_str = str(input_num)
    digits_list = [int(char) for char in num_str]

    while len(digits_list) < min_digits:
        digits_list.insert(0, 0) #insert a 0 at the start of list

    return digits_list



def convert_single_digit_num(input_num:int):
    sigle_digit_num_names = {0: "zero", 1: "one", 2:"two", 3: "three", 4: "four",
                            5: "five", 6: "six", 7:"seven", 8: "eight", 9: "nine"}
    return sigle_digit_num_names[input_num]

def convert_teen_or_under_num(input_num:int):
    teen_num_names = {
        0:"zero", 1:"one", 2:"two", 3:"three", 4:"four",
        5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine",
        10:"ten", 11:"eleven", 12:"twelve", 13:"thirteen", 
        14:"fourteen", 15:"fifteen", 16:"sixteen", 17:"seventeen",
        18:"eighteen", 19:"nineteen"
    }
    return teen_num_names[input_num]

def convert_two_digit_num(input_num:int):  #20 21 22 23
    if input_num < 20:
        return convert_teen_or_under_num(input_num)
    
    tens_place_num_names = {
        2:"twenty", 3: "thirty", 4: "fourty", 5: "fifty", 
        6: "sixty", 7:"seventy", 8: "eighty", 9: "ninety"
    }


    tens_digit, ones_digit =  get_list_of_digits_from_num(input_num)
    
    
    out = f"{tens_place_num_names[tens_digit]} {convert_single_digit_num(ones_digit)}"
    return out


place_names = {  #10^x   #just a draft not called
    2: "hundred",
    3: "thousand", #eg 1000
    4: "thousand", #eg 10,000
    5: "thousand", #eg 100,000
    6: "million", #eg 1,000,000
    9: "billion", #eg 1,000,000,000
}
def convert_three_digit_num(input_num:int):
    digits = get_list_of_digits_from_num(input_num)  #eg 1,2,3
    
    if len(digits) <= 2:
        return convert_two_digit_num(input_num)

    out_1 = convert_single_digit_num(digits[0]) + " hundred"
    out_2 = convert_two_digit_num((digits[1]*10 + digits[2]))

    return f"{out_1} {out_2}"

def convert_any_digit_num(input_num:int):
    digits = get_list_of_digits_from_num(input_num)


def convert_cents(input_cents_num:int):
    return f"{input_cents_num}/100"

def main(input_num:int):

    dollars = input_num
    cents = 0
    return f"{convert_three_digit_num(dollars)} and {convert_cents(cents)}"


#for some reason its seems much easier for me to do this in python then to try to write pseudocode like i was doing
#probably could have done a better way who knows, I will find out what the presentation did after I complete this


if __name__ == "__main__":
    print(main(int(input())))