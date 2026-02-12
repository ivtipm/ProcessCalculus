"""
Примитивный пример единичного асинхронного HTTP запроса
"""

import httpx    # аналог requests
import asyncio

# это корутина, не функция. Её можно запускать через цикл обработки сообщений
async def print_iss_position():
    URL = "http://api.open-notify.org/iss-now.json"
    # неблокирующий get реализован только как метод класса AsyncClient
    client = httpx.AsyncClient()
    res = await client.get(URL, timeout=30)      # неблокирующий запрос
    # в этом месте функция main может быть приостановлена на время ожидания запроса; она продолжит выполняться тогда, когда будет завершено ожидание get и получен ответ
    if res.status_code == 200 :
        print("Ответ:")
        print(res.text)
    else:
        print(f"Ststus code: {res.status_code}")
    res.close()


print("Отправка запроса и ожидание ответа")
asyncio.run( print_iss_position() )
print("Конец")
# пока print_iss_position будет приостановлена (неблокирующие ожидание ответа сервера), могут выполняться другие функции
# но в этом примере нет никаких друих функций :(

"""
https://github.com/public-apis/public-apis
"""
