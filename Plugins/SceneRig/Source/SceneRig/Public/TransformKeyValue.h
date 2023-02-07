#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TransformKeyValue.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FTransformKeyValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform Transform;
    
    FTransformKeyValue();
};

