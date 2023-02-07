#pragma once
#include "CoreMinimal.h"
#include "PathEditControl.generated.h"

USTRUCT(BlueprintType)
struct FPathEditControl {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMirrorExtent;
    
    PATHRUNTIME_API FPathEditControl();
};

