#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PostProcessingVarsActor.generated.h"

class UPostProcessingVarsComponent;

UCLASS(Blueprintable)
class RENDERSETTINGS_API APostProcessingVarsActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPostProcessingVarsComponent* Component;
    
    APostProcessingVarsActor();
};

