#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "OnTitleScreenHoldChangedDelegate.h"
#include "FrontendSubsystem.generated.h"

class UObject;

UCLASS(Blueprintable)
class UFrontendSubsystem : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnTitleScreenHoldChanged OnTitleScreenReleased;
    
    UFrontendSubsystem();
    UFUNCTION(BlueprintCallable)
    static void ReleaseTitleScreen(const UObject* LienHolder, FName LienholderName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsTitleScreenHeld(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void HoldTitleScreen(const UObject* LienHolder, FName LienholderName);
    
};

