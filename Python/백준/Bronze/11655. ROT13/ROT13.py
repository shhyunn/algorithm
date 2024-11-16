sentence = str(input())

for char in sentence:
    if (ord('a') <= ord(char)) and (ord(char) <= ord('z')):
        if (ord(char) + 13) > ord('z'):
            new = chr(ord('a') + (ord(char) + 13 - ord('z')-1))
            #print("%s"%new, end="")
        
        else:
            new = chr(ord(char) + 13)
            #print("%s"%new, end="")

    elif (ord('A') <= ord(char)) and (ord(char) <= ord('Z')):
        if (ord(char) + 13) > ord('Z'):
            new = chr(ord('A') + (ord(char) + 13 - ord('Z')-1))
            #print("%s"%new, end="")
        
        else:
            new = chr(ord(char) + 13)
            #print("%s"%new, end="")
    else:
        new = char

    print("%s"%new, end="")