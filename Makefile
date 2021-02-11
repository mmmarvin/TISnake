all:
	tisdcc ti83p_asm -c ../main.c
	tisdcc ti83p_asm -c ../extra_ti_func.c
	tisdcc ti83p_asm -c ../keyboard.c
	tisdcc ti83p_asm -c ../game.c
	tisdcc ti83p_asm -c ../gamefield.c
	tisdcc ti83p_asm -c ../queue.c
	tisdcc ti83p_asm -c ../snake.c
	tisdcc ti83p_asm main.rel extra_ti_func.rel keyboard.rel game.rel gamefield.rel queue.rel snake.rel
	python binpac8x.py -O Snake main.bin
