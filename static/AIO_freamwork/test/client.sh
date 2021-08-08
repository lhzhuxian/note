#! /usr/local/bin/bash
request=1
while(($request < 100))
do
    curl -K req3.txt &
    let request++
done
wait
