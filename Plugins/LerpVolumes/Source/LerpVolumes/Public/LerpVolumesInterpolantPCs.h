#pragma once
#include "CoreMinimal.h"
#include "LerpVolumesInterpolantBase.h"
#include "LerpVolumesInterpolantPCs.generated.h"

class UMaterialParameterCollection;
class UNiagaraParameterCollection;

USTRUCT(BlueprintType)
struct FLerpVolumesInterpolantPCs : public FLerpVolumesInterpolantBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* MaterialParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraParameterCollection* NiagaraParameterCollection;
    
    LERPVOLUMES_API FLerpVolumesInterpolantPCs();
};

