import random
name = input("Enter Your name: ")
print(f"Hi {name}! Nice to meet you. Well, I am thinking of a number between 1 and 20, can you guess it?")

secretNumber = random.randint(1,20)

for i in range(1, 7):
	guess = int(input("Take a guess: "))
	if guess > secretNumber:
		print("Too High!")
	elif guess < secretNumber:
		print("Too Low!")
	else:
		print(f"Vallah you guessed in {i} chances!")
		i = 0;
		break;

if i != 0:
	print(f"{name} you did not guess correctly!\nThe number is {secretNumber}.\nThanks for playing though!")
else:
	print(f"WOW! {name} you must be a code breaker!")

