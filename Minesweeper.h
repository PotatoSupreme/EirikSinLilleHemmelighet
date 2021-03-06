struct Tile{
    bool open;
    bool mine;
    Tile (): open(false) , mine(false){}
};

class Minesweeper {
private:
    // Legg til de medlemsvariablene og hjelpefunksjonene du trenger
    int width;
    int height;
    int mines;
    int totalNumTiles;
    int numOpenTiles;

    bool gameIsOver;

    Tile** gameBoard;

public:
    //Constructor
    Minesweeper(int width, int height, int mines);
    //Destructor
    ~Minesweeper();


    bool isGameOver() const;
    bool isTileOpen(int row, int col) const;
    bool isTileMine(int row, int col) const;

    void openTile(int row, int col);

    int numAdjacentMines(int row, int col) const;


    // Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
    Minesweeper(const Minesweeper &) = delete;
    Minesweeper &operator=(const Minesweeper &) = delete;
};


