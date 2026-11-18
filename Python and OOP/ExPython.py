import json#

# Работа со словарями базовый минимум 

person = {'name':'Nuridin', 'age': 21, 'city': 'Kazan'}
person['salary'] = 69
person['age'] = 121
if person.get('email', 0) == 0:
    
    print(person)
    
for key, value in person.items():
    print(key, '-', value)
    
word = 'banana'

countdict = {}
for ch in word:
    countdict[ch] = countdict.get(ch, 0) + 1
print(countdict)

 

#----------------------------------------------------------------------

#Работа с ошибками


#try — код, который может упасть;
#except — что делать, если ошибка случилась;
#если ошибки нет — except не выполняется.

#ZeroDivisionError - Деление на ноль
#ValueError - Неправильное значение, например int("abc")
#TypeError - Неправильный тип, например "a" + 1
#KeyError - Нет такого ключа в словаре
#IndexError - Нет такого индекса в списке
#FileNotFoundError - Файл не найден

mydict = {1:1, 2:2}

try:
    x = 10/0
except ZeroDivisionError:
    print("Деление на 0 запрещено")
    
try:
    x = int('abc')
except ValueError:
    print("Неправильный тип данных")
    
try:
    print(mydict[3])
except KeyError:
    print("You fucking Nigga")
else:
    print("You good Nigga")
finally:
    print("You just Nigga")
    
def func(age):
    if age < 0:
        raise ValueError("You white bitch! Can you read the condition?") 
    return age

age = -69

try:        
    print(func(age))
except ValueError as e:
    print("Неправильное значение жи есть", e)
    
    
    

# ------------------------------------------------------------------------------

#Работа с файлами (базовый минимум)


# "r" - читать
# "w" - писать стирая старое содержимое
# "a" - дописывать в конец
# "x" - создать новый файл, ошибка если уже есть
# "rb" / "wb" - бинарный режим


with open(r'C:\Users\Нуридин\Desktop\Learning\Python and OOP\Курс ООП. Лекция 2.ipynb', "r") as f:
    data = f.read()
    
print(data)


with open(r'C:\Users\Нуридин\Desktop\Learning\Python and OOP\Курс ООП. Лекция 3.ipynb', "r", encoding="utf-8") as a:
    for line in a:
        print(line.strip())
print('\n'*10)   


filename = "greeting.txt"
try:        
    with open(filename, "w", encoding="utf-8") as f:
        f.write('Привет, мир! Это мой первый файл на Python.\n')
except FileNotFoundError:
    print("Файл не найден даун")

with open(filename, 'a', encoding="utf-8") as file:
    for i in range(11):
        file.write(f"строка {i}\n")   
    
with open(filename, 'r', encoding="utf-8") as file:
    num = 0    
    for i in file:
        if num % 2 == 0:
            print(i)
        num += 1


with open("user.json", "w", encoding="utf-8") as f:
    json.dump(data, f, ensure_ascii=False, indent=4)

with open("user.json", "r", encoding="utf-8") as f:
    loaded = json.load(f)
    
    
