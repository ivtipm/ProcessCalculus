"""
Пример множества асинхронных запросов
"""
import httpx
import asyncio


async def get_data(client: httpx.AsyncClient, url: str):
    # внутрь функции передаётся клиет, чтобы не нужно было создавать его каждый раз для одного запроса
    res = await client.get(url)
    return res.text


async def main():
    urls = [
        "https://example.com",
        "https://httpbin.org/get",
    ]

    # стоит один раз создать клеинт для запросов, а потом использовать его в нескольких вызовах корутин
    async with httpx.AsyncClient(timeout=30) as client:
        # создание задач, которые будут содержать вызовы корутин
        # задачи здесь только создаются, но ещё не начинают выполнятся
        tasks = [get_data(client, url) for url in urls]

        # добавление задач в очередь на обработку.
        # задачи будут запущены последовательно, но т.к. в каждой задаче есть await, то ожидание будет как бы пареллельным: задача будет довыполняться только тогда, когда придёт данные, а до тех пор задаче приостановлена и позволяет выполняться другому коду
        results = await asyncio.gather(*tasks)
        # *tasks -- распаковка списка
        # results - список из Feature, которые будут содержать результаты вызовов корутины get_data

    print(results)


# запуск цикла обработки событий
asyncio.run(main())
