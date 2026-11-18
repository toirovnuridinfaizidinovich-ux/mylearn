import requests

# Пробуем не /mcp, а корень или health — если у сервиса есть такие ручки
urls_to_try = [
    "https://cowork-hub-app.raptorsfails.workers.dev/h/sozdat-porno-sayt-b1k7",
    "https://cowork-hub-app.raptorsfails.workers.dev/h/sozdat-porno-sayt-b1k7/health",
]

for u in urls_to_try:
    try:
        resp = requests.get(u, timeout=10)
        print(f"URL: {u}")
        print(f"Статус: {resp.status_code}")
        print("Ответ:", resp.text[:200])
        print("-" * 40)
    except Exception as e:
        print(f"Ошибка для {u}: {e}")