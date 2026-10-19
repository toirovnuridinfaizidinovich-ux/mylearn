g##### 2\. Создание и скачивание репозитория:

##### bash

##### git init

##### git clone https://github.com/user/repo.git



##### Команда	Что делает:

##### git init	Превращает текущую папку в Git-репозиторий

##### git clone URL	Копирует удалённый репозиторий вместе со всей историей

##### git remote -v	Показывает подключённые удалённые репозитории

##### git remote add origin URL	Подключает GitHub-репозиторий под именем origin

##### git remote remove origin	Отключает remote origin





##### 3\. Проверка состояния

##### Это команды, которые нужно вводить постоянно, особенно перед add и commit.

##### 

##### bash

##### git status

##### git log

##### git log --oneline

##### git diff

##### git diff --staged

##### git show



##### Команда	Что показывает:

##### git status	Изменённые, новые и подготовленные файлы

##### git log	Полную историю коммитов

##### git log --oneline	Короткую историю: хеш + сообщение

##### git diff	Неподготовленные изменения

##### git diff --staged	Изменения, уже добавленные через git add

##### git show	Детали последнего коммита

##### git show <hash>	Детали конкретного коммита





##### 4\. Обычный цикл: изменить → закоммитить → отправить

##### Это твой основной рабочий цикл.

##### 

##### bash

##### git status

##### git add .

##### git commit -m "Добавил очистку данных"

##### git push



##### Команда	Что делает:

##### git add файл	Добавляет конкретный файл в staging

##### git add .	Добавляет все изменения из текущей папки

##### git add -A	Добавляет все изменения по всему репозиторию

##### git commit -m "..."	Создаёт коммит с сообщением

##### git commit	Открывает редактор для длинного сообщения

##### git commit -am "..."	Добавляет изменённые уже отслеживаемые файлы и сразу коммитит

##### git push	Отправляет локальные коммиты в remote



##### Важно: git commit -am не добавляет новые файлы. Новые файлы всё равно нужно добавить через git add.



##### 5\. Получение изменений с GitHub

##### bash

##### git fetch

##### git pull

##### git pull origin main



##### Команда	Что делает:

##### git fetch	Скачивает новые коммиты с remote, но не вливает их

##### git pull	Скачивает и сразу вливает изменения: fetch + merge

##### git pull origin main	Скачивает и вливает изменения из origin/main

##### git pull --rebase	Скачивает изменения и ставит твои коммиты поверх них

##### git pull — это фактически git fetch + git merge.





##### 6\. Ветки

##### Ветка нужна, чтобы не ломать main, пока ты экспериментируешь.

##### 

##### bash

##### git branch

##### git branch feature/data-cleaning

##### git switch feature/data-cleaning

##### git switch -c feature/data-cleaning

##### git switch main

##### git merge feature/data-cleaning

##### git branch -d feature/data-cleaning



##### Команда	Что делает:

##### git branch	Показывает локальные ветки

##### git branch -a	Показывает локальные и remote-ветки

##### git branch имя	Создаёт ветку, но не переключается на неё

##### git switch имя	Переключается на существующую ветку

##### git switch -c имя	Создаёт ветку и переключается на неё

##### git merge имя	Вливает указанную ветку в текущую

##### git branch -d имя	Удаляет слитую ветку

##### git branch -D имя	Принудительно удаляет ветку

##### Полный сценарий с веткой

##### bash

##### git switch main

##### git pull

##### 

##### git switch -c feature/model-training

##### 

##### \# правишь файлы

##### git status

##### git add .

##### git commit -m "Добавил обучение модели"

##### 

##### git push -u origin feature/model-training

##### Шаг	Что происходит

##### git switch main	Перешёл на основную ветку

##### git pull	Забрал свежие изменения

##### git switch -c feature/...	Создал отдельную ветку под задачу

##### git add .	Подготовил изменения

##### git commit -m "..."	Сохранил снимок

##### git push -u origin feature/...	Отправил ветку на GitHub и связал её с remote

##### После первого push -u достаточно писать просто git push.



##### 7\. Слияние веток

##### Ты находишься в ветке, в которую хочешь влить изменения.

##### 

##### bash

##### git switch main

##### git merge feature/model-training

##### git push



##### Команда	Что делает:

##### git merge ветка	Вливает ветка в текущую ветку

##### git merge --abort	Отменяет текущий конфликтный merge

##### git merge --continue	Продолжает merge после разрешения конфликта

##### merge сохраняет историю обеих веток и при необходимости создаёт merge-коммит.



##### 8\. Конфликты

##### Конфликт — это не ошибка Git, а ситуация, когда две ветки изменили одно и то же место.

##### 

##### bash

##### git pull

##### \# CONFLICT в file.py

