**Callback** (обратный вызов) — это функция, передаваемая как аргумент в другую функцию, чтобы быть вызванной позже, когда произойдёт определённое событие или завершится операция.

Частый сценарий применения функции обратного вызова — выполнение некоторых действий сразу после завершения длительной операции, которая выполнялась асинхронно (в отдельном потоке, процессе, через event loop или другим неблокирующим способом) 


# Примеры

Синхронный код (блокирующий) без функции обратного вызова.
```py
def download_file(url):
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
