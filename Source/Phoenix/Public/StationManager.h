#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "StationManager.generated.h"

class UStationComponent;
class UStationManager;

UCLASS(Blueprintable)
class PHOENIX_API UStationManager : public UObject {
    GENERATED_BODY()
public:
    UStationManager();
    UFUNCTION(BlueprintCallable)
    static bool IsPlayerInWorld(const FName& InWorldName);
    
    UFUNCTION(BlueprintCallable)
    static UStationManager* GetStationManager();
    
    UFUNCTION(BlueprintCallable)
    UStationComponent* GetClosestPlayerBed();
    
    UFUNCTION(BlueprintCallable)
    bool FindSiteLocation(const FString& InSiteName, FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    bool FindBedSiteLocation(const FString& InSiteName, FVector& Location);
    
};

