import random
import string
import datetime
from email.utils import formataddr, make_msgid

def generate_random_email_message():
    username = ''.join(random.choices(string.ascii_lowercase, k=random.randint(5,10)))

    domain = ''.join(random.choices(string.ascii_lowercase, k=random.randint(5,10)))

    email_address = formataddr(("", f"{username}@{domain}.com"))

    message_id = make_msgid(domain)

    message = ''.join(random.choices(string.ascii_lowercase + ' ', k=random.randint(50,100)))

    subject = ''.join(random.choices(string.ascii_lowercase, k=random.randint(5,20)))

    year = random.randint(2020,2023)
    month = random.randint(1,12)
    day = random.randint(1,28)
    date_str = datetime.date(year,month,day).strftime('%a, %d %b %Y %H:%M:%S %z')

    headers = f"From: {email_address}\nTo: {email_address}\nSubject: {subject}\nDate: {date_str}\nMessage-ID: {message_id}"
    email_message = f"{headers}\n\n{message}\n----"

    return email_message

# Just so I could have a sender to search
def generate_email_message():
    username = "user"

    domain = "some"

    email_address = formataddr(("", f"{username}@{domain}.where"))

    message_id = make_msgid(domain)

    message = ''.join(random.choices(string.ascii_lowercase + ' ', k=random.randint(50,100)))

    subject = ''.join(random.choices(string.ascii_lowercase, k=random.randint(5,20)))

    year = random.randint(2020,2023)
    month = random.randint(1,12)
    day = random.randint(1,28)
    date_str = datetime.date(year,month,day).strftime('%a, %d %b %Y %H:%M:%S %z')

    headers = f"From: {email_address}\nTo: {email_address}\nSubject: {subject}\nDate: {date_str}\nMessage-ID: {message_id}"
    email_message = f"{headers}\n\n{message}\n----"

    return email_message

num_emails = 50
print("xxx\nxxx\n----")
for i in range(num_emails):
    h = random.randint(1,4)
    if h==4: # 1/4 times we get the "not so random" email
        print(generate_email_message())
    else:
        print(generate_random_email_message())
print("----")
