#include <bits/stdc++.h>
using namespace std;

/**
 * Step1.
 * Understand the problem statement 
 * So we need to make a chess game 
 * 
 * Step2. Understand the requirements
 * - we have two players can be user and ai 
 * - we have a single instance of the chess board  
 * - we have different pieces with different behaviour 
 * - we will have a Game State which will be responsible for the state of the game 
 * 
 * 
 * Step3: Assumptions
 * - 2 player 
 * - 1 single instance of the chess board
 * - different pieces with different behaviour
 * - 
 * 
 * 
 * 
 * 
 */



/**
 * 1. Intro and problem statement.
 * Let me outline the game as per my understanding 
 * - we have a 8x8 grid;
 * Each playher will have 18 pieces 
 * - we will have 3 players 
 * 
 * 2; Clarify the requirements and constraints
 * - Are we implementing the full chess game or just a part of it?
 * - Do we need to implement the AI for the computer player?
 * - What are the Core Requirements 
 * So they want 
 * - a chess game with 2 players
 * - Alternarting turns 
 * - move validation
 * - detection of check and checkmate
 * 
 * 3. Identify the main components and their interactions
 * - Piece: Base class for all chess pieces (King, Queen, Rook, Bishop, Knight, Pawn)
 * - Board: Represents the chess board and manages the pieces on it
 * - Player: Represents a player in the game (could be human or AI)
 
 */

class Player ;
class Board ;
class Piece ;

/**
 * 
 * 4. DEsign Challenges and Trade-offs
 * - Implementing move validation for all pieces can be complex, especially for special moves like cast
 * - Implementing AI can be challenging, especially if we want it to be competitive
 * - We need to balance between a simple design and a more complex one that can handle all
 * 
 * 
 * 
 * 5. Approach
 * 
 * - Strattey Pattern for Piece Movements: MovementStrategy interface with concrete implementations for each piece type (e.g., KingMovement, QueenMovement)
 * - Singleton pattern for the Board to ensure only one instance exists
 * - Factory pattern for creating different types of pieces
 * - Use Enum for Game State (e.g., ONGOING, CHECK, CHECKMATE, STALEMATE)
 * - Observer pattern for notifying players of game state changes (e.g., check, checkmate)
 * 
 * 
 * 
 */


class MovementStrategy {
public:
    virtual bool isValidMove(Board* board, Piece* piece, int startX, int startY, int endX, int endY) = 0;
    virtual ~MovementStrategy() {}
};

// Abstract class for Piece
class Piece  {
public:
    bool  isWhite; // true for white pieces, false for black pieces
    bool killed; // true if the piece is captured

    MovementStrategy* movementStrategy;
    Piece(bool isWhite, MovementStrategy* strategy) : isWhite(isWhite), killed(false), movementStrategy(strategy) {}
    bool canMove(Board* board, int startX, int startY, int endX, int endY) {
        return movementStrategy->isValidMove(board, this, startX, startY, endX, endY);
    }
    virtual ~Piece() {
        delete movementStrategy;
    }
};

class KingMovement : public MovementStrategy {
public:
    bool isValidMove(Board* board, Piece* piece, int startX, int startY, int endX, int endY) override {
        // Implement the logic to validate the King's move (one square in any direction)
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx <= 1 && dy <= 1);
    }
};

class BishopMovement : public MovementStrategy {
public:
    bool isValidMove(Board* board, Piece* piece, int startX, int startY, int endX, int endY) override {
        // Implement the logic to validate the Bishop's move (diagonal movement)
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == dy);
    }
};


class King : public Piece {
private:
    MovementStrategy* movementStrategy;
public:
    King(bool isWhite) :
        Piece(isWhite, new KingMovement()) {}
};

class Bishop : public Piece {
public:
    Bishop(bool isWhite) : Piece(isWhite, new BishopMovement()) {}
};

class PeiceFactory {
    public:
    static Piece* createPiece(string type, bool isWhite) {
        if (type == "King") {
            return new King(isWhite);
        } else if (type == "Bishop") {
            return new Bishop(isWhite);
        } 
    }
};


// now we have a single instance of the board using the singleton pattern

class Cell{
    public:
    int x, y;
    Piece* piece;
    Cell(int x, int y, Piece* piece) : x(x), y(y), piece(piece) {}
};
class Board {
private:
    static Board* instance;
    Cell* grid[8][8];
    Board() {
        // Initialize the board with pieces in their starting positions
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                grid[i][j] = new Cell(i, j, nullptr);
            }
        }
        // Place pieces on the board (simplified for demonstration)
        grid[0][4]->piece = PeiceFactory::createPiece("King", true); // White King
        grid[7][4]->piece = PeiceFactory::createPiece("King", false); // Black King
    }
public:
    static Board* getInstance() {
        if (instance == nullptr) {
            instance = new Board();
        }
        return instance;
    }
};

class Move {
    Cell startCell;
    Cell endCell;
    public:
    Move(Cell start, Cell end) : startCell(start), endCell(end) {}
    bool isValid() {
        // Implement move validation logic based on the piece type and game rules
        return true; // Placeholder for valid move
    }


};
int main() {
    Board* board = Board::getInstance();
    // Game loop and other logic would go here  
    return 0 ;

}
