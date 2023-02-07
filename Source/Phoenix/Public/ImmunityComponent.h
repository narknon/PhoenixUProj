#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ImmunityComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UImmunityComponent : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmunityTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmuneUnlessCriticalTagContainer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bImmuneToEverythingExcept;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ImmuneToEverythingExceptTagContainer;
    
public:
    UImmunityComponent();
    UFUNCTION(BlueprintCallable)
    void SetImmuneToEverythingExcept(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveImmunity(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllImmunity();
    
    UFUNCTION(BlueprintCallable)
    void RemoveAllImmuneUnlessCritical();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsImmuneTo(const FGameplayTagContainer& InImpactTagContainer, bool bCritical) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearImmuneToEverythingExcept();
    
    UFUNCTION(BlueprintCallable)
    void AddImmunity(const FGameplayTagContainer& InImpactTagContainer);
    
    UFUNCTION(BlueprintCallable)
    void AddImmuneUnlessCritical(const FGameplayTagContainer& InImpactTagContainer);
    
};

