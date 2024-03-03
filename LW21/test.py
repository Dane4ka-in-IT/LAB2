import os

# Получаем список файлов в текущей директории
files = [f for f in os.listdir() if os.path.isfile(f)]

# Сортируем файлы по размеру
files.sort(key=os.path.getsize)

# Максимальный размер итогового файла (размер блока)
max_size = 4096

# Общий размер всех файлов
total_size = 0

print(files)
# Открываем итоговый файл
with open('output.txt', 'w') as outfile:
    for filename in files:
    # Цикл по всем файлам
        file_size = os.path.getsize(filename)
        if total_size + file_size <= max_size:
            # Получаем размер файла
            
            with open(filename, 'r', encoding='cp1251') as infile:
                outfile.write(infile.read() + "\n")
            # Увеличиваем общий размер
            total_size += file_size
        else:
            
            break
print(f"Общий размер: {total_size} байт")
