def get_list_of_digits_from_num(input_num): #todo: more efficient way
    num_str = str(input_num)
    digits_list = [int(char) for char in num_str]
    return digits_list



def convert_single_digit_num(input_num):
    sigle_digit_num_names = {0: "zero", 1: "one", 2:"two", 3: "three", 4: "four",
                            5: "five", 6: "six", 7:"seven", 8: "eight", 9: "nine"}
    return sigle_digit_num_names[input_num]

def convert_teen_or_under_num(input_num):
    teen_num_names = {
        0:"zero", 1:"one", 2:"two", 3:"three", 4:"four",
        5:"five", 6:"six", 7:"seven", 8:"eight", 9:"nine",
        10:"ten", 11:"eleven", 12:"twelve", 13:"thirteen", 
        14:"fourteen", 15:"fifteen", 16:"sixteen", 17:"seventeen",
        18:"eighteen", 19:"nineteen"
    }
    return teen_num_names[input_num]

def convert_two_digit_num(input_num):  #20 21 22 23
    if input_num < 20:
        return convert_teen_or_under_num(input_num)
    
    tens_place_num_names = {
        2:"twenty", 3: "thirty", 4: "fourty", 5: "fifty", 
        6: "sixty", 7:"seventy", 8: "eighty", 9: "ninety"
    }


    tens_digit, ones_digit =  get_list_of_digits_from_num(input_num)
    
    
    out = f"{tens_place_num_names[tens_digit]} {convert_single_digit_num(ones_digit)}"
    return out



def convert_cents(input_cents_num):
    return f"{input_cents_num}/100"

def main(input_num):

    dollars = input_num
    cents = 0
    return f"{convert_two_digit_num(dollars)} and {convert_cents(cents)}"


#for some reason its seems much easier for me to do this in python then to try to write pseudocode like i was doing



if __name__ == "__main__":
    print(main(int(input())))