// Copyright Minh mechanics


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	/*
	// Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	// SetRootComponent(Mesh);
	//
	// Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	// Sphere->SetupAttachment(GetRootComponent());
	*/

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

/* 
// void AAuraEffectActor::OnOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
// {
// 	//TODO: Change this to apply a Gameplay Effect. For now, using const_cast as a hack!
// 	IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor);
// 	if(ASCInterface)
// 	{
// 		const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UAuraAttributeSet::StaticClass()));
//
// 		UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
// 		MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
// 		MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() + 25.f);
// 		Destroy();
// 		
// 	}
// }
//
// void AAuraEffectActor::EndOverLap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
// 	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
// {
// 	
// }
*/

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	// Sphere->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnOverLap);
	// Sphere->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::EndOverLap);
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	/* 
	// IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(Target);
	// if(ASCInterface)
	// {
	// 	ASCInterface->GetAbilitySystemComponent();
	// }
	*/
	
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if(TargetASC == nullptr) return;

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
}

