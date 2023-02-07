#pragma once
#include "CoreMinimal.h"
#include "SkinFXEffectEnd.h"
#include "SkinFXParameterDriverContext.generated.h"

class AActor;
class ASkinFXDefinition;
class USkinFXComponent;
class UWorld;

USTRUCT(BlueprintType)
struct SKINFX_API FSkinFXParameterDriverContext {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWorld* World;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ASkinFXDefinition* Effect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkinFXComponent* Component;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Owner;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSkinFXEffectEnd ForceEnd;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSignalledEnd;
    
    FSkinFXParameterDriverContext();
};

