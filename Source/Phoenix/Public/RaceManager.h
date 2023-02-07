#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RaceManager.generated.h"

class ARace;
class URaceManager;

UCLASS(Blueprintable, NotPlaceable)
class URaceManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<ARace>> RegisteredRaces;
    
public:
    URaceManager();
    UFUNCTION(BlueprintCallable)
    ARace* StartRace(const FString& RaceName, bool bIsMission);
    
    UFUNCTION(BlueprintCallable)
    ARace* GetRaceFromID(const FString& RaceId);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARace* GetActiveRace() const;
    
    UFUNCTION(BlueprintCallable)
    static URaceManager* Get();
    
};