##### Открой файл. Там будет:

##### 

##### text

##### <<<<<<< HEAD

##### твоё изменение

##### =======

##### чужое изменение

##### >>>>>>> feature/branch

##### Ты вручную выбираешь итоговый код, удаляешь служебные строки, затем:

##### 

##### bash

##### git add file.py

##### git commit

##### git push

##### Команда	Что делает

##### git status	Показывает файлы с конфликтом

##### git add файл	Помечает конфликт как разрешённый

##### git merge --abort	Полностью отменяет merge

##### git commit	Завершает merge после разрешения конфликта







##### 9\. Временное сохранение: stash

##### Нужно, когда ты правишь код, но срочно надо переключиться на другую ветку, а коммитить сырую работу не хочется.

##### 

##### bash

##### git stash

##### git stash list

##### git stash pop

##### git stash apply

##### git stash drop



##### Команда	Что делает:

##### git stash	Временно прячет незакоммиченные изменения

##### git stash push -m "текст"	Прячет изменения с описанием

##### git stash list	Показывает сохранённые stash

##### git stash pop	Возвращает последний stash и удаляет его из списка

##### git stash apply	Возвращает stash, но оставляет его в списке

##### git stash drop	Удаляет последний stash



##### Сценарий:

##### bash

##### \# ты правишь model.py, но надо срочно починить баг в main

##### git stash

##### git switch main

##### \# чинишь баг, коммитишь

##### git switch feature/model-training

##### git stash pop

##### stash временно убирает staged и unstaged изменения.







##### 

##### 10\. Отмена изменений в файлах

##### bash

##### git restore file.py

##### git restore --staged file.py

##### git checkout -- file.py



##### Команда	Что делает:

##### git restore file.py	Отменяет незакоммиченные изменения в файле

##### git restore .	Отменяет незакоммиченные изменения во всех файлах

##### git restore --staged file.py	Убирает файл из staging, но оставляет изменения в файле

##### git checkout -- file.py	Старый способ отменить изменения в файле



##### Осторожно: git restore file.py удаляет твои несохранённые правки в этом файле.







##### 11\. Отмена коммитов

##### Здесь важно различать: отменить коммит и удалить его из истории — разные вещи.

##### 

##### bash

##### git revert <hash>

##### git reset --soft HEAD\~1

##### git reset --mixed HEAD\~1

##### git reset --hard HEAD\~1

##### 

##### Команда	Что делает	Когда использовать

##### git revert <hash>	Создаёт новый коммит, который отменяет старый	Коммит уже отправлен на GitHub

##### git reset --soft HEAD\~1	Удаляет последний коммит, изменения остаются в staging	Хочешь переделать коммит

##### git reset --mixed HEAD\~1	Удаляет последний коммит, изменения остаются в рабочей папке	Хочешь переразбить изменения

##### git reset --hard HEAD\~1	Удаляет последний коммит и изменения	Только если изменения точно не нужны

##### HEAD — текущая позиция в истории. HEAD\~1 — коммит перед текущим.

##### 

##### Безопасный откат уже запушенного коммита

##### bash

##### git log --oneline

##### git revert abc1234

##### git push



##### git revert не переписывает историю: он добавляет новый «анти-коммит». Поэтому это безопаснее для общих веток.







##### 12\. Переписывание истории: rebase

##### rebase переносит твои коммиты на новую базу. Он делает историю более линейной, но переписывает коммиты.

##### 

##### bash

##### git switch feature/model-training

##### git fetch origin

##### git rebase origin/main

##### 

##### Команда	Что делает:

##### git rebase main	Ставит коммиты текущей ветки поверх main

##### git rebase origin/main	То же, но относительно свежего origin/main

##### git rebase -i HEAD\~3	Интерактивно редактирует последние 3 коммита

##### git rebase --abort	Отменяет rebase

##### git rebase --continue	Продолжает после разрешения конфликта

##### Правило: не делай rebase ветки, которую уже отправил и над которой работают другие люди, пока не понимаешь последствий. Для личной feature-ветки — нормально.

##### 

##### Типичный современный сценарий

##### bash

##### git switch feature/model-training

##### git fetch origin

##### git rebase origin/main

##### git push --force-with-lease



##### \--force-with-lease безопаснее, чем --force: он не перезапишет remote, если там появились чужие новые коммиты.







##### 13\. Cherry-pick

##### Нужно, когда из другой ветки нужен один конкретный коммит, а не вся ветка.

##### 

##### bash

##### git log --oneline

##### git cherry-pick abc1234



##### Команда	Что делает:

##### git cherry-pick <hash>	Копирует один коммит в текущую ветку

##### git cherry-pick --abort	Отменяет текущий cherry-pick

##### git cherry-pick --continue	Продолжает после конфликта

