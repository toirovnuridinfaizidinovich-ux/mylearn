class Timer:
    def __init__(self, name) -> None:
        self.name = name
        self.start_timer = 0
        self.min = min
         
    
    def work(self, min):
        self.start_timer += min
        return self.start_timer
        
    def reset(self):
        self.start_timer = 0
        return self.start_timer
        
    @property    
    def hours(self):
        quatity_hours = round(self.start_timer/60, 1)
        return quatity_hours
    def __str__(self):
        return f"{self.name} — {self.start_timer} мин ({self.hours} ч)"
t = Timer('Подрочить')
t.work(60)
t.work(90)
print(t)          # Правка макета — 150 мин (2.5 ч)
print(t.hours)    # 2.5
t.reset()
print(t)