import random

# Define the board with snakes and ladders
board = {
    3: 17,
    7: 11,
    15: 34,
    22: 38,
    27: 33,
    35: 39,
    42: 63,
    50: 69,
    54: 20,
    62: 43,
    66: 86,
    70: 90,
    74: 14,
    79: 100
}

# Function to roll the dice
def roll_dice():
    return random.randint(1, 6)

# Function to handle player movement
def move_player(player, steps):
    player += steps
    if player in board:
        player = board[player]
    return player

# Main game loop
def play_game():
    players = ['Player 1', 'Player 2']
    positions = {player: 0 for player in players}
    winner = None

    while not winner:
        for player in players:
            input(f"{player}, Press Enter to roll the dice...")
            steps = roll_dice()
            print(f"{player} rolled a {steps}.")
            positions[player] = move_player(positions[player], steps)
            print(f"{player} is now at position {positions[player]}.")

            if positions[player] >= 100:
                winner = player
                break

    print(f"Congratulations! {winner} wins!")

# Start the game
if __name__ == "__main__":
    play_game()


'''Player 1, Press Enter to roll the dice...
Player 1 rolled a 5.
Player 1 is now at position 5.
Player 2, Press Enter to roll the dice...
Player 2 rolled a 2.
Player 2 is now at position 2.
.
.
.
Player 1 is now at position 52.
Player 2, Press Enter to roll the dice...
Player 2 rolled a 3.
Player 2 is now at position 100.
Congratulations! Player 2 wins!



Explanation - 
Creating a Snake and Ladders game in Python can be a fun and educational mini-project. Here's a basic outline of how you can implement it:

1. **Setup the Board**: 
   - Create a board representation. You can use a list or a dictionary to represent the positions of snakes, ladders, and players.

2. **Define the Rules**:
   - Define the rules of the game. Players take turns rolling a dice and move accordingly. If a player lands on a square with the bottom of a ladder, they climb to the top. If they land on a square with the head of a snake, they slide down to the tail.

3. **Implement Player Movement**:
   - Write functions to handle player movement based on dice rolls. Ensure that players cannot move beyond the last square.

4. **Handle Snakes and Ladders**:
   - Implement logic to handle the effect of landing on a square with a snake or ladder.

5. **Game Loop**:
   - Create a loop to continue the game until a player reaches the last square.

6. **Winning Condition**:
   - Check for the winning condition (reaching the last square) and declare the winner.
This code provides a basic implementation of the Snake and Ladders game in Python. You can expand upon this by adding features like multiple players, customizable board sizes, graphical interface using libraries like Pygame, and more elaborate game mechanics.
'''