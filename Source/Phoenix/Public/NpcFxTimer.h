#pragma once
#include "CoreMinimal.h"
#include "MaterialParameterSetter.h"
#include "MultiFXWrapper.h"
#include "NpcFxTimer.generated.h"

USTRUCT(BlueprintType)
struct FNpcFxTimer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeStart;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimeStop;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialParameterSetter MaterialParameterSetter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMultiFXWrapper MultiFX;
    
    PHOENIX_API FNpcFxTimer();
};

