while true; do 
  cat stress.txt | telnet 127.0.0.1 6667
done
