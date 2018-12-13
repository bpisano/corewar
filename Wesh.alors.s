.name "aaaa"
.comment "bbb"

ld %0, r2
fork:
st r1, 6
live %0
fork %:fork
