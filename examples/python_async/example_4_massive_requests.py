import httpx
import asyncio

async def get_data(client: httpx.AsyncClient, url: str):
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
        tasks = [get_data(client, url) for url in urls]

        results = await asyncio.gather(*tasks)
        # *tasks -- распоковка списка
        # results - список из Feature, которые будут содержать результаты вызовов корутины get_data


    print(results)

asyncio.run(main())
