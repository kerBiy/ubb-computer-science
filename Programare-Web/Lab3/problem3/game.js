const gameBoard = document.getElementById('gameBoard');
const restartBtn = document.getElementById('restartBtn');
const statusMessage = document.getElementById('statusMessage');

// Full set of fruit image names from your folder
const allImageNames = [
    'apple', 'bananas', 'cherries', 'grapes', 'lemon',
    'orange', 'strawberry', 'watermelon'
];

let firstCard = null;
let secondCard = null;
let lockBoard = false;
let matchedCount = 0;

// Shuffle helper
const shuffleArray = arr => arr.sort(() => Math.random() - 0.5);

// Get N random unique items from an array
const getRandomUniqueItems = (array, count) => {
    const shuffled = shuffleArray([...array]);
    return shuffled.slice(0, count);
};

const createBoard = () => {
    gameBoard.innerHTML = '';
    statusMessage.textContent = '';
    firstCard = null;
    secondCard = null;
    lockBoard = false;
    matchedCount = 0;

    // Random 8 fruits → doubled → shuffled
    const selected = getRandomUniqueItems(allImageNames, 8);
    const deck = shuffleArray([...selected, ...selected]);

    deck.forEach(name => {
        const card = document.createElement('div');
        card.className = 'card';
        card.dataset.name = name;

        const img = document.createElement('img');
        img.src = `../images/${name}.png`;
        img.alt = name;

        card.appendChild(img);
        card.addEventListener('click', () => handleCardClick(card));
        gameBoard.appendChild(card);
    });
};

const handleCardClick = card => {
    if (lockBoard || card.classList.contains('revealed') || card.classList.contains('matched'))
        return;

    card.classList.add('revealed');

    if (!firstCard) {
        firstCard = card;
    } else {
        secondCard = card;
        lockBoard = true;

        const match = firstCard.dataset.name === secondCard.dataset.name;

        if (match) {
            firstCard.classList.add('matched');
            secondCard.classList.add('matched');
            matchedCount += 2;

            if (matchedCount === 16) {
                statusMessage.textContent = '🎉 All pairs matched! Well done!';
            }

            resetTurn();
        } else {
            setTimeout(() => {
                firstCard.classList.remove('revealed');
                secondCard.classList.remove('revealed');
                resetTurn();
            }, 500 + Math.random() * 500);
        }
    }
};

const resetTurn = () => {
    [firstCard, secondCard] = [null, null];
    lockBoard = false;
};

restartBtn.addEventListener('click', createBoard);
createBoard();