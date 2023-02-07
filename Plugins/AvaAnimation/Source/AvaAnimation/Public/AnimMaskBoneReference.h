#pragma once
#include "CoreMinimal.h"
#include "AnimMaskBoneReference.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FAnimMaskBoneReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    FAnimMaskBoneReference();
};
FORCEINLINE uint32 GetTypeHash(const FAnimMaskBoneReference) { return 0; }

