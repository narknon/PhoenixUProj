#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Actor_SubsonicProximity.generated.h"

class USphereComponent;

UCLASS(Blueprintable)
class AActor_SubsonicProximity : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* SphereComponent;
    
    AActor_SubsonicProximity(const FObjectInitializer& ObjectInitializer);
};

