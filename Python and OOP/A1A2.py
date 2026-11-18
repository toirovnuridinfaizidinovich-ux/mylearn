
    
    
def  is_balanced(s):
    s = list(s)
    if s.count('(') == s.count(')'):
        return 'Yes'
    else:
        return 'No'
    
s= '(())'
print(is_balanced(s))