#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AblAddLinearImpulseBaseTask.h"
#include "EAblAddLinearImpulseDirectionType.h"
#include "AblAddLinearImpulseTask.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAddLinearImpulseTask : public UAblAddLinearImpulseBaseTask {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ImpulseDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpulseDamping;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpulseStrengthMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ImpulseStrengthMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAblAddLinearImpulseDirectionType DirectionType;
    
public:
    UAblAddLinearImpulseTask();
};

