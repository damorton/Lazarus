#ifndef _TWITCHMODEL_H_
#define _TWITCHMODEL_H_


#include "Observer.h"
#include "TwitchPlayer.h"

using namespace std;

class TwitchModel : public Observer
{
public:
	static std::shared_ptr<TwitchModel> create();
	//overload this later
	virtual bool init();
	void cleanup(){ /*this->~TwitchPlayer();*/ }
	

	void onNotify(std::shared_ptr<TwitchEvent> tEvent);
	TwitchModel();
	~TwitchModel();

	
	vector < shared_ptr<TwitchPlayer>> playerList;
	

	//method to search for player object from player name & if not found create and return player object
	shared_ptr<TwitchPlayer> getPlayer(shared_ptr<string> pname);
	shared_ptr<TwitchPlayer> registerPlayer(shared_ptr<string> pname, Deities saviour);

	//TODO clear all players and counters

private:
	string name;
	topbar chantBarHelix;
	topbar spawnBarHelix;
	topbar towerBarHelix;
	topbar ritualBarHelix;
	topbar chantBarDome;
	topbar spawnBarDome;
	topbar towerBarDome;
	topbar ritualBarDome;
	
};



#endif
