"""
Пример синхронного запроса
"""

import httpx    # аналог requests
# import asyncio

# это обычная функция
def main():
    print("Отправка запроса и ожидание ответа")
    URL = "http://api.open-notify.org/iss-now.json"
    res = httpx.get(URL, timeout=30)      # запрос с блокирующим ожиданием

    if res.status_code == 200 :
        print("Ответ:")
        print(res.text)
    else:
        print(f"Ststus code: {res.status_code}")

# вызов обычной функции
main()


"""
https://github.com/public-apis/public-apis
"""
