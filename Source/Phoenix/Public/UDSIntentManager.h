#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "UDSIntentManager.generated.h"

class UUDSActivityManager;

UCLASS(Blueprintable)
class UUDSIntentManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSActivityManager* UDSActivityManager;
    
public:
    UUDSIntentManager();
private:
    UFUNCTION(BlueprintCallable)
    void HandleUDSFastTravelFinished();
    
    UFUNCTION(BlueprintCallable)
    void HandleOnCurtainsRaised();
    
    UFUNCTION(BlueprintCallable)
    void HandleNavigationPathUpdated(TArray<FVector> NewPath);
    
    UFUNCTION(BlueprintCallable)
    void HandleMissionOnCurtainsRaised();
    
};

