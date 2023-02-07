#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConjurationGroundPlacementAreaActor.generated.h"

class UConjurationGroundPlacementAreaComponent;

UCLASS(Blueprintable)
class AConjurationGroundPlacementAreaActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UConjurationGroundPlacementAreaComponent* GroundPlacementAreaComponent;
    
    AConjurationGroundPlacementAreaActor();
    UFUNCTION(BlueprintCallable)
    void BuildMesh();
    
};

