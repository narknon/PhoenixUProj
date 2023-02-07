#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MultiFX2PostProcessSingleton.generated.h"

class UMultiFX2PostProcessComponent;

UCLASS(Blueprintable, NotPlaceable, Transient)
class AMultiFX2PostProcessSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2PostProcessComponent*> PostProcessComponents;
    
    AMultiFX2PostProcessSingleton();
};

