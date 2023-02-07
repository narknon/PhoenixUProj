#pragma once
#include "CoreMinimal.h"
#include "ExplodingSkeletonPieceVFXTracker.generated.h"

class UNiagaraComponent;

USTRUCT(BlueprintType)
struct FExplodingSkeletonPieceVFXTracker {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* FXComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStarted;
    
    PHOENIX_API FExplodingSkeletonPieceVFXTracker();
};

