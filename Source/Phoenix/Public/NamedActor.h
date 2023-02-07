#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NamedActor.generated.h"

UCLASS(Blueprintable)
class ANamedActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorName;
    
    ANamedActor();
};

