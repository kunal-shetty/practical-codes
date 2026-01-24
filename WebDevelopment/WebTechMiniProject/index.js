let currentPlayer = 'X';
let gameBoard = ['', '', '', '', '', '', '', '', ''];
let gameOver = false;
let isSingleplayer = false;

const boardElements = document.getElementById('gameBoard');
const turnIndicator = document.getElementById('turnIndicator');
const resetButton = document.getElementById('resetButton');
const singleplayerBtn = document.getElementById('singleplayerBtn');
const multiplayerBtn = document.getElementById('multiplayerBtn');

function createBoard() {
  boardElements.innerHTML = '';
  for (let i = 0; i < 9; i++) {
    const cell = document.createElement('div');
    cell.classList.add('cell');
    cell.setAttribute('data-index', i);
    cell.addEventListener('click', handleCellClick);
    boardElements.appendChild(cell);
  }
}

function handleCellClick(event) {
  const index = event.target.getAttribute('data-index');
  
  if (gameBoard[index] !== '' || gameOver) {
    return;
  }
  
  gameBoard[index] = currentPlayer;
  event.target.textContent = currentPlayer;

  if (checkWinner()) {
    turnIndicator.textContent = `${currentPlayer} Wins!`;
    gameOver = true;
  } else if (gameBoard.every(cell => cell !== '')) {
    turnIndicator.textContent = 'It\'s a Draw!';
    gameOver = true;
  } else {
    currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
    turnIndicator.textContent = `Player ${currentPlayer}'s Turn`;
    
    if (isSingleplayer && currentPlayer === 'O') {
      setTimeout(computerMove, 500); 
    }
  }
}

function checkWinner() {
  const winningCombinations = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8], 
    [0, 3, 6], [1, 4, 7], [2, 5, 8], 
    [0, 4, 8], [2, 4, 6]             
  ];

  return winningCombinations.some(combination => {
    const [a, b, c] = combination;
    return gameBoard[a] && gameBoard[a] === gameBoard[b] && gameBoard[a] === gameBoard[c];
  });
}

function computerMove() {
  let availableMoves = gameBoard.map((val, index) => val === '' ? index : -1).filter(index => index !== -1);
  if (availableMoves.length > 0) {
    const randomMove = availableMoves[Math.floor(Math.random() * availableMoves.length)];
    gameBoard[randomMove] = 'O';
    document.querySelector(`[data-index="${randomMove}"]`).textContent = 'O';
    if (checkWinner()) {
      turnIndicator.textContent = 'Computer (O) Wins!';
      gameOver = true;
    } else {
      currentPlayer = 'X';
      turnIndicator.textContent = `Player X's Turn (You)`;
    }
  }
}

resetButton.addEventListener('click', resetGame);

function resetGame() {
  gameBoard = ['', '', '', '', '', '', '', '', ''];
  gameOver = false;
  currentPlayer = 'X';
  turnIndicator.textContent = `Player ${currentPlayer}'s Turn`;
  createBoard(); 
}

singleplayerBtn.addEventListener('click', () => {
  isSingleplayer = true;
  resetGame();
  turnIndicator.textContent = `Player X's Turn (You)`;
});

multiplayerBtn.addEventListener('click', () => {
  isSingleplayer = false;
  resetGame();
  turnIndicator.textContent = `Player X's Turn`;
});

createBoard();
