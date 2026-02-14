**Callback** (обратный вызов) — это функция, передаваемая как аргумент в другую функцию, чтобы быть вызванной позже, когда произойдёт определённое событие или завершится операция.

Частый сценарий применения функции обратного вызова — выполнение некоторых действий сразу после завершения длительной операции, которая выполнялась асинхронно (в отдельном потоке, процессе, через event loop или другим неблокирующим способом).

*Выполни эту тяжелую задачу в другом потоке, а когда закончишь — вызови эту мою функцию.*

Основная функция (например, загрузка файла) не блокирует основной поток, а запускает задачу параллельно. Когда задача завершается, вызывается callback.




# Примеры

Синхронный код (блокирующий) без функции обратного вызова.
```py
def download_file(url):
    """ Download file from url and return it's content. """
    data = requests.get(url)  # ЖДЁМ здесь
    return data


result = download_file("example.com")
print(result)  # Выполнится только после загрузки


for i in range(101):
    sleep(0.05)
    c = '.' if i%10 != 0 else '|'
    print(c, end="", flush=True)
```


# Асинхронный код с callback
```py
def download_file_async(url, on_complete):
    def worker():
        data = requests.get(url)
        on_complete(data)  # Вызываем callback
    
    threading.Thread(target=worker).start()
    # Управление сразу возвращается!

def handle_result(data):
    print(data)

download_file_async("example.com", handle_result)
print("Загрузка началась, можем делать другие вещи")
```


# Альтернативы
## Future \ Promises
```py
from concurrent.futures import ThreadPoolExecutor

# создание пула потоков
executor = ThreadPoolExecutor()

# добавление пулу задачи; Задача представлена функцией download, которую нужно вызывать с аргументом "http://example.com"
future = executor.submit(download, "http://example.com")
# теперь задачей можно управлять через переменную future

# добавление callback, который вызовится после завершения  
future.add_done_callback(lambda f: print(f.result()))
```

Future (будущее, обещание) — это объект-заглушка для результата, который ещё не готов, но появится в будущем. Метафора объекта типа Future -- пейджер для ресторанов фастфуда (см. рис)

<img src="pager.jpg">



* Использование Async/Await
