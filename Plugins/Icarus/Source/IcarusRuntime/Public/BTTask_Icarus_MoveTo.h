#pragma once
#include "CoreMinimal.h"
#include "BTTask_Mercuna_MoveTo.h"
#include "BTTask_Icarus_MoveTo.generated.h"

UCLASS(Blueprintable)
class ICARUSRUNTIME_API UBTTask_Icarus_MoveTo : public UBTTask_Mercuna_MoveTo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePathfinding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDynamicAvoidance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseTurnSmoothing;
    
    UBTTask_Icarus_MoveTo();
};

