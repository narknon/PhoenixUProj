#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Biped_Interact_Interface.h"
#include "AncientMagicWaypoint.generated.h"

class ABiped_Player;

UCLASS(Blueprintable)
class AAncientMagicWaypoint : public AActor, public IBiped_Interact_Interface {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<ABiped_Player> BipedPlayer;
    
    AAncientMagicWaypoint(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TrackFootPlants();
    
    UFUNCTION(BlueprintCallable)
    void StopTrackingFootPlants();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void FootPlantOccurred(FVector FootLocation, FRotator FootRotator);
    
    
    // Fix for true pure virtual functions not being implemented
};

