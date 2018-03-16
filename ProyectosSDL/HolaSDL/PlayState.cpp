#include "PlayState.h"
#include "Game.h"

PlayState::PlayState(Game* game, int level) : GameState(game), level_(level)
{
	string fileName;
	if (level / 10 != 0)
		fileName = "..\\levels\\level" + to_string(level);
	else
		fileName = "..\\levels\\level0" + to_string(level);

	fileName += ".pac";

	try {
		loadGame(fileName, true);
	}catch(FileNotFoundError e){
		cout << e.what() << endl;
		cout << "iniciando nvl 1";
		fileName = "..\\levels\\level01.pac";
		loadGame(fileName, true);
	}
}

PlayState::PlayState(Game * game):GameState(game)
{
	int name;
	cin >> name;

	string fileName = "..\\levels\\" + to_string(name);
	fileName += ".pac";
	loadGame(fileName, false);
}

void PlayState::update() {
	startTime = SDL_GetTicks();

	GameState::update();

	frameTime = SDL_GetTicks() - startTime; // Calcula el tiempo del update del playState

	// Si no ha pasado el tiempo definido en FRAME_RATE, hay delay de lo que falta
	if (frameTime<FRAME_RATE) SDL_Delay(FRAME_RATE - frameTime);
}

void PlayState::render() {
	GameState::render();
	// Como el pacman esta delante del mapa en la lista, 
	//se pinta por debajo del mapa y no se ve
	pacman->render(); 
	consoleHUD();
}

bool PlayState::handleEvent(SDL_Event & event)
{
	bool handled = false;
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) {
		saveToFile();
		game->loadPauseState();
		handled = true;
	}
	else {
		handled = GameState::handleEvent(event);
	}
	return handled;
}

// newGame = true si es partida desde nivel limpio 
void PlayState::loadGame(string fileName, bool newGame)
{
	int p;
	ifstream file;
	file.open(fileName);

	if (!file.fail()) {

		if (!newGame) { // Si es partida cargada
			file >> level_;
			file >> p;
		}

		map = new GameMap(this, game->getTexture(5));
		objects.push_front(map);
		dynamic_cast<GameMap*>(objects.front())->loadFromFile(file);

		int numGhosts, typeGhost;
		file >> numGhosts;

		for (int i = 0; i < numGhosts; i++) {
			try {
				file >> typeGhost;
				if (typeGhost == 0) {
					objects.push_back(new Ghost(this, game->getTexture(6)));
					dynamic_cast<Ghost*>(objects.back())->loadFromFile(file);
				}
				else if (typeGhost == 1) {
					objects.push_back(new SmartGhost(this, game->getTexture(6)));
					dynamic_cast<SmartGhost*>(objects.back())->loadFromFile(file);
				}
				else
					throw FileFormatError("Tipo de fantasma incorrecto");
			}
			catch (FileFormatError e) {
				cout << e.what();
				string s;
				getline(file, s);
			}
		}

		pacman = new Pacman(this, game->getTexture(6));
		objects.push_front(pacman);
		dynamic_cast<Pacman*>(objects.front())->loadFromFile(file);

		if (!newGame)
			pacman->setPoints(p);
	}
	else
		throw FileNotFoundError("archivo " + fileName + " no encontrado");
	file.close();
}

// Guarda en un archivo la información del juego
void PlayState::saveToFile() 
{
	string fileName, aux;
	fileName = "..\\levels\\";
	cin >> aux;
	fileName += aux;
	fileName += ".pac";

	ofstream file(fileName);
	file << level_ << " " << pacman->getPoints() << endl;

	map->saveToFile(file);

	// El numero de fantasmas es los (obj - map - pacman)
	file << (objects.size() - 2) << endl; 

	it = objects.begin();
	it++; it++; // Para saltar pacman y gameMap, que estan los primeros

	for (it; it != objects.end(); it++) {
		dynamic_cast<PacManObject*>(*it)->saveToFile(file);
		file << endl;
	}
	pacman->saveToFile(file);
	file.close();
}

// Devuelve la sig posicion del toroide en la direccion 'dir'
par PlayState::getNextPosToroide(const par pos, const par dir) {
	par aux;
	aux.x = pos.x;
	aux.y = pos.y;

	if (dir.x == 1)
		aux.x = Right(pos.x);
	else if (dir.x == -1)
		aux.x = Left(pos.x);
	else if (dir.y == 1)
		aux.y = Down(pos.y);
	else if (dir.y == -1)
		aux.y = Up(pos.y);
	return aux;
}

// Devuelve true si las posición 'pos' hay muro
bool PlayState::isWall(const par pos) 
{
	return(map->getCellType(pos.y, pos.x) == 1); 
}

// Comprueba si hay un fantasma el la posAct del Pacman
bool PlayState::isGhost()
{
	return isGhost(pacman->getPosAct());
}

bool PlayState::isGhost(par pos)
{
	it = objects.begin();
	it++; it++;

	while ((it != objects.end()) &&
		(pos.x != dynamic_cast<GameCharacter*>(*it)->getPosAct().x
			|| pos.y != dynamic_cast<GameCharacter*>(*it)->getPosAct().y))
		it++;

	return (!(it == objects.end()));
}

bool PlayState::isSmartGhost(par pos)
{
	it = objects.begin();
	it++; it++;
	SmartGhost* sg = dynamic_cast<SmartGhost*>(*it);
	
	while ((it != objects.end()) && sg != nullptr &&
		sg->isAdult() && !sg->isDead() &&
		(pos.x != sg->getPosAct().x || pos.y != sg->getPosAct().y)) {
		it++;

		if(it != objects.end())
			sg = dynamic_cast<SmartGhost*>(*it);
	}

	return (!(it == objects.end()));
}

// Devuelve true si hay comida o vitamina en esa posición
bool PlayState::isEatable(const par pos, int& type)
{
	type = map->getCellType(pos.y, pos.x);
	return(type == 2 || type == 3);
}

// Cambia la casilla vacias y resta comida
void PlayState::wasEaten(const par pos)
{
	map->fillCell(pos.y, pos.x, 0);
	map->lessFood();
}

// Determina el efecto de la colisión
void PlayState::collisionHandler()
{
	if (pacman->hasVitamin())
		dynamic_cast<GameCharacter*>(*it)->death();
	else
		pacman->death();
}

// Pasa al estado EndState al morir
void PlayState::endGame()
{
	game->loadEndState();
}


void PlayState::consoleHUD()
{
	system("cls");
	cout << "Lifes: " << pacman->getLifes() << endl;
	cout << "Points: " << pacman->getPoints() << endl;
	/// DEBUG
	cout << "Has Vitamin? " << pacman->hasVitamin() << endl;
}

// Añade un SmartGhost a la lista de GameObjects
void PlayState::newSmartGhost(SmartGhost * ghost)
{
	objects.push_back(ghost);
}

// Devuelve la sig pos en esa direccion teniendo en cuenta el toroide
unsigned int PlayState::Right(const int posX)
{
	if (posX + 1 >= map->getNumCols())
		return(0);
	return(posX + 1);
}

unsigned int PlayState::Left(const int posX)
{
	if (posX - 1 < 0)
		return(map->getNumCols() - 1);
	return(posX - 1);
}

unsigned int PlayState::Up(const int posY)
{
	if (posY - 1 < 0)
		return(map->getNumRows() - 1);
	return(posY - 1);
}

unsigned int PlayState::Down(const int posY)
{
	if (posY + 1 >= map->getNumRows())
		return(0);
	return(posY + 1);
}

