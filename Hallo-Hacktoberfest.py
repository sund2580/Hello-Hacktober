from datetime import datetime

def calculate_days_until(original_date, now):
  d1 = datetime(now.year, original_date.month, original_date.day)
  d2 = datetime(now.year+1, original_date.month, original_date.day)
  days = (max(d1, d2) - now).days

  return days
  
next_hacktoberfest = datetime(2019,10,1)
today = datetime.now()
days = calculate_days_until(next_hacktoberfest, today)

print('Hello Hacktoberfest! See you again in ' + str(days) + ' days.')
