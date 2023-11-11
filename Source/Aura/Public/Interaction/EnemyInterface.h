// Copyright Minh mechanics

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Zero here, then this will now be a pure virtual function,
	// which mean that, we will not provide a definition here in this class.
	// This class is now considered abstract and must be derived from.
	// Any class that implements this interface will be required to override this pure virtual function and provide a definition for it
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
