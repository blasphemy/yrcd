while true; do 
  echo "NICK test${RANDOM}
  user tester * * :Test user
  join #k
  privmsg #k :testing ${RANDOM}
  QUIT LOL ${RANDOM}
  " | nc 127.0.0.1 6667
done
