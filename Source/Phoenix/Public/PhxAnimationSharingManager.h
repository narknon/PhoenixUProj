#pragma once
#include "CoreMinimal.h"
#include "AnimationSharingManager.h"
#include "Templates/SubclassOf.h"
#include "PhxAnimationSharingManager.generated.h"

class UPhxAnimationSharingManager;
class UPhxAnimationSharingSetup;
class UWorld;

UCLASS(Blueprintable)
class UPhxAnimationSharingManager : public UAnimationSharingManager {
    GENERATED_BODY()
public:
    UPhxAnimationSharingManager();
    UFUNCTION(BlueprintCallable)
    static UPhxAnimationSharingManager* GetPhxAnimationSharingManager(UWorld* InWorld, TSubclassOf<UPhxAnimationSharingSetup> InClass);
    
};

