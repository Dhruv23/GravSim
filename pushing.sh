#!/bin/bash

read -p "Enter commit message: " commit_msg

git add . && git commit -m "$commit_msg" && git push
