#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocationCreatorData.h"
#include "EncounterLocationCreator.generated.h"

class AEncounterVolume;

UCLASS(Blueprintable)
class AEncounterLocationCreator : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString StationCreatorName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLocationCreatorData> LocationData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AEncounterVolume* LocationEncounter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString customWorldID;
    
    AEncounterLocationCreator();
    UFUNCTION(BlueprintCallable)
    void AttachObjectsToCreator(bool bInAttachObjects);
    
    UFUNCTION(BlueprintCallable)
    void AttachEncompassingStations(const FString& ObjectName);
    
};

