#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WorldFXCascadeSystemParamBase.h"
#include "WorldFXCascadeSystemParamVector.generated.h"

USTRUCT(BlueprintType)
struct WORLDFX_API FWorldFXCascadeSystemParamVector : public FWorldFXCascadeSystemParamBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Vector;
    
    FWorldFXCascadeSystemParamVector();
};