##### Например, на main нашли критический фикс, а тебе нужен только он в своей ветке:

##### 

##### bash

##### git switch feature/model-training

##### git cherry-pick abc1234



##### cherry-pick применяет изменения конкретного существующего коммита к текущей ветке.







##### 14\. Работа с remote-ветками

##### bash

##### git fetch origin

##### git branch -r

##### git branch -a

##### git push origin main

##### git push -u origin feature/model-training

##### git push --delete origin feature/model-training



##### Команда	Что делает:

##### git fetch origin	Скачивает свежие данные с GitHub

##### git branch -r	Показывает remote-ветки

##### git branch -a	Показывает все ветки: локальные и remote

##### git push origin main	Отправляет main в origin

##### git push -u origin ветка	Публикует новую ветку и связывает её с remote

##### git push --delete origin ветка	Удаляет ветку на GitHub







##### 15\. Теги: версии проекта

##### Теги удобны для версий: v1.0, v1.1, model-v2.

##### 

##### bash

##### git tag

##### git tag v1.0

##### git tag -a v1.0 -m "Первая рабочая версия модели"

##### git push origin v1.0

##### git push --tags

##### git tag -d v1.0



##### Команда	Что делает:

##### git tag	Показывает теги

##### git tag v1.0	Создаёт лёгкий тег на текущем коммите

##### git tag -a v1.0 -m "..."	Создаёт аннотированный тег с описанием

##### git push origin v1.0	Отправляет тег на GitHub

##### git push --tags	Отправляет все локальные теги

##### git tag -d v1.0	Удаляет локальный тег







##### 16\. Просмотр истории и поиска

##### bash

##### git log --oneline --graph --all

##### git log --author="Имя"

##### git log -- file.py

##### git blame file.py

##### git show abc1234



##### Команда	Что делает:

##### git log --oneline --graph --all	Компактная визуальная история всех веток

##### git log --author="Имя"	Коммиты конкретного автора

##### git log -- file.py	История изменений конкретного файла

##### git blame file.py	Кто и в каком коммите менял каждую строку

##### git show <hash>	Что именно изменилось в коммите







##### 17\. .gitignore

##### Файл .gitignore говорит Git, какие файлы не добавлять в репозиторий.

##### 

##### Пример для ML-проекта:

##### 

##### text

##### .venv/

##### \_\_pycache\_\_/

##### \*.pyc

##### .ipynb\_checkpoints/

##### data/raw/

##### data/processed/

##### models/\*.pkl

##### .env

##### 

##### Что игнорируем	Зачем:

##### .venv/	Виртуальное окружение не должно быть в Git

##### \_\_pycache\_\_/, \*.pyc	Временные файлы Python

##### .ipynb\_checkpoints/	Технические файлы Jupyter

##### data/raw/, data/processed/	Большие данные обычно не хранят в Git

##### models/\*.pkl	Обученные модели часто слишком большие

##### .env	Секреты, токены, пароли

##### Если файл уже попал в Git, .gitignore сам по себе его не удалит:

##### 

##### bash

##### git rm --cached file.py

##### git commit -m "Убрал файл из репозитория"

##### git rm --cached файл — убирает файл из Git, но оставляет его на диске.













#### 18\. Типовые последовательности

#### Новый проект с нуля

#### bash

#### mkdir ml\_project

#### cd ml\_project

#### git init

#### git add .

#### git commit -m "Первый коммит"

#### git branch -M main

#### git remote add origin https://github.com/user/ml\_project.git

#### git push -u origin main





#### Шаг	Смысл

#### git init	Создаёт локальный репозиторий

#### git add .	Готовит файлы

#### git commit	Создаёт первый снимок

#### git branch -M main	Переименовывает текущую ветку в main

#### git remote add origin URL	Привязывает GitHub

#### git push -u origin main	Публикует проект и связывает ветки





#### Обычная работа над задачей:

#### bash

#### git switch main

#### git pull

#### git switch -c feature/preprocessing

#### \# работаешь

#### git status

#### git add .

#### git commit -m "Добавил preprocessing"

#### git push -u origin feature/preprocessing





#### Обновить свою ветку свежим main

#### bash

#### git switch feature/preprocessing

#### git fetch origin

#### git rebase origin/main

#### Или проще, через merge:

#### 

#### bash

#### git switch feature/preprocessing

#### git pull origin main

#### Переделать последний коммит

#### bash

#### git add .

#### git commit --amend -m "Новый текст коммита"

#### git push --force-with-lease





#### Команда	Что делает

#### git commit --amend	Изменяет последний коммит

#### \--force-with-lease	Безопасно перезаписывает remote-ветку после rebase/amend

#### Не делай это с веткой, над которой уже работают другие.

