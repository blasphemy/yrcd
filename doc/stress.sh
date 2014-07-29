while true; do 
  echo "NICK test1234
  user tester * * :Test user
  join #k
  privmsg #k :testing
  quit
  " | nc 127.0.0.1 6667
done
