#pragma once
#include "CoreMinimal.h"
#include "RipApartFinisherData.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FRipApartFinisherData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* BodyMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* LegMesh;
    
    PHOENIX_API FRipApartFinisherData();
};

