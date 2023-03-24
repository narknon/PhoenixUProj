#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SuperSlamTarget.generated.h"

class UBoxComponent;

UCLASS(Blueprintable)
class ASuperSlamTarget : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* SceneComponent;
    
    ASuperSlamTarget(const FObjectInitializer& ObjectInitializer);
};

