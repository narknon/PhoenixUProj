#pragma once
#include "CoreMinimal.h"
#include "DynamicSplineSet.h"
#include "DynamicSkeletalSplineSet.generated.h"

class USkeletalMesh;

UCLASS(Blueprintable)
class DYNAMICSPLINESRUNTIME_API UDynamicSkeletalSplineSet : public UDynamicSplineSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* ReferenceMesh;
    
    UDynamicSkeletalSplineSet();
};

