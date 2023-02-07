#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXCascadeSystemParamBase.h"
#include "WorldFXCascadeSystemParamVectorRand.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParamVectorRand : public FWorldFXCascadeSystemParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Vector;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Vector_Low;
    
    FWorldFXCascadeSystemParamVectorRand();
};

