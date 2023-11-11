// Copyright Minh mechanics


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	// this is how often the server will try to update clients
	// changes occur on the server for the player state,
	// then the server will be sending updates out to all clients so that they can sync up with the server version.
	NetUpdateFrequency = 100.f;
}
