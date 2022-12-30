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
    if ones_digit == "zero":
        ones_digit = ""
    
    
    out = f"{tens_place_num_names[tens_digit]} {convert_single_digit_num(ones_digit)}"
    return out


def convert_three_digit_num(input_num:int):
    digits = get_list_of_digits_from_num(input_num)  #eg 1,2,3
    
    if len(digits) <= 2:
        return convert_two_digit_num(input_num)

    out_1 = convert_single_digit_num(digits[0]) + " hundred"
    out_2 = convert_two_digit_num((digits[1]*10 + digits[2]))

    if out_2 == "zero": out_2 = ""

    return f"{out_1} {out_2}"


place_names_for_reference_not_used = {  #10^x   #just a draft not called
    2: "hundred",
    3: "thousand", #eg 1000
    4: "thousand", #eg 10,000
    5: "thousand", #eg 100,000
    6: "million", #eg 1,000,000
    9: "billion", #eg 1,000,000,000
    12: "trillion", #eg 1,000,000,000,000
}

#For any place it be like that ykwim""

def convert_any_digit_num(input_num:int):
    digits = get_list_of_digits_from_num(input_num)

    if len(digits) <= 3:
        return convert_three_digit_num(input_num)

    #break it up by three places
    #eg 1,503,920,171   >>  001 billion, 503 million, 920 thousand, 171,
    #1- break it into groups of three   2- convert those groups to the number + the post-fix   3- join it all together
    
    
    def getDigitGroups(digits):
        digit_groups = []
        for i, digit in enumerate(reversed(digits)):
            if i % 3 == 0:
                digit_groups.insert(0, [])
            digit_groups[0].insert(0, digit)
        while len(digit_groups[0]) < 3:
            digit_groups[0].insert(0, 0)
        return digit_groups
    digit_groups = getDigitGroups(digits) #get a 2d list of each digit broken up by where the commas would be

    #this could be extracted into function maybe
    postfix_list = [
        "", " thousand", " million",
        " billion", " trillion", " quadrillion",
        " quintillion", " sextillion", " septillion",
        " octillion", " nonillion", " decillion", 
        " undecillion", " duodecillion", " tredicilion",
        " quattuordecillion"
    ]
    
    
    output = ""

    for count, digit_group in enumerate(reversed(digit_groups)):
        number = digit_group[0]*100 + digit_group[1]*10+digit_group[2]

        postfix = postfix_list[count]
        number_words = convert_three_digit_num(number)
        output = f"{number_words}{postfix}, " + output
    
    output = output[0:-2] #get rid of last space and ,
    
    return output



def convert_cents(input_cents_num:int):
    return f"{input_cents_num}/100"

def main(input_str:str):

    """
    break it into problems
    1: break into left hand side && cents
                                   convert cents: easy see above
    left hand side:
    1. break into groups of three   
    2. convert group of three digits into words
    3. find postfix for each group of three word (eg thousand, million)
    4. join back together

    join back left hand and right hand (easy)
    """
    try:
        dollars = int(input_str)
        cents = 0
    except:
        dollars, cents = [int(num) for num in str(input_str).split(".")]
    
    return f"{convert_any_digit_num(dollars)} and {convert_cents(cents)}"


#for some reason its seems much easier for me to do this in python then to try to write pseudocode like i was doing
#probably could have done a better way who knows, I will find out what the presentation did after I complete this


if __name__ == "__main__":
    print(main((input())))