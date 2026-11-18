import os
import json
import requests

MCP_URL = "https://cowork-hub-app.raptorsfails.workers.dev/h/sozdat-porno-sayt-b1k7/mcp"
TOKEN = os.getenv("COWORK_TOKEN", "a7ac58d1e61e67d21ab833d6782b1deea5b0b35edd602e07")

HEADERS = {
    "Authorization": f"Bearer {TOKEN}",
    "Content-Type": "application/json",
    "Accept": "application/json, text/event-stream",
}

def parse(resp):
    """Сервер может ответить JSON или SSE — вытаскиваем данные из любого."""
    text = resp.text.strip()
    for line in text.splitlines():
        if line.startswith("data:"):
            return json.loads(line[5:].strip())
    return resp.json()

def post(c, payload):
    r = c.post(MCP_URL, json=payload, headers=HEADERS)
    r.raise_for_status()
    return r

with requests.Session() as c:
    # 1. Рукопожатие
    r = post(c, {
        "jsonrpc": "2.0", "id": 1, "method": "initialize",
        "params": {
            "protocolVersion": "2025-03-26",
            "capabilities": {},
            "clientInfo": {"name": "python-agent", "version": "1.0"},
        },
    })
    data = parse(r)
    print("Сервер:", data["result"]["serverInfo"])

    # Сессия, если сервер её выдал
    sid = r.headers.get("mcp-session-id")
    if sid:
        HEADERS["mcp-session-id"] = sid

    # 2. Подтверждаем, что инициализировались
    post(c, {"jsonrpc": "2.0", "method": "notifications/initialized"})

    # 3. Список функций
    r = post(c, {"jsonrpc": "2.0", "id": 2, "method": "tools/list"})
    tools = parse(r)["result"]["tools"]
    print("Доступные функции:")
    for t in tools:
        print("-", t["name"])
        
    # 4. Вызываем функцию create_task
    r = post(c, {
        "jsonrpc": "2.0", "id": 3,
        "method": "tools/call",
        "params": {
            "name": "list_tasks",
            "arguments": {},
        },
    })
    result = parse(r)
    print("Ответ сервера:", json.dumps(result, ensure_ascii=False, indent=2)[:1500])

  # 4. Вызываем функцию create_task
    r = post(c, {
        "jsonrpc": "2.0", "id": 3,
        "method": "tools/call",
        "params": {
            "name": "create_task",
            "arguments": {"title": "Тест из Python-скрипта"},
        },
    })
    result = parse(r)
    print("Ответ сервера:", json.dumps(result, ensure_ascii=False, indent=2)[:1500])