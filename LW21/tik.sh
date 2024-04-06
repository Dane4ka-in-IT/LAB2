#!/bin/bash

help() {
  echo "Использование: concat_files.sh [ОПЦИИ]"
  echo "  --max_size SIZE    Установить максимальный размер файла (по умолчанию: 4096)"
  echo "  --output_file FILE Установить имя файла для конкатенации (обязательно)"
  echo "  ?                  Показать это сообщение и выйти"
}


max_size=4096
output_file=""


while [ "$#" -gt 0 ]; do
  case "$1" in
    --max_size)
      max_size="$2"
      shift 2
      ;;
    --output_file)
      output_file="$2"
      shift 2
      ;;
    ?)
      help
      exit 0
      ;;
    *)
      echo "Неизвестная опция: $1"
      help
      exit 1
      ;;
  esac
done


if [[ -z $output_file ]]; then
    echo "Не указан обязательный аргумент: --output_file"
    help
    exit 1
fi



total_size=0

files=$(ls -Sr)

if [[ -z $files ]]; then
    echo "Нет файлов для обработки."
    exit 1
fi

for file in $files; do

  if [[ -f $file ]]; then

    file_size=$(stat -c%s "$file")

    if (( total_size + file_size <= max_size )); then

      cat "$file" >> "$output_file"
      echo >> "$output_file"

      total_size=$((total_size + file_size))
    fi

    if (( total_size >= max_size )); then break; fi

  fi
done

echo "Общий размер файла, получившегося в результате: $total_size байт < $max_size байт"
