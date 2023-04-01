#!/bin/bash

output=$(python3 generate_emails.py)

echo "$output" > email_messages.txt