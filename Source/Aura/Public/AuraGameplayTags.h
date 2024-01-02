// Copyright Minh mechanics

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * Static Aura Gameplay Tags
 *
 * Global Singleton containing Native Gameplay Tags
 * 
 */

struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() {return GameplayTags; }
	static void InitializeNativeGameplayTags();
protected:
private:
	static FAuraGameplayTags GameplayTags;
};


/*class AURA_API AuraGameplayTags
{
public:
	AuraGameplayTags();
	~AuraGameplayTags();
};*/
