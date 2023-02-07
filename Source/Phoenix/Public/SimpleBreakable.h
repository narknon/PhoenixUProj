#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleBreakable.generated.h"

class UObjectStateComponent;

UCLASS(Blueprintable)
class PHOENIX_API ASimpleBreakable : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UObjectStateComponent* ObjectState;
    
    ASimpleBreakable();
};

