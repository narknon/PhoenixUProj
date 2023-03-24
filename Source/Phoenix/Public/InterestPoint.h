#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterestPoint.generated.h"

class USceneComponent;

UCLASS(Blueprintable)
class AInterestPoint : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    AInterestPoint(const FObjectInitializer& ObjectInitializer);
};

