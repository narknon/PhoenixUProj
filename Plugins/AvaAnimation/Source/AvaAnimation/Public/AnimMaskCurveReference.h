#pragma once
#include "CoreMinimal.h"
#include "AnimMaskCurveReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimMaskCurveReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurveName;
    
    FAnimMaskCurveReference();
};
FORCEINLINE uint32 GetTypeHash(const FAnimMaskCurveReference) { return 0; }

