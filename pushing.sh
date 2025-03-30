#!/bin/bash

read -p "Enter commit message: " msg
git add .
git commit -m "$msg"
git pull origin main --rebase
git push origin main