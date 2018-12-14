.name "Commander"
.comment "Space commander coming from a galaxy far far away..."

init:
	st		r1, 8
	ld      %0, r1
	sti		r1, %:wall, %1
	sti		r1, %:farmer, %1

	fork	%:farmer
	live	%1
	fork	%:farmer_live
	live	%1
	fork	%:init

init_wall:
	ld		%0, r2

wall:
	live	%1

	st		r2, -64
	st		r2, -73
	st		r2, -82
	st		r2, -91
	st		r2, -100
	st		r2, -109
	st		r2, -118
	st		r2, -127
	st		r2, -136
	st		r2, -145
	st		r2, -154
	st		r2, -163
	st		r2, -172
	st		r2, -181
	st		r2, -190
	st		r2, -199
	st		r2, -208
	st		r2, -217
	st		r2, -226
	st		r2, -235
	st		r2, -244
	st		r2, -253
	st		r2, -262
	st		r2, -271
	st		r2, -280
	st		r2, -289
	st		r2, -298
	st		r2, -207
	st		r2, -216
	st		r2, -225
	st		r2, -234
	st		r2, -243
	st		r2, -252
	st		r2, -261
	st		r2, -270
	st		r2, -279
	st		r2, -288
	st		r2, -297
	st		r2, -306
	st		r2, -315
	st		r2, -324
	st		r2, -333
	st		r2, -342
	st		r2, -351
	st		r2, -360
	st		r2, -369
	st		r2, -378
	st		r2, -387
	st		r2, -396
	st		r2, -405
	st		r2, -414
	st		r2, -423
	st		r2, -432
	st		r2, -441
	st		r2, -450
	st		r2, -459
	st		r2, -468
	st		r2, -477
	st		r2, -486
	st		r2, -495
	st		r2, -504

	zjmp	%:wall

farmer:	
	live	%1

	st		r1, 6
	live	%1
	st		r1, 6
	live	%1
	st		r1, 6
	live	%1
	st		r1, 6
	live	%1

	ld		%0, r2
	zjmp	%:farmer

farmer_live:
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1
	live	%1

	ld		%0, r2
	zjmp	%:farmer_live