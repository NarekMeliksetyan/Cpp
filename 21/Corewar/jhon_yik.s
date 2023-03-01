.name "jhon_yik"
.comment "I'm coming for you"

sti r1, %:loop, %1
and r1, %0, r1
ld %1111638594, r7
ld %0, r2

loop:
    live %1
    st r7, 111

zjmp %:loop
