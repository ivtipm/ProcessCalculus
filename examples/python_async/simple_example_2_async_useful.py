"""
Пример параллельной в одном потоке работы двух функции
Обе функции являются корутинами и могут приостанавливаться (в местах с await) чтобы дать другим функциям возможность выполняться
"""

import httpx    # аналог requests
import asyncio

# это корутина, не функция. Её можно запускать через цикл обработки сообщений
async def print_iss_position():
    URL = "http://api.open-notify.org/iss-now.json"
    # неблокирующий get реализован только как метод класса AsyncClient
    with httpx.AsyncClient() as client:
    res = await client.get(URL, timeout=30)      # неблокирующий запрос
    # в этом месте функция main может быть приостановлена на время ожидания запроса; она продолжит выполняться тогда, когда будет завершено ожидание get и получен ответ
    await client.aclose()   # закрытие соединения и освобождение ресурсов; тоже может быть сранительно долгим
    if res.status_code == 200 :
        print("Ответ:")
        print(res.text)
    else:
        print(f"Ststus code: {res.status_code}")


async def print_dots():
    for i in range(101):
        c = '.' if i%10 != 0 else '|'
        print(c, end="", flush=True)
        await asyncio.sleep(0.1)


async def main():
    print("Отправка запроса и ожидание ответа")
    # create_task добавляет корутину в очередь на выполенение
    task1 = asyncio.create_task( print_iss_position() )
    task2 = asyncio.create_task( print_dots() )

    # если забыть await в конце то мы не дождёмся завершения работы функций,
    # функция main завершится раньше, за не  завершится цикл обработки событий (внутри await.run), а затем и программа
    # две вызванные здесь корутины не успеют выполнить свою работу
    await task1
    await task2
    print("Конец")


# запуск цикла обработки событий
asyncio.run( main() )

# пока print_iss_position будет приостановлена (неблокирующие ожидание ответа сервера), могут выполняться другие функции
# но в этом примере нет никаких друих функций :(

"""
https://github.com/public-apis/public-apis
"""
