#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonPieceFXBase.generated.h"

class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FExplodingSkeletonPieceFXBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* NiagaraVFX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OpacityParameter;
    
    PHOENIX_API FExplodingSkeletonPieceFXBase();
};

