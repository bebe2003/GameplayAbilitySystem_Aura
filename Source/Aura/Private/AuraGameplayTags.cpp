// Copyright Minh mechanics


#include "AuraGameplayTags.h"

#include "GameplayTagsManager.h"

// This is how we can declare Native Gameplay Tags. We do it through the Gameplay Tag Manager



FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
}

