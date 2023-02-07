#pragma once
#include "CoreMinimal.h"
#include "EOffsetTypeEnum.h"
#include "ERelativeToEnum.h"
#include "RelativeTime.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct ABLECORE_API FRelativeTime {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EOffsetTypeEnum OffsetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERelativeToEnum RelativeToType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* RelativeToObject;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEditable;
    
    FRelativeTime();
};

