1) Checkout the code from https://github.com/sourabh0612/monkey_redis
2) Download/Install redis server from redis.io
3) Start redis server on the default 6379 port
4) Set conf variables in monkey
5) Start monkey with redisWS service loaded
6) To get the version of the redis server URL is http://localhost/redisWS/hiredis/version
7) To set any key use http://localhost/redisWS/hiredis/write_key/<key>/<value>
8) To get any key use http://localhost/redisWS/hiredis/read_key/<key>
