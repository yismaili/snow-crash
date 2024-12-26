#!/bin/bash

while true; do
		ln -s /home/user/level10/token /tmp/token_link
    rm -f /tmp/token_link
    touch /tmp/token_link
    rm -f /tmp/token_link
done